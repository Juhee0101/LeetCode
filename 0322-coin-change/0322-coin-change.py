class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        coinNum = [0] + [float('inf')] * amount

        for coin in coins:
            if coin <= amount:
                coinNum[coin] = 1

        for i in range(1, len(coinNum)):
            for coin in coins:
                if i - coin >= 0:
                    coinNum[i] = min(coinNum[i], coinNum[i - coin] + 1)
        
        if coinNum[amount] == float('inf'):
            return -1
        else:
            return int(coinNum[amount])