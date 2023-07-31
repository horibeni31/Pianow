#ifndef STAFF_H
#define STAFF_H
#include "src/midimessage.h"
#include <qnamespace.h>
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
  void drawNote(Note n, QPainter &painter,Qt::GlobalColor color = Qt::black);
private slots:
  void onMidiEvent(const MidiMessage &message);

private:
  int _gap;
  int _staffHeight;

  QImage treble;
  QImage bass;
  std::vector<Note> pressedNotes;
  std::vector<Note> fixNotes;

  QImage image;
  Ui::StaffWidget *_ui;
};
#endif