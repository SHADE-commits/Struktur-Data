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