#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) : val(x), next(NULL) {}
};


int main() {
	int t;
	cin >> t;
	while (t--) {
		int N, K, S;
		cin >> N >> K >> S;
		Node* head = new Node(1);
		Node* prev = head;
		for (int i = 2; i <= N; i++) {
			Node* node = new Node(i);
			prev->next = node;
			prev = node;
		}
		prev->next = head;

		Node* cur = head;
		Node* before = prev;
		for (int i = 1; i < S; i++) {
			before = cur;
			cur = cur->next;
		}

		while (cur->next != cur) {
			for (int i = 1; i < K; i++) {
				before = cur;
				cur = cur->next;
			}
			cout << cur->val << " ";

			before->next = cur->next;
			Node* temp = cur;
			cur = cur->next;
			delete temp;
		}
		cout << cur->val <<" "<< endl;
		delete cur;
	}
	return 0;
}