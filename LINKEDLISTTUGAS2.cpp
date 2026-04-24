#include <iostream>
using namespace std;

struct Node {

  int data;
  Node *next;
};

void traverse(struct Node *temp);

int cariMaksimal(Node *head) {

  if (head == NULL) {
    return -1;
  }
  int max = head->data;

  Node *current = head->next;
  while (current != NULL) {
    if (current->data > max) {
      max = current->data;
    }
    current = current->next;
  }
  return max;
}

int main() {

  Node *node1 = NULL;
  Node *node2 = NULL;
  Node *node3 = NULL;

  node1 = new Node;
  node2 = new Node;
  node3 = new Node;

  node1->data = 10;
  node1->next = node2;

  node2->data = 20;
  node2->next = node3;

  node3->data = 30;
  node3->next = NULL;

  cout << " Data linked list adalah : " << endl;
  traverse(node1);
  cout << " Nilai maksimal adalah : " << cariMaksimal(node1);
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
