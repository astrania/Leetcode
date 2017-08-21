class Solution {
    public:
    int lengthOfLIS(vector<int>& nums) {
        int max = 1;
        int size = nums.size();
        int *lengthArray = new int[size];
        
        for (int i = 0; i < size; i++)
        {
            lengthArray[i] = 1;
            for (int j = 0; j < i; j++)
            {
                if(nums[j] <= nums[i] && lengthArray[j] + 1 > lengthArray[i] )
                {
                    lengthArray[i] = lengthArray[j] + 1;
                }
                if (lengthArray[i] > max) 
                {
                    max = lengthArray[i];
                }
            }
        }
        delete[] lengthArray;
        
        return max;
    }
};
