#ifndef STUDIO_VIEW_H
#define STUDIO_VIEW_H
#include <iostream>
#include <string>
#include <iomanip>
#include "../Model/StudioModel.h"
using namespace std;

void vAddStudio() {
    string nama;
    int jumlahKursi;

    cout << "Masukkan Nama Studio: ";
    getline(cin, nama);
    cout << "Masukkan Jumlah Kursi: ";
    cin >> jumlahKursi;
    cin.ignore();  // Clear the newline character from the input buffer
    if (nama.empty() || jumlahKursi <= 0) {
        cout << "Nama studio dan jumlah kursi harus diisi dengan benar." << endl;
        return;
    }
    mAddStudio(nama, jumlahKursi);
}

void vViewStudios() {
    mViewStudios();
}

void vSearchStudio() {
    string nama;
    cout << "Masukkan Nama Studio yang dicari: ";
    getline(cin, nama);
    int index = mSearchStudio(nama);
    if (index != -1) {
        cout << "Data Studio" << endl;
        cout << "===================================================================================" << endl;
        cout << "| No | Nama                 | Jumlah Kursi |" << endl;
        cout << "===================================================================================" << endl;
        cout << "| " << setw(2) << left << (index + 1) 
             << " | " << setw(20) << left << studios[index].nama
             << " | " << setw(12) << left << studios[index].jumlahKursi
             << " |" << endl;
        cout << "===================================================================================" << endl;
    } else {
        cout << "Studio dengan nama " << nama << " tidak ditemukan." << endl;
    }
}

void vMenuStudio() {
    int pilihan;

    do {
        cout << "Menu Studio:" << endl;
        cout << "1. Tambah Studio" << endl;
        cout << "2. Lihat Daftar Studio" << endl;
        cout << "3. Cari Studio" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();  // Clear the newline character from the input buffer

        switch (pilihan) {
            case 1:
                vAddStudio();
                break;
            case 2:
                vViewStudios();
                break;
            case 3:
                vSearchStudio();
                break;
            case 0:
                cout << "Kembali ke Menu Utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while(pilihan != 0);
}
#endif