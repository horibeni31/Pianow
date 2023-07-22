#ifndef NOTE_IDENTIFICATION_H
#define NOTE_IDENTIFICATION_H
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
class NoteIdentification :  public QDialog {
private:
  QPushButton *button;
 Ui::NoteIdentification* _ui;
public:
  NoteIdentification(QWidget* parent = nullptr);
  ~NoteIdentification();
  //oid HandleMidiMessage(MidiMessage m) override;
  //Note GenerateRandomNote();
};

#endif