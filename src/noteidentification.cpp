#include "src/noteidentification.h"

#include <qboxlayout.h>
#include <qcolor.h>
#include <qdatetime.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qtimer.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include <stdlib.h>

#include <QImage>
#include <QLayout>
#include <QPaintEvent>
#include <QPainter>
#include <QTime>
#include <QTimer>
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <nlohmann/json_fwd.hpp>
#include <string>
#include <thread>
#include <utility>
#include <vector>

#include "exerciseresult.h"
#include "midicontroller.h"
#include "note.h"
#include "ui_noteidentification.h"
NoteIdentification::NoteIdentification(QWidget* parent) : QDialog(parent), _ui(new Ui::NoteIdentification())
{
    QTimer* timer = new QTimer(this);
    time = 0;
    timer->setInterval(100);
    timer->start();

    timer->setTimerType(Qt::TimerType::PreciseTimer);
    connect(timer, &QTimer::timeout,
            [=]()
            {
                timer->start();
                time += 100;
                _currentTime += 100;
                QTime t = QTime::fromMSecsSinceStartOfDay(time);
                _ui->lblTime->setText(t.toString("hh:mm:ss:zzz"));
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
            std::cout << "goal hit" << std::endl;

            if (_currentGoalIndex == _goals.size())
            {
                std::cout << "all goals hit" << std::endl;
                ExerciseResult res;
                res.goals = _goals;
                res.tries = _tries;
                nlohmann::json json = res;
                QDateTime date = QDateTime::currentDateTime();
                QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
                QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();

                std::ofstream of(formattedTimeMsg.toStdString());
                of << json;
            }
            else
            {
                _ui->staff->increaseCursorPosition();
            }
            //     _ui->staff->RemoveNote(_goal, true);
            //    // _goal = Note::getRandom();
            _ui->lblGoal->setText(_goals[_currentGoalIndex].getStr());
            //     _ui->staff->AddNote(_goal, true);
            //     success++;
            //     _ui->lblPassed->setText(QString("Success:  %1").arg(success));
        }
        else
        {
            // std::cout<<n.getStr().toStdString()<<std::endl;
            // std::cout<<_goals[_currentGoalIndex].getStr().toStdString()<<std::endl;
            _tries[_currentGoalIndex].second++;
            //_ui->lblError->setText(QString("Error:  %1").arg(error));
        }
    }
}
