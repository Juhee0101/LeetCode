class Solution:
    def __robHelp(self, nums: list[int]) -> int:
        numHouse = len(nums)
        lastHouseIdx = len(nums) - 1

        money = [0] * numHouse
        firstHouse = [False] * numHouse

        money[0:3] = nums[0:3]            
        firstHouse[0] = True
        firstHouse[2] = True
        money[2] += money[0]

        lastFalseIdx = 1

        for i in range(3, lastHouseIdx):
            prevIdx = i-2 if money[i-2] > money[i-3] else i-3
            money[i] = money[prevIdx] + nums[i]

            if money[i-2] == money[i-3] and firstHouse[i-2] * firstHouse[i-3] != 1:
                firstHouse[i] = False
            else:
                firstHouse[i] = firstHouse[prevIdx]

            lastFalseIdx = i if firstHouse[i] == False and i != lastHouseIdx-1 else lastFalseIdx

        money[lastHouseIdx] = money[lastFalseIdx] + nums[lastHouseIdx]

        return max(money)

    def rob(self, nums: list[int]) -> int:
        if len(nums) <= 3:
            return max(nums)
        
        maxMoney1 = self.__robHelp(nums)
        maxMoney2 = self.__robHelp(nums[::-1])
        return max(maxMoney1, maxMoney2)