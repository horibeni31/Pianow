#ifndef STAFF_H
#define STAFF_H

#include "midi/note.h"
#include <qimage.h>
#include <qobjectdefs.h>
#include <qwidget.h>
class Staff : public QWidget {
  Q_OBJECT
public:
  Staff(QWidget *parent = nullptr);

  void AddNote(Note n );
  void RemoveNote(Note n );
protected:
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

private:
  std::vector<Note> pressedNotes;

  QImage image;

};
#endif