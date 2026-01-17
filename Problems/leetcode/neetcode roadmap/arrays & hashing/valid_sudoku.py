from collections import defaultdict

board = [
  ["5","3",".",".","7",".",".",".","."],
  ["6",".",".","1","9","5",".",".","."],
  [".","9","8",".",".",".",".","6","."],
  ["8",".",".",".","6",".",".",".","3"],
  ["4",".",".","8",".","3",".",".","1"],
  ["7",".",".",".","2",".",".",".","6"],
  [".","6",".",".",".",".","2","8","."],
  [".",".",".","4","1","9",".",".","5"],
  [".",".",".",".","8",".",".","7","9"] ]

# Nećemo koristit liste jer je pretraga u njima O(n)
column = defaultdict(set)
row = defaultdict(set)
box = defaultdict(set)

for y in range(9):
    for x in range(9):

        rn = board[y][x]
        if rn == '.':
            continue

        if (rn in column[y]
            or rn in row[x]
            or rn in box[(y//3, x//3)]):
            print(False)
            exit()
            
        column[y].add(rn)
        row[x].add(rn)
        box[(y//3, x//3)].add(rn)
print(True)