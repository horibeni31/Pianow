#include "note.h"
#
Note::Note(char p, int o){
this->octave = o;
this->pitch = p;
}
bool Note::operator==(const Note& other){
return this->octave == other.octave && this->pitch == other.pitch;
}