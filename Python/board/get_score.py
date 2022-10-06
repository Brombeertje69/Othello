# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 14:18:39 2022

@author: Swen
"""

from common.names import BLACK, WHITE
from collections import Counter

#@jit
def get_score(board):
     freq = Counter(board)
     return freq[BLACK] - freq[WHITE]
