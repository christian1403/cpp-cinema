#ifndef JADWAL_DATABASE_H
#define JADWAL_DATABASE_H
#include <iostream>
#include <string>
#include "StudioDatabase.h"
#include "FilmDatabase.h"
using namespace std;

struct Jadwal {
    string kode;
    string jam;
    string tanggal;
    Studio *studio;
    Film *film;
    int hargaTiket;
};

Jadwal jadwal[100];
int nJadwal = 0;

#endif