class Solution:
    def largestPalindromic(self, num: str) -> str:
        countArr = [0]*10 # 0부터 9까지 개수세기 
        for n in num:
            countArr[int(n)] += 1 # 숫자로 변환    
        front = "" #순서대로 palindrome담기
        #palindrome의 앞부분
        for i in range(9,-1,-1):
            share = countArr[i]//2
            if i==0 and len(front)==0: #0으로 시작하는 숫자는 제외
                continue
            front += str(i)*share
            countArr[i] = countArr[i]%2 #나머지만 남김
            # print(result)
        #홀수개 있는 숫자 추가하기
        middle = ""
        for i in range(9,-1,-1):
            if countArr[i]:
                middle = str(i)
                break

        if not front and not middle:
            return "0"

        return front+middle+front[::-1]