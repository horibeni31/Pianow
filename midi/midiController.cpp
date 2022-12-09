#include "midiController.h"
#include "exercises/exercise.h"
#include "exercises/noteIdentification.h"
#include "midi/midiMessage.h"
#include "midi/note.h"
#include <iostream>
#include <queue>
#include <rtmidi/RtMidi.h>

RtMidiIn *MidiController::rtmidiin;
std::queue<MidiMessage> MidiController::messages;
std::string MidiController::lookup;

Exercise *MidiController::currExercise;
void MidiController::Init() {
  rtmidiin = new RtMidiIn();
  messages = std::queue<MidiMessage>();
  lookup = "aAbcCdDefFgG";
  currExercise = nullptr;
}

void MidiController::Connect(int port) {
  rtmidiin->openPort(port);
  rtmidiin->ignoreTypes(false, true, true);
  rtmidiin->setCallback(&midi_event_handler);
}
void MidiController::midi_event_handler(double deltatime,
                                        std::vector<unsigned char> *message,
                                        void *userData) {
  unsigned int nBytes = message->size();
  if ((int)message->at(0) == 144) { // key event
    int key = message->at(1) ;

    bool pressed = message->at(2) != 0;
    if (currExercise) {

      currExercise->HandleMidiMessage(
          MidiMessage(Note::getNote(key), pressed));
    
    }
  }
 
}

bool MidiController::getMessage(MidiMessage &message) {
  if (messages.size() > 0) {
    message = messages.front();

    messages.pop();
    return true;
  } else {
    return false;
  }
}