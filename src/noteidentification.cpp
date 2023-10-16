#include "src/noteidentification.h"

#include <qboxlayout.h>
#include <qcolor.h>
#include <qdatetime.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qmessagebox.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qtimer.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include <stdlib.h>

#include <QImage>
#include <QLayout>
#include <QMessageBox>
#include <QPaintEvent>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <memory>
#include <nlohmann/json_fwd.hpp>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "exerciseresult.h"
#include "midicontroller.h"
#include "note.h"
#include "ui_noteidentification.h"
#include <sqlite3.h> 
NoteIdentification::NoteIdentification(QWidget* parent)
    : QDialog(parent), _ui(new Ui::NoteIdentification()), _timer(std::make_unique<QTimer>())
{
    _timer->setTimerType(Qt::TimerType::PreciseTimer);
    time = 0;
    _timer->setInterval(100);
    _timer->start();

    connect(_timer.get(), &QTimer::timeout,
            [=]()
            {
                if (_currentGoalIndex != _goals.size())
                {
                    _timer->start();
                    time += 100;
                    _currentTime += 100;
                    QTime t = QTime::fromMSecsSinceStartOfDay(time);
                    _ui->lblTime->setText(t.toString("hh:mm:ss:zzz"));
                }
            });
    _ui->setupUi(this);
    connect(MidiController::GetInstance(), &MidiController::midiEvent, this, &NoteIdentification::onMidiEvent);
    for (int i = 0; i < 10; i++)
    {
        _goals.push_back(Note::getRandom());
        _tries.push_back(std::pair<int, int>(0, 0));
        _ui->staff->AddNote(_goals[i], true);
    }
    _ui->lblGoal->setText(_goals[0].getStr());
}
NoteIdentification::~NoteIdentification()
{
    delete _ui;
}

void NoteIdentification::onMidiEvent(const MidiMessage& message)
{
    Note n = message.note;
    if (!message.pressed)
    {
        if (n == _goals[_currentGoalIndex])
        {
            _tries[_currentGoalIndex].first = _currentTime;

            _currentTime = 0;
            _currentGoalIndex++;
            if (_currentGoalIndex == _goals.size())
            {
                ExerciseResult res;
                res.goals = _goals;
                res.tries = _tries;
                nlohmann::json json = res;
                QDateTime date = QDateTime::currentDateTime();
                QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
                QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

                std::ofstream of(formattedTimeMsg.toStdString() + ".json");
                of << json;
                //auto ans = QMessageBox::question(this, "Exercsise done", "do you want to restart?");
              //  if (ans == QMessageBox::Yes)
                {
                    time = 0;
                    for (int i = 0; i < 10; i++)
                    {
                        _ui->staff->RemoveNote(_goals[i], true);
                    }
                    _goals.clear();
                    _tries.clear();
                    for (int i = 0; i < 10; i++)
                    {
                        _goals.push_back(Note::getRandom());
                        _tries.push_back(std::pair<int, int>(0, 0));
                        _ui->staff->AddNote(_goals[i], true);
                    }
                    _currentGoalIndex = 0;
                    _timer->start();
                    _ui->staff->resetCursor();
                }
            }
            else
            {
                _ui->staff->increaseCursorPosition();
            }

            _ui->lblGoal->setText(_goals[_currentGoalIndex].getStr());
        }
        else
        {
            _tries[_currentGoalIndex].second++;
        }
    }
}
