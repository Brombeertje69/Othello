# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 17:08:17 2022

@author: Swen
"""

from common.names import BLACK, WHITE

def opponent(player):
    return BLACK if player == WHITE else WHITE


### TEST AND COMPILE:
opponent(BLACK) == WHITE
opponent(WHITE) == BLACK

#%time for _ in range(1000000): opponent(BLACK)


chr(BLACK)

int(BLACK)
