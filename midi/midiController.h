#ifndef MIDI_INPUT_H
#define MIDI_INPUT_H

#include "exercises/exercise.h"
#include "midi/midiMessage.h"
#include "midi/note.h"
#include <cstdlib>
#include <iostream>
#include <queue>
#include <rtmidi/RtMidi.h>
#include <vector>
class MidiController {

public:
  void Connect(int port);

  static Exercise *currExercise;
  static MidiController *GetInstance();
  std::vector<std::string> getDevices();

private:
  MidiController();
  static MidiController *_instance;
  std::queue<MidiMessage> messages;
  RtMidiIn *rtmidiin;
  std::string lookup;
  static void midi_event_handler(double deltatime,
                                 std::vector<unsigned char> *message,
                                 void *userData);
};
#endif