#include <iostream>
#include <string>
using namespace std;

struct File {
    string name;
    int size;
    long time;
};

struct Node {
    File data;
    Node* next;
};

struct LinkedList {
    Node* head;
};

// khởi tạo list
void init(LinkedList &list) {
    list.head = NULL;
}

// thêm file theo thứ tự thời gian
void insertFile(LinkedList &list, File f) {
    Node* newNode = new Node{f, NULL};

    if (list.head == NULL || f.time < list.head->data.time) {
        newNode->next = list.head;
        list.head = newNode;
        return;
    }

    Node* cur = list.head;
    while (cur->next != NULL && cur->next->data.time < f.time) {
        cur = cur->next;
    }

    newNode->next = cur->next;
    cur->next = newNode;
}

// tính tổng dung lượng
int totalSize(LinkedList list) {
    int sum = 0;
    Node* cur = list.head;

    while (cur != NULL) {
        sum += cur->data.size;
        cur = cur->next;
    }

    return sum;
}

// tìm file nhỏ nhất
Node* findMin(LinkedList list) {
    if (list.head == NULL) return NULL;

    Node* minNode = list.head;
    Node* cur = list.head;

    while (cur != NULL) {
        if (cur->data.size < minNode->data.size) {
            minNode = cur;
        }
        cur = cur->next;
    }

    return minNode;
}

// xóa node an toàn
void deleteNode(LinkedList &list, Node* target) {
    if (list.head == NULL || target == NULL) return;

    if (list.head == target) {
        Node* temp = list.head;
        list.head = list.head->next;
        delete temp;
        return;
    }

    Node* cur = list.head;
    while (cur->next != NULL && cur->next != target) {
        cur = cur->next;
    }

    if (cur->next == NULL) return;

    Node* temp = cur->next;
    cur->next = temp->next;
    delete temp;
}

// backup USB
void backupUSB(LinkedList &list, int capacity) {
    while (list.head != NULL && totalSize(list) > capacity) {
        Node* minNode = findMin(list);

        if (minNode == NULL) break;

        deleteNode(list, minNode);
    }
}

// in danh sách file
void printList(LinkedList list) {
    Node* cur = list.head;

    while (cur != NULL) {
        cout << cur->data.name << " - "
             << cur->data.size << " - "
             << cur->data.time << endl;
        cur = cur->next;
    }
}

int main() {
    LinkedList list;
    init(list);

    File f1 = {"A.txt", 10, 1};
    File f2 = {"B.txt", 5, 2};
    File f3 = {"C.txt", 20, 3};
    File f4 = {"D.txt", 3, 4};

    insertFile(list, f1);
    insertFile(list, f2);
    insertFile(list, f3);
    insertFile(list, f4);

    cout << "Danh sach ban dau:\n";
    printList(list);

    cout << "\nBackup USB (capacity = 25)\n";
    backupUSB(list, 25);

    cout << "\nSau backup:\n";
    printList(list);

    return 0;
}