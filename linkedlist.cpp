#include <bits/stdc++.h>
using namespace std;
class Node {
    public:
        int value;
        Node *next;
};

class LinkedList {
    public:
        Node *head;
        Node *tail;
};

// void insert(LinkedList **list, int value){
//     LinkedList *temp;
    
//     Node *tail_node = *temp->tail;
//     Node newnode;
//     newnode.value = value;
//     tail_node->next = &newnode;

// }
int main(){
    LinkedList *List1;
    Node *head;
    head->value = 1;
    
    Node *tail = NULL;
    head->next = tail;
    List1->head = head;
    List1->tail = tail;
    // insert(&List1, 2);
    // printf("%d", List1->tail->value);


    
}
