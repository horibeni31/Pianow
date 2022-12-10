#include "staff.h"
#include "midi/note.h"
#include <algorithm>
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
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

  int startx = 10;
  int starty = 10;

  int width = 300;
  int gap = 10;
  QPainter painter(this);
  painter.drawImage(QRect(startx, starty - gap / 2, gap * 2, gap * 6), treble);
  painter.drawImage(QRect(startx, starty + gap * 6, gap * 2, gap * 3.5), bass);
  for (int i = 0; i < 11; i++) {
    if (i == 5)
      continue;
    painter.drawLine(startx, starty + gap * i, startx + width,
                     starty + gap * i);
  }

  int middleCpos = starty + 4 * gap + gap * 0.5;

  painter.setPen(Qt::NoPen);
  painter.setBrush(QBrush(Qt::black, Qt::SolidPattern));
  // draw fix notes
  for (int i = 0; i < fixNotes.size(); i++) {
    int notePos = middleCpos - (fixNotes[i].pitch * gap * 0.5 +
                                (fixNotes[i].octave - 4) * 7 * gap * 0.5);
    painter.drawEllipse(startx + gap * 4, notePos, gap, gap);
    if (fixNotes[i].accidental == Accidental::SHARP) {
      painter.drawText(startx + gap * 4 - gap, notePos + gap, "#");
    }
    if (fixNotes[i].accidental == Accidental::FLAT) {
      painter.drawText(startx + gap * 4 - gap, notePos + gap, "b");
    }
  }

  // draw pressed notes
  for (int i = 0; i < pressedNotes.size(); i++) {
    if (std::find(fixNotes.begin(), fixNotes.end(), pressedNotes[i]) !=
        fixNotes.end()) {
      painter.setBrush(QBrush(Qt::green, Qt::SolidPattern));

    } else {
      painter.setBrush(QBrush(Qt::red, Qt::SolidPattern));
    }

    int notePos = middleCpos - (pressedNotes[i].pitch * gap * 0.5 +
                                (pressedNotes[i].octave - 4) * 7 * gap * 0.5);
    painter.drawEllipse(startx + gap * 4, notePos, gap, gap);
    if (pressedNotes[i].accidental == Accidental::SHARP) {
      painter.drawText(startx + gap * 4 - gap, notePos + gap, "#");
    }
    if (pressedNotes[i].accidental == Accidental::FLAT) {
      painter.drawText(startx + gap * 4 - gap, notePos + gap, "b");
    }
  }
}
void Staff::resizeEvent(QResizeEvent *event) { update(); }

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