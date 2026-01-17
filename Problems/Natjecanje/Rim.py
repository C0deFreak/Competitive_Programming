area = input().split()
n, m = int(area[0]), int(area[1])

grid = []
res = 0
for g in range(n):
    line = input().split()
    grid.append(line)

def dfs():
    res = 0
    for y in range(n):
        for x in range(m):
            if grid[y][x] == '0':
                if x > 0 and grid[y][x-1] == '0':
                    res += 1
                if y > 0 and grid[y-1][x] == '0':
                    res += 1

    return res

for y in range(n):
    for x in range(m):
        if grid[y][x] == '0':
            grid[y][x] = '1'
            if x > 0 and grid[y][x-1] == '0':
                grid[y][x-1] = '1'
                res += dfs()
                grid[y][x-1] = '0'
            if y > 0 and grid[y-1][x] == '0':
                grid[y-1][x] = '1'
                res += dfs()
                grid[y-1][x] = '0'
            grid[y][x] = '0'

print(res)