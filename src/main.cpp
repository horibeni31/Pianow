
#include "src/mainwindow.h"
#include "midimessage.h"
#include <QApplication>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>
Q_DECLARE_METATYPE(MidiMessage);
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
qRegisterMetaType<MidiMessage>();
  srand(time(NULL));
  MainWindow mainWindow;
  mainWindow.show();
  return app.exec();
}
