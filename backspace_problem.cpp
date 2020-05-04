// backspace_problem.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/

#include <iostream>
#include <string>
#include <string.h>

using namespace std;


void modify_str(string& myString){
    myString.append("O");
    // std :: cout << "--------\n" ;
    char c = '#';
    int index =0;
    int length = myString.size();
    int i = 0;
    // Delete the character before backspace
    for( i; i< length;){
        // std :: cout << i << " " << myString << endl;
        if(myString[i] == c ){

            if (i!=0) {
                myString.erase(i-1, 2); 
                i -=2;
                i = max(0, i);
            }
            else{
                // std :: cout << "Zerp";
                myString.erase(0, 1);
                i = 0;
            }
            // std :: cout << '\t' << myString << " Aftewr " << i << " "<< myString[i] << length  << endl;    
        } 
        else{
            i ++;
        }
    }
// std :: cout << " " << i << "--------\n" ;
}

int main() {
    std::string b = "y#fo##f";
    std::string a = "y#f#o##f";
    int index = 0;
    char c = '#';
    modify_str(b);
    modify_str(a);
    if (a.compare(b) != 0){
        // std :: cout << "Faalse" << '\n';
        return false;
    }
    else{
        // std :: cout << "True" << '\n';
    }
    return true;
    
    std:: cout << b <<'\n';
    std:: cout << a <<'\n';
    return 0;
}
