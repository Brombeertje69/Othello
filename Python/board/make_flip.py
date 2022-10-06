# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 19:34:15 2022

@author: Swen
"""

def make_flip(board, move, player, direction, bracket):
    """
        Flip pieces in the given direction as a result of the move by player
    """
    # found a bracket in this direction
    square = move + direction                       #Alternatieve naam voor Square bedenken
    while square != bracket:
        board[square] = player
        square += direction
    return board
