#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev; // Tambahan untuk Double Linked List
};

// Fungsi untuk mencetak list secara melingkar
void traverseCircular(Node *head);

int main() {
    Node *node1, *node2, *node3;

    // Alokasi memori
    node1 = new Node;
    node2 = new Node;
    node3 = new Node;

    // Isi data dan atur pointer node1
    node1->data = 10;
    node1->next = node2;
    node1->prev = node3; // Circular: prev node1 ke node terakhir

    // Isi data dan atur pointer node2
    node2->data = 20;
    node2->next = node3;
    node2->prev = node1;

    // Isi data dan atur pointer node3
    node3->data = 30;
    node3->next = node1; // Circular: next node3 kembali ke node pertama
    node3->prev = node2;

    cout << "Data Circular Double Linked List:" << endl;
    traverseCircular(node1);

    // Jangan lupa hapus memori
    delete node1;
    delete node2;
    delete node3;

    cin.get();
    return 0;
}

void traverseCircular(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    int i = 1;

    // Menggunakan do-while karena kondisi awal temp == head
    do {
        cout << "Data ke " << i << " : " << temp->data;
        cout << " (Prev: " << temp->prev->data << ", Next: " << temp->next->data << ")";
        cout << endl;
        
        temp = temp->next;
        i++;
    } while (temp != head); // Berhenti jika sudah kembali ke node awal
}
