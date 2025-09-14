#include <iostream>
#include <string>

using namespace std;

struct Mahasiswa{
    string nama;
    string nim;
    double ipk;
};

int main(){
    Mahasiswa mhsw[4];

    for(int i = 0; i < 4; i++){
        cout << i+1 << ". Nama Lengkap : ";
        getline(cin, mhsw[i].nama);
        cout << "   NIM : ";
        getline(cin, mhsw[i].nim);
        cout << "   IPK : ";
        cin >> mhsw[i].ipk;
        cin.ignore();
        cout << endl;
    }

    for(int i = 0; i < 4-1; i++){
        for(int j = 0; j < 4-i-1; j++){
            if(mhsw[j].ipk > mhsw[j+1].ipk){
                swap(mhsw[j], mhsw[j+1]);
            }
        }
    }

    cout << "Berikut data semua mahasiswa setelah diurutkan berdasarkan ascending IPK" << endl;
    for(int i = 0; i < 4; i++){
        cout << i+1 << ". Nama : " << mhsw[i].nama << endl;
        cout << "   NIM : " << mhsw[i].nim << endl;
        cout << "   IPK : " << mhsw[i].ipk << endl;
    }

    return 0;

};