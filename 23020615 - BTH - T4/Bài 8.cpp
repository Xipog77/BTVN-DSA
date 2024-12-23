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
 
// hàm kiểm tra
// bool check(SinglyLinkedListNode* node1, SinglyLinkedListNode* node2) {
//     if (node1->data != node2->data) return true;
//     if (((node1->next == nullptr && node2->next != nullptr) || (node2->next == nullptr && node1->next != nullptr))) return true;
//     return false;
// }

// Lặp
// bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//     SinglyLinkedListNode* list1 = head1;
//     SinglyLinkedListNode* list2 = head2;
    
//     if (check(list1, list2)) return false;
    
//     while (list1 != nullptr && list2 != nullptr) {
//         if (check(list1, list2)) return false;
//         list1 = list1->next;
//         list2 = list2->next;
//     }
//     return true;
// }
// ---

// Đệ quy
// bool compare_lists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
//     if (head1 == nullptr && head2 == nullptr) return true;
//     SinglyLinkedListNode* list1 = head1;
//     SinglyLinkedListNode* list2 = head2;
//     if (check(list1, list2)) return false;
//     return compare_lists(list1->next, list2->next);
// }
//  ---

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        bool result = compare_lists(llist1->head, llist2->head);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
