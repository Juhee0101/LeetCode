class Solution:
    def shortestPalindrome(self, s: str) -> str:
        idx = len(s)-1
        pre = ""

        while True:
            if pre+s == (pre+s)[::-1]:
                return pre+s
            pre = pre + s[idx]
            idx -= 1