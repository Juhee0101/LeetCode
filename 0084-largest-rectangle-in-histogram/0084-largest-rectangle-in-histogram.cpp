class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int cnt, prevIdx, area, width, maxArea=0;
        stack<int> idxList;

        for (int i=0; i<heights.size(); i++) {
            while (!idxList.empty() && heights[idxList.top()] > heights[i]) {
                prevIdx = idxList.top();
                idxList.pop();
                width = idxList.empty() ? i : i - idxList.top() - 1;
                area = heights[prevIdx] * width;
                // area = heights[prevIdx] * (i-prevIdx);
                maxArea = (area>maxArea? area : maxArea);
            }
            idxList.push(i);
        }
        while(!idxList.empty()){
            prevIdx = idxList.top();
            idxList.pop();
            if (!idxList.empty()) {
                area = heights[prevIdx] * (heights.size() - idxList.top() - 1);
            }
            else {
                area = heights[prevIdx] * (heights.size());
            }
            maxArea = (area>maxArea? area : maxArea);
        }
        return maxArea;
    }
};