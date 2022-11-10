
#include <iostream>
#include <cstdlib>
#include <qapplication.h>
#include <signal.h>
#include "rtmidi/RtMidi.h"
#include<unistd.h>  
#include <QApplication>
#include "mainWindow.h"
int main(int argc ,char* argv[])
{
  QApplication app(argc,argv);


MainWindow* mw = new MainWindow();
mw->show();
  return app.exec();
}