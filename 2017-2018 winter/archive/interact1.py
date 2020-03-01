#!/usr/bin/python3

import sys
import subprocess

def check(b, msg):
    if not b:
        print(msg)
        sys.exit(1)

NO = -1
PP = [0, 1]
SIZE = 8

class Game:
    def __init__(self):
        self.board = [[NO for i in range(SIZE)] for j in range(SIZE)]

        a = SIZE // 2 - 1
        b = SIZE // 2

        self.board[a][a] = self.board[b][b] = PP[1]
        self.board[a][b] = self.board[b][a] = PP[0]

        self._turn = 0
        self._fail_player = -1
        
    def turn(self):
        return self._turn

    def inside(self, x, y):
        return 0 <= x < SIZE and 0 <= y < SIZE 
    
    def get_killed_cells(self, x, y):
        dx = [+1, -1,  0,  0,   +1, +1, -1, -1]
        dy = [ 0,  0, +1, -1,   +1, -1, +1, -1]

        ans = []
        
        for dr in range(8):
            cx, cy = x + dx[dr], y + dy[dr]

            subans = []
            
            while self.inside(cx, cy) and self.board[cx][cy] == PP[1 - self.turn()]:
                subans.append((cx, cy))
                cx, cy = cx + dx[dr], cy + dy[dr]

            if self.inside(cx, cy) and self.board[cx][cy] == PP[self.turn()]:
                ans += subans
        return ans
    
    def is_good_move(self, x, y):
        return self.inside(x, y) and self.board[x][y] == NO and len(self.get_killed_cells(x, y)) > 0

    def move(self, x, y):
        if not self.is_good_move(x, y):
            self._fail()
            return False

        lst = self.get_killed_cells(x, y)
        self.board[x][y] = PP[self._turn]
        for (a, b) in lst:
            self.board[a][b] = PP[self._turn]
        
        self._turn = 1 - self._turn
        if not self.has_move():
            self._turn = 1 - self._turn
            if not self.has_move():
                self._turn = -1

        return True
    
    def has_move(self):
        for i in range(SIZE):
            for j in range(SIZE):
                if self.is_good_move(i, j):
                    return True
        return False

    def score(self):
        ans = [0, 0]
        for i in range(SIZE):
            for j in range(SIZE):
                if self.board[i][j] != NO:
                    ans[self.board[i][j]] += 1

        if self._fail_player != -1:
          ans[self._fail_player] *= -1
        return (ans[0], ans[1])

    def _fail(self):
        self._fail_player = self._turn
        self._turn = -1

    def fail(self):
        return self._fail_player != -1
    
def describe_field(game):
    field = ""
    for i in range(SIZE):
        field = field + " ".join(map(str, game.board[i])) + "\n"
    return field

def describe_nice_field(game):
    field = ""
    for i in range(SIZE):
        mp = {-1:'.', 0:'W', 1:'B'}
        
        field = field + "".join(map(lambda x: mp[x], game.board[i])) + "\n"
    return field

def main():
    verbose = False
    if len(sys.argv) >= 2 and sys.argv[1] == "--verbose":
        verbose = True
        sys.argv = sys.argv[:1] + sys.argv[2:]
    
    check(len(sys.argv) == 3, "usage: " + sys.argv[0] + " [--verbose] player1 player2")

    pp = [None, None]
    pp[0] = subprocess.Popen(sys.argv[1], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)
    pp[1] = subprocess.Popen(sys.argv[2], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)

    game = Game()
    while game.turn() != -1:
        field = describe_field(game) + str(game.turn()) + "\n"
            
        pp[game.turn()].stdin.write(field)
        pp[game.turn()].stdin.flush()

        (a, b) = map(int, pp[game.turn()].stdout.readline().strip().split())
        if verbose:
            print("")
            print("moving to: {} {}".format(a, b))
        
        if verbose:
            print(describe_nice_field(game), end="")
        if not game.move(a, b):
            print("Epic fail, {} has made a bad move".format("white" if game.turn() == 0 else "black"))
            print("Field:")
            print(describe_nice_field(game), end="")

    for i in range(2):
        field = describe_field(game) + str(game.turn()) + "\n"
        field = field + "-1\n"

        pp[i].stdin.write(field)
        pp[i].stdin.flush()

    if not game.fail():
        a, b = game.score()
        msg = "draw" if a == b else ("black wins" if a < b else "white wins")
        print("")
        print("Game over W:{}, B:{}, {}".format(a, b, msg))
        print("Field:")
        print(describe_nice_field(game), end="")

if __name__ == "__main__":
    main()
