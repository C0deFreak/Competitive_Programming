"""
ID: grgurin1
LANG: PYTHON3
TASK: dualpal
"""

fin = open("dualpal.in", 'r')
n, s = map(int, fin.readline().strip().split())

# Pretvara broj u drugu bazu
def base(x, y):
    t = ''
    while y:
        if y%x < 10:
            t += str(y%x)
        else:
            t += chr(y%x - 10 + ord('A'))

        y = y // x
    return t[::-1]

with open('dualpal.out', 'w') as fout:
    while n:
        s += 1
        scnd = False
        for b in range(2, 11):
            chck = base(b, s)

            # Provjerava jeli palindrom preko pointera
            r, l = 0, len(chck)-1
            while r < l:
                if chck[r] != chck[l]:
                    break
                r += 1
                l -= 1
            
            if r >= l:
                if scnd:
                    fout.write(str(s) + '\n')
                    n -= 1
                    break
                scnd = True


