#ifndef EXERCISE_H
#define EXERCISE_H

#include "midi/midiMessage.h"
#include "widgets/staff.h"
class  Exercise{
    protected:
      Staff* staff;
    public:
        Exercise();
        virtual void HandleMidiMessage(MidiMessage m) = 0;
        ~Exercise();


};

#endif