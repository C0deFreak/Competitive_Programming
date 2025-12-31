def solve(n, nums):
    # Sort the nums and split them intu a bigger and smaller half
    nums.sort()
    ans = ''
    small, big = nums[:n], nums[n:]
    # If we add smaller numbers at even and bigger at odd positions, you guarantee that
    # an odd position will be too big for the mean and an even position will be to small for the mean
    for i in range(n*2):
        if not i % 2:
            ans += str(small[0])+' '
            small.pop(0)
        else:
            ans += str(big[0])+' '
            big.pop(0)
    
    return ans.strip()
    

for _ in range(int(input())):
    print(solve(int(input()), list(map(int, input().split()))))