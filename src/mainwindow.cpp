#include "mainwindow.h"
#include "midicontroller.h"
#include "ui_mainwindow.h"

#include "src/settingsdialog.h"
#include "src/noteidentification.h"
#include <cstdlib>
MainWindow::MainWindow(QWidget* parent):_ui(new Ui::MainWindow()) {
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
MainWindow::~MainWindow(){

  delete _ui;
}
