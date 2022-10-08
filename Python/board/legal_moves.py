# -*- coding: utf-8 -*-
"""
Created on Mon Oct  3 14:12:08 2022

@author: Swen
"""
#from numba import njit
import itertools

from .find_legal_move import find_legal_move

def legal_moves(board, player):
      #Get the squares that need to be checked for player
      squares = [sq for sq, value in enumerate(board) if value == player]
      moves = [find_legal_move(board, sq, player) for sq in squares]
      moves = list(set(itertools.chain(*moves)))
      #moves.sort()
      return moves
