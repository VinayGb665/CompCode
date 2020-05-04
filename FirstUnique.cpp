// FirstUnique.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3313/
#include<bits/stdc++.h>
#include<unordered_map>
#include<queue>

using namespace std;

class FirstUnique {
public:
    unordered_map<int , int> countmap;
    list <int> numq;
    FirstUnique(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++){
            add(nums[i]);
        }
    }
    
    int showFirstUnique() {
        for(std::list<int>::iterator it=numq.begin(); it!=numq.end(); it++){
            if (countmap[*it] == 1) return *it;
        }
        return -1;
    }
    
    void add(int value) {
        int res = countmap[value];
        if(res!=0){
            countmap[value]++;
            return;
        }
        countmap[value] = 1;
        numq.push_back(value);
        return;
    }
};

int main(){
    vector <int> nums{2,3,5};
    FirstUnique *obj =  new FirstUnique(nums);
    std :: cout << obj->showFirstUnique() << endl;
}
