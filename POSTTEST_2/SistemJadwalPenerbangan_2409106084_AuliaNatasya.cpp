#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct dataPenerbangan {
    string kodePenerbangan;
    string tujuanPenerbangan;
    string statusPenerbangan;
    dataPenerbangan* next;
};

dataPenerbangan* head = nullptr;
int kodeUnik = 0;

bool isEmpty(){
    return head == nullptr;
};

void tambah_jadwal(string tujuanPenerbangan, string statusPenerbangan, string nim){
    dataPenerbangan* nodeBaru = new dataPenerbangan;
    string kodeDasar = "JT-" + nim.substr(nim.length() - 3);
    if(kodeUnik == 0){
        nodeBaru -> kodePenerbangan = kodeDasar;
    } else {
        nodeBaru -> kodePenerbangan = kodeDasar + "-" + to_string(kodeUnik);
    } 
    nodeBaru -> tujuanPenerbangan = tujuanPenerbangan;
    nodeBaru -> statusPenerbangan = statusPenerbangan;
    nodeBaru -> next = nullptr;

    if(isEmpty()){
        head = nodeBaru;
    } else {
        dataPenerbangan* temp = head;
        while(temp -> next !=nullptr) {
            temp = temp -> next;
        } 
        temp -> next = nodeBaru;
    }
    kodeUnik++;
    cout << "Jadwal berhasil ditambahkan : "
         << nodeBaru -> kodePenerbangan
         << " | " << tujuanPenerbangan
         << " | " << statusPenerbangan << endl;
}

void sisipkan_jadwal(string tujuanPenerbangan, string statusPenerbangan, string nim){
    int posisiSisip = (nim.back() - '0') + 1;
    if(nim.back() == '0') posisiSisip = 2;


    dataPenerbangan* nodeBaru = new dataPenerbangan;
    string kodeDasar = "JT-" + nim.substr(nim.length() - 3);
    nodeBaru -> kodePenerbangan = kodeDasar + to_string(kodeUnik);
    nodeBaru -> tujuanPenerbangan = tujuanPenerbangan;
    nodeBaru -> statusPenerbangan = statusPenerbangan;
    nodeBaru -> next = nullptr;

    if(posisiSisip <= 1 || isEmpty()){
        nodeBaru -> next = head;
        head = nodeBaru;
    } else {
        dataPenerbangan* temp = head;
        int hitung = 1;
        while (temp -> next != nullptr && hitung < posisiSisip - 1) {
            temp = temp -> next;
            hitung++;
        }
        nodeBaru -> next = temp -> next;
        temp -> next = nodeBaru;
    }
    kodeUnik++;
    cout << "Jadwal berhasil disisipkan di posisi " << posisiSisip << endl;
}

void hapus_jadwal(){
    if(isEmpty()){
        cout << "Jadwal yang masih kosong" << endl;
        return;
    }
    dataPenerbangan* hapusJadwal = head;
    head = head -> next;
    cout << "Jadwal " << hapusJadwal -> kodePenerbangan << " telah dihapus!" << endl;
    delete hapusJadwal;

}

void update_status(string kodeTujuan){
    if(isEmpty()){
        cout << "Opsie! Tidak ada jadwal dengan kode tersebut!" << endl;
        return;
    }
    dataPenerbangan* temp = head;
    while(temp != nullptr){
        if(temp -> kodePenerbangan == kodeTujuan){
            cout << "Status lama : " << temp -> statusPenerbangan << endl;
            cout << "Status baru : ";
            string statusBaru;
            cin.ignore();
            getline(cin, statusBaru);
            temp -> statusPenerbangan = statusBaru;
            cout << "Status berhasil diupdate!" << endl;
            return;
        }
        temp = temp -> next;
    }
    cout << "Jadwal dengan kode " << kodeTujuan << " tidak ditemukan." << endl;
}

void tampilkan_jadwal(){
    if(isEmpty()){
        cout << "Tidak terdapat jadwal penerbangan" << endl;
        return;
    }
    
    cout << "\n+------------------+------------------+------------------+\n";
    cout << "|                  FLIGHT SCHEDULE LIST                  |\n";
    cout << "+------------------+------------------+------------------+\n";
    cout << "| Kode Penerbangan | Tujuan           | Status           |\n";
    cout << "+------------------+------------------+------------------+\n";

    dataPenerbangan* temp = head;
    while(temp != nullptr){
        cout << "| " << setw(17) << left << temp->kodePenerbangan
             << "| " << setw(17) << left << temp->tujuanPenerbangan
             << "| " << setw(17) << left << temp->statusPenerbangan
             << "|\n";
        temp = temp->next;
    }

    cout << "+------------------+------------------+------------------+\n";
}

int main(){
    string nim = "2409106084";
    int pilihan;
    do{
        cout << "\n+----------------------------------------------------+\n";
        cout << "|               FLIGHT SCHEDULE SYSTEM               |\n";
        cout << "|           [ AULIA NATASYA - " << nim << " ]           |\n";
        cout << "+----------------------------------------------------+\n";
        cout << "| 1. Tambah Jadwal Penerbangan                       |\n";
        cout << "| 2. Sisipkan Jadwal Penerbangan                     |\n";
        cout << "| 3. Hapus Jadwal Paling Awal                        |\n";
        cout << "| 4. Update Status Penerbangan                       |\n";
        cout << "| 5. Tampilkan Semua Jadwal                          |\n";
        cout << "| 0. Keluar                                          |\n";
        cout << "+----------------------------------------------------+\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        string tujuanPenerbangan, statusPenerbangan, kodeTujuan;
        switch(pilihan){
            case 1:
            cout << "Masukkan tujuan penerbangan anda : ";
            cin.ignore();
            getline(cin, tujuanPenerbangan);
            cout << "Masukan status penerbangan : ";
            getline(cin, statusPenerbangan);
            tambah_jadwal(tujuanPenerbangan, statusPenerbangan, nim);
            break;
            case 2:
            cout << "Masukkan tujuan penerbangan anda : ";
            cin.ignore();
            getline(cin, tujuanPenerbangan);
            cout << "Masukan status penerbangan : ";
            getline(cin, statusPenerbangan);
            sisipkan_jadwal(tujuanPenerbangan, statusPenerbangan, nim);
            break;
            case 3:
            hapus_jadwal();
            break;
            case 4:
            cout << "Masukan kode penerbangan : ";
            cin >> kodeTujuan;
            update_status(kodeTujuan);
            break;
            case 5:
            tampilkan_jadwal();
            break;
            case 0:
            cout << "Anda keluar dari program . . . Ciao!" << endl;
            break;
            default:
            cout << "Oh naww! Pilihan anda tidak valid!" << endl;
        }
    } while(pilihan != 0);

    return 0;    

}