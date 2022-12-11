#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "exercises/noteIdentification.h"
#include "midi/midiController.h"
#include <QDialog>
#include <QMainWindow>
#include <QPushButton>
#include <qdialog.h>
#include <qevent.h>
#include <qgroupbox.h>
#include <qmainwindow.h>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qwidget.h>
#include <qwindowdefs.h>

class MainWindow : public QMainWindow {

  Q_OBJECT
private:
  MidiController *midiController;
  QPushButton *_btn_note_identification;
  QPushButton *_btn_chord_identification;
  QPushButton *_btn_keySigniture_identification;
  QPushButton *_btn_exit;
  NoteIdentification *exercise;
  QGroupBox* groupBox;

public:
  MainWindow();
private slots:
  void exercise_note_identification();
};

#endif