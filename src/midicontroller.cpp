#include "src/midicontroller.h"
#include "src/midimessage.h"
#include <algorithm>
#include <iostream>
#include <qpushbutton.h>
#include <queue>
#include <rtmidi/RtMidi.h>
#include <sys/types.h>
#include <vector>

MidiController *MidiController::_instance;

MidiController *MidiController::GetInstance() {

  if (_instance == nullptr) {
    _instance = new MidiController();
  }
  return _instance;
}

MidiController::MidiController() {
  rtmidiin = new RtMidiIn();
  messages = std::queue<MidiMessage>();
  lookup = "aAbcCdDefFgG";
  rtmidiin->setCallback(&midi_event_handler);
  rtmidiin->ignoreTypes(false, true, true);
}

void MidiController::Connect(int port) {
  if (rtmidiin->isPortOpen()) {
    rtmidiin->closePort();
  }
  if (rtmidiin->getPortCount() > port) {

    rtmidiin->openPort(port);
  } else {
    std::cout << "No midi device found." << std::endl;
  }
}
void MidiController::onMidiEvent(const MidiMessage& message)
{
  emit midiEvent(message);
  std::cout<<message.note.getStr().toStdString()<<std::endl;
}
void MidiController::midi_event_handler(double deltatime,
                                        std::vector<unsigned char> *message,
                                        void *userData) {
  unsigned int nBytes = message->size();
  if ((int)message->at(0) == 144) { // key event
    int key = message->at(1);

    bool pressed = message->at(2) != 0;
    MidiController::GetInstance()->onMidiEvent(MidiMessage(Note::getNote(key), pressed));
  }

}

std::vector<std::string> MidiController::getDevices() {

  std::vector<std::string> ret;
  for (int i = 0; i < rtmidiin->getPortCount(); i++) {

    ret.push_back(rtmidiin->getPortName(i));
  }
  return ret;
}
