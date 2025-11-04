//penginisialisasikan vector dan queue
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph {
private:
    int Numver;//menyimpan vertex  
    vector<vector<int>> adjMatrix;//menyimpan hubungan 

public:
//memanggil konstruktor graph
//menyimpan jumlah total vertex dalam grap 
    Graph(int V) : Numver(V) {
//resize untuk mengatur ukuran matrix
        adjMatrix.resize(Numver, vector<int>(Numver, 0));
    }//koneksi antara dua node yaitu node j dan i dimana hubungannya hanya lah satu arah
    void addEdge(int i, int j) {
        if (i >= 0 && i < Numver && j >= 0 && j < Numver) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;//satu arah agar graf tidak berarah
        }
    }
//fungsi untuk permulaan dan limit hari infeksi
    void pencarianinfeksi(int permulaianhari, int limithari) 
        // Vektor 'days' digunakan untuk melacak hari ke-berapa setiap node terinfeksi.
        //  inisialisasi dengan -1, yang berarti 'belum terinfeksi'.
        vector<int> days(Numver, -1); 
        //q akan menjadi queue yang dijelajahi oleh BFS untuk mensimulasikan hari perhari infeksi
        queue<int> q;
        
        //mengecek jika node awal valid atau tidak tidak boleh melebihi vertex
        if (permulaianhari < 0 || permulaianhari >= Numver) {
            cout << "Node terinfeksi: (TIDAK ADA)" << endl;
            return; 
        }

        // start bfs
        //permulaian hari node awal dibuat 0 dan Masukkan node awal ke dalam antrian untuk diproses
        days[permulaianhari] = 0;
        q.push(permulaianhari);

        //proses  penjalanan BFS dimana akan berjalan selama tidak kosong
        //mengambil node terdepan yang akan dihapus 
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            //informasi hari infeksi untuk node pasien 
            int currentDay = days[u]; 
            
            // Jika hari infeksi node 'u' mencapai limit, tidak perlu menyebarkan infeksi DARI 'u' karena akan  terinfeksi pada hari setelahnya,
            //   yang  akan melewati limit dari hari yang ditentukan.'
            if (currentDay >= limithari) {
                 continue; 
            }


            //  Periksa semua node lain vektor untuk menemukan tetangga 'u'
            // mengecek apakah  V adalah tetangga dari u dan apakah dia terinfeksi
            for (int v = 0; v < Numver; ++v) {
                if (adjMatrix[u][v] == 1 && days[v] == -1) {
                    //Jika ya, 'v' akan terinfeksi pada hari berikutnya
                    int nextDay = currentDay + 1;
                    //   mengecek apakah  infeksi yang terjadi mencapai limit hari
                    //    Jika ' masih dalam batas, proses jika tidak lewati.
                    if (nextDay <= limithari) {
                        //jika terinfeksi dimasukan ke barisan agar bisa mengecek tetangga v juga
                        days[v] = nextDay;
                        q.push(v);
                    }
                }
            }
        }
        cout << "Node terinfeksi: ";
        //variavek agar tidak error pas di spasikan
        bool firstNodePrinted = false;
        //pemgurutan dan pengecekan semua node
        for (int i = 0; i < Numver; ++i) {
            //Jika node 'i' terinfeksi sama  dengan limithari dan pemberian spasi per nodenya
            if (days[i] == limithari) { 
                if (firstNodePrinted) {
                    cout << " "; 
                }
                cout << i;
                firstNodePrinted = true;
            }
        }
        //  tidak ada node yang ditemukan terinfeksi
        if (!firstNodePrinted) {
             cout << "TIDAK ADA"; 
        }
        cout << endl;//akhir proses bfs
    }
};

int main() {
    int Numver2, numEdges;
    int permulaianhari, limithari;
    //meminta inout node dan vertex dan 
    cout << "jumlah vertex dan edge: " ;
    if (!(cin >> Numver2 >> numEdges)) {
        return 0;
    }
    //  Buat objek Graf dengan Numver2 jumlah vertex karena nuvertex private
    Graph graph(Numver2);
    //pembacaan koneksi dan penghubungan koneksi ke graf
    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }
    //input node awal dan infeksi
    cout << "node awal dan hari terifeksi: " ;
    if (!(cin >> permulaianhari >> limithari)) {
        return 0;
    }
    //hasil simulasi pencarian
    graph.pencarianinfeksi(permulaianhari, limithari);
    return 0;
}
//inisialisai vektor hubungan node dan queue
//membuat hari permulaan dan hari terakhir dan juga pelacakan infeksi
//pembuatan fungsi bfs dan queue
//permulaian program 
//program akan meminta node dan vertex lalu akan menentukan hari awal dan yang terinfeksi siapa
