class Solution:
    def Counter(self, s): #dictionary로 개수 세주는 함수 만들기
        sDict = {}
        for c in s:
            if c in sDict:
                sDict[c]+=1
            else:
                sDict[c]=1
        return sDict

    #from discussion 코드(test case 모두 통과)

    #from collections import Counter

    def canConstruct(self, s: str, k: int) -> bool:  
        if len(s)<k:
            return False
        freq =Counter(s) ##dictionary로 만들어주는 함수
        odd =0
        for key,v in freq.items():
            if v%2:
                odd+=1
        if odd>k:  ##모든 palindrome안에는 모두 짝수개의 알파벳이 들어가고, 홀수개의 1개 알파벳이 포함될 수 있음. 따라서 odd>k이면 k개의 palindrome으로 자를 수 없음
            return False
        return True