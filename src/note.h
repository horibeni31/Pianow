#ifndef NOTE_H
#define NOTE_H
enum Accidental{
    FLAT,
    SHARP,
    NORMAL
};
enum Pitch{

    C,D,E,F,G,A,B
};
struct Note{
 Pitch pitch;
 int octave;
 Accidental accidental;
 Note(Pitch p, int o,Accidental accidental);
 Note(){};
 bool operator==(const Note& other);
 static Note getNote(int i);
 static Note getRandom();
};


#endif