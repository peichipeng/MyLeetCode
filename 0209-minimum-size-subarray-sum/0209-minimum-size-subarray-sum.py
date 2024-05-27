class Solution(object):
    def minSubArrayLen(self, target, nums):
        """
        :type target: int
        :type nums: List[int]
        :rtype: int
        """
        subLength = float('inf')
        sum = 0
        i = 0
        for j in range(len(nums)):
            sum += nums[j]
            while sum >= target:
                length = j-i+1
                if length < subLength:
                    subLength = length
                sum -= nums[i]
                i += 1
        if subLength != float('inf'):
            return subLength
        return 0

        