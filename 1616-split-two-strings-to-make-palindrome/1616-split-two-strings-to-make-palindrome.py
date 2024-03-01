class Solution:
    def checkPalindromeFormation(self, a: str, b: str) -> bool:        
        return self.isPalindrome(a, b) or self.isPalindrome(b, a)

    
    def isPalindrome(self, s1: str, s2: str) -> bool:
        i, j = 0, len(s1)-1

        while (i < j):
            if s1[i] != s2[j]:
                break
            i += 1
            j -= 1
        
        sub_s1 = s1[i:j+1]
        sub_s2 = s2[i:j+1]

        return (sub_s1 == sub_s1[::-1]) or (sub_s2 == sub_s2[::-1])