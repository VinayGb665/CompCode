// LRUcache->cpp 
// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/531/week-4/3309/
#include<bits/stdc++.h>
#include <unordered_map> 
using namespace std;
struct Node
{
    /* data */
    int data;
    struct Node *next;
    struct Node *prev;
};

class DLL{

    private:
        Node *create_node(int value){
            struct Node *temp;
            temp = new(struct Node); 
            temp->next = NULL;
            temp->prev = NULL;
            temp->data = value;
            return temp;
        }

        void print_dll(){
            struct Node *temp = head;
            while(temp->next!=NULL){
                std :: cout << temp->data << " "; 
                temp = temp->next;
                // break;
            }
            std :: cout << temp->data << endl;
        }

    public:
        int size = 0;
        int max_size;
        Node *head;
        Node *tail;
        DLL(int capacity=10){
            max_size = capacity;    
        }
        void insertBeginning(int value){
            if (size == 0){
                Node *newNode = create_node(value);
                head = newNode;
                tail = newNode;

                size++;
                return;
            }
            struct Node *newNode = create_node(value);
            struct Node *temp = head;
            // std :: cout << "Inserting before head value " << temp->data << endl;
            newNode->next = temp;
            newNode->prev =  NULL;
            head->prev = newNode;
            head = newNode;
            size++;
            
        }
        
        int get_current_size(){
            return size;
        }

        void find_and_move_to_start(int key, int move=1){
            // if (nodeNumber > size) return;
            struct Node *movingPointer = head;
            int count = 0;
            std :: cout << "Head is " << head->data << " Ddata is " <<key <<endl;
            // First element was the key
            if (movingPointer->data == key) return;

            while(movingPointer->next!=NULL && movingPointer->next->data!=key){    
                movingPointer = movingPointer->next;
                count++;
            }
            
            struct Node *requiredNodePointer;
            if (movingPointer->next == NULL  ){
                if(movingPointer->data ==key){
                    requiredNodePointer = movingPointer;
                    tail = movingPointer->prev;
                }
                else{
                    std :: cout << "Arye foo";
                    return ;
                }
                
            }
            else{
                // -- Delete -- 
                requiredNodePointer = movingPointer->next;
                // std :: cout << requiredNodePointer->data << endl;
                // Changing next node's previous to current
                if (requiredNodePointer!=NULL && requiredNodePointer->next != NULL) requiredNodePointer->next->prev =  movingPointer;
                else if (requiredNodePointer->next == NULL)
                {
                    /* code */
                    tail = requiredNodePointer->prev;
                }
                
                // Changing current node's next to next
                movingPointer->next = requiredNodePointer->next;
        
            }
                      
            if(move==1) {
                // Move flag is 0, delete the key
                std :: cout << "Removing old key to update" << key << endl;
                // delete requiredNodePointer;
                // size--;
                // return;
            }

            // -- Move to start --
            struct Node *temp = head;
            requiredNodePointer->next = temp;
            requiredNodePointer->prev = NULL;
            temp->prev = requiredNodePointer;
            head = requiredNodePointer;

        }
        int delete_last(){ // returns the key deleted
            std :: cout << "Evicting with LRU " << size << endl;
            
            if (size==1){
                
                struct Node *temp = head;
                int key = head->data;
                delete temp;
                size--;
                return key;
                
            }
            else{
                std :: cout << "Evicting with LasdRU " << size << endl;

                struct Node *temp = tail;
                
                int data = temp->data;
                // std :: cout << "Asasa" << data ;
                tail = temp->prev;
                temp->prev->next = NULL;
                delete temp;
                size--;
                return data;
            }
            return -1;
        }
        
};
class LRUCache {
    private:
        void pre_put_things(int key, int value){
            /*
                * Handles the LRU eviction things
            */
            // std :: cout << "put " << backingList.get_current_size() << maxCapacity << endl;
            // Check if already there, evict the key first then add new value
            // if (pageTable[key]!=0) backingList.find_and_move_to_start(key, 1);
            
            // Check if capacity of the frame, evict if full
            if (backingList.get_current_size() >= maxCapacity) {
                int deletedKey = backingList.delete_last();
                pageTable.erase(deletedKey);

            }

            backingList.insertBeginning(key);
        }
    public:
        unordered_map<int , int> pageTable;
        DLL backingList;
        int maxCapacity;
        LRUCache(int capacity) {
            std :: cout << capacity << endl;
            maxCapacity = capacity;
        }
        
        int get(int key) {
            int res = pageTable[key];
            if (res!=0){
                // Value was found, move up
                backingList.find_and_move_to_start(key);
            }
            else res = -1; // Send as -1 
            std :: cout <<"Get value =" << res <<endl;
            return res;
        }
        
        void put(int key, int value) {
            pre_put_things(key, value);
            pageTable[key] = value;
        }

};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(){
    LRUCache* cache = new LRUCache(2);
    cache->put(2, 1);
    cache->put(1, 1);    // evicts key 2
    cache->put(2, 3);
    cache->get(1);       // returns 1
    // cache->get(2);       // returns -1 (not found)
    cache->put(1, 2);    // evicts key 1
    // cache->get(1);       // returns -1 (not found)
    // cache->get(3);       // returns 3
    // cache->get(4);       // returns 4
    
    // DLL dlist;
    // dlist.insertBeginning(1);
    // dlist.insertBeginning(2);
    // dlist.insertBeginning(3);
    // dlist.print_dll();
    // dlist.find_and_move_to_start(1);
    
    // dlist.print_dll();
    // dlist.insertBeginning(4);
    // std :: cout << dlist.delete_last() << endl;
    // dlist.print_dll();
}   