"""
ID: grgurin1
LANG: PYTHON3
TASK: namenum
"""
fin = open('namenum.in', 'r')
name = fin.readline().strip()
l_name = len(name)
trans = {'A': '2', 'B': '2', 'C': '2', 'D': '3', 'E': '3', 'F': '3', 'G': '4', 'H': '4', 'I': '4', 'J': '5',
         'K': '5', 'L': '5', 'M': '6', 'N': '6', 'O': '6', 'P': '7', 'R': '7', 'S': '7', 'T': '8', 'U': '8', 
         'V': '8', 'W': '9', 'X': '9', 'Y': '9', 'Q':'-1', 'Z': '-1'}

nonnull = False
fout = open('namenum.out', 'w')
# Radije ću uspoređivat 5000 stavri s brojem, nego potencialno 20^12 imena s dokumentom
with open('dict.txt', 'r') as data:

    rn = 1
    while rn:
        rn = data.readline().strip()
        if trans[rn[0]] > name[0]:
            break
        if l_name != len(rn):
            continue
        for n in range(l_name):
            if trans[rn[n]] != name[n]:
                break
            if n == l_name-1:
                nonnull = True
                fout.write(rn+'\n')

    if not nonnull:
        fout.write('NONE\n')