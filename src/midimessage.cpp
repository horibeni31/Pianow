#include "src/midimessage.h"
MidiMessage::MidiMessage(Note n, bool pressed)
{
    this->note = n;

    this->pressed = pressed;
}

MidiMessage::MidiMessage()
{
}