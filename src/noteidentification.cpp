#include "src/noteidentification.h"
#include "midicontroller.h"
#include "note.h"
#include "ui_noteidentification.h"

#include <QImage>
#include <QPaintEvent>
#include <QPainter>
#include <algorithm>
#include <cstdlib>
#include <iostream>

#include <QLayout>
#include <qboxlayout.h>
#include <qcolor.h>
#include <qdialog.h>
#include <qmainwindow.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qwidget.h>
#include <qwindowdefs.h>
#include <stdlib.h>
#include <string>
#include <thread>
#include <vector>
NoteIdentification::NoteIdentification(QWidget *parent)
    : QDialog(parent), _ui(new Ui::NoteIdentification()) {
  _ui->setupUi(this);
  connect(MidiController::GetInstance(), &MidiController::midiEvent, this,
          &NoteIdentification::onMidiEvent);
  _goal = Note::getRandom();
      _ui->lblGoal->setText(_goal.getStr());

  _ui->staff->AddNote(_goal,true);
}
NoteIdentification::~NoteIdentification() { delete _ui; }

void NoteIdentification::onMidiEvent(const MidiMessage &message) {
  Note n = message.note;
  if(!message.pressed){

  if (n == _goal) {
    _ui->staff->RemoveNote(_goal, true);
    _goal = Note::getRandom();
    _ui->lblGoal->setText(_goal.getStr());
    _ui->staff->AddNote(_goal, true);
    success++;
    _ui->lblPassed->setText(QString("Success:  %1").arg(success));
  }else {
    error++;
    _ui->lblError->setText(QString("Error:  %1").arg(error));
  }
  }
}
