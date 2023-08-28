class Solution:
    def lengthOfLIS(self, nums: list[int]) -> int:
        result = [1] * len(nums)
        prevIdx = [-1] * len(nums)

        searchIdx = [0]

        for i in range(1, len(nums)):
            for j in searchIdx:
                idx = j
                while nums[idx] >= nums[i] and prevIdx[idx] != -1:
                    idx = prevIdx[idx]
                if nums[idx] < nums[i] and result[i] < result[idx] + 1:
                    result[i] = result[idx] + 1
                    prevIdx[i] = idx

            if prevIdx[i] in searchIdx:
                searchIdx.remove(prevIdx[i])

            searchIdx += [i]

        return max(result)