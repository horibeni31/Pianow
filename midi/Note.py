class Note:
    def __init__(self, note, octave, color =(0,0,0), press = True):
        self.note = note
        self.octave = octave
        self.color = color
        self.press = press
        
    def __eq__(self, other):
        if isinstance(other, Note):
            return self.note == other.note  and self.octave == other.octave
        return False


    