#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(int n) {
    ListNode* dummyHead = new ListNode(0);  
    ListNode* cur = dummyHead;             
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        cur->next = new ListNode(val);     
        cur = cur->next;                   
    }
    return dummyHead->next; 
}

void printList(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val;
        if (cur->next != nullptr) {
            cout << " ";
        }
        cur = cur->next;
    }
    cout << endl;
}

void clear(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        ListNode* next = cur->next;
        delete cur;
        cur = next;
    }
}

ListNode* LL_merge(ListNode* La, ListNode* Lb) {
    ListNode* dummyHead = new ListNode(0);
    ListNode* cur = dummyHead;
    while (La != nullptr && Lb != nullptr) {
        if (La->val < Lb->val) {
            cur->next = La;
            La = La->next;
        }
        else {
            cur->next = Lb;
            Lb = Lb->next;
        }
        cur = cur->next;
    }
    cur->next = (La != nullptr) ? La : Lb;
    return dummyHead->next; 
}

int main() {
    int n, m;
    cin >> n;
    ListNode* heada = createLinkedList(n);
    cin >> m;
    ListNode* headb = createLinkedList(m);

    ListNode* mergedHead = LL_merge(heada, headb);
    printList(mergedHead);

    clear(mergedHead);
    return 0;
}
