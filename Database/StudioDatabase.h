#ifndef STUDIO_DATABASE_H
#define STUDIO_DATABASE_H
#include <iostream>
#include <string>
using namespace std;

struct Studio {
    string nama;
    int jumlahKursi;
};

Studio studios[100];
int nStudio = 0;
#endif