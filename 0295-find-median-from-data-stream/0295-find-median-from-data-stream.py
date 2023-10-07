class MedianFinder:

    def __init__(self):
        self.cnt = 0
        self.nums = []
        

    def addNum(self, num: int) -> None:
        # heapq.heappush(self.nums, num)
        self.nums.append(num)
        self.cnt += 1

    def findMedian(self) -> float:
        self.nums.sort()
        if self.cnt % 2 == 0:
            return (self.nums[self.cnt//2-1] + self.nums[self.cnt//2]) / 2
            
        else:
            return self.nums[self.cnt//2]


# Your MedianFinder object will be instantiated and called as such:
# obj = MedianFinder()
# obj.addNum(num)
# param_2 = obj.findMedian()