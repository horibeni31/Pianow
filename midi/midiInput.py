import pygame as pg
import pygame.midi
lookup = ["C","C#","D","D#","E","F","F#","G","G#","A","A#","B",]


class MidiKeboard:

    def __init__(self):
        pass

    def connect(self):
        pygame.midi.init()
      


        self.i = pygame.midi.Input(3)  # todo id hardcoded
      

        pass
    def disconnect(self):
        pygame.midi.quit()
        del self.i
    def getEvent(self):
        if self.i.poll():
            midi_events = self.i.read(1)[0]
            (data, time) = midi_events
            (status, key, speed, data3) = data

            if data[0] == 248:
                return ("CLOCK", 0, 0,0)
            else:
                event = "KEY_UP" if speed == 0 else "KEY_DOWN"
                note = lookup[key % 12]
                octave = int(str(int(key/12)))
                return (event, note,octave, speed)
        return ("VOID", 0, 0,0)




