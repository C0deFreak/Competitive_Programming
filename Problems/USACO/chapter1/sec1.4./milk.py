"""
ID: grgurin1
LANG: PYTHON3
TASK: milk
"""
with open('milk.in', 'r') as fin:
    n, m = map(int, fin.readline().strip().split())
    # Kako je max cijena 1000, treba nam 1001 mjesto (0 uključena)
    options = [0]*1001

    for _ in range(m):
        p, a = map(int, fin.readline().strip().split())
        options[p] += a
    
ans = 0

# Također možeš stavit u listu, listu sortat i proći kroz nju slično ko ođe
# options = {}
# options[p] = a + options.get(a, 0)
# options = list(options.items())
# options.sort()

# ali sort je n log n gdje je n cijena (max 1000 + 1 zbog nule) - O(n log n)
# ako napraviš unassigned listu dugu tisuću, samo treba proć kroz listu što je n (max 1000 + 1 zbog nule) - O(n)


if m and n:
    for p, a in enumerate(options):
        if n > a:
            n -= a
            ans += a*p
        else:
            ans += p*n
            break

fout = open('milk.out', 'w')
fout.write(str(ans)+'\n')
