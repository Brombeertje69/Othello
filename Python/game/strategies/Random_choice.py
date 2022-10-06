# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 17:38:55 2022

@author: Swen
"""

import random

from board import legal_moves

def Random_choice(board, player):
    """
        Returns a random choice from the legal options
    """
    moves = legal_moves(board, player)
    move = random.choice(moves) if moves else None
    return move
