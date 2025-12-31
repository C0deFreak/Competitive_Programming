from collections import defaultdict

coun = defaultdict(list)
strs = ["eat","tea","tan","ate","nat","bat"]

for n in strs:
    code = [0]*26 #napraviš ASCII tablicu za sva slova i dodavaš im vrijednost, dobiješ nešto kao kod
    for m in n:
        code[ord(m) - ord('a')] += 1
    coun[tuple(code)].append(n)

print(list(coun.values()))