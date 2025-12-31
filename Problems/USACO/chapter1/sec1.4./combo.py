"""
ID: grgurin1
LANG: PYTHON3
TASK: combo
"""
fin = open('combo.in', 'r')
n = int(fin.readline().strip())
farmer = fin.readline().strip().split()
master = fin.readline().strip().split()


# Dodaje svaku legalnu kombinaciju u intervalu [loz-2, loz+2]
# Ako je legalna dodava je u set (izbjegava mogućnost duplikata)
# Provjerava 3 mjesta, a svako mjesto ima max 5 legalnih mogućnost
# n_max = 5^3 za jednu lozinku, pošto ih je 2 to je 2*5^3 = 250
# Kako uvijek provjeravam za sve brojeve u intervalu (barem jesu li legalni) n je uvijek 250
# Time: O(1) (tj. O(250))

# Ako samo ideš preko svake moguće konbinacije i samo gledaš je li udaljenost <= 2 (ne trebaš legalnost)
# To je O(n^3) za obje lozinku, space complexity je vjr. manji je nema dodatnih arrayova
# Ali kako je n_max = 100, max vrijeme je 1,000,000 što je PUNO veće od konstantnog 250
def check(num, place=2):
    checked = set()   
    for i in range(-2, 3):
        rn = num.copy()
        if int(num[place])+i <= 0:
            if -i < n:
                rn[place] = str(n+int(num[place])+i)
        elif int(num[place])+i > n:
            if i < n:
                rn[place] = str(i)
        else:
            rn[place] = str(int(num[place])+i)
        
        if not place:
            checked.add(' '.join(rn))
        else:
            checked = checked.union(check(rn, place-1))

    return checked

checked = check(farmer)
checked = checked.union(check(master))


fout = open('combo.out', 'w')
fout.write(str(len(checked))+'\n')