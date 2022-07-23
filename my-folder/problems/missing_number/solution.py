class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        nums2=[i for i in range(0,len(nums))]        
        for i in nums2:
            if i not in nums:
                return i;
        return nums2[-1]+1