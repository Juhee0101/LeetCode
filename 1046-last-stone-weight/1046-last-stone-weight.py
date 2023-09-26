class Solution:
    def lastStoneWeight(self, stones: list[int]) -> int:
#         if len(stones) == 0:
#             return 0
    
        while (len(stones) > 1):
            s1 = max(stones)
            stones.remove(s1)

            s2 = max(stones)
            stones.remove(s2)

            newStone = abs(s1 - s2)
            if newStone > 0:
                stones.extend([newStone])

        if len(stones) != 0:
            return stones[0]
        else:
            return 0