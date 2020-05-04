// rangeBitwiseAnd.cpp 
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3308/
#include<bits/stdc++.h>
using namespace std;

#include <cmath>
class Solution {
public:
    int Checker(int m, int n) {
        int base1, base2;
        base1 = 0;
        base2 = 0;
        if (m==0) base1 =1;
        else while (m >>= 1) ++base1;
        if (n==0) base2 =1; 
        else while (n >>= 1) ++base2;
        if (base2 == base1){
            std :: cout << int(pow(2,base1)) << endl;
        }
        else{
            std:: cout << 0 << endl;
        }
        
    }
    int rangeBitwiseAnd(int m, int n){
        if (Checker(m,n) == 0 ){
            return 0;
        }
        int res;
        res = m & m+1;
        for(int i= m+1; i<n; i++){
            res = res & (i+1);
        }
        std :: cout << res << endl;
    }
};

int main(){
    Solution S;
    int a = 9;
    int b = 11;
    S.rangeBitwiseAnd(a,b);
    S.rangeBitwiseAnd1(a,b);
}