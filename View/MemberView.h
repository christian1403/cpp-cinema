#ifndef MEMBER_VIEW_H
#define MEMBER_VIEW_H
#include "../Model/MemberModel.h"
#include <iostream>
#include <iomanip>  // For setw() and left
#include <string>
using namespace std;

void vAddMember() {
    string nama, telp, email, password;

    cout << "Masukkan Nama: ";
    getline(cin, nama);
    cout << "Masukkan Telepon: ";
    getline(cin, telp);
    cout << "Masukkan Email: ";
    getline(cin, email);
    cout << "Masukkan Password: ";
    getline(cin, password);
    if (nama.empty() || telp.empty() || email.empty() || password.empty()) {
        cout << "Semua field harus diisi." << endl;
        return;
    }
    mAddMember(nama, telp, email, password);
}

void vViewMembers() {
    mViewMembers();
}

void searchMember() {
    string telp;
    cout << "Masukkan Telepon Member yang dicari: ";
    getline(cin, telp);
    int index = mSearchMember(telp);
    if (index != -1) {
        cout << "Data Member" << endl;
        cout << "===================================================================================" << endl;
        cout << "| No | Nama                 | Telepon      | Email                | Password     |" << endl;
        cout << "===================================================================================" << endl;
        cout << "| " << setw(2) << left << (index + 1) 
             << " | " << setw(20) << left << members[index].nama
             << " | " << setw(12) << left << members[index].telp
                << " | " << setw(20) << left << members[index].email
                << " | " << setw(12) << left << members[index].password
                << " |" << endl;
        cout << "===================================================================================" << endl;
    } else {
        cout << "Member dengan telepon " << telp << " tidak ditemukan." << endl;
    }
}

void vUpdatePassMember() {
    string telp, password;
    cout << "Masukkan Telepon Member yang ingin diupdate: ";
    getline(cin, telp);
    cout << "Masukkan Password Baru: ";
    getline(cin, password);
    
    if (telp.empty() || password.empty()) {
        cout << "Telepon dan Password harus diisi." << endl;
        return;
    }
    
    mUpdateMember(telp, password);
}

bool vLoginMember() {
    string telp, password;
    cout << "Masukkan Telepon: ";
    getline(cin, telp);
    cout << "Masukkan Password: ";
    getline(cin, password);
    
    if (telp.empty() || password.empty()) {
        cout << "Telepon dan Password harus diisi." << endl;
        return false;
    }
    
    return mLoginMember(telp, password);
}
#endif