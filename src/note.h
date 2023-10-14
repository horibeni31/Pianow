#ifndef NOTE_H
#define NOTE_H

#include <QString>
#include <nlohmann/json.hpp>

enum Accidental
{
    FLAT,
    SHARP,
    NORMAL
};
enum Pitch
{

    C,
    D,
    E,
    F,
    G,
    A,
    B
};
struct Note
{
    Pitch pitch;
    int octave;
    Accidental accidental;
    Note(Pitch p, int o, Accidental accidental);
    Note(){};

    QString getStr() const;
    bool operator==(const Note &other);
    static Note getNote(int i);
    static Note getRandom();
};
NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Note, pitch, octave, accidental);

#endif