import pygame
lookup = ["C","D","E","F","G","A","B"]
startx = 50
starty = 50
length = 500
gap = 12
class Staff:
    def __init__(self,surf):
        self._display_surf = surf
        self.pressedNotes = []
        self.staffNotes = []
        font = pygame.font.SysFont('Arial', 20,bold=True)
    
        self.flat = font.render('♭', True, (0, 0, 0))
        self.sharp = font.render('♯', True, (0, 0, 0))
    def writeNote(self,note):
        self.staffNotes.append(note)
    def RemNote(self, note):
        i = 0
        for a in self.staffNotes:
            if a.pitch ==note.pitch and a.octave == note.octave and a.press:
                break
            i = i+1
        self.staffNotes.pop(i)
    def keyDown(self, note):
        self.pressedNotes.append(note)
        pass
    def keyUp(self,note):
        i = 0
        for a in self.pressedNotes:
            if a.pitch ==note.pitch and a.octave == note.octave and a.press:
                break
            i = i+1
        self.pressedNotes.pop(i)
        
    def draw(self, type="GRANDSTAFF"):
        self.draw_grandStaff()
    
        for n in self.staffNotes:
            self.drawNote(n)
        for n in self.pressedNotes:
            self.drawNote(n)
            

    def drawNote(self, n):
        c4_pos =starty+gap*4.5
        octave = int(n.octave)
        note = int(lookup.index(n.pitch[0]))
        notePos = c4_pos-(0.5*gap*note+(octave-5)*7*0.5*gap);
        if(len(n.pitch) ==2):
            if n.pitch[1] == '#':
                self._display_surf.blit(self.sharp,(90,notePos-gap/3))
            

        print(n)
        pygame.draw.ellipse(self._display_surf,n.color,(100,notePos,gap*1.2,gap))
        if(notePos == c4_pos):
            pygame.draw.line(self._display_surf,(0,0,0),(100-gap*0.5,notePos+gap*0.5),(100+gap*1.2+gap*0.5,notePos+gap*0.5))
        
    def draw_grandStaff(self):
       
    
        pygame.draw.line(self._display_surf,(0,0,0),(startx,starty),(startx,starty+gap*10))
        for i in range(5):
            pygame.draw.line(self._display_surf,(0,0,0),(startx,starty+gap*i),(length,50+gap*i))
        for i in range(5):
            pygame.draw.line(self._display_surf,(0,0,0),(startx,starty+6*gap+gap*i),(length,starty+6*gap+gap*i))
        myimage = pygame.image.load("treble.svg")
        x,y = myimage.get_size()
        myimage = pygame.transform.scale(myimage, (0.4*x, 0.4*y))
        imagerect = myimage.get_rect()
        imagerect = imagerect.move((50, 40))
      
        self._display_surf.blit(myimage, imagerect)