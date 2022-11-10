#include "noteIdentification.h" 
#include <qcolor.h>
#include <qdialog.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qwindowdefs.h>
#include <QPainter>
#include <QImage>
#include <QPaintEvent>
NoteIdentification::NoteIdentification(){
    this->button = new QPushButton("Hello there");
  //  this->setCentralWidget(image);
  
    QPainter painter(&image);
    painter.setPen(QPen(QColor(0,0,0),1,Qt::SolidLine, Qt::RoundCap,Qt::RoundJoin));
    painter.drawLine(QPoint(0,0),QPoint(100,100));
    update();


    
}
 void NoteIdentification::paintEvent(QPaintEvent* event){
 QPainter painter(this);
    QRect dirtyRect = event->rect();
    for (int i = 0; i<4; i++) {
    painter.drawLine(10,10+i*10,700,10+i*10);

    }

 }