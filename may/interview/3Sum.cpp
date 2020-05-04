// 3Sum.cpp
// https://leetcode.com/explore/interview/card/top-interview-questions-medium/103/array-and-strings/776/
/*
    *  Finding x+y+z=0 right?
    *  Fix x value, store it in a hashmap
    *  Iterate in O(n^2) for y,z and if 0-(y+z) is in hashmap, youve found the x, one of your triplet
    *  Uses extra space 
*/

#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
class Solution {
private:
    void print_triplets(vector<vector<int>> &result){
        for(int i=0;i<result.size();i++){
            vector<int> temp = result[i];
            for(int j=0; j <3 ;j++){
                std :: cout << temp[j] << " ";
            }
            std :: cout << endl;
        }
    }
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> resultSet;
        vector<vector<int>> result;
        int len = nums.size();
        for(int i=0; i<=len-2; i++){
            unordered_map<int, int> hashMap; // New hashmap for this X
            std :: cout << nums[i] << " " ;
            for(int j=i+1; j<=len-1; j++){
                int possibleX = -(nums[i] + nums[j]); // Do y+z 

                if (hashMap[possibleX]!=0){ // Found x = -(y+z) in the map
                    std :: cout << "Psobke x is "<< possibleX <<" " << nums[i]<<" " <<nums[j]<< endl;
                    vector<int> temp{possibleX, nums[i], nums[j]};
                    sort(temp.begin(), temp.end());
                    // result.push_back(temp);
                    resultSet.insert(temp);
                }
                else
                {
                    hashMap[nums[j]] = 1; // Store back in hashmap as x 
                }
                
            }
        }
        for(set<vector <int>>:: iterator it=resultSet.begin(); it!=resultSet.end(); it++){
            
            result.push_back(*it);
        }
        std :: cout << endl;
        print_triplets(result);
        return result;     
    }

};

int main(){
    vector<int> nums{1,2,-2,-1};
    Solution S;
    S.threeSum(nums);
}