#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void traverseAndSum(Node *head);

int main() {
    // Inisialisasi node
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;

    // Node 1
    node1->data = 10;
    node1->next = node2;
    node1->prev = node3; // Menunjuk ke akhir (Circular)

    // Node 2
    node2->data = 20;
    node2->next = node3;
    node2->prev = node1;

    // Node 3
    node3->data = 30;
    node3->next = node1; // Menunjuk ke awal (Circular)
    node3->prev = node2;

    cout << "--- Data Circular Double Linked List ---" << endl;
    traverseAndSum(node1);

    // Membersihkan memori
    delete node1;
    delete node2;
    delete node3;

    cin.get();
    return 0;
}

void traverseAndSum(Node *head) {
    if (head == NULL) {
        cout << "List kosong." << endl;
        return;
    }

    Node *temp = head;
    int i = 1;
    int total = 0;

    // Menggunakan do-while karena pada circular list, 
    // pointer tidak akan pernah NULL
    do {
        cout << "Data ke " << i << " : " << temp->data << endl;
        total += temp->data; // Menambahkan data ke total
        temp = temp->next;
        i++;
    } while (temp != head); // Berhenti jika sudah kembali ke node awal

    cout << "---------------------------" << endl;
    cout << "Total nilai adalah : " << total << endl;
}
