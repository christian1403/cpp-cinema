#ifndef JADWAL_VIEW_H
#define JADWAL_VIEW_H
#include <iostream>
#include <string>
#include <iomanip> 
#include "../Model/JadwalModel.h"
#include "../Model/StudioModel.h"
#include "../Model/FilmModel.h"
using namespace std;

void vAddJadwal() {
    int hargaTiket;
    string kode;
    string jam, tanggal;
    string studioNama, filmJudul;

    cout << "Masukkan Kode Jadwal: ";
    getline(cin, kode);
    cout << "Masukkan Jam (HH:MM): ";
    getline(cin, jam);
    cout << "Masukkan Tanggal (DD-MM-YYYY): ";
    getline(cin, tanggal);
    
    cout << "Masukkan Nama Studio: ";
    getline(cin, studioNama);

    if(mSearchStudio(studioNama) == -1) {
        cout << "Studio tidak ditemukan." << endl;
        return;
    }
    cout << "Masukkan Judul Film: ";
    getline(cin, filmJudul);

    if(mSearchFilm(filmJudul) == -1) {
        cout << "Film tidak ditemukan." << endl;
        return;
    }

    cout << "Masukkan Harga Tiket: ";
    cin >> hargaTiket;
    
    cin.ignore();

    Studio *studio = &studios[mSearchStudio(studioNama)];
    Film *film = &films[mSearchFilm(filmJudul)];

    mAddJadwal(kode, jam, tanggal, studio, film, hargaTiket);
}
void vViewJadwal() {
    mViewJadwal();
}

void vSearchJadwal() {
    string kode;
    cout << "Masukkan Kode Jadwal yang ingin dicari: ";
    getline(cin, kode);
    
    int index = mSearchJadwal(kode);
    if (index != -1) {
        cout << "Jadwal ditemukan:" << endl;
        cout << "Kode: " << jadwal[index].kode << endl;
        cout << "Jam: " << jadwal[index].jam << endl;
        cout << "Tanggal: " << jadwal[index].tanggal << endl;
        cout << "Studio: " << jadwal[index].studio->nama << " (Jumlah Kursi: " << jadwal[index].studio->jumlahKursi << ")" << endl;
        cout << "Film: " << jadwal[index].film->judul << " (" << jadwal[index].film->genre << ")" << endl;
        cout << "Harga Tiket: " << jadwal[index].hargaTiket << endl;
    } else {
        cout << "Jadwal dengan kode '" << kode << "' tidak ditemukan." << endl;
    }
}

void vMenuJadwal() {
    int pilihan;

    do {
        cout << "Menu Jadwal:" << endl;
        cout << "1. Tambah Jadwal" << endl;
        cout << "2. Lihat Daftar Jadwal" << endl;
        cout << "3. Cari Jadwal" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();  // Clear the newline character from the input buffer

        switch (pilihan) {
            case 1:
                vAddJadwal();
                break;
            case 2:
                vViewJadwal();
                break;
            case 3:
                vSearchJadwal();
                break;
            case 0:
                cout << "Kembali ke Menu Utama." << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 0);
}
#endif