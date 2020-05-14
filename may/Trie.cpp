// Trie.cpp
// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3329/

#include<bits/stdc++.h>
using namespace std;

class Trie {

    public:
        struct TrieNode
        {
            TrieNode* children[26];
            int leaf;
        };
        TrieNode *root;
        Trie() {
            root = getNewNode();
        }
        
        /** Inserts a word into the trie. */
        void insert(string word) {
            
            TrieNode* temp = root;
            int indexCount;

            for(int i=0; i<word.size(); i++){
                indexCount = word[i] - 'a';

                if(temp->children[indexCount] == nullptr){
                    temp->children[indexCount] = getNewNode();
                }

                temp = temp->children[indexCount];
            }
            temp->leaf = 1;
        }
        
        // /** Returns if the word is in the trie. */
        bool search(string word, int full=1) {

            TrieNode* temp = root;
            int indexCount;

            for(int i=0; i<word.size(); i++){
                indexCount = word[i] - 'a';

                if(temp->children[indexCount] == nullptr){
                    std :: cout << "Failed to find char "<< word[i] << endl;
                    return false;
                }

                temp = temp->children[indexCount];
            }

            if(full==1 && temp->leaf!=1){
                std :: cout << "Hengo hudkidvi adre waste nan maga full word alla" << endl;
                return false;
            }

            std :: cout << "Hengo hudkidvi" << endl;
            return true;
        }
        
        // /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(string prefix) {
            return search(prefix, 0);   
        }
    
    private:
        TrieNode* getNewNode(){
            TrieNode *newNode = new TrieNode();

            // Init all children to null
            for(int i=0; i<26; i++){
                newNode->children[i] = nullptr;
            }

            // Set leaf to be false
            newNode->leaf = 0;
            return newNode;
        }

};

static auto fastio = [](){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return nullptr;
}();

int main(){
    Trie *t1 = new Trie();
    t1->insert("apple");
    t1->search("app");
    t1->startsWith("app");
    
}