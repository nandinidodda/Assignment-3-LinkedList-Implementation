#include <iostream>
using namespace std;

struct node {
    int row;
    int column;
    int value;
    node* next;
};

node* createNode(int row, int column, int value) {
    node* new_Node = new node();
    new_Node->row = row;
    new_Node->column = column;
    new_Node->value = value;
    new_Node->next = nullptr;
    return new_Node;
}

node* convertToSparseLinkedList(int matrix[][4], int rows, int columns) {
    node* head = nullptr;
    node* tail = nullptr;

    for (int l = 0; l < rows; l++) {
        for (int m = 0; m < columns; m++) {
            if (matrix[l][m] != 0) {
                node* new_Node = createNode(l, m, matrix[l][m]);
                if (head == nullptr) {
                    head = new_Node;
                    tail = new_Node;
                } else {
                    tail->next = new_Node;
                    tail = new_Node;
                }
            }
        }
    }

    return head;
}

void printSparseLinkedList(node* head) {
    cout << "Sparse Matrix Representation (Linked List):" << endl;
    cout << "Row\tColumn\tValue" << endl;
    node* current = head;
    while (current != nullptr) {
        cout << current->row << "\t" << current->column << "\t" << current->value << endl;
        current = current->next;
    }
}

int main() {
    int matrix[4][4] = {
        {5, 0, 0, 0},
        {0, 8, 0, 0},
        {0, 0, 3, 0},
        {0, 6, 0, 0}
    };

    node* sparseList = convertToSparseLinkedList(matrix, 4, 4);

    printSparseLinkedList(sparseList);

    node* current = sparseList;
    while (current != nullptr) {
        node* temp = current;
        current = current->next;
        delete temp;
    }

    return 0;
}