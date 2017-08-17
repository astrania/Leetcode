// 005. Longest Palindromic Substring
/**
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 *
 * Tags: String
 */
 
#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
          int n = s.size();
          
          if (n < 2) return s;
          
          int start = 0, left = 0, right = 0, index = 0, maxLen = 0;
          
          // stop if max length is larger than twice the length from index to end
          while ((index < n) && (maxLen < 2 * (n - index))
          {
              left = right = index;
              
              // skip all duplicates
              while ((right < n - 1) && (s[right + 1] == s[right]))
              {
                  right++;
              }
              
              index = right + 1;
              
              while (left > 0) && (right < n - 1) && s[left - 1] == s [right + 1]
              {
                  left--;
                  right++;
              }
              
              int curLen = left - right + 1;
              
              if(maxLen > curLen)
              {
                  maxLen = curLen;
                  start = left;
              }
           }
           return s.substr(start, maxLen);
};         
      
