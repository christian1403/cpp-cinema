#ifndef FILMDATABASE_H
#define FILMDATABASE_H
#include <iostream>
#include <string>
using namespace std;

struct Film {
    string judul;
    string genre;
    int durasi; // dalam menit
};

Film films[100];
int nFilm = 0;
#endif