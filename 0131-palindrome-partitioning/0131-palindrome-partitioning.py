class Solution:

    def isPalindrome(self, s: str) -> bool:
        """
        주어진 문자열이 Palindrome인가?
        """
        return s == s[::-1]

    # 어떤 str에 대한 모든 분할을 담은 list return
    def getSublists(self, s: str, start: int, path: list, results: list) -> None:
        """
        Generate all palindromic partitions of s starting from 'start' and add them to 'results'.
        'path' keeps the current partition.
        """
        # If we've reached the end of the string, add the current partition to the results
        if start == len(s):
            results.append(path[:])
            return

        for end in range(start + 1, len(s) + 1):
            # If the current segment is a palindrome, recurse with this segment added to the path
            if self.isPalindrome(s[start:end]):
                self.getSublists(s, end, path + [s[start:end]], results)


    def partition(self, s: str) -> List[List[str]]:
        self.getSublists(s, 0, [], results:=[])
        return results