# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 14:17:47 2022

@author: Swen
"""
from common.names import DISPLAY

def board_to_string(board):
        """
            Gets a string representation of the board
        """
        str_rep = ''
        str_rep += '  %s\n' % ' '.join(map(str, range(1, 9)))
        # begin,end = 11,19 21,29 31,39 ..
        for row in range(1, 9):
            begin, end = 10*row + 1, 10*row + 9
            str_rep += '%d %s\n' % (row, ' '.join(DISPLAY[board[begin:end]]))
        return str_rep
