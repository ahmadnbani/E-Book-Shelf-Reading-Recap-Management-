#include "tubes.h"
#include <iostream>
using namespace std;

static int nomorRak = 0;
static int nomorEbook = 0;
void createListRak (listRak &L) {
    L.first = nullptr;
    L.last = nullptr;
}
bool isEmptyRak (listRak L) {
    return (L.first == nullptr);
}
bool isEmptyEbook (adrRak p) {
    return (p->firstEbook == nullptr);
}
adrRak createListRak (string namaRak, string deskripsi, int kapasitas) {
    adrRak p = new elmRak;
    p->info.idRak = generateIdRak("RAK", nomorRak);
    p->info.namaRak = namaRak;
    p->info.deskripsi = deskripsi;
    p->info.kapasitas = kapasitas;

    p->next = nullptr;
    p->prev = nullptr;
    p->firstEbook = nullptr;
    return p;
}
string generateIdRak (string code, int &nomorRak) {
    nomorRak++;
    string angka = to_string(nomorRak);
    while (angka.length() < 3) {
        angka = "0" + angka;
    }
    return code + "-" + angka;
}
void insertParent (listRak &L, adrRak p, int pilihan, string idPrev) {
    if (isEmptyRak(L)) {
        return;
    }
    switch (pilihan) {
    case 1:
        insertFirst(L, p);
    case 2:
        adrRak prec = findParentById(L, idPrev);
        if (prec == nullptr){
            cout << "ID tidak ditemukan! Silahkan input ulang"
            return;
        }
        insertAfter(L, prec, p);
    case 3:
        insertLast(L, p);
    }
}
adrRak findParentById (listRak L, string idRak) {
    adrRak p = L.first;
    while (!isEmptyRak(L)) {
        if (p->info.idRak == idRak) {
            return p;
        }
        p = p->next;
    }
    return nullptr;
}
void insertFirst (listRak &L, adrRak p) {
    if (isEmptyRak(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->next = L.first;
        L.first->prev = p;
        L.first = p;
    }
}
void insertLast (listRak &L, adrRak p) {
    if (isEmptyRak(L)) {
        L.first = p;
        L.last = p;
    } else {
        p->prev = L.last;
        L.last->next = p;
        L.last = p;
    }
}
void insertAfter (listRak &L, adrRak prec, adrRak p) {
    if (prec == L.last) {
        insertLast(L, p);
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}
void printParent (listRak L) {

}
