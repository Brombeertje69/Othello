# -*- coding: utf-8 -*-
"""
Created on Sat Oct  1 17:48:35 2022

@author: Swen
"""



#from Board.optim3 import Board
#
# import board
# board = board.initialize_board()

#from common.names import BLACK
# player = BLACK
# depth = 0
# maximizer = player
# max_depth = 1

from board import get_score, make_move, legal_moves, opponent

import numpy as np


def Minimax(board, player, maximizer = None, depth = 0, max_depth = 5):
    if maximizer is None: maximizer = player

    best_move = None
    if depth == max_depth:
        max_score = get_score(board) #Static evaluate current situation
    else:
        moves = legal_moves(board, player) #First find legal moves
        if moves is None:
            max_score = get_score(board)  #Static evaluate current situation
        else:
            max_score = -np.Inf #Initialize default to negative inf
        #print('Legal:', moves)

        for move in moves:
            #Play the move
            copy = board.copy()
            copy = make_move(copy, move, player)
            score, _ = Minimax(copy, opponent(player), maximizer, depth + 1, max_depth)
            #print('move:', move)
            #print('score:', score)
            if score > max_score:
                max_score = score
                best_move = move
            #print('best move:', best_move)

        #Check minimizer or maximizer:
    return -max_score, best_move

# from board import board_to_string
# print(board_to_string(board))
# player = BLACK
# depth = 0
# maximizer = player
# max_depth = 8
# %time Minimax(board, player, maximizer, depth, max_depth)
# print(board_to_string(board))
