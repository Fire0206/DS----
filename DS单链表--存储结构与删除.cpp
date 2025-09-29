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
    

    // 删除第 n 个节点（n从1开始计数）
    bool removeAt(int n) {
        if(n <= 0 || !head) {
            cout << "error" << endl;
            return false;
        }

        // 删除头节点
        if(n == 1) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
            if(!head) tail = NULL; // 如果链表空了
            return true;
        }

        // 找到第 n-1 个节点
        Node* cur = head;
        for(int i = 1; i < n - 1; i++) {
            cur = cur->next;
            if(cur == NULL || cur->next == NULL) {
                cout << "error" << endl;
                return false;
            }
        }

        Node* toDelete = cur->next;
        cur->next = toDelete->next;
        if(toDelete == tail) {
            tail = cur; // 更新尾指针
        }
        delete toDelete;
        return true;
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
    if(list.removeAt(n)) {
        list.print();
    }

    cin >> n;
    if(list.removeAt(n)) {
        list.print();
    }

    return 0;
}

