"""
ID: grgurin1
LANG: PYTHON3
TASK: transform
"""

with open('transform.in', 'r') as fin:
    orig = []
    finl = []
    rever = []
    ans = 7

    n = int(fin.readline().strip())
    for _ in range(n):
        orig.append(list(fin.readline().strip()))
        rever.append(orig[-1][::-1])
    
    for _ in range(n):
        finl.append(list(fin.readline().strip()))
    
    if orig == finl:
        ans = 6
    
    if rever == finl:
        ans = 4
    

# Rotira matrix za 90 stupnjeva u smijeru kazaljke na satu - time O(n²)
# Brže je od: return [list(reversed(col)) for col in zip(*matrix)] jer ovo stvara nove liste i tuple
# Za obrnuto od kazaljke na satu:
#   stavi m.reverse() iza translacije
# time je isti
def rotate_90(m):
    m.reverse()
    for i in range(n):
        for j in range(i):
            m[i][j], m[j][i] = m[j][i], m[i][j]
    
    return m



for k in range(3):
    orig = rotate_90(orig)
    if finl == orig:
        ans = k+1
        break
    if ans > 5:
        rever = rotate_90(rever)
        if finl == rever:
            ans = 5

fout = open('transform.out', 'w')
fout.write(str(ans) + '\n')
fout.close()
