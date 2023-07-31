#ifndef NOTE_IDENTIFICATION_H
#define NOTE_IDENTIFICATION_H
#include "midimessage.h"
#include "note.h"
#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <cstddef>
#include <qdialog.h>
#include <qimage.h>
#include <qwidget.h>
#include <vector>
namespace Ui {
class NoteIdentification;
}
class NoteIdentification : public QDialog {

private:
  Ui::NoteIdentification *_ui;
  Note _goal;
  int error = 0;
  int success = 0;

public:
  NoteIdentification(QWidget *parent = nullptr);
  ~NoteIdentification();

private slots:
  void onMidiEvent(const MidiMessage &message);
};

#endif