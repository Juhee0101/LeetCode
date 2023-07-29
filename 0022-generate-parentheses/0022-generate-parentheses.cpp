class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        stack<string> back;
        string caseString;
        getAllCases(n, caseString, output, back);

        return output;
    }
private:
    void getAllCases(int n, string &caseString, vector<string> &output, stack<string> &back) {
        if (n==0 && back.empty()) {
            output.push_back(caseString);
            return;
        }
        else if (n>0 && back.empty()) {
            caseString += "(";
            back.push(")");
            getAllCases(n-1, caseString, output, back);
            caseString.pop_back();
            back.pop();
        } 
        else if (n==0 && !back.empty()) {
            caseString += ")";
            back.pop();
            getAllCases(n, caseString, output, back);
            caseString.pop_back();
            back.push(")");
        }
        else {
            caseString += "(";
            back.push(")");
            getAllCases(n-1, caseString, output, back);
            caseString.pop_back();
            back.pop();

            caseString += ")";
            back.pop();
            getAllCases(n, caseString, output, back);
            caseString.pop_back();
            back.push(")");
        }
    }
};