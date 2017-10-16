/*
Given two sorted integer arrays A and B, 
merge B into A as one sorted array.

Note:
You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. 
The number of elements initialized in A and B are m andn respectively.
*/

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int count = m + n - 1;
        
        --m;
        --n;
        
        while (m >= 0 && n >=0) {
            A[count--] = (A[m] > B[n] ? A[m--] : B[n--]);
        }
        
        while (n >= 0) {
            A[count--] = B[n--];
        }
    }
};
  
        
    
