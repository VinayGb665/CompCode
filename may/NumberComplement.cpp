// NumberComplement.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findComplement(int num) {
        int temp =num;
        int result = 0;
        int k;
        int resArr[32] = {0};
        int count = 32;
        int flag =  0;
        while(count>0){
            count--;
            k = temp >> count;
            if (k&1){
                std :: cout << 1;
                flag = 1;
            }
            else{
                std:: cout << 0;
                if (flag==1){
                    resArr[count] = 1;
                }
            }
            
            // temp = temp>>1;
            // std :: cout << k ;
        }
        std :: cout << endl;
        for(int i=0;i<32;i++){
            if(resArr[i]==1){
                result += pow(2, i);
            }
            std :: cout << resArr[i] ;
        }
        std ::cout << endl;
        std :: cout << result << endl;
        return result;
    }
};

int main(){
    int number=1;
    Solution S;
    S.findComplement(number);

}