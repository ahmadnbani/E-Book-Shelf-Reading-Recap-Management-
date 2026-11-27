#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmRak *adrRak;
typedef struct elmEbook *adrEbook;
struct dataEbook {
    string idEbook;
    string judul;
    string penulis;
    string genre;
    string deskripsi;
    int totalHal;
    int HalTerbaca;
    float rating;
    string status;
};
struct dataRak {
    string idRak;
    string namaRak;
    string deskripsi;
    int kapasitas;
};
struct elmRak {
    dataRak info;
    adrRak next;
    adrRak prev;
    adrEbook firstEbook;
};
struct elmEbook {
    dataEbook info;
    adrEbook next;
    adrEbook prev;
};
struct listRak {
    adrRak first;
    adrRak last;
};
void createListRak (listRak &L);
bool isEmptyRak (listRak L);
bool isEmptyEbook (adrEbook p);
adrRak createParent(string namaRak, string deskripsi, int kapasitas);
string generateIdRak (string awalan, int &nomorRak);
void insertParent (listRak &L, adrRak p, int pilihan, string idPrev);
adrRak findParentById (listRak L, string idRak);
void insertFirst (listRak &L, adrRak p);
void insertLast (listRak &L, adrRak p);
void insertAfter (listRak &L, adrRak prec, adrRak p);
void printParent (listRak L);
#endif // TUBES_H_INCLUDED
