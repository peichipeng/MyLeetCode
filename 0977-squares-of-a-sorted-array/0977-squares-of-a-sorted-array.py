class Solution(object):
    def sortedSquares(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        i = 0
        j = len(nums) - 1
        current = len(nums) - 1
        arr = [0] * len(nums)
        while i <= j:
            if nums[i]**2 > nums[j]**2:
                arr[current] = nums[i] ** 2
                i += 1
            else:
                arr[current] = nums[j] ** 2
                j -= 1
            current -= 1
        return arr
        