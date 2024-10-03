#include <iostream>
#include <vector>

using namespace std;

struct Node
{
    int data;
    Node * next;

    Node(int _data){
        data = _data;
        next = nullptr;
    }

};

Node* addNode(Node* head, int _data){
         
        Node * newNode = new Node(_data);
        if (head == nullptr) return newNode;
        else{
            Node* temp = head;
            while(temp->next != nullptr)
            {temp = temp->next;}
            temp->next = newNode;
            return head;
        }
        
    }
Node * insertNewNode(Node* head, int x, int y){
    Node * newNode = new Node(x);
    if (y == 1){
        newNode->next = head;
        return newNode;
    }
    Node * current = head;
    for (int i = 0; i < y; i++)
    {
        current = current->next;
    }
    newNode-> next = current-> next;
    current ->next = newNode;
    return head;
    
    
}

void printAll(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    delete temp;
    return;
}


int main(){
    int n, x, y;
    cin >> n;
    Node* head = nullptr;
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        head = addNode(head,temp);
    }
    cin >> x >> y;
    head = insertNewNode(head,x,y);
    printAll(head);
    
}
    
// testcase: 
// 5
// 1 3 4 2 5
// 5 3