
#ifndef STUDIO_MODEL_H
#define STUDIO_MODEL_H

#include <iostream>
#include <string>
#include <iomanip> 
#include "../Database/StudioDatabase.h"
using namespace std;

void mAddStudio(string nama, int jumlahKursi) {
    if (nStudio < 100) {
        studios[nStudio].nama = nama;
        studios[nStudio].jumlahKursi = jumlahKursi;
        nStudio++;
    } else {
        cout << "Database studio penuh, tidak bisa menambah studio baru." << endl;
    }
}

void mViewStudios() {
    if (nStudio == 0) {
        cout << "Tidak ada studio yang terdaftar." << endl;
        return;
    }
    
    cout << "Daftar Studio:" << endl;
    cout << "Jumlah Studio: " << nStudio << endl;
    cout << "===================================================================================" << endl;
    cout << "| No | Nama                 | Jumlah Kursi |" << endl;
    cout << "===================================================================================" << endl;
    
    for (int i = 0; i < nStudio; i++) {
        cout << "| " << setw(2) << left << (i + 1) 
             << " | " << setw(20) << left << studios[i].nama
             << " | " << setw(12) << left << studios[i].jumlahKursi
             << " |" << endl;
    }
    cout << "===================================================================================" << endl;
}

int mSearchStudio(string nama) {
    for (int i = 0; i < nStudio; i++) {
        if (studios[i].nama == nama) {
            return i;
        }
    }
    return -1;
}
#endif