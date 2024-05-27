class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        current = 0
        i = 0
        while i <= len(nums)-1 :
            if nums[i] != val:
                nums[current] = nums[i]
                current += 1
            i += 1
        return current 
        