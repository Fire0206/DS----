#include<iostream>
using namespace std;
struct Node {
	int val;
	Node* next;
public:
	Node(int val):val(val),next(nullptr){}
};
int main() {
	int n,a1;
	cin >> n>>a1;
	Node* head = new Node(a1);
	Node* cur = head;
	for (int i = 1; i < n; i++) {
		cin >> a1;
		cur->next = new Node(a1); // 修正：创建新节点并连接
		cur = cur->next;
	}
	cur = head;
	for (int i = 0; i < n; i++) {
		cout << cur->val << " "; // 可选：输出空格分隔
		cur = cur->next;
	}
	return 0;
}