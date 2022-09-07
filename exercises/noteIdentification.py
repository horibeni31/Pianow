from midi import Staff
from midi import Note
from midi import midiInput
import pygame  
import random
from UI import Button
lookup = ["C","C#","D","D#","E","F","F#","G","G#","A","A#","B",]
class noteIdentification:
    
    def __init__(self,surf) :
        self.noteToHit = self.GenerateNote()
        self._display_surf = surf
        self.staff = Staff.Staff(surf)
        self.staff.writeNote(Note.Note(self.noteToHit[0],self.noteToHit[1]))
        self.backBtn = Button.Button(surf,"back to main menu","backToMain",(50,500),(200,50))
        self.noteHit = False
        self.errors = 0
        self.notesPassed = 0
        self.font = pygame.font.SysFont('Arial', 20,bold=True)
        self.errorText = self.font.render("errors: "+str(self.errors), True, (0,0,0))
        self.passedText = self.font.render("passed notes: "+str(self.notesPassed), True, (0,0,0))
    def cleanUp(self):
        pass
    def handle_midiEvent(self, event):
        note,octave = event.key

        if (event.action == "KEY_DOWN"):
            if(self.noteToHit ==(note,octave)):
                self.noteHit = True
                color = (0,255,0)
                
            else:
                self.errors+=1
                color = (255,0,0)
            self.staff.keyDown(Note.Note(note,octave,color,True))
            pass
        if(event.action == "KEY_UP"):
            self.staff.keyUp(Note.Note(note,octave,(0,0,0),True))
            pass
    def update(self):
        self.backBtn.update()
        self.errorText = self.font.render("errors: "+str(self.errors), True, (0,0,0))
        self.passedText = self.font.render("passed notes: "+str(self.notesPassed), True, (0,0,0))
        if(self.noteHit):
            self.noteHit = False
            self.notesPassed +=1
            self.staff.RemNote(Note.Note(self.noteToHit[0],self.noteToHit[1]))

            self.noteToHit = self.GenerateNote()
            self.staff.writeNote(Note.Note(self.noteToHit[0],self.noteToHit[1]))

    def render(self):
        self._display_surf.fill((255,255,255))
        self.backBtn.render()
        self.staff.draw()
        self._display_surf.blit(self.errorText,(0,700))
        self._display_surf.blit(self.passedText,(0,800))


        pass
    def GenerateNote(self):
        return (random.choice(lookup),5) 