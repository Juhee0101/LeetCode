class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int freshOrange = 0;
        int result = 0;
        queue<pair<int, int>> q;

        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshOrange++;
                }
            }
        }
        
        if (freshOrange == 0 && q.size() == 0) {
            return 0;
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            int qSize = q.size();
            for (int size = 0; size < qSize; size++) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (auto dir : dirs) {
                    int newI = i + dir.first;
                    int newJ = j + dir.second;

                    if (newI >= 0 && newI < grid.size() && newJ >= 0 && newJ < grid[0].size() && grid[newI][newJ] == 1) {
                        grid[newI][newJ] = 2;
                        freshOrange--;
                        q.push({newI, newJ});
                    }
                }
            }
            result++;
        }
        
        return (freshOrange == 0)? result - 1 : -1;        
    }
};