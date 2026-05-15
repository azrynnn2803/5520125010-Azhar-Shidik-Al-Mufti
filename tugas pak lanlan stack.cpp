#include <iostream>
using namespace std;

int main() {
    const int MAX_STACK = 100;
    string historyStack[MAX_STACK];
    int top = -1;

	string currentDocument = "";
    int choice;
    string inputText;

    do {
        cout << "\n===== Pilihan Menu =====" << endl;
        cout << "1. Ketik Teks" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Tampilkan Dokumen" << endl;
        cout << "4. Keluar" << endl;
        cout << "Pilih No: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Masukkan teks: ";
                cin.ignore();
                getline(cin, inputText);
                
                if (currentDocument != "") {
                    currentDocument += " ";
                }
                currentDocument += inputText;
                
                if (top < MAX_STACK - 1) {
                    top++;
                    historyStack[top] = currentDocument;
                    cout << ">> Teks berhasil ditambahkan." << endl;
                } else {
                    cout << ">> Memori penuh, gabisa memuat teks." << endl;
                }
                break;
                
            case 2:
                if (top >= 0) {
                    top--;
                    
                    if (top >= 0) {
                        currentDocument = historyStack[top]; 
                    } else {
                        currentDocument = ""; 
                    }
                    cout << ">> Undo berhasil dilakukan." << endl;
                } else {
                    cout << ">> Tidak ada yang bisa di-undo. Dokumen sudah kosong." << endl;
                }
                break;
                
            case 3:
                cout << "\n--- Isi dari Text / document	: ---" << endl;
                if (currentDocument == "") {
                    cout << "(Kosong)" << endl;
                } else {
                    cout << currentDocument << endl;
                }
                cout << "----------------------------\n" << endl;
                break;
                
            case 4:
                cout << "Keluar program..." << endl;
                break;
                
            default:
                cout << ">> Pilihan tidak valid, silakan coba lagi." << endl;
        }
    } while (choice != 4);

    return 0;
}
