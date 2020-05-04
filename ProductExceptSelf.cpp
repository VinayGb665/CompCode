// ProductExceptSelf.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/530/week-3/3300/
using namespace std;
#include <bits/stdc++.h>
#include <limits.h>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int len = nums.size();
        for(int i=0;i <len; i++){
            product = product * (nums[i]);
        }
        std :: cout << "Product : " <<product << endl;
        std :: cout << "Individual : ";
        for(int i=0;i <len; i++){
            nums[i]=product/nums[i];
            std :: cout << nums[i] << " ";
        }


        return nums;
    }
};

int main() {
    vector <int> nums{5,7,2,4};
    Solution S;
    S.productExceptSelf(nums);
}