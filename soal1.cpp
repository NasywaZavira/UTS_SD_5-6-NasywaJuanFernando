#include <iostream>
#include <vector>
using namespace std;

// Fungsi untuk melakukan rotasi kiri sebanyak d kali
vector<int> rotasiKiri(int d, vector<int> arr) {
    int n = arr.size();
    
    // Jika array kosong atau hanya 1 elemen, kembalikan array asli
    if (n <= 1) {
        return arr;
    }
    
    // Normalisasi d agar tidak melebihi ukuran array
    // Karena rotasi n kali = kembali ke posisi awal
    d = d % n;
    
    // Membuat array hasil rotasi
    vector<int> hasil(n);
    
    // Setiap elemen di posisi i akan dipindahkan ke posisi (i - d + n) % n
    for (int i = 0; i < n; i++) {
        int posisiBaru = (i - d + n) % n;
        hasil[posisiBaru] = arr[i];
    }
    
    return hasil;
}

int main() {
    int n, d;
    
    // Input jumlah elemen dan jumlah rotasi
    cout << "Masukkan n dan banyak rotasi: ";
    cin >> n >> d;
    
    // Input elemen array
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // Melakukan rotasi kiri
    vector<int> hasil = rotasiKiri(d, arr);
    
    // Menampilkan hasil
    for (int i = 0; i < hasil.size(); i++) {
        cout << hasil[i];
        if (i < hasil.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
