#include "tubes.h"
#include <iostream>
#include <iomanip>
using namespace std;

static int nomorRak = 0;
void createListRak (listRak &L) {
    L.first = nullptr;
    L.last = nullptr;
}
bool isEmptyRak (listRak L) {
    return (L.first == nullptr);
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
void insertParent (listRak &L, adrRak p, int pilihan) {
    switch (pilihan) {
    case 1:
        insertFirst(L, p);
        return;
    case 2: {
        string idPrev;
        cout << "Masukkan ID Rak sebelumnya: ";
        cin >> idPrev;
        adrRak prec = findParentById(L, idPrev);
        if (prec == nullptr){
            cout << "ID tidak ditemukan! Silahkan input ulang" << endl;
            return;
        }
        insertAfter(L, prec, p);
        return;
    }
    case 3:
        insertLast(L, p);
        return;
    default:
        cout << "Pilihan tidak valid!" << endl;
        return;
    }
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
void deleteParent (listRak &L, adrRak &p, string idRak) {
    p = findParentById(L, idRak);
    if (p == nullptr) {
        cout << "ID tidak ditemukan! Silahkan input ulang" << endl;
        return;
    } else if (p->firstEbook != nullptr) {
        cout << "Rak tidak kosong! Hapus ebook terlebih dahulu." << endl;
        return;
    }
    if (p == L.first) {
        L.first = p->next;
        p->next = nullptr;
        if (L.first != nullptr) {
            L.first->prev = nullptr;
        } else {
            L.last = nullptr;
        }
    } else if (p == L.last) {
        L.last = p->prev;
        p->prev = nullptr;
        if (L.last != nullptr) {
            L.last->next = nullptr;
        } else {
            L.first = nullptr;
        }
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        p->next = nullptr;
        p->prev = nullptr;
    }
}
void printBarisKartu (string isi) {
    if (isi.length() > 34) {
        isi = isi.substr(0, 31) + "...";
    }
    cout << "| " << left << setw(34) << isi << " |" << endl;
    cout << right;
}
void printParent (listRak L) {
    string garisTebal = string(38, '=');
    string garisTipis = string(38, '-');
    string garisKartu = "+" + string(36, '-') + "+";

    cout << garisTebal << endl;
    cout << "       E-BOOK SHELF MANAGEMENT" << endl;
    cout << garisTebal << endl;

    if (L.first == NULL) {
        cout << " Belum ada rak." << endl;
        cout << garisTebal << endl;
        return;
    }

    int totalRak = 0;
    int totalEbook = 0;
    int rakKosong = 0;

    adrRak P = L.first;
    while (P != NULL) {                       
        string deskripsi = P->info.deskripsi;
        if (deskripsi == "") {               
            deskripsi = "-";
        }

        cout << garisKartu << endl;
        printBarisKartu(P->info.idRak + " - " + P->info.namaRak);
        printBarisKartu(deskripsi);
        printBarisKartu("Ebook: " + to_string(P->info.jumlahEbook) + "/" + to_string(P->info.kapasitas));
        cout << garisKartu << endl;

        totalRak++;
        totalEbook += P->info.jumlahEbook;
        if (P->info.jumlahEbook == 0) {
            rakKosong++;
        }

        P = P->next;                         
    }

    cout << garisTipis << endl;
    cout << " Rekap: " << totalRak << " rak | " << totalEbook << " ebook | "
         << rakKosong << " kosong" << endl;
    cout << garisTebal << endl;
}
