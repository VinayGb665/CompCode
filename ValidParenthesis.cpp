#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        stack <char> st; 
        int counter = 0;
        int StarCounter = 0;
        bool checkValidString(string s){
            for(int i=0; i < s.size(); i++){
                if (s[i] == '('){
                    st.push('(');
                    // counter ++;
                }
                else if (s[i] == ')')
                {   
                    if (!st.empty()) {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                    
                }
                else
                {
                    st.push(s[i]);
                    // StarCounter++;
                }
                
            }
            while(!st.empty() && st.top()=="*"){
                st.pop();
                // StarCounter--;
            }
            std:: cout << st.empty() << " " << counter << " " << StarCounter << endl; 
            if(st.empty()){
                return true;
            }
            return false;
        }
};

int main(){
    string axa = "())";
    bool a;
    Solution S;
    a= S.checkValidString(axa);
    std :: cout << a << endl;

}