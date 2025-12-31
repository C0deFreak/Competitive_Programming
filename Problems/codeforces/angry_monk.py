
# This solution is O(n log n) plus the going through the list
def solve(trash, nums):
    ans = 0
    # We will add all of the casserole to the biggest piece, starting from the smallest ones
    nums.sort()
    # We can either split or add 1
    # There is always 1 left after all the splitting, and for the rest there is the same amount of splitting and adding (minus the one thats left)
    while len(nums) != 1:
            ans += 1+(nums[0]-1)*2
            nums.pop(0)
    return ans


# There is a O(1) solution
# 2*n-k-2*max(nums)+1
# We add all of them minus one for each anyways
# So we just need to remove the biggest one minus one
for _ in range(int(input())):
    print(solve(input(), list(map(int, input().split()))))