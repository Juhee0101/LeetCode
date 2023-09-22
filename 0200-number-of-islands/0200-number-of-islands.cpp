class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        int nRow = grid.size();
        int nCol = grid[0].size();
        int result = 0;
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(nRow, vector<bool>(nCol, 0));

        for (int i=0; i<nRow; i++) {
            for (int j=0; j<nCol; j++) {
                if (visited[i][j] == 1) {
                    continue;
                }
                else if (grid[i][j] == '0') {
                    visited[i][j] = 1;
                    continue;
                }
                else {
                    visited[i][j] = 1;
                    q.push(make_pair(i,j));

                    while (!q.empty()) {
                        int rowIdx = q.front().first;
                        int colIdx = q.front().second;
                        q.pop();

                        neighborCheck(grid, visited, q, rowIdx, colIdx-1);
                        neighborCheck(grid, visited, q, rowIdx, colIdx+1);
                        neighborCheck(grid, visited, q, rowIdx-1, colIdx);
                        neighborCheck(grid, visited, q, rowIdx+1, colIdx);
                    }
                    result++;
                }
            }
        }
        return result;
    }
private:
    void neighborCheck(vector<vector<char>> &grid, vector<vector<bool>> &visited, queue<pair<int, int>> &q, int rowIdx, int colIdx) {
        if (rowIdx >= 0 && rowIdx < grid.size() && colIdx >= 0 && colIdx < grid[0].size()) {
            if (visited[rowIdx][colIdx] == 0) {
                visited[rowIdx][colIdx] = 1;
                if (grid[rowIdx][colIdx] == '1') {
                    q.push(make_pair(rowIdx, colIdx));
                }
            }
        }
    }
};