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

/*
1. KONSEP ROTASI KIRI:
   - Rotasi kiri sebanyak d kali berarti setiap elemen bergeser d posisi ke kiri
   - Elemen yang berada di awal array akan "memutar" ke belakang (circular)
   - Contoh: [1,2,3,4,5] rotasi kiri 2 kali → [3,4,5,1,2]

2. FORMULA POSISI BARU:
   - Untuk elemen di posisi i, posisi barunya setelah rotasi kiri d kali adalah:
     posisi_baru = (i - d + n) % n
   
   - Penjelasan formula:
     * (i - d): mengurangi indeks sebanyak d (geser ke kiri)
     * + n: menambah n untuk menghindari nilai negatif
     * % n: operasi modulo untuk membuat circular (kembali ke awal jika melewati akhir)

3. NORMALISASI ROTASI:
   - Jika d >= n, maka d = d % n
   - Karena rotasi sebanyak n kali akan kembali ke posisi semula
   - Contoh: rotasi 7 kali pada array 5 elemen = rotasi 2 kali (7 % 5 = 2)

4. KOMPLEKSITAS:
   - Time Complexity: O(n) - hanya melakukan satu kali iterasi
   - Space Complexity: O(n) - membuat array baru untuk hasil

5. CONTOH EKSEKUSI (Test Case 1):
   Input: n=5, d=4, arr=[1,2,3,4,5]
   
   Proses:
   - Elemen arr[0]=1 → posisi baru = (0-4+5)%5 = 1 → hasil[1]=1
   - Elemen arr[1]=2 → posisi baru = (1-4+5)%5 = 2 → hasil[2]=2
   - Elemen arr[2]=3 → posisi baru = (2-4+5)%5 = 3 → hasil[3]=3
   - Elemen arr[3]=4 → posisi baru = (3-4+5)%5 = 4 → hasil[4]=4
   - Elemen arr[4]=5 → posisi baru = (4-4+5)%5 = 0 → hasil[0]=5
   
   Output: [5,1,2,3,4]
*/
