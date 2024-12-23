#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Lặp:
// SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
//     if (llist == nullptr) return nullptr;
//     else if (llist->next == nullptr) return llist;
//     else if (llist->next->next == nullptr) {
//         SinglyLinkedListNode* A = llist->next;
//         A->next = llist;
//         llist->next = nullptr;
//         return A;
//     }
//     else {
//         SinglyLinkedListNode* A = llist; 
//         SinglyLinkedListNode* B = A->next;
//         SinglyLinkedListNode* C = B->next;
//         llist->next = nullptr;
//         while (C->next != nullptr) {
//             B->next = A;
//             A = B;
//             B = C;
//             C = C->next;
//         }
//         B->next = A;
//         C->next = B;
//         return C;
//     }
// }
// ---


// Đệ quy
// SinglyLinkedListNode* reverse(SinglyLinkedListNode* llist) {
//     if (llist == nullptr) return nullptr;
//     SinglyLinkedListNode* current = llist->next;
//     SinglyLinkedListNode* head;
//     if (current->next == nullptr){
//         current->next = llist;
//         return current;
//     }
//     head = reverse(current);
//     current->next = llist;
//     llist->next = nullptr;
//     return head;
// }
//  ---

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist = new SinglyLinkedList();

        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist->insert_node(llist_item);
        }

        SinglyLinkedListNode* llist1 = reverse(llist->head);

        print_singly_linked_list(llist1, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist1);
    }

    fout.close();

    return 0;
}
