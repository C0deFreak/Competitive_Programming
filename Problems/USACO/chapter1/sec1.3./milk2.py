"""
ID: grgurin1
LANG: PYTHON3
TASK: milk2
"""

with open('milk2.in', 'r') as fin:
    n = int(fin.readline().strip())
    table = []    
    for _ in range(n):
        table.append(list(map(int, fin.readline().strip().split())))

table.sort()
curr = table[0]

nomilk = 0
milk = 0

# Ako se niz rada nastavlja, max rada se povećava, a ako se niz nerada nastavlja, max nerada se povećava
# ako se niz prekine usporedit će s dosadašnjim progresom
for i in range(1, n):
    if curr[1] < table[i][0]:
        nomilk = max(nomilk, table[i][0]-curr[1])
        milk = max(milk, curr[1]-curr[0])
        curr = table[i]
    else:
        curr[1] = max(table[i][1], curr[1])
    
milk = max(milk, curr[1]-curr[0])
    

fout = open('milk2.out', 'w')
fout.write(f'{milk} {nomilk}\n')