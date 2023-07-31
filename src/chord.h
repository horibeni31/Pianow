#ifndef CHORD_H
#define CHORD_H

#include "src/note.h"
#include <vector>
class Chord
{
    public:
        Note root();

    private:
    std::vector<Note> _notes;
    

};


#endif