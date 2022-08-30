
from pickle import NONE
import sys
import os

import pygame as pg
import pygame.midi
from exercises import noteIdentification
# print_device_info()
# input_main(device_id=3)

def input_main(device_id=None):
    pg.init()
    pg.fastevent.init()
    event_get = pg.fastevent.get
    event_post = pg.fastevent.post

    pygame.midi.init()


    if device_id is None:
        input_id = pygame.midi.get_default_input_id()
    else:
        input_id = device_id

    print("using input_id :%s:" % input_id)
    i = pygame.midi.Input(input_id)

    pg.display.set_mode((1, 1))

    going = True
    while going:

        if i.poll():    
            midi_events = i.read(1)[0]
            
          

    
            (data,timestamp) = midi_events
            if not data[0] == 248:
                print(data)    
    del i
    pygame.midi.quit()

class App:
    def __init__(self):
        self._running = True
        self._display_surf = None
        self.size = self.weight, self.height = 1920, 1080
 
    def on_init(self):
        pygame.init()
        pygame.font.init() 
        print (pygame.display.list_modes())
        self._display_surf = pygame.display.set_mode(self.size,pygame.RESIZABLE)
        self.currentExercise = noteIdentification.noteIdentification(self._display_surf)
        self._running = True
 
    def on_event(self, event):
        if event.type == pygame.QUIT:
            self._running = False
    def on_loop(self):
        self.currentExercise.update()
        pass    
   
            
        
        
    def on_render(self):

        if(self.currentExercise == None):    
            pass
        else: 
            self.currentExercise.render()
        pygame.display.update()
    def on_cleanup(self):
        pygame.quit()
 
    def on_execute(self):
        if self.on_init() == False:
            self._running = False
 
        while( self._running ):
            
            for event in pygame.event.get():
                self.on_event(event)
            self.on_loop()
            self.on_render()
        self.on_cleanup()
 
if __name__ == "__main__" :
    app = App()
    app.on_execute()

# print_device_info()

