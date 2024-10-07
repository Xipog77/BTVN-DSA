#include <iostream>

// Sử dụng Linked-list.
//struct Queue
//{
//private:
//	int data;
//	Queue* next;
//
//public:
//	Queue(int d) {
//		data = d;
//		next = NULL;
//	}
//
//	Queue* add(int d, Queue* head) {
//		Queue* newQueue = new Queue(d);
//		if (head == NULL) return newQueue;
//		Queue* current = head;
//		while (current->next != NULL) {
//			current = current->next;
//		}
//		current->next = newQueue;
//		return head;
//	}
//
//	Queue* remove(Queue* head) {
//		Queue* temp = head;
//		head = head->next;
//		delete temp;
//		return head;
//	}
//
//	void get() {
//		cout << data << endl;
//	}
//};
// ----

// Sử dụng Array.
//struct Queue
//{
//private:
//	int head = 0;
//	int tail = 0;
//	int size = 0;
//	int arr[100];
//public:
//	void add(int v) {
//		if (size == 100) {
//			cout << "Queue is full!" << endl;
//			return;
//		}
//		arr[tail++] = v;
//		size++;
//		if (tail == 100) tail = 0;
//	}
//
//	void remove() {
//		if (size == 0) {
//			cout << "Queue is empty!" << endl;
//			return;
//		}
//		head++;
//		size--;
//		if (head == 100) head = 0;
//	}
//
//	void printAll() {
//		int i = head;
//		while (i != tail)
//		{
//			cout << arr[i++] << endl;
//			if (i == 100) i = 0;
//		}
//		return;
//	}
//};
// ----