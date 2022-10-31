
//! [main program]
#include <QtWidgets>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QWidget window;
    window.setFixedSize(1000, 500);
    
    

//! [create, position and show]
    QPushButton *button = new QPushButton("Note indentification", &window);
    button->setGeometry(10, 10, 300, 80);

     QPushButton *button2 = new QPushButton("Chord indentification", &window);
    button2->setGeometry(10, 100, 300, 80);
    window.show();


//! [create, position and show]
    return app.exec();
}
//! [main program]