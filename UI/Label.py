import pygame 
import events
font = pygame.font.SysFont('Arial', 20,bold=True)
class Button:
    def __init__(self,surf: pygame.Surface, text,pos,size):
        self.surface = surf 
       
        self.pos= pos
        self.size= size  
        self.col = (0,0,0)
        self.renderedText = font.render(text, True, (0,0,0))
        pass
    def mouseOver(self,mousePos):
        return self.pos[0]<mousePos[0]<self.pos[0]+self.size[0] and self.pos[1]<mousePos[1]<self.pos[1]+self.size[1]
    def update(self,txt):X
        self.renderedText = self.font.render(txt, True, (0,0,0))

    def render(self):
    

        self.surface.blit(self.renderedText,self.pos)
        pass
    