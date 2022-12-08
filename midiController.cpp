#include "midiController.h"
#include <rtmidi/RtMidi.h>

MidiController* MidiController::_instance;

MidiController* MidiController::getInstance(){

  if(MidiController::_instance == nullptr){
    _instance = new MidiController();
  }
  return MidiController::_instance;
}


 MidiController::MidiController(){
this->rtmidiin = new  RtMidiIn();
}

void MidiController::Connect(int port, void (*callback)()){
  rtmidiin->openPort(port);
  rtmidiin->setCallback(&(MidiController::midi_event_handler));
rtmidiin->ignoreTypes( false, true, true );





}
 void MidiController:: midi_event_handler( double deltatime, std::vector< unsigned char > *message, void *userData ) {
  unsigned int nBytes = message->size();
  for ( unsigned int i=0; i<nBytes; i++ )
    std::cout << "Byte " << i << " = " << (int)message->at(i) << ", ";
  if ( nBytes > 0 )
    std::cout << "stamp = " << deltatime << std::endl;
  _instance->callback();
}


