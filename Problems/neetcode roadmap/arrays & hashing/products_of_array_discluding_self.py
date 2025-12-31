#Vrijeme O(n) bez dijeljenja
nums = [1,2,4,6]

ans = [1]*len(nums)
l, r = 1, 1

# N je umnožak svih predhodnih elemenata
for n in range(len(nums)):
    ans[n] = l
    l *= nums[n]

# Množi N sa umnoškom svih predhodnih elemenata (unazad)
for m in range(len(nums)-1, -1, -1):
    ans[m] *= r
    r *= nums[m]

print(ans)