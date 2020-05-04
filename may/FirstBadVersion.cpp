// FirstBadVersion.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3316/
/*
    * Cannot be compiled locally
    * 2nd May 20, 03:23
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstBadVersion(int n) {
        int left=0, right=n-1;
        int cur=0;
        while(right>=left){
            cur = (left/2)+(right/2)+(((left%2)+(right%2))/2);

            if(isBadVersion(cur+1)){ 
                if(cur==0){
                    return 1;
                }
                if(!isBadVersion(cur)){
                    return cur+1;
                }
                right = cur-1;
                

            }
            else
            {
                left = cur+1;

            }
            
        }
        return 1;

    }
};