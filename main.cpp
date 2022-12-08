
#include <iostream>
#include <cstdlib>
#include <qapplication.h>
#include <signal.h>
#include "rtmidi/RtMidi.h"
#include<unistd.h>  
#include <QApplication>
#include "exercises/noteIdentification.h"
#include "widgets/mainWindow.h"
int main(int argc ,char* argv[])
{
  QApplication app(argc,argv);


MainWindow* mw = new MainWindow();
mw->show();
  return app.exec();
}
