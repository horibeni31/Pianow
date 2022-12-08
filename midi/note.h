#ifndef NOTE_H
#define NOTE_H

struct Note{
 char pitch;
 int octave;
 Note(char p, int o);
 Note(){};
 bool operator==(const Note& other);
};


#endif