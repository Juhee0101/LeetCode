class Solution:
    def __init__(self):
        self.result = []

    def __permuteHelp(self, nums: list[int], idx: int) -> None:
        if len(nums)==1:
            self.result.append(nums[:])

        if idx==len(nums)-1:
            return
        
        for i in range(len(nums)-idx):
            num = nums.pop(idx)
            nums.append(num)
            if nums not in self.result:
                self.result.append(nums[:])
            self.__permuteHelp(nums, idx+1)

    def permute(self, nums: list[int]) -> list[list[int]]:
        self.__permuteHelp(nums, 0)
        return self.result