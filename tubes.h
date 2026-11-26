#ifndef MAHASISWA_H
#define MAHASISWA_H

#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
};

void inputMahasiswa(Mahasiswa &m);
void tampilMahasiswa(Mahasiswa m);

#endif