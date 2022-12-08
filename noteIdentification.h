#ifndef NOTE_IDENTIFICATION_H
#define  NOTE_IDENTIFICATION_H
#include <QMainWindow>
#include <QDialog>

#include <QObject>
#include <QPushButton>
#include <qdialog.h>
#include <qimage.h>
#include <qwidget.h>


class NoteIdentification: public QMainWindow
{


    Q_OBJECT
private:

    QPushButton *button;
    QImage image;
public:
    NoteIdentification();
protected:

    void paintEvent(QPaintEvent* event);
private slots:
void asd(){};
};

#endif