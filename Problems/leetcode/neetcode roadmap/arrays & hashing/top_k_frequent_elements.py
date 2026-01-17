#from collections import Counter

#coun = Counter(nums)
nums = [1,1,1,2,2,3]
k = 2

coun = {}
# Opet ovaj kao kod, s time da što je veći broj to ga stavlja više na kraj liste
code = [[] for _ in range(len(nums)+1)]
ans = []

for num in nums:
    coun[num] = coun.get(num, 0) + 1
for num, val in coun.items():
    code[val].append(num)

# Ide odzada i appenda elemente dok ans nije k
for n in range(len(code)-1, 0, -1):
    for c in code[n]:
        ans.append(c)

        if len(ans) == k:
            print(ans)
            exit()