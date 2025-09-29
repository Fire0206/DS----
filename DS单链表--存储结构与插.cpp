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
    
    // 在第n个位置前插入元素（n从1开始计数）
    bool insertBefore(int n, int val) {
        if(n <= 0) {
            cout << "error" << endl;
            return false;
        }
        
        // 空链表
        if(!head) {
            if(n == 1) {
                head = tail = new Node(val);
                return true;
            } else {
                cout << "error" << endl;
                return false;
            }
        }
        
        // 插在头部
        if(n == 1) {
            Node* newNode = new Node(val);
            newNode->next = head;
            head = newNode;
            return true;
        }
        
        // 找到第 n-1 个节点
        Node* cur = head;
        for(int i = 1; i < n - 1; i++) {
            cur = cur->next;
            if(cur == NULL) {
                cout << "error" << endl;
                return false;
            }
        }
        
        // 执行插入
        Node* newNode = new Node(val);
        newNode->next = cur->next;
        cur->next = newNode;
        
        // 如果插入在尾部，更新 tail
        if(newNode->next == NULL) {
            tail = newNode;
        }
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

    cin >> n >> val;
    if(list.insertBefore(n, val)){
        list.print();
    }

    cin >> n >> val;
    if(list.insertBefore(n, val)){
        list.print();
    }

    return 0;
}

