#ifndef MIDI_INPUT_H
#define MIDI_INPUT_H
#include "src/midimessage.h"
#include <cstdlib>
#include <iostream>
#include <qobject.h>
#include <qobjectdefs.h>
#include <QObject>
#include <queue>
#include <RtMidi.h>
#include <vector>
#include <queue>

class MidiController :public QObject {
  Q_OBJECT
public:
  void Connect(int port);

  //static Exercise *currExercise;
  static MidiController *GetInstance();
  std::vector<std::string> getDevices();
signals:
  void midiEvent(const MidiMessage& message);
private:
  MidiController();
  static MidiController *_instance;
  std::queue<MidiMessage> messages;
  RtMidiIn *rtmidiin;
  std::string lookup;
  void onMidiEvent(const MidiMessage& message);
  static void midi_event_handler(double deltatime,
                                 std::vector<unsigned char> *message,
                                 void *userData);
};
#endif