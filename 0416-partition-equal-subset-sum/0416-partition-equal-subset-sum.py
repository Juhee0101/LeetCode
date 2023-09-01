class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        targetNum = sum(nums) / 2
        if targetNum % 1 != 0:
            return False
        
        sumSet = set([])

        for i in range(len(nums)):
            if nums[i] == targetNum:
                return True
            
            newSet = set([nums[i]])
            
            for element in sumSet:
                if nums[i] + element == targetNum:
                    return True
                
                newSet.add(nums[i] + element)
            
            sumSet = sumSet.union(newSet)
        
        return False