#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "exercises/noteIdentification.h"
#include "midi/midiController.h"
#include "widgets/settings.h"
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

  NoteIdentification *exercise;
  Settings *settings;
  QGroupBox *groupBox;
  void create_menu();

public:
  MainWindow();
private slots:
  void show_exercise_note_identification();
  void show_settings();
};

#endif