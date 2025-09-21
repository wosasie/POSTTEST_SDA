#include <iostream>

using namespace std;

bool isPrime(int a){
    if(a < 2) return false;
    for(int i = 2; i*i <= a; i++){
        if(a % i == 0) return false;
    }
    return true;
}



void balik_array(int *ptr, int uk){
    int *awal = ptr;
    int *akhir = ptr + uk - 1;
    while (awal < akhir){
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}

int main(){
    int panjang_array[7];
    int prima = 2;
    
    for(int i = 0; i < 7; i++){
        while(!isPrime(prima)) prima++;
        panjang_array[i] = prima;
        prima++;
    }

    cout << "Array sebelum dibalik : ";
    for(int i = 0; i < 7; i++) 
    cout << panjang_array[i] << " ";
    cout << endl;

    balik_array(panjang_array, 7);

    cout << "Array setelah dibalik : ";
    for(int i = 0; i < 7; i++)
    cout << panjang_array[i] << " ";
    cout << endl;
}
