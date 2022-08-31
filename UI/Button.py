from cmath import rect
from multiprocessing import Event
import pygame 
import events
class Button:
    def __init__(self,surf: pygame.Surface, text,name,pos,size):
        self.surface = surf 
        self.name = name
        self.pos= pos
        self.size= size
       
        self.col = (0,0,0)
        self.font = pygame.font.SysFont('Arial', 20,bold=True)
        self.text = self.font.render(text, True, (0,0,0))
        pass
    def mouseOver(self,mousePos):
        return self.pos[0]<mousePos[0]<self.pos[0]+self.size[0] and self.pos[1]<mousePos[1]<self.pos[1]+self.size[1]
    def update(self):
        mousePos =  pygame.mouse.get_pos()
        mousePressed = pygame.mouse.get_pressed(3)[0]
        if(mousePressed and self.mouseOver(mousePos)):
            self.col = (255,0,0)
            pygame.event.post(pygame.event.Event(events.BUTTON_CLICKED,name=self.name))
        else:
            self.col = (0,0,0)
        pass
    def render(self):
    

        pygame.draw.rect(self.surface, self.col,(self.pos[0], self.pos[1], self.size[0], self.size[1]),1)
        self.surface.blit(self.text,self.pos)
        pass
    