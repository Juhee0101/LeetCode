class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mSize = matrix.size();
        vector<int> array;
        int idx = 0;

        for (int col=0; col<mSize; col++) {
            for (int row=mSize-1; row>=0; row--){
                array.push_back(matrix[row][col]);
            }
        }

        for (int row=0; row<mSize; row++) {
            for (int col=0; col<mSize; col++) {
                matrix[row][col] = array[idx];
                idx++;
            }
        }
    }
};