from midi import Staff
from midi import Note
from midi import midiInput
import pygame  
from UI import Button
class noteIdentification:
    
    def __init__(self,surf) :
        self.noteToHit = Note.Note("A",4,(0,0,0),False)
        self._display_surf = surf
        self.staff = Staff.Staff(surf)
        self.staff.writeNote(self.noteToHit)
        self.backBtn = Button.Button(surf,"back to main menu","backToMain",(50,500),(200,50))
    def cleanUp(self):
        pass
    def handle_midiEvent(self, event):
        note = event.note[:-1]
        octave = int(event.note[-1])
        if (event.action == "KEY_DOWN"):
            self.staff.keyDown(Note.Note(note,octave,((0,255,0) if note == self.noteToHit.pitch and octave == self.noteToHit.octave else (0,0,0)),True))
            pass
        if(event.action == "KEY_UP"):
            self.staff.keyUp(Note.Note(note,octave,(0,0,0),True))
            pass
    def update(self):
        self.backBtn.update()
    def render(self):
        self._display_surf.fill((255,255,255))
        self.backBtn.render()
        self.staff.draw()

        pass
    def GenerateNote(self):
        pass