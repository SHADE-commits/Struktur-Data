#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Node: satu mahasiswa = satu node
struct Mahasiswa {
    string nim;
    string nama;
    float persentaseKehadiran;
    Mahasiswa* next;
};

Mahasiswa* head = NULL;

// Membuat node baru
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
    baru->next = head;   // node baru menunjuk ke head lama
    head = baru;         // head pindah ke node baru
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