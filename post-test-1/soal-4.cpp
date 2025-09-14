#include <iostream>

using namespace std;

int main(){
    int nilai1, nilai2;
    cout << "Masukkan nilai pertama : ";
    cin >> nilai1;
    cout << "Masukkan nilai kedua : ";
    cin >> nilai2;

    cout << "Nilai sebelum pertukaran : " << endl;
    cout << "Nilai 1 = " << nilai1 << endl;
    cout << "Nilai 2 = " << nilai2 << endl;

    int temp = nilai1;
    nilai1 = nilai2;
    nilai2 = temp;

    cout << "Nilai setelah pertukaran : " << endl;
    cout << "Nilai 1 = " << nilai1 << endl;
    cout << "Nilai 2 = " << nilai2 << endl;
}