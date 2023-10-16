#include "src/staffwidget.h"

#include <qbrush.h>
#include <qcolor.h>
#include <qevent.h>
#include <qimage.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qsize.h>
#include <qwidget.h>
#include <qwindowdefs.h>

#include <QPainter>
#include <algorithm>
#include <iostream>
#include <vector>

#include "midicontroller.h"
#include "midimessage.h"
#include "ui_staffwidget.h"

StaffWidget::StaffWidget(QWidget* parent) : QWidget(parent), _ui(new Ui::StaffWidget())
{
    _ui->setupUi(this);
    MidiController* instance = MidiController::GetInstance();
    connect(instance, &MidiController::midiEvent, this, &StaffWidget::onMidiEvent);
    this->treble = QImage(":/resources/treble.png");
    this->bass = QImage(":/resources/bass.png");
}
StaffWidget::~StaffWidget()
{
    delete _ui;
}
void StaffWidget::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);
    int starty = 7 * _gap / 2 * 3 - _gap;
    painter.drawImage(QRect(0, starty - _gap, _gap * 2, _gap * 6), treble);
    painter.drawImage(QRect(0, starty + _gap * 6, _gap * 2, _gap * 3.5), bass);
    for (int i = 0; i < 11; i++)
    {
        if (i == 5)  // skip line for middle c
            continue;
        painter.drawLine(0, starty + _gap * i, geometry().width(), starty + _gap * i);
    }

    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
    // draw fix notes
    for (int i = 0; i < fixNotes.size(); i++)
        drawNote(fixNotes[i], painter, Qt::black, i * 2);

    // draw pressed notes
    for (int i = 0; i < pressedNotes.size(); i++)
    {
        if (std::find(fixNotes.begin(), fixNotes.end(), pressedNotes[i]) != fixNotes.end())
        {
            drawNote(pressedNotes[i], painter, Qt::green, _cursorPosition * 2);
        }
        else
        {
            drawNote(pressedNotes[i], painter, Qt::red, _cursorPosition * 2);
        }
    }
}

void StaffWidget::drawNote(Note n, QPainter& painter, Qt::GlobalColor color, int position)
{
    int middleCpos = 14 * _gap;
    int notePosY = _staffHeight - (n.pitch * _gap / 2 + n.octave * 7 * _gap / 2);
    int notePosX = _gap * 4 + position * _gap;
    float noteWidth = 1.2 * _gap;
    float noteHeight = _gap;

    // draw note leg
    painter.setPen(QPen(Qt::black, _gap / 10));
    painter.drawLine(notePosX + noteWidth - _gap / 20, notePosY + _gap / 2, notePosX + noteWidth - _gap / 20,
                     notePosY + _gap - 3 * _gap);

    // draw note
    painter.setPen(Qt::NoPen);
    painter.setBrush(QBrush(color, Qt::SolidPattern));
    painter.drawEllipse(notePosX, notePosY, noteWidth, noteHeight);
    // cursorpos++;
    painter.setPen(Qt::PenStyle::SolidLine);
    QFont font;
    font.setPixelSize(_gap);
    painter.setFont(font);
    if (n.accidental == Accidental::SHARP)
        painter.drawText(_gap * 4 - _gap, notePosY + _gap, "#");
    if (n.accidental == Accidental::FLAT)
        painter.drawText(_gap * 4 - _gap, notePosY + _gap, "b");

    // draw lower ledger lines
    for (int i = middleCpos + 6 * _gap; i <= notePosY; i += _gap)
    {
        painter.drawLine(notePosX - _gap / 2, i + _gap / 2, notePosX + 3 * _gap / 2, i + _gap / 2);
    }
    // draw upper ledger lines
    for (int i = middleCpos - 6 * _gap; i >= notePosY; i -= _gap)
    {
        painter.drawLine(notePosX - _gap / 2, i + _gap / 2, notePosX + 3 * _gap / 2, i + _gap / 2);
    }
    // draw ledger line for middle c
    if (notePosY == middleCpos)
        painter.drawLine(notePosX - _gap / 2, middleCpos + _gap / 2, notePosX + 3 * _gap / 2, middleCpos + _gap / 2);
}
void StaffWidget::resizeEvent(QResizeEvent* event)
{
    _gap = geometry().height() / (7 * 8 / 2);  // 52 white keys
    _staffHeight = (7 * 8) * _gap / 2;         // 52 white keys

    update();
}
void StaffWidget::onMidiEvent(const MidiMessage& message)
{
    if (message.pressed)
    {
        // std::cout << message.note.getStr().toStdString() << std::endl;

        AddNote(message.note);
    }
    else
    {
        RemoveNote(message.note);
    }
}
void StaffWidget::AddNote(Note n, bool fixed)
{
    if (!fixed)
    {
        this->pressedNotes.push_back(n);
    }
    else
    {
        this->fixNotes.push_back(n);
    }
    update();
}
void StaffWidget::RemoveNote(Note n, bool fixed)
{
    if (!fixed)
    {
        this->pressedNotes.erase(std::find(pressedNotes.begin(), pressedNotes.end(), n));
    }
    else
    {
        this->fixNotes.erase(std::find(fixNotes.begin(), fixNotes.end(), n));
    }

    update();
}

void StaffWidget::increaseCursorPosition()
{
    _cursorPosition++;
}
void StaffWidget::resetCursor()
{
    _cursorPosition = 0;
}
