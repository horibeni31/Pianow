#ifndef SETTIGNS_H
#define SETTIGNS_H
#include <string>
class Settings
{
public:
    static Settings* getInstance();
private:
    Settings();
    static Settings* _instance;


public:
    const std::string& midiDevice() const;
    void setMidiDevice(const std::string & device);

private:
    std::string _midiDevice;


};

#endif