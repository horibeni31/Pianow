#ifndef EXERCISE_H
#define EXERCISE_H

#include "midi/midiMessage.h"
class  Exercise{
    protected:
     
    public:
        Exercise();
        virtual void HandleMidiMessage(MidiMessage m) = 0;
        ~Exercise();


};

#endif