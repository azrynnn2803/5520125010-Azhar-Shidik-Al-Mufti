#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev; // Pointer ke belakang
};

void traverse(Node *head);
void insertAkhir(Node*& head, int newData);

int main() {
    Node* head = NULL; 

    int jumlahData;
    cout << "Berapa banyak data yang ingin diinput? : ";
    cin >> jumlahData;

    for (int i = 1; i <= jumlahData; i++) {
        int inputData;
        cout << "Masukkan data ke-" << i << " : ";
        cin >> inputData;
        insertAkhir(head, inputData);
    }

    cout << "\nData Linked List Sekarang (Circular Double) : " << endl;
    traverse(head);

    int dataTambahan;
    cout << "\nMasukkan data yang ditambahkan di akhir : ";
    cin >> dataTambahan;

    insertAkhir(head, dataTambahan);
    cout << "\nData Linked List Setelah Ditambahkan di Akhir : " << endl;
    traverse(head);

    cin.ignore();
    cin.get();
    return 0;
}

void traverse(Node *head) {
    if (head == NULL) {
        cout << "List kosong!" << endl;
        return;
    }

    Node *temp = head;
    int i = 1;
    // Menggunakan do-while karena pada circular, temp tidak akan pernah NULL
    do {
        cout << "Data ke " << i << " : " << temp->data;
        // Opsional: bukti double linked (melihat data sebelum dan sesudahnya)
        cout << " [Prev: " << temp->prev->data << " | Next: " << temp->next->data << "]";
        cout << endl;
        temp = temp->next;
        i++;
    } while (temp != head);
}

void insertAkhir(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;

    if (head == NULL) {
        // Jika list kosong, node menunjuk ke dirinya sendiri
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        // Pada CDLL, node terakhir adalah head->prev
        Node* tail = head->prev;

        // Hubungkan newNode dengan tail dan head
        newNode->next = head;
        newNode->prev = tail;

        // Update pointer tail dan head lama
        tail->next = newNode;
        head->prev = newNode;
    }
}
