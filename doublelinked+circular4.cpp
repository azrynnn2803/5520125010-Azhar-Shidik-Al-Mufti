#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev; // Tambahan untuk Double
};

void traverse(Node *head);
void insertAwal(Node*& head, int newData);
void insertAkhir(Node*& head, int newData);

int main() {
    Node* head = NULL; 

    int jumlahData;
    cout << "Berapa Banyak Data Yang Ingin Diinput?? : ";
    cin >> jumlahData;

    for (int i = 1; i <= jumlahData; i++) {
        int inputData;
        cout << "Masukkan Data Ke-" << i << " : ";
        cin >> inputData;
        insertAkhir(head, inputData); 
    }

    cout << "\nData Linked List Sekarang Adalah : " << endl;
    traverse(head);

    int dataTambahan;
    cout << "\nMasukkan Data Yang Ditambahkan Di Awal : ";
    cin >> dataTambahan;

    insertAwal(head, dataTambahan);

    cout << "\nData Linked List Setelah Ditambahkan Di Awal (CDLL): " << endl;
    traverse(head);

    cin.ignore();
    cin.get();
    return 0;
}

void traverse(Node *head) {
    if (head == NULL) return;

    Node *temp = head;
    int i = 1;
    do {
        cout << "Data ke " << i << " : " << temp->data;
        // Kita tampilkan prev dan next untuk membuktikan sirkular
        cout << " [Prev: " << temp->prev->data << " | Next: " << temp->next->data << "]" << endl;
        temp = temp->next;
        i++;
    } while (temp != head);
}

void insertAwal(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev; // Node terakhir adalah prev-nya head

        newNode->next = head;
        newNode->prev = tail;
        
        tail->next = newNode; // Ekor sekarang menunjuk ke node baru
        head->prev = newNode; // Head lama menunjuk balik ke node baru
        head = newNode;       // Pindahkan head ke node baru
    }
}

void insertAkhir(Node*& head, int newData) {
    Node* newNode = new Node;
    newNode->data = newData;

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
    } else {
        Node* tail = head->prev; // Di CDLL, tail bisa langsung diakses via head->prev

        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = head;
        head->prev = newNode;
    }
}
