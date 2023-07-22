
#include "src/mainwindow.h"
#include "midimessage.h"
#include <QApplication>
#include <iostream>
Q_DECLARE_METATYPE(MidiMessage);
int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
qRegisterMetaType<MidiMessage>();

  MainWindow mainWindow;
  mainWindow.show();
  return app.exec();
}
