"""
ID: grgurin1
LANG: PYTHON3
TASK: barn1
"""

with open('barn1.in', 'r') as fin:
    m, s, c = map(int, fin.readline().strip().split())
    stalls = []
    gaps = []

    for _ in range(c):
        stalls.append(int(fin.readline().strip()))
    
    # Minumalna duljina je uvijek broj štala
    ans = len(stalls)
    stalls.sort()

    # Pridružuje razmake između štala
    for g in range(1, c):
        gap = stalls[g] - stalls[g-1] - 1
        if gap > 0:
            gaps.append(gap)
    
    # Ako dasaka nema dovoljno, najbolje je prekriti što manje rupe kako bismo uštedili na duljini
    gaps.sort()
    ans += sum(gaps[:len(gaps)+1-m])

fout = open('barn1.out', 'w')
fout.write(str(ans)+'\n')


