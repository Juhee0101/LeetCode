class MinStack:

    def __init__(self):
        self.arr = []
        self.minIdx = []
        self.num = 0

    def push(self, val: int) -> None:
        self.arr.append(val)
        self.num += 1
        
        if not self.minIdx:
            self.minIdx.append(0)
        elif val < self.arr[self.minIdx[self.num-2]]:
            self.minIdx.append(self.num-1)
        else:
            self.minIdx.append(self.minIdx[self.num-2])

    def pop(self) -> None:
        if self.arr:
            self.arr = self.arr[:-1]
            self.minIdx = self.minIdx[:-1]
            self.num -= 1

    def top(self) -> int:
        if self.arr:
            return self.arr[self.num-1]
        else:
            return []

    def getMin(self) -> int:
        return self.arr[self.minIdx[self.num-1]]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()