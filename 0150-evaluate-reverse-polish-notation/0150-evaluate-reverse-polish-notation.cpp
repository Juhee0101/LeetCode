class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> operators = {"+", "-", "*", "/"};
        vector<int> numList;
        int num1, num2;
        
        for (int i=0; i<tokens.size(); i++) {
            if (operators.count(tokens[i]) == 0) {
                numList.push_back(stoi(tokens[i]));
            } 
            else {
                num2 = numList.back();
                numList.pop_back();
                num1 = numList.back();
                numList.pop_back();

                if (tokens[i] == "+") {
                    numList.push_back(num1+num2);
                }
                else if (tokens[i] == "-") {
                    numList.push_back(num1-num2);
                }
                else if (tokens[i] == "/") {
                    numList.push_back(num1/num2);
                } else {
                    numList.push_back(num1*num2);
                }
            }
        }
        return numList.back();
    }
};