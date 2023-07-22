#ifndef STAFF_H
#define STAFF_H
#include "src/midimessage.h"
namespace Ui {
class StaffWidget;
}
#include <QWidget>
#include <qimage.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <vector>
class StaffWidget : public QWidget {
  Q_OBJECT
public:
  StaffWidget(QWidget *parent = nullptr);
  ~StaffWidget();

  void AddNote(Note n, bool fixed = false);
  void RemoveNote(Note n, bool fixed = false);

protected:
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;
  void drawNote(Note n, QPainter &painter);
private slots:
  void onMidiEvent(const MidiMessage &message);

private:
  int startx;
  int starty;
  int gap;
  int middleCpos;
  int width;
  // QImage treble;
  // QImage bass;
  std::vector<Note> pressedNotes;
  std::vector<Note> fixNotes;

  QImage image;
  Ui::StaffWidget *_ui;
};
#endif