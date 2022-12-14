#include "mainWindow.h"
#include "exercises/noteIdentification.h"
#include "midi/midiController.h"
#include "widgets/settings.h"
#include <QApplication>
#include <QPushButton>
#include <qboxlayout.h>
#include <qgroupbox.h>
#include <qnamespace.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qwindowdefs.h>
MainWindow::MainWindow() {

  this->exercise = nullptr;
  this->settings = new Settings();

  MidiController::GetInstance()->Connect(0);
  create_menu();
  setCentralWidget(groupBox);
}
void MainWindow::create_menu() {
  this->groupBox = new QGroupBox();

  QPushButton *_btn_exit = new QPushButton("exit", this);

  QPushButton *_btn_note_identification =
      new QPushButton("Note Identification", this);
  QPushButton *_btn_chord_identification =
      new QPushButton("Chord Identification", this);
  QPushButton *_btn_settings = new QPushButton("Settings", this);
  QPushButton *_btn_keySigniture_identification =
      new QPushButton("Key signiture Identification", this);

  _btn_chord_identification->setEnabled(false);
  _btn_keySigniture_identification->setEnabled(false);

  QVBoxLayout *layout = new QVBoxLayout();
  layout->addWidget(_btn_note_identification);
  layout->addWidget(_btn_chord_identification);
  layout->addWidget(_btn_keySigniture_identification);
  layout->addWidget(_btn_settings);
  layout->addWidget(_btn_exit);
  groupBox->setLayout(layout);
  groupBox->setContentsMargins(100, 100, 100, 100);

  connect(_btn_exit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
  connect(_btn_note_identification, SIGNAL(clicked()), this,
          SLOT(show_exercise_note_identification()));
  connect(_btn_settings, SIGNAL(clicked()), this, SLOT(show_settings()));
  ;
}
void MainWindow::show_exercise_note_identification() {
  if (!this->exercise) {

    this->exercise = new NoteIdentification();
    midiController->currExercise = this->exercise;

    this->exercise->show();
  }
}
void MainWindow::show_settings() { this->settings->show(); }