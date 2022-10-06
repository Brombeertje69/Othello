# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 19:32:43 2022

@author: Swen
"""
from common.names import DIRECTIONS

from .find_bracket import find_bracket
from .make_flip import make_flip
from .board_to_string import board_to_string

import time

def make_move(board, move, player, show_moves = False):
    """
        Place a brick on the 'move' square for player
    """
    board[move] = player

    # When the player makes a valid move, we need to update the board and flip all the
    # bracketed pieces. Look for a bracket in any direction
    for direction in DIRECTIONS:
        bracket = find_bracket(board, move, player, direction)
        if bracket:
            make_flip(board, move, player, direction, bracket)

    if show_moves:
        print(board_to_string(board))
        time.sleep(1)
    return board
