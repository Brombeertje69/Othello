# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 19:35:45 2022

@author: Swen
"""
from common.names import DIRECTIONS, EMPTY
from .find_bracket import find_bracket


def find_legal_move(board, move, player):
      #Takes a square as input, checks for all directions if a bracket exists.
      getBrackets = lambda direction: find_bracket(board, move, player, direction, EMPTY)
      return [getBrackets(d) for d in DIRECTIONS if getBrackets(d) is not None]
