gen = input()
ans = gen
gen = gen+gen
k = int(input())
s = len(ans)
if not k:
    print(ans)
    exit()
if k>1:
    print(''.join(sorted(ans)))
    exit()


for i in range(0, s):
    ans = min(ans, gen[i:i+s])

print(ans)