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
// Buat node baru berisi nama pasien.
// Jika antrian kosong → head dan tail menunjuk ke node tersebut
// Jika tidak kosong → sambungkan node baru ke tail, lalu pindahkan tail ke node baru itu.

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
// Buat node baru berisi nama pasien.
// Hubungkan node baru sehingga next-nya menunjuk ke head.
// Geser head ke node baru tersebut.
// Jika antrian sebelumnya kosong, maka tail juga ikut ke node ini.

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
// Jika antrian tidak kosong, tampilkan nama pasien yang dilayani (cout head->nama)
// Pindahkan head ke node berikutnya.
// Hapus node lama.
// Jika setelah dihapus antrian menjadi kosong => set tail = NULL.


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
// Program membaca jumlah perintah N
// Setiap perintah dapat berupa:
// DATANG nama => panggil tambahNormal(nama)
// DARURAT nama => panggil tambahDarurat(nama)
// LAYANI => panggil layani()

