#ifndef JADWAL_MODEL_H
#define JADWAL_MODEL_H
#include <iostream>
#include <string>
#include <iomanip>
#include "../Database/JadwalDatabase.h"
using namespace std;

void mAddJadwal(string kode, string jam, string tanggal, Studio *studio, Film *film, int hargaTiket) {
    if (nJadwal < 100) {
        jadwal[nJadwal].kode = kode;
        jadwal[nJadwal].jam = jam;
        jadwal[nJadwal].tanggal = tanggal;
        jadwal[nJadwal].studio = studio;
        jadwal[nJadwal].film = film;
        jadwal[nJadwal].hargaTiket = hargaTiket;
        nJadwal++;
    } else {
        cout << "Database jadwal penuh, tidak bisa menambah jadwal baru." << endl;
    }
}

void mViewJadwal() {
    if (nJadwal == 0) {
        cout << "Tidak ada jadwal yang terdaftar." << endl;
        return;
    }
    
    cout << "Daftar Jadwal:" << endl;
    cout << "Jumlah Jadwal: " << nJadwal << endl;
    cout << "=========================================================================================================" << endl;
    cout << "| No | Kode | Jam     | Tanggal   | Studio            | Film               | Harga Tiket |" << endl;
    cout << "=========================================================================================================" << endl;
    
    for (int i = 0; i < nJadwal; i++) {
        cout << "| " << setw(2) << left << (i + 1)
             << " | " << setw(4) << left << jadwal[i].kode
             << " | " << setw(7) << left << jadwal[i].jam
             << " | " << setw(10) << left << jadwal[i].tanggal
             << " | " << setw(20) << left << jadwal[i].studio->nama
             << " | " << setw(20) << left << jadwal[i].film->judul
             << " | " << setw(12) << left << jadwal[i].hargaTiket
             << " |" << endl;
    }
    cout << "=========================================================================================================" << endl;
}

int mSearchJadwal(string kode) {
    for (int i = 0; i < nJadwal; i++) {
        if (jadwal[i].kode == kode) {
            return i;
        }
    }
    return -1;
}

#endif