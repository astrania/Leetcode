/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBST(nums, 0, nums.size()-1);
    }
    
    TreeNode *sortedArrayToBST(vector<int> &nums, int left, int right) {
        if(left > right) return NULL;
        
        int mid = (left + right) / 2;
        
        TreeNode *cur = new TreeNode(nums[mid]);
        cur->left = sortedArrayToBST(nums, left, mid-1);
        cur->right = sortedArrayToBST(nums, mid + 1, right);
        
        return cur;
    }
};
