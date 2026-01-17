nums = [2,7,11,15]
target = 9

pos = {}

for n in range(len(nums)):
    i = nums[n]
    if target-i in pos:
        print([pos[target-i], n])
        exit()
    pos[i] = n