def solve(n, nums):
    # Time O(n+n) --> O(n) cus of min()
    # The only actually important numbers are the two smallest ones (min and sec) (all nums are different)
    # The biggest denumerator (BD) is at least going to be min, we can mod (%) every other num (bigger) with themselves to get 0
    # BD cannot be the sec because if we mod x with a number larger then x we get x back 
    # So the number can be in the interval [min, sec>
    # Since we know what we get from modding a smaller number with a larger one we know all other numbers must return min after modding
    # To get with what number we have to mod sec we just deduce min from it
    # If the deductiuon is smaller then min the answer is definitely min (we cannot get min from modding sec)
    # If it is bigger then min the number we get is the answer, because sec returns min after modding sec with it
    # Every other number larger then sec must have a denumerator taht returns min if sec has it
    first = min(nums)
    nums.remove(first)
    second = min(nums)
    return max(first, second-first)




for _ in range(int(input())):
    print(solve(int(input()), list(map(int, input().split()))))