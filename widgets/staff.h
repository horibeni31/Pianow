#ifndef STAFF_H
#define STAFF_H

#include <qimage.h>
#include <qobjectdefs.h>
#include <qwidget.h>
class Staff : public QWidget {
  Q_OBJECT
public:
  Staff(QWidget *parent = nullptr);
  void drawLine(int x);
  void drawStaff();

protected:
  void paintEvent(QPaintEvent *event) override;
  void resizeEvent(QResizeEvent *event) override;

private:
  QImage image;

};
#endif