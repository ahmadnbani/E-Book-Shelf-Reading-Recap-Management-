#include "tubes.h"

void inputMahasiswa(Mahasiswa &m) {
    cout << "Masukkan nama: ";
    cin >> m.nama;

    cout << "Masukkan NIM: ";
    cin >> m.nim;
}

void tampilMahasiswa(Mahasiswa m) {
    cout << "\n=== DATA MAHASISWA ===" << endl;
    cout << "Nama: " << m.nama << endl;
    cout << "NIM: " << m.nim << endl;
}