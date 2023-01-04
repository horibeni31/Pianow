#include "staff.h"
#include "midi/note.h"
#include <algorithm>
#include <iostream>

#include <qbrush.h>
#include <qcolor.h>
#include <qevent.h>
#include <qimage.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qpen.h>
#include <qsize.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include <vector>

Staff::Staff(QWidget *parent)
    : QWidget(parent), treble(QImage("treble.png")), bass(QImage("bass.png")) {
  setAttribute(Qt::WA_StaticContents);

  pressedNotes = std::vector<Note>();
}

void Staff::paintEvent(QPaintEvent *event) {

  QPainter painter(this);
  painter.drawImage(QRect(startx, starty - gap / 2, gap * 2, gap * 6), treble);
  painter.drawImage(QRect(startx, starty + gap * 6, gap * 2, gap * 3.5), bass);

  for (int i = 0; i < 11; i++) {
    if (i == 5)
      continue;
    painter.drawLine(startx, starty + gap * i, startx + width,
                     starty + gap * i);
  }

  painter.setPen(Qt::NoPen);
  painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
  // draw fix notes
  for (int i = 0; i < fixNotes.size(); i++) {
    drawNote(fixNotes[i], painter);

    // draw pressed notes
    for (int i = 0; i < pressedNotes.size(); i++) {
      if (std::find(fixNotes.begin(), fixNotes.end(), pressedNotes[i]) !=
          fixNotes.end()) {
        painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));
      } else {
        painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
      }
      drawNote(pressedNotes[i], painter);
    }
  }
}

void Staff::drawNote(Note n, QPainter &painter) {
  int notePos =
      middleCpos - (n.pitch * gap * 0.5 + (n.octave - 4) * 7 * gap * 0.5);
  painter.setPen(QPen(Qt::black));
  painter.drawLine(startx+gap*4 + gap, notePos + gap, startx+gap*4  + gap,
                   notePos + gap - 3 * gap);

  painter.setPen(Qt::NoPen);
  painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
  painter.drawEllipse(startx + gap * 4, notePos, gap, gap);
  if (n.accidental == Accidental::SHARP) {
    painter.drawText(startx + gap * 4 - gap, notePos + gap, "#");
  }
  if (n.accidental == Accidental::FLAT) {
    painter.drawText(startx + gap * 4 - gap, notePos + gap, "b");
  }
}
void Staff::resizeEvent(QResizeEvent *event) {
  startx = 10;
  starty = 10;
  gap = 10;
  middleCpos = starty + 4 * gap + gap * 0.5;
  width = 300;
  // todo responsive

  update();
}

void Staff::AddNote(Note n, bool fixed) {
  if (!fixed) {

    this->pressedNotes.push_back(n);
  } else {
    this->fixNotes.push_back(n);
  }
  // drawStaff();
  update();
}
void Staff::RemoveNote(Note n, bool fixed) {
  if (!fixed) {

    this->pressedNotes.erase(
        std::find(pressedNotes.begin(), pressedNotes.end(), n));
  } else {
    this->fixNotes.erase(std::find(fixNotes.begin(), fixNotes.end(), n));
  }

  // drawStaff();
  update();
}