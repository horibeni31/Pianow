#include "mainWindow.h"
#include "exercises/noteIdentification.h"
#include "midi/midiController.h"
#include <QApplication>
#include <QPushButton>
#include <qboxlayout.h>
#include <qgroupbox.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qwindowdefs.h>
MainWindow::MainWindow() {
  this->_btn_exit = new QPushButton("exit", this);

  this->_btn_note_identification = new QPushButton("Note Identification", this);

  this->exercise = nullptr;
  this->groupBox = new QGroupBox();
  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(_btn_exit);
  layout->addWidget(_btn_note_identification);
  groupBox->setLayout(layout);
  MidiController::Init();
  MidiController::Connect(0);
setCentralWidget(groupBox);
  connect(_btn_exit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
  connect(_btn_note_identification, SIGNAL(clicked()), this,
          SLOT(exercise_note_identification()));
}
void MainWindow::exercise_note_identification() {

  this->exercise = new NoteIdentification();
  midiController->currExercise = this->exercise;

  this->exercise->show();
}