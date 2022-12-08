#include "noteIdentification.h" 
#include <qcolor.h>
#include <qdialog.h>
#include <qnamespace.h>
#include <qpen.h>
#include <qpoint.h>
#include <qwindowdefs.h>
#include <QPainter>
#include <QImage>
#include <iostream>
#include "midiController.h"
#include <QPaintEvent>
float a = 0;
NoteIdentification::NoteIdentification(){
    this->button = new QPushButton("Hello there");
  //  this->setCentralWidget(image);
  
   update();
    
}
 void NoteIdentification::paintEvent(QPaintEvent* event){
 QPainter painter(this);
   static int a = 4;
    for (int i = 0; i<a; i++) {
    painter.drawLine(10,10+i*10,700,10+i*10);

    }
    a++;

 }