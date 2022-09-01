import pygame
from exercises import noteIdentification
from UI import Button
import midi.midiInput
import events
class mainMenu:
    def __init__(self):
        pygame.init()
        pygame.midi.init()
        pygame.font.init() 
        self.running = True
        self.size = self.weight, self.height = 1920, 1080
        self.currentExercise = None
        self.midiInp = midi.midiInput.MidiKeboard()
        self.midiInp.connect()
        self.surf = pygame.display.set_mode(self.size,pygame.RESIZABLE)
        self.exitbtn = Button.Button(self.surf,"exit","exit",(50,50),(200,50))
        self.startNI = Button.Button(self.surf,"NoteIdentification","startNI",(50,150),(200,50))
    def handle_event(self, event: pygame.event.Event):
        if event.type == pygame.QUIT:
              self.running = False
        if event.type == events.BUTTON_CLICKED:
            if event.name == "exit":
                self.running = False
            if event.name == "startNI":
                self.currentExercise = noteIdentification.noteIdentification(self.surf)
            if event.name == "backToMain":
                self.currentExercise.cleanUp()
                self.currentExercise = None
        if event.type == events.MIDI_EVENT:
            if self.currentExercise:
               self.currentExercise.handle_midiEvent(event)
            pass
    def update(self):
        self.midiInp.update()
        if(self.currentExercise == None):
            self.exitbtn.update()
            self.startNI.update()
        else:
            self.currentExercise.update()
   
    def render(self):
        self.surf.fill((255,255,255))
        if(self.currentExercise == None):
             self.exitbtn.render()
             self.startNI.render()
        else:
            self.currentExercise.render()
        
        pygame.display.update()
    def cleanup(self):
        pygame.quit()
    def start(self): 
        while( self.running ):
            for event in pygame.event.get():
                self.handle_event(event)
            self.update()
            self.render()
        self.cleanup()
        


