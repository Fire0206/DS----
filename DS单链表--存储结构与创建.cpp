#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val): val(val), next(NULL) {}
};

class LinkedList {
private:
    Node* head;
    Node* tail;
public:
    LinkedList(): head(NULL), tail(NULL) {}

    // 插入到链表尾部
    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) { // 空链表
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    // 查找第 n 个节点（从 1 开始计数）
    void find(int n){
        if (n <= 0) {
            cout << "error" << endl;
            return;
        }
        Node* cur = head;
        int count = 1;
        while (cur && count < n) {
            cur = cur->next;
            count++;
        }
        if (!cur) {
            cout << "error" << endl;
        } else {
            cout << cur->val << endl;
        }
    }

    // 打印链表
    void print() const {
        Node* cur = head;
        while (cur) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

    // 析构函数，释放内存
    ~LinkedList() {
        Node* cur = head;
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
};

int main() {
    int n, val;
    cin >> n;
    LinkedList list;
    for (int i = 0; i < n; i++) {
        cin >> val;
        list.insert(val);
    }
    list.print();

    cin >> n;
    list.find(n);

    cin >> n;
    list.find(n);

    return 0;
}

