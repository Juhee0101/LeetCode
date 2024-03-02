class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        # 문자의 처음과 마지막 위치를 저장하는 사전
        char_indices = {}
        for i, char in enumerate(s):
            if char not in char_indices:
                char_indices[char] = [i, i]
            else:
                char_indices[char][1] = i

        resultSet = set()
        # 각 문자에 대해
        for char, (start, end) in char_indices.items():
            if start < end:  # 최소한 하나의 중간 문자가 있을 때
                # 중간 문자들을 집합으로 변환하여 유니크한 문자만 남김
                unique_chars = set(s[start+1:end])
                for mid_char in unique_chars:
                    resultSet.add(char + mid_char + char)

        return len(resultSet)
