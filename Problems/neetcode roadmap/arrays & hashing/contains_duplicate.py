#from collections import Counter

nums = [1, 2, 3, 4]
'''
coun = Counter(nums)
for c in coun:
    if coun[c] != 1:
        print(True)
        exit()

print(False)
'''

# set je ko skupovi brojeva, znači ne možeš imat duple elemente,
# sve njegove funkcije su: add, remove, union, intersection, difference, itd.
# set je implementiran kao hash table, pa su sve njegove operacije O(1)
print(len(set(nums)) != len(nums))