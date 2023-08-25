class Solution:
    def __robHelp(self, nums: list[int]) -> int:
        numHouse = len(nums)
        lastFalseIdx = 1

        money = [0] * numHouse
        firstHouse = [False] * numHouse

        money[0:3] = nums[0:3]            
        firstHouse[0] = True
        firstHouse[2] = True
        money[2] += money[0]

        for i in range(3, numHouse-1):
            prevIdx = i-2 if money[i-2] > money[i-3] else i-3
            money[i] = money[prevIdx] + nums[i]

            if money[i-2] == money[i-3] and firstHouse[i-2] * firstHouse[i-3] != 1:
                firstHouse[i] = False
            else:
                firstHouse[i] = firstHouse[prevIdx]

            lastFalseIdx = i if firstHouse[i] == False and i != numHouse-2 else lastFalseIdx

        money[numHouse-1] = money[lastFalseIdx] + nums[numHouse-1]

        return max(money)

    def rob(self, nums: list[int]) -> int:
        if len(nums) <= 3:
            return max(nums)
        
        maxMoney1 = self.__robHelp(nums)
        maxMoney2 = self.__robHelp(nums[::-1])
        return max(maxMoney1, maxMoney2)