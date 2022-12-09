#ifndef NOTE_IDENTIFICATION_H
#define NOTE_IDENTIFICATION_H
#include "exercises/exercise.h"
#include "midi/midiController.h"
#include "midi/midiMessage.h"
#include "midi/note.h"
#include "widgets/staff.h"
#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <qdialog.h>
#include <qimage.h>
#include <qwidget.h>
#include <vector>

class NoteIdentification : public QMainWindow, public Exercise {

  Q_OBJECT
private:
  QPushButton *button;
  Staff* staff;

public:
  NoteIdentification();
  void HandleMidiMessage(MidiMessage m) override;
};

#endif