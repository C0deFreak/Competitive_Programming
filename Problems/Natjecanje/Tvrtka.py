n = int(input())
time = []
info = []

for t in range(n):
    t = input().split()
    if t in time:
        info[time.index(t)][0] -= 1 
    else:
        time.append(t)
        info.append([n, int(t[1])-int(t[0]), int(t[0])])

x = info.index(min(info))
print(f'{time[x][0]} {time[x][1]}')