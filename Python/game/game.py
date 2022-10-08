# -*- coding: utf-8 -*-
"""
Created on Fri Sep 30 19:15:29 2022

@author: Swen
"""

from common.names import BLACK, WHITE

import board
from game.strategies import Random_choice, Minimax

import time

class Game():
    """
        Launches a new game. First creates a board, then handles the game flow.
    """
    def __init__(self, show_moves = False, show_score = True):
        # set settings
        self.show_moves = show_moves
        self.show_score = show_score

        self.reset_score()                   # set score to 0-0

    def reset_score(self):
        """ Resets the score"""
        self.wins = 0
        self.losses = 0

    def play(self, rounds, show_score = True):
        for Round in range(rounds):
            self.__play_round()
            print("Completed (", Round + 1, "/", rounds ,')')

        if show_score:
            self.output_score(rounds)

    def output_score(self, rounds):
        out_str = 'RESULTS:' + \
        '\n \t\t\t Wins: \t\t' + str(self.wins) +\
        '\n \t\t\t Losses:\t' + str(self.losses) +\
        '\n \t\t\t Ties\t\t' + str(rounds - (self.wins + self.losses))
        print(out_str)

    def __play_round(self, show_results = False):
        self.__init_new_round()   #Create a new round
        while True:
            move = self.__get_move() #obtain the moves
            if move is not None:
                #print(self.player, move)
                #print("Player: ",self.player, "\t Move: ", move , '\n')
                #time.sleep(1)
                board.make_move(self.board, move, self.player, show_moves = self.show_moves) # update the field, go next player
                self.previous_passed = False
            else:
                if self.previous_passed == True:
                    break           # exit the game
                self.previous_passed = True #Set bool to keep track of previous player
            self.__next_player()    # move to the next player

        self.__update_score()

        if show_results:
            print(self.board)
            print('Black scored:', self.board.score)

    def __init_new_round(self):
        #Creates a new game, sets black as player
        self.board = board.initialize_board()
        self.player = BLACK            # Black always begins
        self.previous_passed = False # Nobody passed yet


    def __get_move(self):
        #NB: Need to pass the instance of the board
        move = None
        if self.player == WHITE: # or self.player == BLACK:
            #_, move = Minimax(self.board, self.player, max_depth = 1)
            move = Random_choice(self.board, self.player)
        elif self.player == BLACK:
            _, move = Minimax(self.board, self.player)
        return move

    def __update_score(self):
        score = board.get_score(self.board)
        if score > 0:
             self.wins += 1
        elif score < 0:
            self.losses += 1

    def __next_player(self):
        self.player = board.opponent(self.player) #Switch players

if __name__ == "__main__":
    game = Game()
    game.play(1000)
