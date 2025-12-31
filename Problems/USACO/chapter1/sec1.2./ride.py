"""
ID: grgurin1
LANG: PYTHON3
TASK: ride
"""
fin = open ('ride.in', 'r')
fout = open ('ride.out', 'w')

comet = fin.readline().strip()
group = fin.readline().strip()

ans = 'STAY'
cans = 1
gans = 1
# Samo ascii
for c in comet:
    cans *= ord(c)-ord('A')+1
for g in group:
    gans *= ord(g)-ord('A')+1

if gans % 47 == cans % 47:
    ans = 'GO'

fout.write (ans + '\n')
fout.close()