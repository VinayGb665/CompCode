// RemoveKdigits.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3328/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string removeKdigits(string num, int k) {
        int currentMaxIndex;
        int temp;
        for(int j=0; j<k ; j++){
            currentMaxIndex = 0;
            for(int i=0; i<num.size(); i++){
                if (int(num[i])>=int(num[currentMaxIndex])){
                    currentMaxIndex = i;
                }
                else{
                    break;
                }
            }
            std :: cout << "Found mAx to be " << num[currentMaxIndex] << endl;  
            num.erase(currentMaxIndex,1);
            
            // Remove trailing zeroes
            if(num.size()>0){
                temp = int(num[0]-'0');
                std :: cout << "Fukin" << temp << endl;
                while(temp==0){
                    num.erase(0,1);
                    temp = int(num[0]-'0');
                }
            }
        }
        if(num==""){
            return "0";
        }
        return num;   
    }
};

int main(){
    string f ="10200";
    Solution S;
    S.removeKdigits(f, 1);

}