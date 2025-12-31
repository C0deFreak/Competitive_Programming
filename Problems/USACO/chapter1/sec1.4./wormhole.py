"""
ID: grgurin1
LANG: PYTHON3
TASK: wormhole
"""

from collections import defaultdict
with open('wormhole.in', 'r') as fin:
    n = int(fin.readline().strip())
    wormholes = []
    # Kako krava ide samo u +x ovo će služit da provjeriš je li ima portal ispred nje ili će izaći iz loopa
    wormholes_pos = defaultdict(list)
    for _ in range(n):
        x, y = map(int, fin.readline().strip().split())
        wormholes.append((x, y))
        wormholes_pos[y].append(x)
        wormholes_pos[y].sort()

def check(combo):
    pos = 0
    # Može se dogodit da je loop ovisan o mjestu u kojem je započela
    for start, end in combo.items():
        checked = [(start, end)]
        rn = wormholes[end]
        
        # Provjeravat će dok ne ispadne iz loopa ili dok ne dođe do provjerenog mjesta
        while len(checked) < n:
            place = wormholes_pos[rn[1]]
            
            if rn[0] != max(place):
                # Ako nije na zadnjem(+x) wormholeu uči će u idući te će kravina trenutna pozicija biti par od wormholea u kojeg je ušla
                rn = wormholes[combo[wormholes.index((place[place.index(rn[0])+1],rn[1]))]]
                pos = (combo[wormholes.index(rn)], wormholes.index(rn))
            else:
                break
            
            # Ako je na paru koji je provjeran(x:y nije isto ko y:x jer to ne znači loop) u loopu je
            if pos in checked:
                return 1
            
            checked.append(pos)

    return 0


possibility = {}
def combos():
    ans = 0
    
    # Odabire početni wormhole
    for i in range(n):
        if i not in possibility:
            break
    
    if i+1 == n:
        return check(possibility)
    
    # Dava par početnom wormholeu ako ga nema u mogućnostima
    # Dobit ćeš n*2 dugu listu jer je x povezano na y i obrnuto
    for j in range(i+1, n):
        if j not in possibility:
            possibility[i] = j
            possibility[j] = i
            
            # Rekurzija
            ans += combos()
            possibility[i] = 0
            possibility.pop(j)
    
    possibility.pop(i)
    return ans




res = combos()

fout = open('wormhole.out', 'w')
fout.write(str(res)+'\n')

    


