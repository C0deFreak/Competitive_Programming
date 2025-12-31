"""
ID: grgurin1
LANG: PYTHON3
TASK: crypt1
"""
fin = open('crypt1.in', 'r')
n = int(fin.readline().strip())
digits = fin.readline().strip().split()

# Ide kroz svaku kombinaciju digita za duži broj
def check_num(place, num):
    ans = 0
    for i in range(n):
        num[place] = digits[i]
        if place == 2:
            trinum = int(''.join(num))

            for x in range(n):
                for y in range(n):
                    
                    zero = list(str(trinum*int(digits[x])))
                    first = list(str(trinum*int(digits[y])))

                    # Provjerava jesu li produkti OK
                    if len(zero) == 3 and set(zero).issubset(set(digits)) and len(first) == 3 and set(first).issubset(set(digits)):
                        res = trinum*(10*int(digits[y]) + int(digits[x]))
                        res = list(str(res))

                        # Provjerava jeli rezultat umnoška OK
                        if len(res) == 4 and set(res).issubset(set(digits)):
                            ans += 1
        else:
            ans += check_num(place+1, num)
    
    return ans

fout = open('crypt1.out', 'w')
fout.write(str(check_num(0, [0]*3))+'\n')