#include <iostream>
using namespace std;

const int MAX_LENGTH = 1000;
void createList(int arr[], int& length) {
    for (int i = 0; i < length; i++) {
        cin >> arr[i];
    }
}

bool deleteElement(int arr[], int& length, int place) {
    if (place < 1 || place > length) {
        return false;
    }
    
    for (int i = place; i < length; i++) {
        arr[i - 1] = arr[i];
    }
    
    length--;
    return true;
}

void printList(int arr[], int length) {
    cout << length << " ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[MAX_LENGTH];
    int length;
    
    cin >> length;
    createList(arr, length);
    
    printList(arr, length);
    
    int place;
    cin >> place;
    if (deleteElement(arr, length, place)) {
        printList(arr, length);
    } else {
        cout << "error" << endl;
    }
    
    cin >> place;
    if (deleteElement(arr, length, place)) {
        printList(arr, length);
    } else {
        cout << "error" << endl;
    }
    
    return 0;
}
    
