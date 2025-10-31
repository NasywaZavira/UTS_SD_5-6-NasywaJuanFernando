#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = NULL;
Node* tail = NULL;

// Tambah pasien normal (belakang)
void tambahNormal(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = NULL;

    if (head == NULL) {       // jika antrian kosong
        head = tail = baru;
    } else {
        tail->next = baru;
        tail = baru;
    }
}

// Tambah pasien darurat (depan)
void tambahDarurat(string nama) {
    Node* baru = new Node;
    baru->nama = nama;
    baru->next = head;

    head = baru;
    if (tail == NULL) {
        tail = baru;
    }
}

// Layani pasien (hapus depan)
void layani() {
    if (head != NULL) {
        cout << head->nama << endl;
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
    }
}

int main() {
    int N;
    cin >> N; //untuk banyak perintah

    for(int i = 0; i < N; i++){
        string cmd, nama;
        cin >> cmd;

        if(cmd == "DATANG"){
            cin >> nama;
            tambahNormal(nama);
        }
        else if(cmd == "DARURAT"){
            cin >> nama;
            tambahDarurat(nama);
        }
        else if(cmd == "LAYANI"){
            layani();
        }
    }

    return 0;
}
