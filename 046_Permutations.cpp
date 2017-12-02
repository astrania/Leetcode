/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1]
*/

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int> > res;
        vector<int> out;
        vector<int> visited(num.size(), 0);
        permuteDFS(num, 0, visited, out, res);
        return res;
    }
    
    void permuteDFS(vector<int> &num, int level, vector<int> &visited, vector<int> &out, vector<vector<int> > &res) {
        if (level == num.size()) res.push_back(out);
        
        else {
            for (int i = 0; i < num.size(); ++i) {
                if (visited[i] == 0) {
                    visited[i] = 1;
                    out.push_back(num[i]);
                    
                    permuteDFS(num, level + 1, visited, out, res);
                    
                    out.pop_back();
                    visited[i] = 0;
                }
            }
        }
    }
};
