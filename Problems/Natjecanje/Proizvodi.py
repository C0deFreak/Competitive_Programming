n = int(input())
info = {}
res = [0, 0]

def check(x):
    if float(item[2]) < info[item[x]]:
            res[1] -= info[item[x]] - float(item[2])
            info[item[x]] = float(item[2])

for p in range(n):
    item = input().split('-')
    item[2] = item[2].replace(',', '.')
    if item[0] in info:
        check(0)
            
    if item[1] in info:
        check(1)
    
    else:
        res[0] += 1
        res[1] += float(item[2])
        info[item[0]] = float(item[2])
        info[item[1]] = float(item[2])

print(f'{res[0]} {str(round(res[1], 2)).replace('.', ',')}')

