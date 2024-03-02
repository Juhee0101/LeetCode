class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        strCnt = {}
        for i in range(len(s)):
            if s[i] in strCnt:
                strCnt[s[i]] += 1
            else:
                strCnt[s[i]] = 1
        
        numOdd = 0
        for key in strCnt:
            if strCnt[key] % 2 == 1:
                numOdd += 1
        
        if numOdd > k or len(s) < k:
            return False
        else:
            return True