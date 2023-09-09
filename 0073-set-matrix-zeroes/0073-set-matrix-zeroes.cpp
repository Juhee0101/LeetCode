class Solution {
public: 
    void setZeroes(vector<vector<int>> &matrix) {
        int numRow = matrix.size(), numCol = matrix[0].size();
        vector<int> rowIdx, colIdx;

        for (int i=0; i<numRow; i++) {
            for (int j=0; j<numCol; j++) {
                if (matrix[i][j] == 0) {
                    rowIdx.push_back(i);
                    colIdx.push_back(j);
                }
            }
        }

        for (int row : rowIdx) {
            for (int j=0; j<numCol; j++) {
                matrix[row][j] = 0;
            }
        }

        for (int col : colIdx) {
            for (int i=0; i<numRow; i++) {
                matrix[i][col] = 0;
            }
        }
    }
};