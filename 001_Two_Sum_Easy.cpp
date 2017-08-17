/*
 *Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 *You may assume that each input would have exactly one solution.
 *Example:
 *Given nums = [2, 7, 11, 15], target = 9,
 *Because nums[0] + nums[1] = 2 + 7 = 9,
 *return [0, 1].
 *Tag: Array, Hash Table
 */
 
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> indexResults;
        unordered_map<int, int> index_map;
        unordered_map<int, int>::iterator it;
        for (int i=0; i<numbers.size(); ++i) {
            it = index_map.find(target-numbers[i]);
            if (it != index_map.end()) {
                indexResults.push_back(it->second);
                indexResults.push_back(i);
                return indexResults;
            } else {
                index_map[numbers[i]] = i;
            }
        }
        return indexResults;
    }
};
