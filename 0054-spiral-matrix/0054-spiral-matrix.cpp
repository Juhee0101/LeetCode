class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowLen = matrix.size();
        int colLen = matrix[0].size();
        int minRow = 0, maxRow = rowLen-1, minCol = 0, maxCol = colLen-1;
        int idx = 0;
        string turnRC = "row", turnMM = "min";
        vector<int> output(rowLen * colLen, -1000);

        while (output[rowLen * colLen - 1] == -1000) {
            if (turnRC == "row") {
                if (turnMM == "min") {
                    for (int i=minCol; i<=maxCol; i++){
                        output[idx] = matrix[minRow][i];
                        idx++;
                    }
                    minRow++;
                    turnMM = "max";
                } else {
                    for (int i=maxCol; i>=minCol; i--) {
                        output[idx] = matrix[maxRow][i];
                        idx++;
                    }
                    maxRow--;
                    turnMM = "min";
                }
                turnRC = "col";
            }
            else { // turnRC == "col"
                if (turnMM == "min") {
                    for (int i=maxRow; i>=minRow; i--){
                        output[idx] = matrix[i][minCol];
                        idx++;
                    }
                    minCol++;
                } else {
                    for (int i=minRow; i<=maxRow; i++) {
                        output[idx] = matrix[i][maxCol];
                        idx++;
                    }
                    maxCol--;
                }
                turnRC = "row";
            }
        }
        return output;
    }
};