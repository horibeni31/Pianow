#ifndef MIDI_INPUT_H
#define MIDI_INPUT_H

#include <iostream>
#include <cstdlib>
#include  <rtmidi/RtMidi.h>
class MidiController{
    
  
     public:
     static MidiController* getInstance();
     ~MidiController();
     private:
     void Connect(int port,void (*callback)());
     MidiController();
     static MidiController* _instance;
     RtMidiIn* rtmidiin;
     void (*callback)();
   static  void midi_event_handler( double deltatime, std::vector< unsigned char > *message, void *userData );




};
#endif