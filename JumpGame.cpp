// JumpGame.cpp
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3310/
#include<bits/stdc++.h>

using namespace std;

class DiGraph{
    void build_adjacency_matrix(vector <int>&jump_weights_by_index){
        int ad
        int len = jump_weights_by_index.size();
        int temp;
        int flag;

        /*
            //  Print out inputs for debug
            std :: cout << "Input was ";
            for(int i=0;i<len;i++){
                std:: cout << jump_weights_by_index[i] << " " ;
            }
            std ::cout <<endl;
        */
        for(int i=0; i<len;i++){
            temp = jump_weights_by_index[i];
            for(int j=0;j <i;j++){

                // std :: cout <<  0 << " " ;
                
                adj[i][j] = 0;
            }
            for(int j=i; j<len; j++){
                flag = temp>=0?1:0;
                // std :: cout <<  flag << " " ;
                adj[i][j] = flag;
                temp--;
            }
            // std :: cout << endl;
        }
    }
    public:
        int nVertices;
        int **adj;
        DiGraph(vector <int> &jump_weights){
            nVertices = jump_weights.size();
            this->adj = new int 
            // adj = adjM;
            build_adjacency_matrix(jump_weights);
        }
    



};

int main(){
    vector <int> nums {3,2,1,1,4};
    

}