# Get the greatest subarray of an array
# Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
# Output: 11
# Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.
def kadanes(nums):
    maxSum = nums[0]
    curSum = 0
    
    # O(n)
    for n in nums:
        # If the current sum is less than 0, there is no point 
        # in continiuing with it, we rather start from zero
        curSum = max(curSum, 0)
        curSum += n
        maxSum = max(maxSum, curSum)
    return maxSum