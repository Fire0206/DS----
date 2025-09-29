#include<iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int x) :val(x), next(nullptr) {}
};

Node* LinkedList(int n) {
	Node* dummyhead = new Node(0);
	Node* cur = dummyhead;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		cur->next = new Node(val);
		cur = cur->next;
	}
	return dummyhead;
}

Node* Delete(Node* dummyhead) {
	Node* first = dummyhead->next;
	while (first != nullptr && first->next != nullptr) {
		Node* pre = first;
		Node* cur = first->next;

		while (cur != nullptr) {
			if (cur->val == first->val) {
				Node* temp = cur;
				pre->next = cur->next;
				cur = cur->next;
				delete temp;
			}
			else {
				pre = cur;
				cur = cur->next;
			}
		}

		first = first->next;
	}
	return dummyhead;
}

void print(Node* head) {
	int len = 0;
	Node * cur = head->next;
	while(cur!= nullptr) {
		len++;
		cur = cur->next;
	}
	cout << len << ":";
	cur = head->next;
	while (cur != nullptr) {
		cout << " " << cur->val;
		cur = cur ->next;
	}
	cout << endl;
}

void free(Node* head) {
	Node* cur = head;
	while (cur != nullptr) {
		Node* temp = cur;
		cur = cur->next;
		delete temp;
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		Node* head = LinkedList(n);
		print(Delete(head));
		free(head);
	}
	return 0;
}