"""
ID: grgurin1
LANG: PYTHON3
TASK: ariprog
"""

# aritmetička progresija je sekvenca a+ib, i = [0, n]
# p, q = [0, M] skup bisquare su svi brojevi za koje vrijedi p2 + q2
# tvoj zadatak je pronać a i b, tako da svaki element njihove sekvence pripadaju skupu bisquare
# N=5, M=7, bisquare=(0, 1, 4, 9 ... 2, 5, 10 ... 13 ...)
# Mogući a i b: 1 4 --> 1+0, 1+4, 1+8, 1+12...
# OVO GOVNO JE TOLIKO SPORO DA NE MOŽE RIJEŠIT VRIJEME JE DA NAUČIŠ C++

fin = open('USACO/ariprog.in', 'r')
n = int(fin.readline().strip())
m = int(fin.readline().strip())

bisquares = set()
for y in range(m+1):
    for x in range(y, m+1):
        bisquares.add(y*y + x*x)

with open('USACO/ariprog.out', 'w') as fout:
    empty = False
    for b in range(1, int((2*m*m)/(n-1))+1):
        for a in bisquares:
            if a > (2*m*m)-((n-1)*b):
                continue
            for i in range(n):
                if a + i*b not in bisquares:
                    break

            if a+i*b in bisquares:
                empty = True
                fout.write(f'{a} {b}\n')
    if not empty:
        fout.write('NONE\n')