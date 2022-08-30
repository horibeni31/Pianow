from collections import namedtuple


from typing import NamedTuple
class Note(NamedTuple):
    pitch:str
    octave:int
    color:tuple
    press:bool

    