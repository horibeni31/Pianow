
#include <QApplication>
#include <cstddef>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "midimessage.h"
#include "src/mainwindow.h"
#include "userdata.h"
Q_DECLARE_METATYPE(MidiMessage);
int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("pianow");
    app.setOrganizationName("pianow");
    qRegisterMetaType<MidiMessage>();
    srand(time(NULL));
    MainWindow mainWindow;
    mainWindow.show();
    UserData::instance();
    return app.exec();
}
