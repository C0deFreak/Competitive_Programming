"""
ID: grgurin1
LANG: PYTHON3
TASK: palsquare
"""

fin = open("palsquare.in", 'r')
b = int(fin.readline().strip())

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

with open('palsquare.out', 'w') as fout:
    for n in range(1, 300):
        chck = base(b, n*n)
        
        # Palindrom preko pointera
        r, l = 0, len(chck)-1
        while r < l:
            if chck[r] != chck[l]:
                break
            r += 1
            l -= 1
        if r >= l:
            fout.write(f'{base(b, n)} {chck}\n')


