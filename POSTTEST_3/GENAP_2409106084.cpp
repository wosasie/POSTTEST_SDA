#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct dataPenerbangan {
    string kodePenerbangan;
    string tujuanPenerbangan;
    string statusPenerbangan;
};

struct Node {
    dataPenerbangan data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

int kodeUnik = 0;

bool isEmpty(){
    return head == nullptr;
};

void tambah_jadwal(string tujuanPenerbangan, string statusPenerbangan, string nim){
    Node* nodeBaru = new Node;

    string kodeDasar = "JT-" + nim.substr(nim.length() - 3);
    if (kodeUnik == 0) nodeBaru->data.kodePenerbangan = kodeDasar;
    else               nodeBaru->data.kodePenerbangan = kodeDasar + "-" + to_string(kodeUnik);

    nodeBaru->data.tujuanPenerbangan  = tujuanPenerbangan;
    nodeBaru->data.statusPenerbangan  = statusPenerbangan;
    nodeBaru->prev = tail;
    nodeBaru->next = nullptr;

    if (isEmpty()){
        head = tail = nodeBaru;
    } else {
        tail->next = nodeBaru;
        tail = nodeBaru;
    }

    kodeUnik++;
    cout << "Jadwal berhasil ditambahkan : "
         << nodeBaru->data.kodePenerbangan
         << " | " << tujuanPenerbangan
         << " | " << statusPenerbangan << endl;
}

void sisipkan_jadwal(string tujuanPenerbangan, string statusPenerbangan, string nim){
    int posisiSisip = (nim.back() - '0') + 1;
    if (nim.back() == '0') posisiSisip = 2;

    Node* nodeBaru = new Node;
    string kodeDasar = "JT-" + nim.substr(nim.length() - 3);
    nodeBaru->data.kodePenerbangan  = kodeDasar + to_string(kodeUnik);
    nodeBaru->data.tujuanPenerbangan = tujuanPenerbangan;
    nodeBaru->data.statusPenerbangan = statusPenerbangan;
    nodeBaru->prev = nullptr;
    nodeBaru->next = nullptr;

    if (posisiSisip <= 1 || isEmpty()){
        nodeBaru->next = head;
        if (head) head->prev = nodeBaru;
        head = nodeBaru;
        if (!tail) tail = nodeBaru;
    } else {
        Node* temp = head;
        int hitung = 1;
        while (temp->next != nullptr && hitung < posisiSisip - 1) {
            temp = temp->next;
            hitung++;
        }
        nodeBaru->next = temp->next;
        nodeBaru->prev = temp;
        if (temp->next) temp->next->prev = nodeBaru;
        temp->next = nodeBaru;
        if (temp == tail) tail = nodeBaru;
    }
    kodeUnik++;
    cout << "Jadwal berhasil disisipkan di posisi " << posisiSisip << endl;
}

void hapus_jadwal(){
    if (isEmpty()){
        cout << "Jadwal yang masih kosong" << endl;
        return;
    }
    Node* hapusJadwal = head;
    head = head->next;
    if (head) head->prev = nullptr;
    else      tail = nullptr; 
    cout << "Jadwal " << hapusJadwal->data.kodePenerbangan << " telah dihapus!" << endl;
    delete hapusJadwal;
}

void update_status(string kodeTujuan){
    if (isEmpty()){
        cout << "Opsie! Tidak ada jadwal dengan kode tersebut!" << endl;
        return;
    }
    Node* temp = head;
    while (temp != nullptr){
        if (temp->data.kodePenerbangan == kodeTujuan){
            cout << "Status lama : " << temp->data.statusPenerbangan << endl;
            cout << "Status baru : ";
            string statusBaru;
            cin.ignore();
            getline(cin, statusBaru);
            temp->data.statusPenerbangan = statusBaru;
            cout << "Status berhasil diupdate!" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Jadwal dengan kode " << kodeTujuan << " tidak ditemukan." << endl;
}

void tampilkan_jadwal(){
    if (isEmpty()){
        cout << "Tidak terdapat jadwal penerbangan" << endl;
        return;
    }
    cout << "\n+------------------+------------------+------------------+\n";
    cout << "|                  FLIGHT SCHEDULE LIST                  |\n";
    cout << "+------------------+------------------+------------------+\n";
    cout << "| Kode Penerbangan | Tujuan           | Status           |\n";
    cout << "+------------------+------------------+------------------+\n";

    Node* temp = head;
    while (temp != nullptr){
        cout << "| " << setw(17) << left << temp->data.kodePenerbangan
             << "| " << setw(17) << left << temp->data.tujuanPenerbangan
             << "| " << setw(17) << left << temp->data.statusPenerbangan
             << "|\n";
        temp = temp->next;
    }
    cout << "+------------------+------------------+------------------+\n";
}


void tampilkan_jadwal_belakang(){
    if (isEmpty()){
        cout << "Tidak terdapat jadwal penerbangan" << endl;
        return;
    }
    cout << "\n[  Cetak dari belakang  ]\n";
    cout << "+------------------+------------------+------------------+\n";
    cout << "| Kode Penerbangan | Tujuan           | Status           |\n";
    cout << "+------------------+------------------+------------------+\n";

    Node* temp = tail;
    while (temp != nullptr){
        cout << "| " << setw(17) << left << temp->data.kodePenerbangan
             << "| " << setw(17) << left << temp->data.tujuanPenerbangan
             << "| " << setw(17) << left << temp->data.statusPenerbangan
             << "|\n";
        temp = temp->prev;
    }
    cout << "+------------------+------------------+------------------+\n";
}

void tampilkan_detail(){
    if (isEmpty()){
        cout << "Tidak terdapat jadwal penerbangan" << endl;
        return;
    }
    cout << "Masukkan Kode Penerbangan ATAU Nama/Tujuan: ";
    string kunci;
    cin.ignore();
    getline(cin, kunci);

    for (Node* p = head; p != nullptr; p = p->next){
        if (p->data.kodePenerbangan == kunci){
            cout << "\n[ DETAIL JADWAL BERDASARKAN KODE ]\n";
            cout << "Kode   : " << p->data.kodePenerbangan << "\n";
            cout << "Tujuan : " << p->data.tujuanPenerbangan << "\n";
            cout << "Status : " << p->data.statusPenerbangan << "\n";
            return;
        }
    }

    bool ada = false;
    for (Node* p = head; p != nullptr; p = p->next){
        if (p->data.tujuanPenerbangan == kunci){
            if (!ada){
                cout << "\n[ DETAIL JADWAL BERDASARKAN TUJUAN ]\n";
                cout << "+------------------+------------------+------------------+\n";
                cout << "| Kode Penerbangan | Tujuan           | Status           |\n";
                cout << "+------------------+------------------+------------------+\n";
            }
            cout << "| " << setw(17) << left << p->data.kodePenerbangan
                 << "| " << setw(17) << left << p->data.tujuanPenerbangan
                 << "| " << setw(17) << left << p->data.statusPenerbangan
                 << "|\n";
            ada = true;
        }
    }
    if (ada){
        cout << "+------------------+------------------+------------------+\n";
    } else {
        cout << "Data dengan Kode/Tujuan " << kunci << " tidak ditemukan.";
    }
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
        cout << "| 6. Tampilkan Jadwal dari Belakang                  |\n";
        cout << "| 7. Tampilkan Detail                                |\n";
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
            case 6:
                tampilkan_jadwal_belakang();
                break;
            case 7:
                tampilkan_detail();
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
