#include <iostream>
using namespace std;

struct Node {

  int data;
  Node *next;

};

void traverse(struct Node *temp);
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

  cout << "\nData Linked List Setelah Ditambahkan Di Awal : " << endl;
  traverse(head);

  cin.ignore();
  cin.get();
  return 0;

}

void traverse(struct Node *temp) {

  int i = 1;
  while (temp != NULL) {

    cout << "Data ke " << i << " : ";
    cout << temp->data;
    temp = temp->next;
    cout << endl;
    i++;

  }

}

void insertAwal(Node*& head, int newData) {

  Node* newNode = new Node;
  newNode->data = newData;
  newNode->next = head;
  head = newNode;

}

void insertAkhir(Node*& head, int newData) {

  Node* newNode = new Node;
  newNode->data = newData;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  Node* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;

}
