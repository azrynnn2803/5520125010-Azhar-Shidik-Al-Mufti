#include <iostream>
using namespace std;

struct Node {

  int data;
  Node *next;

};

void traverse(struct Node *temp);
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

  cout << "\nData linked list sekarang adalah : " << endl;
  traverse(head);

  int dataTambahan;
  cout << "\nMasukkan data yang ditambahkan di akhir : ";
  cin >> dataTambahan;

  insertAkhir(head, dataTambahan);
  cout << "\nData linked list setelah ditambahkan di akhir : " << endl;
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
