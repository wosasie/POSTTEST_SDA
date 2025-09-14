#include <iostream>

using namespace std;

int main(){
    int matriks[3][3];
    int jumlah = 0;

    cout << "Masukkan elemen matriks 3x3 : " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cin >> matriks[i][j];
        }
    }

    for(int i = 0; i < 3; i++){
        if(i % 2 == 0){
            for(int j = 0; j < 3; j++){
                jumlah += matriks[i][j];
            }
        }
    }

    cout << "Matriksa 3x3 : " << endl;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << matriks[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah elemen baris yang genap : " << jumlah << endl;

};