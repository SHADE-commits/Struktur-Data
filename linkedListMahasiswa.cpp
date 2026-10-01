#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;
// 
Mahasiswa* buatNode(string nim, string nama, float persen) {
    Mahasiswa* baru = new Mahasiswa;
    baru->nim = nim;
    baru->nama = nama;
    baru->persentaseKehadiran = persen;
    baru->next = NULL;
    return baru;
}

void insertHead(string nim, string nama, float persen) {
    Mahasiswa* baru = buatNode(nim, nama, persen);
    baru->next = head;   
    head = baru;         
}

void insertLast(string nim, string nama, float persen) {
    Mahasiswa* baru = buatNode(nim, nama, persen);
    if (head == NULL) {
        head = baru;
        return;
    }
    Mahasiswa* bantu = head;
    while (bantu->next != NULL) {
        bantu = bantu->next;
    }
    bantu->next = baru;
}

void cetakDaftar() {
    if (head == NULL) {
        cout << "Daftar kosong.\n";
        return;
    }
    cout << "\n" << left << setw(5) << "No" << setw(14) << "NIM"
         << setw(32) << "Nama" << "Kehadiran (%)\n";
    cout << string(66, '-') << "\n";
    int no = 1;
    for (Mahasiswa* p = head; p != NULL; p = p->next) {
        cout << left << setw(5) << no++ << setw(14) << p->nim
             << setw(32) << p->nama << fixed << setprecision(1)
             << p->persentaseKehadiran << "\n";
    }
    cout << string(66, '-') << "\n";
}

void deleteHead() {
    if (head == NULL) {
        cout << "Daftar kosong, tidak ada yang dihapus.\n";
        return;
    }
    Mahasiswa* hapus = head;
    head = head->next;
    cout << "Dihapus dari depan: " << hapus->nama << "\n";
    delete hapus;
}

void deleteLast() {
    if (head == NULL) {
        cout << "Daftar kosong, tidak ada yang dihapus.\n";
        return;
    }
    if (head->next == NULL) {
        cout << "Dihapus dari belakang: " << head->nama << "\n";
        delete head;
        head = NULL;
        return;
    }
    Mahasiswa* bantu = head;
    while (bantu->next->next != NULL) {
        bantu = bantu->next;
    }
    cout << "Dihapus dari belakang: " << bantu->next->nama << "\n";
    delete bantu->next;
    bantu->next = NULL;
}

void isiDataAwal() {
    const int N = 15;
    string nim[N] = {
        "103032500005","103032500041","103032500146","103032500149","103032500150",
        "103032500153","103032500159","103032500176","103032500180","103032500191",
        "103032540001","103032540002","103032540003","103032540004","103032540005"};
    string nama[N] = {
        "Fadhil Asyam Damanik","Rahsya Iman Dehavilland","Mahesa Putra Mulyawan",
        "Gyio Rangga Satria Putra","Naufal Nafiz Faturrahman","Fazli Baktiadi",
        "Matthew Glen Abram Pakpahan","Vendra Fausta Andrean","Dzaky Allam Shidiq",
        "Nayla Novtiera Anjani","Fathin Arib Nurhumam","Ida Bagus Harell",
        "Nigel William Pieters","Aqila Fathatulayya","Badriah Nuraini Rahayu"};
    float persen[N] = {100,93.8,87.5,100,81.3,75,93.8,100,
                       68.8,87.5,100,93.8,81.3,100,75};
    for (int i = 0; i < N; i++) insertLast(nim[i], nama[i], persen[i]);
    
}

int main() {
    isiDataAwal();   
    int pilih;
    string nim, nama;
    float persen;

    do {
        cout << "\n=== MENU KEHADIRAN MAHASISWA (SINGLE LINKED LIST) ===\n";
        cout << "1. Insert Head\n2. Insert Last\n3. Delete Head\n"
             << "4. Delete Last\n5. Cetak Daftar\n0. Keluar\nPilih: ";
        cin >> pilih;

        if (pilih == 1 || pilih == 2) {
            cout << "NIM: ";   cin >> nim;
            cout << "Nama: ";  cin.ignore(); getline(cin, nama);
            cout << "Persentase kehadiran: "; cin >> persen;
            if (pilih == 1) insertHead(nim, nama, persen);
            else insertLast(nim, nama, persen);
            cout << "Data berhasil ditambahkan.\n";
        } else if (pilih == 3) {
            deleteHead();
        } else if (pilih == 4) {
            deleteLast();
        } else if (pilih == 5) {
            cetakDaftar();
        } else if (pilih != 0) {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilih != 0);

    cout << "Program selesai.\n";
    return 0;
}