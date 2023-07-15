class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int left = 0, right = row*col-1, mid, mid_val;

        if (target < matrix[0][0] || target > matrix[row-1][col-1]) return false;

        while (left <= right) {
            mid = (left + right) / 2;
            mid_val = matrix[mid/col][mid%col];
            if (target == mid_val) return true;
            else if (target < mid_val) right = mid - 1;
            else left = mid + 1;
        }
        return false;
    }
};