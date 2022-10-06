# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 19:34:40 2022

@author: Swen
"""
from numba import njit, objmode

from .opponent import opponent

def find_bracket(board, move, player, direction, value = None):
    """
          find and return the square that forms a bracket with square for player in the given
          direction; returns None if no such square exists.

          Value: Field that is searched for -> either player or empty
    """
    #with objmode(opp = 'int64'):
    opp = opponent(player)
    if value is None: value = player

    first_square = move + direction
    square = first_square
    while board[square] == opp:
        square += direction

    bracket = square if board[square] == value and square is not first_square else None
    return bracket
