class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;
        
        while (true){
            int val = numbers[left] + numbers[right];
            if (val == target) {
                return {left+1, right+1};
            }
            else if (val < target) {
                left++;
            }
            else {
                right--;
            }
        }
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         vector<int> result(2, -2000);
//         int num1, num2, remain, left, right, mid;

//         for (int i=0; i<numbers.size(); i++) {
//             remain = target - numbers[i];
//             left = i+1;
//             right = numbers.size()-1;

//             while (left <= right) { 
//                 mid =(left+right) / 2;
//                 if (remain == numbers[mid]) {
//                     result = {i+1, mid+1};
//                     break;
//                 }
//                 else if (remain > numbers[mid]) {
//                     left = mid + 1;
//                 }
//                 else {
//                     right = mid - 1;
//                 }
//             }
//         }
//         return result;
//     }
// };