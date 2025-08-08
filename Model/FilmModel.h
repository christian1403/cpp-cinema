#ifndef FILM_MODEL_H
#define FILM_MODEL_H
#include <iostream>
#include <string>
#include <iomanip>
#include "../Database/FilmDatabase.h"
using namespace std;

void mAddFilm(string judul, string genre, int durasi) {
    if (nFilm < 100) {
        films[nFilm].judul = judul;
        films[nFilm].genre = genre;
        films[nFilm].durasi = durasi;
        nFilm++;
    } else {
        cout << "Database film penuh, tidak bisa menambah film baru." << endl;
    }
}

void mViewFilms() {
    if (nFilm == 0) {
        cout << "Tidak ada film yang terdaftar." << endl;
        return;
    }
    
    cout << "Daftar Film:" << endl;
    cout << "Jumlah Film: " << nFilm << endl;
    cout << "===================================================================================" << endl;
    cout << "| No | Judul               | Genre              | Durasi (menit) |" << endl;
    cout << "===================================================================================" << endl;
    
    for (int i = 0; i < nFilm; i++) {
        cout << "| " << setw(2) << left << (i + 1) 
             << " | " << setw(20) << left << films[i].judul
             << " | " << setw(18) << left << films[i].genre
             << " | " << setw(14) << left << films[i].durasi
             << " |" << endl;
    }
    cout << "===================================================================================" << endl;
}

int mSearchFilm(string judul) {
    for (int i = 0; i < nFilm; i++) {
        if (films[i].judul == judul) {
            return i;
        }
    }
    return -1;
}

#endif