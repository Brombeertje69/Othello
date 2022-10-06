# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 14:23:58 2022

@author: Swen
"""
import numpy as np

from common.constants import VALID_SQUARES
from common.names import OUTER, WHITE, BLACK, EMPTY

def initialize_board():
        """
            Create a new board with the initial black and white possitions.
            Returns a list corresponding to each element.
        """
        board = [OUTER] * 100
        for i in VALID_SQUARES:
            board[i] = EMPTY
        # the middle four squares should hold the initial piece positions.
        board[44], board[45] = WHITE, BLACK
        board[54], board[55] = BLACK, WHITE
        return np.array(board)
