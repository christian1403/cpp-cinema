#ifndef MEMBER_MODEL_H
#define MEMBER_MODEL_H
#include <iostream>
#include <iomanip>  // Add this for setw() and left
#include "../Database/MemberDatabase.h"
#include <string>

using namespace std;

void mAddMember(string nama, string telp, string email, string password) {
    if (nMember < 100) {
        members[nMember].nama = nama;
        members[nMember].telp = telp;
        members[nMember].email = email;
        members[nMember].password = password;
        nMember++;
    } else {
        cout << "Database penuh, tidak bisa menambah member baru." << endl;
    }
}

void mViewMembers() {
    if (nMember == 0) {
        cout << "Tidak ada member yang terdaftar." << endl;
        return;
    }
    
    cout << "Daftar Member:" << endl;
    cout << "Jumlah Member: " << nMember << endl;
    cout << "===================================================================================" << endl;
    cout << "| No | Nama                 | Telepon      | Email                | Password     |" << endl;
    cout << "===================================================================================" << endl;
    
    for (int i = 0; i < nMember; i++) {
        cout << "| " << setw(2) << left << (i + 1) 
             << " | " << setw(20) << left << members[i].nama
             << " | " << setw(12) << left << members[i].telp
             << " | " << setw(20) << left << members[i].email
             << " | " << setw(12) << left << members[i].password
             << " |" << endl;
    }
    cout << "===================================================================================" << endl;
}

int mSearchMember(string telp) {
    for (int i = 0; i < nMember; i++) {
        if (members[i].telp == telp) {
            return i;
        }
    }
    return -1;
}

void mUpdateMember(string telp, string password) {
    int index = mSearchMember(telp);
    if (index >= 0) {
        members[index].password = password;
        cout << "Password member dengan telepon " << telp << " telah diperbarui." << endl;
    } else {
        cout << "Member dengan telepon " << telp << " tidak ditemukan." << endl;
    }
}

bool mLoginMember(string telp, string password) {
    for (int i = 0; i < nMember; i++) {
        if (members[i].telp == telp && members[i].password == password) {
            cout << "Login berhasil untuk member: " << members[i].nama << endl;
            return true;
        }
    }
    cout << "Telepon atau password salah." << endl;
    return false;
}
#endif