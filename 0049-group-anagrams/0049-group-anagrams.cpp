class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        vector<vector<string>> result;

        for (string str:strs) {
            string str_key = str;

            sort(str_key.begin(), str_key.end());
            if (mp.find(str_key) == mp.end()){
                vector<string> vec{str};
                mp.insert(make_pair(str_key, vec));
            }
            else {
                mp[str_key].push_back(str);
            }
        }
        
        for (auto m : mp) {
            result.push_back(m.second);
        } 

        return result;        
    }
};

// int main(void) {
//     vector<string> strs = {"eat","tea","tan","ate","nat","bat"};

//     // Solution()
// }