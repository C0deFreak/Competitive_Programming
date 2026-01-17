#from collections import Counter
#print(Counter(s) == Counter(t))

t="racecar"
s="carrace"
if len(t)!= len(s):
    print(False)
    exit()
    
# HASH MAPE ili dictionaries u pythonu
# za razliku od lista, index u dictu može bit bilo što
# brži je od liste (O(1) da nađeš element, a u listi je O(n))
t_coun = {}
s_coun = {}

for i in range(len(t)):
    t_coun[t[i]] = 1 + t_coun.get(t[i], 0)
    s_coun[s[i]] = 1 + s_coun.get(s[i], 0)


print(t_coun == s_coun)