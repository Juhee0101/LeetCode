class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> courseMatrix(numCourses, vector<int>(numCourses, 0));
        vector<int> numPre(numCourses, 0);
        queue<int> q;

        for (auto pre : prerequisites) {
            courseMatrix[pre[1]][pre[0]] = 1;
            numPre[pre[0]]++;
        }
        
        for (int i=0; i<numCourses; i++) {
            if (numPre[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()){
            int pre = q.front();
            q.pop();

            for (int post=0; post<numCourses; post++) {
                if (courseMatrix[pre][post] == 1) {
                    numPre[post]--;
                    if (numPre[post] == 0) {
                        q.push(post);
                    }
                }
            }                            
        }

        for (int i=0; i<numCourses; i++){
            if (numPre[i] > 0) {
                return false;
            }
        }
        return true;
    }    
};