#ifndef FILM_VIEW_H
#define FILM_VIEW_H
#include <iostream>
#include <string>
#include <iomanip> 
using namespace std;
#include "../Model/FilmModel.h"

void vAddFilm() {
    string judul, genre;
    int durasi;

    cout << "Masukkan Judul Film: ";
    getline(cin, judul);
    cout << "Masukkan Genre Film: ";
    getline(cin, genre);
    cout << "Masukkan Durasi Film (dalam menit): ";
    cin >> durasi;
    cin.ignore();  // Clear the newline character from the input buffer

    if (judul.empty() || genre.empty() || durasi <= 0) {
        cout << "Judul, genre, dan durasi film harus diisi dengan benar." << endl;
        return;
    }
    
    mAddFilm(judul, genre, durasi);
}

void vViewFilms() {
    mViewFilms();
}

void vSearchFilm() {
    string judul;
    cout << "Masukkan Judul Film yang dicari: ";
    getline(cin, judul);
    int index = mSearchFilm(judul);
    if (index != -1) {
        cout << "Data Film" << endl;
        cout << "===================================================================================" << endl;
        cout << "| No | Judul               | Genre              | Durasi (menit) |" << endl;
        cout << "===================================================================================" << endl;
        cout << "| " << setw(2) << left << (index + 1) 
             << " | " << setw(20) << left << films[index].judul
             << " | " << setw(18) << left << films[index].genre
             << " | " << setw(14) << left << films[index].durasi
             << " |" << endl;
        cout << "===================================================================================" << endl;
    } else {
        cout << "Film dengan judul " << judul << " tidak ditemukan." << endl;
    }
}

void vMenuFilm() {
    int pilihan;

    do {
        cout << "Menu Film:" << endl;
        cout << "1. Tambah Film" << endl;
        cout << "2. Lihat Daftar Film" << endl;
        cout << "3. Cari Film" << endl;
        cout << "0. Kembali ke Menu Utama" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();  // Clear the newline character from the input buffer

        switch (pilihan) {
            case 1:
                vAddFilm();
                break;
            case 2:
                vViewFilms();
                break;
            case 3:
                vSearchFilm();
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

