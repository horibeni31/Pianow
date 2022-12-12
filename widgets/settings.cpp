#include "settings.h"
#include "midi/midiController.h"
#include <iostream>
#include <qboxlayout.h>
#include <qcombobox.h>
#include <qdialog.h>
#include <vector>

Settings::Settings() : QDialog() {
  resize(500, 500);
  this->layout = new QVBoxLayout;
  this->layout->setContentsMargins(100,100,100,100);

  this->cmb_midi_devices = new QComboBox(this);
  


  this->layout->addWidget(this->cmb_midi_devices);
  this->setLayout(this->layout);
  std::vector<std::string> devices =
      MidiController::GetInstance()->getDevices();
  for (int i = 0; i < devices.size(); i++) {

    cmb_midi_devices->addItem(devices[i].c_str());
  }

     connect(cmb_midi_devices, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged), this, &Settings::device_selection_changed);
  //  connect(cmb_midi_devices, &QComboBox::textActivated,
  //           this, &Settings::device_selection_changed);
}

void Settings::device_selection_changed(int index){
  // std::cout << "changed"<<index << std::endl;
  MidiController::GetInstance()->Connect(index);
}