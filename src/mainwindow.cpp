#include "mainwindow.h"

#include <cstdlib>

#include "midicontroller.h"
#include "src/noteidentification.h"
#include "src/settingsdialog.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget* parent) : _ui(new Ui::MainWindow())
{
    _ui->setupUi(this);
    MidiController::GetInstance()->Connect(0);
}

void MainWindow::on_btnSettings_clicked()
{
    SettingsDialog sd(this);
    sd.exec();
}
void MainWindow::on_btnExit_clicked()
{
    exit(0);
}

void MainWindow::on_btnStart_clicked()
{
    NoteIdentification nd(this);
    nd.exec();
}
MainWindow::~MainWindow()
{
    delete _ui;
}
