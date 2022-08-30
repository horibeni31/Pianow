from midi import Staff
from midi import Note
from midi import midiInput
import pygame  
class noteIdentification:
    
    def __init__(self,surf) :
        self.noteToHit = Note.Note("A",4,(0,0,0),False)
        self.midiinp = midiInput.MidiKeboard()
        self.midiinp.connect()    
        self._display_surf = surf
        self.staff = Staff.Staff(surf)
        self.staff.writeNote(self.noteToHit)
    def update(self):
        data= self.midiinp.getEvent()
        (event,pitch,octave,speed) = data
           
        if (event == "KEY_DOWN"):
            self.staff.keyDown(Note.Note(pitch,octave,(0,255,0) if pitch == self.noteToHit.pitch and octave == self.noteToHit.octave else (0,0,0),True))
            pass
        if(event == "KEY_UP"):
            self.staff.keyUp(Note.Note(pitch,octave,(0,0,0),True))
            pass
    def render(self):
        
        self._display_surf.fill((255,255,255))
       
        self.staff.draw()

        pass
    def GenerateNote(self):
        pass