#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

void traverse(Node *head);
int cariMaksimal(Node *head);

int main() {
    // Inisialisasi pointer
    Node *node1 = new Node;
    Node *node2 = new Node;
    Node *node3 = new Node;

    // Node 1
    node1->data = 10;
    node1->next = node2;
    node1->prev = node3; // Menunjuk ke node terakhir

    // Node 2
    node2->data = 30; // Saya ubah jadi 30 untuk tes maksimal
    node2->next = node3;
    node2->prev = node1;

    // Node 3
    node3->data = 20;
    node3->next = node1; // Kembali ke node pertama
    node3->prev = node2;

    cout << "--- Data Linked List (Circular Double) ---" << endl;
    traverse(node1);
    
    cout << "\nNilai maksimal adalah : " << cariMaksimal(node1) << endl;

    // Dealokasi memori
    delete node1;
    delete node2;
    delete node3;

    cin.get();
    return 0;
}

// Fungsi Mencari Nilai Maksimal pada Circular List
int cariMaksimal(Node *head) {
    if (head == NULL) return -1;

    int max = head->data;
    Node *current = head->next;

    // Berhenti jika sudah berputar kembali ke head
    while (current != head) {
        if (current->data > max) {
            max = current->data;
        }
        current = current->next;
    }
    return max;
}

// Fungsi Traversal (Cetak Data)
void traverse(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    int i = 1;
    do {
        cout << "Data ke " << i << " : " << temp->data;
        // Opsional: tampilkan informasi pointer untuk membuktikan ini double & circular
        cout << " [Prev: " << temp->prev->data << " | Next: " << temp->next->data << "]" << endl;
        
        temp = temp->next;
        i++;
    } while (temp != head);
}
