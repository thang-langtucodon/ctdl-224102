#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Định nghĩa cấu trúc của một nút (Node) trên cây
struct Node {
    int namSinh;
    struct Node* left;
    struct Node* right;
};
// Hàm tiện ích để tạo một nút mới
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->namSinh = value;
     newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
// ham them nut vao cay
struct Node* insert(struct Node* root, int value) {
    // Nếu cây (hoặc nhánh) đang rỗng, tạo nút mới tại đây
    if (root == NULL) {
        return createNode(value);
    }