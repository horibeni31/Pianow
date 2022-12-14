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
#include <cstdlib>
#include <iostream>

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
#include <stdlib.h>
NoteIdentification::NoteIdentification()
    : QMainWindow(), staff(new Staff(this)) {
  this->button = new QPushButton("Hello there");
  setCentralWidget(staff);
  srand(time(0));
  //  this->setCentralWidget(image);
  this->goal = GenerateRandomNote();
  staff->AddNote(goal,true);

  resize(500, 500);
}

void NoteIdentification::HandleMidiMessage(MidiMessage m) {
  if (m.pressed) {
    std::cout << m.note.pitch << "," << m.note.accidental << ","
              << m.note.octave << std::endl;
    this->staff->AddNote(m.note);
    

  } else {
    this->staff->RemoveNote(m.note);
    if(m.note == goal){
      this->staff->RemoveNote(goal,true);
      this->goal = GenerateRandomNote();
      this->staff->AddNote(goal,true);
    }
    // pressedNotes.erase(std::remove(pressedNotes.begin(),pressedNotes.end(),m.note));
  }
  // std::cout << m.note.octave << ", " << m.note.pitch << std::endl;
}

Note NoteIdentification::GenerateRandomNote(){
  Note n = Note((Pitch)(rand()%7),4,Accidental::NORMAL); 
    return n;
}