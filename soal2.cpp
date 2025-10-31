#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    deque<string> antrian;
    
    for(int i = 0; i < N; i++){
        string cmd, nama;
        cin >> cmd;

        if(cmd == "DATANG"){
            cin >> nama;
            antrian.push_back(nama);   // normal: masuk belakang
        }
        else if(cmd == "DARURAT"){
            cin >> nama;
            antrian.push_front(nama);  // darurat: masuk depan
        }
        else if(cmd == "LAYANI"){
            if(!antrian.empty()){
                cout << antrian.front() << endl; // pasien di paling depan
                antrian.pop_front();             // keluar setelah dilayani
            }
        }
    }
    return 0;
}
