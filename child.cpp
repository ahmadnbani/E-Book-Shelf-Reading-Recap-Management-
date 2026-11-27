#include "tubes.h"
#include <iostream>
using namespace std;
static int nomorEbook = 0;
bool isEmptyEbook (adrRak p) {
    return (p->firstEbook == nullptr);
}
adrEbook createChild (string judul, string penulis, string genre, string deskripsi, int totalHal, int HalTerbaca, float rating, string status) {
    adrEbook c = new elmEbook;
    c->info.idEbook = generateIdEbook("EBK", nomorEbook);
    c->info.judul = judul;
    c->info.penulis = penulis;
    c->info.genre = genre;
    c->info.deskripsi = deskripsi;
    c->info.totalHal = totalHal;
    c->info.HalTerbaca = HalTerbaca;
    c->info.rating = rating;
    c->info.status = status;

    c->next = nullptr;
    c->prev = nullptr;
    return c;
}
string generateIdEbook (string awalan, int &nomorEbook) {
    nomorEbook++;
    string angka = to_string(nomorEbook);
    while (angka.length() < 3) {
        angka = "0" + angka;
    }
    return awalan + "-" + angka;
}
adrEbook findChildById (adrRak p, string idEbook) {
    adrEbook c = p->firstEbook;
    while (c != nullptr) {
        if (c->info.idEbook == idEbook) {
            return c;
        }
        c = c->next;
    }
    return nullptr;
}
void insertChild (adrRak p, adrEbook c, int pilihan) {
    if (isEmptyEbook(p)) {
        p->firstEbook = c;
        return;
    }
    switch (pilihan) {
    case 1:
        c->next = p->firstEbook;
        p->firstEbook->prev = c;
        p->firstEbook = c;
        return;
    case 2: {
        string idPrev;
        cout << "Masukkan ID Ebook sebelumnya: ";
        cin >> idPrev;
        adrEbook prec = findChildById(p, idPrev);
        if (prec == nullptr) {
            cout << "ID tidak ditemukan! Silahkan input ulang" << endl;
            return;
        }
        c->next = prec->next;
        if (prec->next != nullptr) {
            prec->next->prev = c;
        }
        prec->next = c;
        c->prev = prec;
        return;
    }
    case 3: {
        adrEbook last = p->firstEbook;
        while (last->next != nullptr) {
            last = last->next;
        }
        last->next = c;
        c->prev = last;
        return;
    }
    default:
        cout << "Pilihan tidak valid!" << endl;
    }
}
void deleteChildOption (adrRak p, adrEbook &c, int pilihan, string idEbook) {
    switch (pilihan) {
    case 1:
        c = p->firstEbook;
        if (c == nullptr) {
            cout << "Tidak ada ebook untuk dihapus." << endl;
            return;
        }
        p->firstEbook = c->next;
        if (p->firstEbook != nullptr) {
            p->firstEbook->prev = nullptr;
        }
        c->next = nullptr;
        c->prev = nullptr;
        return;
    case 2:
        c = findChildById(p, idEbook);
        if (c == nullptr) {
            cout << "ID tidak ditemukan! Silahkan input ulang" << endl;
            return;
        }
        if (c->prev != nullptr) {
            c->prev->next = c->next;
        } else {
            p->firstEbook = c->next;
        }
        if (c->next != nullptr) {
            c->next->prev = c->prev;
        }
        c->next = nullptr;
        c->prev = nullptr;
        return;
    case 3:
        c = p->firstEbook;
        if (c == nullptr) {
            cout << "Tidak ada ebook untuk dihapus." << endl;
            return;
        }
        while (c->next != nullptr) {
            c = c->next;
        }
        if (c->prev != nullptr) {
            c->prev->next = nullptr;
        } else {
            p->firstEbook = nullptr;
        }
        c->prev = nullptr;
        return;
    }
}
void deleteAllChild (adrRak p) {
    adrEbook c = p->firstEbook;
    while (c != nullptr) {
        adrEbook temp = c;
        c = c->next;
        delete temp;
    }
    p->firstEbook = nullptr;   
}