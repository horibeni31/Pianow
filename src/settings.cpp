#include "src/settings.h"
#include <new>
Settings* Settings::_instance;
Settings::Settings()
{

}
Settings* Settings::getInstance()
{

    if(!_instance)
        _instance = new Settings();
    return _instance;
    
}
void Settings::setMidiDevice(const std::string& midiDevice)
{

    _midiDevice = midiDevice;
}
const std::string& Settings::midiDevice() const
{
    return _midiDevice;
}