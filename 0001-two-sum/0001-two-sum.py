class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        
        d = {}
        ans = []
        for i in range(0, len(nums)):
            rem=target-nums[i]
            if rem in d:
                return [d[rem],i]
            else:
                d[nums[i]]=i
        
        return []