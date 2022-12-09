#include "staff.h"
#include "midi/note.h"
#include <algorithm>
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
#include <qevent.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qsize.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include <vector>
Staff::Staff(QWidget *parent) : QWidget(parent) {
  setAttribute(Qt::WA_StaticContents);

  pressedNotes = std::vector<Note>();
}

void Staff::paintEvent(QPaintEvent *event) {

  int startx = 10;
  int starty = 10;

  int width = 300;
  int gap = 10;
  QPainter painter(this);
  for (int i = 0; i < 11; i++) {
    if (i == 5)
      continue;
    painter.drawLine(startx, starty + gap * i, startx + width,
                     starty + gap * i);
  }

  int middleCpos = starty + 4 * gap + gap * 0.5;
  for (int i = 0; i < pressedNotes.size(); i++) {
    int notePos = middleCpos - (pressedNotes[i].pitch * gap * 0.5 +
                                (pressedNotes[i].octave - 4) * 7 * gap * 0.5);
    painter.drawEllipse(startx, notePos, gap, gap);
    if(pressedNotes[i].accidental==Accidental::SHARP){
      painter.drawText(startx-gap,notePos+gap,"#");
    }if(pressedNotes[i].accidental==Accidental::FLAT){
      painter.drawText(startx-gap,notePos+gap,"b");
    }
  }
}
void Staff::resizeEvent(QResizeEvent *event) { update(); }

void Staff::AddNote(Note n) {

  this->pressedNotes.push_back(n);
  // drawStaff();
  update();
}
void Staff::RemoveNote(Note n) {

  this->pressedNotes.erase(
      std::find(pressedNotes.begin(), pressedNotes.end(), n));
  // drawStaff();
  update();
}