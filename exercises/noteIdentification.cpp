#include "noteIdentification.h"
#include "exercises/exercise.h"
#include "midi/midiController.h"
#include "midi/midiMessage.h"
#include "midi/note.h"
#include "widgets/staff.h"
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <algorithm>
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
#include <qcolor.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qwindowdefs.h>
#include <string>
#include <thread>
#include <vector>

NoteIdentification::NoteIdentification()
    : QMainWindow(), staff(new Staff(this)) {
  this->button = new QPushButton("Hello there");
  setCentralWidget(staff);
  //  this->setCentralWidget(image);
  resize(500, 500);
  
}


void NoteIdentification::HandleMidiMessage(MidiMessage m) {
  if (m.pressed) {
std::cout<<m.note.pitch<<","<<m.note.accidental<<","<<m.note.octave<<std::endl;
    this->staff->AddNote(m.note);

  } else {
    this->staff->RemoveNote(m.note);
    // pressedNotes.erase(std::remove(pressedNotes.begin(),pressedNotes.end(),m.note));
  }
 // std::cout << m.note.octave << ", " << m.note.pitch << std::endl;

}
