"""
ID: grgurin1
LANG: PYTHON3
TASK: beads
"""

fin = open('beads.in', 'r')
n = int(fin.readline().strip())
beads = fin.readline().strip()*2
temp = 0
ans = 0
last = 1

# WHEN YOU HAVE A SUB STRING, ARRAY ECT. USE POINTERS

def check(pos):
    res = 0
    r, l = pos-1, pos
    rc, lc = beads[pos-1], beads[pos]
    while r != 0 and (beads[r] == rc or beads[r] == 'w'):
        res += 1
        r -= 1
        if rc == 'w':
            rc = beads[r]
    
    while l != n*2-1 and (beads[l] == lc or beads[l] == 'w'):
        res += 1
        l += 1
        if lc == 'w':
            lc = beads[l]
    

    return res, l

while last < n*2-1:
    temp, last = check(last)
    ans = max(temp, ans)

if ans > n:
    ans = n

fout = open('beads.out', 'w')
fout.write(str(ans) + '\n')
fout.close()

