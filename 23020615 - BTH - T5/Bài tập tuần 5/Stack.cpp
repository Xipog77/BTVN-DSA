#include "Header.h"

using namespace std;

//struct Stack
//{
//	private:
//		int Data;
//		Stack* next;
//	public:
//		Stack(int d) {
//			Data = d;
//			next = NULL;
//		}
//		Stack* add(int d, Stack* head) {
//			 Stack* newStack = new Stack(d);
//			 newStack->next = head;
//			 return newStack;
//		}
//		Stack* remove(Stack* head) {
//			Stack* temp = head;
//			cout << head->Data << endl;
//			head = head->next;
//			delete temp;
//			return head;
//		}
//};

struct Stack
{
private:
	int arr[100];
	int top = 0;
public:
	void add(int d) {
		if (top > 100) {
			cout << "Stack is full!" << endl;
			return;
		}
		arr[top] = d;
		top++;
	}
	void remove() {
		if (top == 0) {
			cout << "Nothing in Stack" << endl;
			return;
		}
		top--;
		arr[top] = NULL;
	}
	void get() {
		cout << arr[top - 1] << endl;
	}
};