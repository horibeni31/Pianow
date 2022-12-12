#ifndef STAFF_H
#define STAFF_H

#include "midi/note.h"
#include <qimage.h>
#include <qobjectdefs.h>
#include <qpainter.h>
#include <qwidget.h>
#include <vector>
class Staff : public QWidget {
  Q_OBJECT
public:
  Staff(QWidget *parent = nullptr);

  void AddNote(Note n, bool fixed = false);
  void RemoveNote(Note n, bool fixed = false);

protected:
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;
  void drawNote(Note n, QPainter &painter);

private:
  int startx;
  int starty;
  int gap;
  int middleCpos;
  int width;
  QImage treble;
  QImage bass;
  std::vector<Note> pressedNotes;
  std::vector<Note> fixNotes;

  QImage image;
};
#endif