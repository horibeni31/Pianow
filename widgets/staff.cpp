#include "staff.h"
#include <iostream>
#include <qevent.h>
#include <qnamespace.h>
#include <qpainter.h>
#include <qsize.h>
#include <qwidget.h>
#include <qwindowdefs.h>
Staff::Staff(QWidget *parent) : QWidget(parent) {
  setAttribute(Qt::WA_StaticContents);

  QImage newImage(QSize(width(), height()), QImage::Format_RGB32);
  newImage.fill(qRgb(255, 0, 0));
  image = newImage;
  drawLine(5);
}

void Staff::paintEvent(QPaintEvent *event) {

  QPainter painter(this);
  QRect dirtyRect = event->rect();
  painter.drawImage(dirtyRect, image, dirtyRect);
}
void Staff::drawLine(int x) {
  QPainter painter(&image);
  painter.drawLine(10, 10, 100, 100 + x);
  update();
}
void Staff::resizeEvent(QResizeEvent *event) {
  QImage newImage(QSize(width(), height()), QImage::Format_RGB32);
  newImage.fill(qRgb(255, 255, 255));

  image = newImage;
  QWidget::resizeEvent(event);
  drawStaff();
}

void Staff::drawStaff() {
  QPainter painter(&image);
  for (int i = 0; i < 5; i++) {
    painter.drawLine(10, 10 + 10 * i, 300, 10 + 10 * i);
  }
  update();
}