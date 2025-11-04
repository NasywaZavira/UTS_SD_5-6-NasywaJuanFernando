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
    Graph(int V) : Numver(V) {
//resize untuk mengatur ukuran matrix
        adjMatrix.resize(Numver, vector<int>(Numver, 0));
    }//koneksi antara dua node
    void addEdge(int i, int j) {
        if (i >= 0 && i < Numver && j >= 0 && j < Numver) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1;//satu arah agar graf tidak berarah
        }
    }
//fungsi untuk permulaan dan limit hari infeksi
    void pencarianinfeksi(int permulaianhari, int limithari) {
       //menjadi penenntu pencarian hari
        vector<int> days(Numver, -1); 
        queue<int> q;
        
        if (permulaianhari < 0 || permulaianhari >= Numver) {
            cout << "Node terinfeksi: (TIDAK ADA)" << endl;
            return; 
        }

        // start bfs
        days[permulaianhari] = 0;
        q.push(permulaianhari);
        //proses
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            int currentDay = days[u]; 
            //jika mencapai batas berhenti
            if (currentDay >= limithari) {
                 continue; 
            }
            for (int v = 0; v < Numver; ++v) {
                if (adjMatrix[u][v] == 1 && days[v] == -1) {
                    int nextDay = currentDay + 1;

                    if (nextDay <= limithari) {
                        days[v] = nextDay;
                        q.push(v);
                    }
                }
            }
        }
        cout << "Node terinfeksi: ";
        bool firstNodePrinted = false;
        //pemgurutan
        for (int i = 0; i < Numver; ++i) {
            
            if (days[i] == limithari) { 
                if (firstNodePrinted) {
                    cout << " "; 
                }
                cout << i;
                firstNodePrinted = true;
            }
        }
        if (!firstNodePrinted) {
             cout << "TIDAK ADA"; 
        }
        cout << endl;
    }
};

int main() {
    int Numver2, numEdges;
    int permulaianhari, limithari;

    cout << "jumlah vertex dan edge: " ;
    if (!(cin >> Numver2 >> numEdges)) {
        return 0;
    }

    Graph graph(Numver2);

    for (int i = 0; i < numEdges; ++i) {
        int u, v;
        cin >> u >> v;
        graph.addEdge(u, v);
    }

    cout << "node awal dan hari terifeksi: " ;
    if (!(cin >> permulaianhari >> limithari)) {
        return 0;
    }

    graph.pencarianinfeksi(permulaianhari, limithari);
    return 0;
}
//inisialisai vektor hubungan node dan queue
//membuat hari permulaan dan hari terakhir dan juga pelacakan infeksi
//pembuatan fungsi bfs dan queue
//permulaian program 
//program akan meminta node dan vertex lalu akan menentukan hari awal dan yang terinfeksi siapa
