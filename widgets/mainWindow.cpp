#include "mainWindow.h"
#include <QPushButton>
#include <QApplication>
#include <qboxlayout.h>
#include <qgroupbox.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include "exercises/noteIdentification.h"
#include "midi/midiController.h"
MainWindow::MainWindow(){
    this->_btn_exit  = new QPushButton("exit",this);
    this->_btn_exit->setGeometry(0,0,100,20);
    this->_btn_note_identification  = new QPushButton("Note Identification",this);
    this->_btn_note_identification->setGeometry(0,30,100,20);
  
    this->exercise =nullptr;
    
MidiController::Init();
MidiController::Connect(0);

 connect(_btn_exit, SIGNAL (clicked()), QApplication::instance(), SLOT (quit()));
 connect(_btn_note_identification, SIGNAL (clicked()), this, SLOT (exercise_note_identification()));

}
void MainWindow::exercise_note_identification() {
   
   this->exercise = new NoteIdentification();
   midiController->currExercise=this->exercise;

    this->exercise->show();
    
   

}