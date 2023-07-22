#include "mainwindow.h"
#include "midicontroller.h"
#include "ui_mainwindow.h"

#include "src/settingsdialog.h"
#include "src/noteidentification.h"
#include <cstdlib>
MainWindow::MainWindow(QWidget* parent):_ui(new Ui::MainWindow()) {
  _ui->setupUi(this);

//   this->exercise = nullptr;
//   this->settings = new Settings();

//   MidiController::GetInstance()->Connect(0);
//   create_menu();
//   setCentralWidget(groupBox);
// }
// void MainWindow::create_menu() {
//   this->groupBox = new QGroupBox(this);

//   QPushButton *_btn_exit = new QPushButton("exit", this);

//   QPushButton *_btn_note_identification =
//       new QPushButton("Note Identification", this);
//   QPushButton *_btn_chord_identification =
//       new QPushButton("Chord Identification", this);
//   QPushButton *_btn_settings = new QPushButton("Settings", this);
//   QPushButton *_btn_keySigniture_identification =
//       new QPushButton("Key signiture Identification", this);

//   _btn_chord_identification->setEnabled(false);
//   _btn_keySigniture_identification->setEnabled(false);

//   QVBoxLayout *layout = new QVBoxLayout();
//   layout->addWidget(_btn_note_identification);
//   layout->addWidget(_btn_chord_identification);
//   layout->addWidget(_btn_keySigniture_identification);
//   layout->addWidget(_btn_settings);
//   layout->addWidget(_btn_exit);
//   groupBox->setLayout(layout);
//   groupBox->setContentsMargins(100, 100, 100, 100);

//   connect(_btn_exit, SIGNAL(clicked()), QApplication::instance(), SLOT(quit()));
//   connect(_btn_note_identification, SIGNAL(clicked()), this,
//           SLOT(show_exercise_note_identification()));
//   connect(_btn_settings, SIGNAL(clicked()), this, SLOT(show_settings()));
//   ;

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
// void MainWindow::show_exercise_note_identification() {

//   NoteIdentification n;

//   n.exec();
// }
// void MainWindow::show_settings() { this->settings->show(); }