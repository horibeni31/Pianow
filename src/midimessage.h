#ifndef MIDI_MESSAGE_H
#define MIDI_MESSAGE_H

#include "src/note.h"
#include <cstddef>
struct  MidiMessage{
    Note note;
    bool pressed;
    int speed;
    MidiMessage(Note n, bool pressed);
    MidiMessage();
};



#endif