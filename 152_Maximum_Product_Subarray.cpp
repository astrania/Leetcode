/*
Find the contiguous subarray within an array (containing at least one number) which has the largest product.

For example, given the array [2,3,-2,4],
the contiguous subarray [2,3] has the largest product = 6. 
*/


int maxProduct(vector<int>& nums) {
        if (nums.size() < 0) return 0;
        int size = nums.size();
        
        int *maxarray = new int[size];
        int *minarray = new int[size];
        maxarray[0] = nums[0];
        minarray[0] = nums[0];
        int result = nums[0];
        
        for (int i = 1; i < size; i++)
        {
            maxarray[i] = std::max(std::max(maxarray[i-1]*nums[i], minarray[i-1]*nums[i]), nums[i]);
            minarray[i] = std::min(std::min(maxarray[i-1]*nums[i], minarray[i-1]*nums[i]), nums[i]);
            
            result = std::max(maxarray[i], result);
        }
        return result;
        
        delete[] maxarray;
        delete[] minarray;  
    }
