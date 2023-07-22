#ifndef EXERCISE_H
#define EXERCISE_H

#include "midi/midiMessage.h"
#include "widgets/staff.h"

#include <QDialog>
class  Exercise : public QDialog{
  Q_OBJECT
    protected:
      Staff* staff;
    public:
        Exercise();
        virtual void HandleMidiMessage(MidiMessage m) = 0;
        ~Exercise();


};

#endif