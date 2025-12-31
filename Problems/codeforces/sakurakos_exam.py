def solve(nums):
    ones, twos = map(int, nums)

    # If there is an odd number of ones, there wil always be one left so the sum can't be 0
    if ones % 2 != 0:
        return 'NO'
    # If there is an odd number of twos, sum can be 0 if there is enough ones to get an even nuber of twos (ones stay even cus we waste 2 of them)
    if twos % 2 != 0 and ones == 0:
        return 'NO'
    
    # If you can get an even number of ones and twos you can gat zero sum
    return 'YES'


for _ in range(int(input())):
    print(solve(input().split()))