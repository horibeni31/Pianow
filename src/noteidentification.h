#ifndef NOTE_IDENTIFICATION_H
#define NOTE_IDENTIFICATION_H
#include <qdialog.h>
#include <qimage.h>
#include <qwidget.h>

#include <QDialog>
#include <QMainWindow>
#include <QObject>
#include <QPushButton>
#include <cstddef>
#include <vector>

#include "midimessage.h"
#include "note.h"
namespace Ui
{
class NoteIdentification;
}
class NoteIdentification : public QDialog
{
  private:
    Ui::NoteIdentification* _ui;
    std::vector<Note> _goals;
    std::vector<std::pair<int, int>> _tries;
    int time;
    int _currentTime;
    int _currentGoalIndex = 0;
  public:
    NoteIdentification(QWidget* parent = nullptr);
    ~NoteIdentification();

  private slots:
    void onMidiEvent(const MidiMessage& message);
};

#endif