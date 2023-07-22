#include "src/settingsdialog.h"
#include "ui_settingsdialog.h"
// #include "midi/midiController.h"
#include <iostream>

#include <vector>

SettingsDialog::SettingsDialog(QWidget* parent) : QDialog(parent),_ui(new Ui::SettingsDialog()) {
  _ui->setupUi(this);
  


  // this->layout->addWidget(this->cmb_midi_devices);
  // this->setLayout(this->layout);
  // std::vector<std::string> devices =
  //     MidiController::GetInstance()->getDevices();
  // for (int i = 0; i < devices.size(); i++) {

  //   cmb_midi_devices->addItem(devices[i].c_str());
  // }

  //    connect(cmb_midi_devices, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Settings::device_selection_changed);
  // //  connect(cmb_midi_devices, &QComboBox::textActivated,
  // //           this, &Settings::device_selection_changed);
}
 SettingsDialog:: ~SettingsDialog(){
  delete _ui;
 }

void SettingsDialog::device_selection_changed(int index){
  // std::cout << "changed"<<index << std::endl;
  //MidiController::GetInstance()->Connect(index);
}