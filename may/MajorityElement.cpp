// MajorityElement.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3321/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hashMap;
        int count = int(nums.size()/2);
        for(int i=0;i< nums.size(); i++){
            hashMap[nums[i]]++;
            if (hashMap[nums[i]]>count){
                return nums[i];
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums{2,2,1,1,1,2,2};
    vector<int> nums2{3,2,3};
    Solution S;
    std :: cout << "Majority element is " << S.majorityElement(nums) << endl;
    std :: cout << "Majority element is " << S.majorityElement(nums2) << endl;
}