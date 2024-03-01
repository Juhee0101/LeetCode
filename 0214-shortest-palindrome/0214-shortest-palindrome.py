def palindrome(s):
    if s == s[::-1]: return True
    return False

class Solution:
    def shortestPalindrome(self, s: str) -> str:
        if len(s) == 1 or s == s[::-1]:
            return s

        out = ""
        for i in range(len(s)-1, -1, -1):
            out = out + s[i]
            if palindrome(out + s):
                return out + s