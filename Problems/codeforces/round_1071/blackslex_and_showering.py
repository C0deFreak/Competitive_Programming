# Time O(n+n) --> O(n)
def solve(n, nums):
    # first off we get the time without skipping any floor
    time = 0
    for i in range(1, n):
        time += abs(nums[i]-nums[i-1])
    
    # the first possible answer is just skiping the first floor, so that is just removing the time between the first and the second
    ans = time - abs(nums[0]-nums[1])

    # for every other floor (except the first and the last) we:
    # remove it from the route so now we have to deduce the time from the floor before to jth floor and from jth floor to the floor after it
    # after that we calculate the time needed to get from one floor before jth floor to one floor after the jth floor
    # compare the result to the current best
    for j in range(1, n-1):
        rn = abs(nums[j-1]-nums[j])+abs(nums[j+1]-nums[j])-abs(nums[j-1]-nums[j+1])
        ans = min(ans, time-rn)
    # last possible solution is just removing the last floor from the route
    ans = min(ans, time-abs(nums[-1]-nums[-2]))
    return ans
    


for _ in range(int(input())):
    print(solve(int(input()), list(map(int, input().split()))))