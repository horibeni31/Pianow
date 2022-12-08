#include "noteIdentification.h"
#include "exercises/exercise.h"
#include "midi/midiController.h"
#include "midi/midiMessage.h"
#include "midi/note.h"
#include "widgets/staff.h"
#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <iostream>
#include <pstl/glue_algorithm_defs.h>
#include <qcolor.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qwindowdefs.h>
#include <vector>
#include <thread>
#include <algorithm>
#include <string>

NoteIdentification::NoteIdentification():QMainWindow(),staff(new Staff(this)) {
  this->button = new QPushButton("Hello there");
  setCentralWidget(staff);
  this->pressedNotes = std::vector<Note>();
  //  this->setCentralWidget(image);
resize(500,500);
  staff->drawStaff();
}

void NoteIdentification::Start() {
 //std::thread listenThread(&NoteIdentification::Listen,this);
}
void NoteIdentification::HandleMidiMessage(MidiMessage m){
 if(m.pressed){
        pressedNotes.push_back(m.note);
        
      }else {
      pressedNotes.erase(std::remove(pressedNotes.begin(),pressedNotes.end(),m.note));
      }
      std::cout<<m.note.octave<<", "<<m.note.pitch<<std::endl;
      staff->drawStaff();
}
void NoteIdentification::Listen(){
  MidiMessage m;
 while (true) {
  
    if(MidiController::getMessage(m)){
     
    }
  }

}