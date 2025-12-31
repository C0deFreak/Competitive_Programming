"""
ID: grgurin1
LANG: PYTHON3
TASK: skidesign
"""

with open('skidesign.in', 'r') as fin:
    n = int(fin.readline().strip())
    heights = []
    for _ in range(n):
        heights.append(int(fin.readline().strip()))

ans = 100000000000
# Svi će vrhovi SIGURNO biti u nekom intervalu (i, i+17) (uključujući i između)
# Najmanje što i može biti je min(vrhova), a najviše je max(vrhova)-17 (jer je drugi dio intervala i+17)
for i in range(min(heights), max(1, max(heights)-16)):
    res = 0
    for j in heights:

        # Ako vrh_j nije u intervalu onda je:
        # Manji od intervala[0], dodajemo razliku na 2
        if j < i:
            res += (i-j)**2
        # Veći od intervala[1], dodajemo razliku na 2
        elif j > i+17:
            res += (i+17-j)**2
        # Ako je u intervalu ne trebamo ga mijenjat
    
    ans = min(res, ans)
    

fout = open('skidesign.out', 'w')
fout.write(str(ans)+'\n')