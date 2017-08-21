/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
the contiguous subarray [4,-1,2,1] has the largest sum = 6
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int size = nums.size();
        int *sum = new int[size];
        int max = nums[0];
        sum [0] = nums[0];
        
        for(int i = 1; i < size; i++)
        {
            sum[i] = std::max(sum[i-1] + nums[i], nums[i]);
            if (sum[i] > max) max = sum[i];
        }
        delete[] sum;
        
        return max;
    }
};
