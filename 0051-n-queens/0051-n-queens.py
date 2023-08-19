class Solution:
    def __init__(self):
        self.results = []

    def __solveNQueensHelp(self, n:int, i:int, colCheck:list[int], diagCheck1:list[int], diagCheck2:list[int]) -> None:
            if i >= n:
                self.results.append(colCheck[:])
                return

            for j in range(n):                
                diag1 = i + j
                diag2 = 3 - i + j

                if j in colCheck or diag1 in diagCheck1 or diag2 in diagCheck2:
                    continue

                colCheck.append(j)
                diagCheck1.append(diag1)
                diagCheck2.append(diag2)

                self.__solveNQueensHelp(n, i+1, colCheck, diagCheck1, diagCheck2)
                
                colCheck.pop()
                diagCheck1.pop()
                diagCheck2.pop()
  
    def __numsToString(self, n: int) -> list[list[str]]:
        outputTot = []

        for result in self.results:
            output = []
            for queenCol in result:
                output.append("." * queenCol + "Q" + "." * (n-queenCol-1))
            outputTot.append(output)

        return outputTot

    def solveNQueens(self, n: int) -> list[list[str]]:
        self.__solveNQueensHelp(n, 0, [], [], [])
        outputStr = self.__numsToString(n)
        return outputStr