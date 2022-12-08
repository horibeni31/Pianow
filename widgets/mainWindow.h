#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "exercises/noteIdentification.h"
#include "midi/midiController.h"
#include <QMainWindow>
#include <qdialog.h>
#include <qevent.h>
#include <qwindowdefs.h>
#include <QDialog>
#include <qmainwindow.h>
#include <QPushButton>
#include <qobjectdefs.h>
#include <qpushbutton.h>
#include <qwidget.h>

class MainWindow: public QMainWindow{
  
Q_OBJECT
private:
    MidiController* midiController;
QPushButton* _btn_note_identification;
QPushButton* _btn_exit;
NoteIdentification* exercise;

public:
MainWindow();
private slots:
void exercise_note_identification();


};

#endif