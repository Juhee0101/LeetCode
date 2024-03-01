class Solution:
    def ispalindrome(self, s: str):
        return s == s[::-1]
    
    def shortestPalindrome(self, s: str) -> str:
        if self.ispalindrome(s): return s

        for i in range(len(s)-1, 0, -1):
            if self.ispalindrome(s[:i]):
                back = s[i:]
                break

        return s[:i-1:-1]+s