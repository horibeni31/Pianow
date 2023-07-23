#include "note.h"
#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>
Note::Note(Pitch p, int o, Accidental accidental = Accidental::NORMAL) {
  this->octave = o;
  this->pitch = p;
  this->accidental = accidental;
}
bool Note::operator==(const Note &other) {
  return this->octave == other.octave && this->pitch == other.pitch &&
         this->accidental == other.accidental;
}
Note Note::getNote(int midiId) {

  Note note;
  note.octave = midiId / 12 - 1;
  std::string lookup = "cCdDefFgGaAb";
  std::string pitchLookup = "CDEFGAB";
  char p = lookup[midiId % 12];
  std::cout << p << std::endl;
  note.pitch = (Pitch)(pitchLookup.find(std::toupper(p)));
  note.accidental =
      (int)(lookup[midiId % 12]) < 97 ? Accidental::SHARP : Accidental::NORMAL;
  return note;
}
Note Note::getRandom(){

  return Note((Pitch)(rand()%7),4,Accidental::NORMAL); 

}