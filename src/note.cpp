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
  note.pitch = (Pitch)(pitchLookup.find(std::toupper(p)));
  note.accidental =
      (int)(lookup[midiId % 12]) < 97 ? Accidental::SHARP : Accidental::NORMAL;
  return note;
}
Note Note::getRandom() {

  return Note((Pitch)(rand() % 7), 4, Accidental::NORMAL);
}
QString Note::getStr() const {
  QString ret;
  switch (pitch) {

  case Pitch::C:
    ret += "C";
    break;
  case Pitch::D:
    ret += "D";
    break;
  case Pitch::E:
    ret += "E";
    break;
  case Pitch::F:
    ret += "F";
    break;
  case Pitch::G:
    ret += "G";
    break;
  case Pitch::A:
    ret += "A";
    break;
  case Pitch::B:
    ret += "B";
    break;
  }
  switch (accidental) {
  case Accidental::FLAT:
    ret += "b";
    break;
  case Accidental::SHARP:
    ret += "#";
    break;
  case Accidental::NORMAL:
  default:
    break;
  }
  return ret + std::to_string(octave).c_str();
}