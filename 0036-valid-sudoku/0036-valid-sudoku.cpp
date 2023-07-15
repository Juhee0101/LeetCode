class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row
        for (int i=0; i<9; i++) {
            vector<char> boardVec = board[i];
            boardVec.erase(remove(boardVec.begin(), boardVec.end(), '.'), boardVec.end());
            set<char> numSet(boardVec.begin(), boardVec.end());
            if (boardVec.size() != numSet.size()) return false;            
        }

        // Column
        for (int j=0; j<9; j++) {
            vector<char> boardVec;
            for (int i=0; i<9; i++) {
                boardVec.push_back(board[i][j]);
            }     
            boardVec.erase(remove(boardVec.begin(), boardVec.end(), '.'), boardVec.end());
            set<char> numSet(boardVec.begin(), boardVec.end());
            if (boardVec.size() != numSet.size()) return false;            
        }

        // Square
        for (int j=0; j<9; j+=3){
            vector<char> boardVec;
            for (int i=0; i<9; i++) {
                boardVec.push_back(board[i][j]);
                boardVec.push_back(board[i][j+1]);
                boardVec.push_back(board[i][j+2]);
            }
            for (int k=0; k<boardVec.size(); k+=9) {
                vector<char> boardVec2(boardVec.begin()+k, boardVec.begin()+(k+9));
                boardVec2.erase(remove(boardVec2.begin(), boardVec2.end(), '.'), boardVec2.end());
                set<char> numSet(boardVec2.begin(), boardVec2.end());
                if (boardVec2.size() != numSet.size()) return false;                       
            }
        }
        return true;        
    }
};