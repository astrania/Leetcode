/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), 
prove that at least one duplicate element must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:

    You must not modify the array (assume the array is read only).
    You must use only constant extra space.
    Your runtime complexity should be less than O(n2).
*/

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) * 0.5;
            int cnt = 0;
            for (auto a : nums) {
                if (a <= mid) ++cnt;
            }
            if (cnt <= mid) low = mid + 1;
            else high = mid;
        }
        return low;
    }
};
