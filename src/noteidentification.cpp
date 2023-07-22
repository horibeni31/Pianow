#include "src/noteidentification.h"
#include "ui_noteidentification.h"

#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <algorithm>
#include <cstdlib>
#include <iostream>

#include <qboxlayout.h>
#include <qcolor.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include <string>
#include <thread>
#include <vector>
#include <stdlib.h>
#include <QLayout>
NoteIdentification::NoteIdentification(QWidget* parent)
    :QDialog(parent),_ui(new Ui::NoteIdentification()) {
  // this->button = new QPushButton("Hello there");
  // Form* f = new Form();
  // this->setLayout(new QVBoxLayout(this));
  // this->layout()->addWidget(f);
  // this->layout()->addWidget(new Staff(this));
  // srand(time(0));
  // //  this->setCentralWidget(image);
  // this->goal = GenerateRandomNote();
  // staff->AddNote(goal,true);

  // resize(500, 500);
  _ui->setupUi(this);
}
NoteIdentification::~NoteIdentification(){
  delete _ui;
}

// void NoteIdentification::HandleMidiMessage(MidiMessage m) {
//   if (m.pressed) {
//     std::cout << m.note.pitch << "," << m.note.accidental << ","
//               << m.note.octave << std::endl;
//     this->staff->AddNote(m.note);
    

//   } else {
//     this->staff->RemoveNote(m.note);
//     if(m.note == goal){
//       this->staff->RemoveNote(goal,true);
//       this->goal = GenerateRandomNote();
//       this->staff->AddNote(goal,true);
//     }
//     // pressedNotes.erase(std::remove(pressedNotes.begin(),pressedNotes.end(),m.note));
//   }
//   // std::cout << m.note.octave << ", " << m.note.pitch << std::endl;
// }

// Note NoteIdentification::GenerateRandomNote(){
//   Note n = Note((Pitch)(rand()%7),4,Accidental::NORMAL); 
//     return n;
// }