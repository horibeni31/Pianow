#ifndef MIDI_INPUT_H
#define MIDI_INPUT_H

#include "exercises/exercise.h"
#include "midi/midiMessage.h"
#include "midi/note.h"
#include <cstdlib>
#include <iostream>
#include <rtmidi/RtMidi.h>
#include <queue>
class MidiController {

public:
  static void Connect(int port);
  static void Init();
  static bool getMessage(MidiMessage& message);
  static Exercise* currExercise;

private:
  static std::queue<MidiMessage> messages;
  static RtMidiIn *rtmidiin;
  static std::string lookup;
  static void midi_event_handler(double deltatime,
                                 std::vector<unsigned char> *message,
                                 void *userData);
};
#endif