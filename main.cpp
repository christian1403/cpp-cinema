#include <iostream>
#include "View/MemberView.h"
#include "View/StudioView.h"
#include "View/FilmView.h"
#include "View/JadwalView.h"
using namespace std;

void initData() {

    mAddMember("Christian", "085784089313", "christian@user.com", "password123");
    mAddMember("Chandra", "085334815766", "chandra@user.com", "password456");

    mAddStudio("Studio A", 100);
    mAddStudio("Studio B", 150);

    mAddFilm("Film A", "Action", 120);
    mAddFilm("Film B", "Drama", 90);
}

void menuUtama() {
    int pilihan;

    do {
        cout << "Selamat datang di Cinema!" << endl;
        cout << "Silakan pilih menu:" << endl;

        cout << "Menu Utama:" << endl;
        cout << "1. Film" << endl;
        cout << "2. Studio" << endl;
        cout << "3. Jadwal" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                vMenuFilm();
                break;
            case 2:
                vMenuStudio();
                break;
            case 3:
                vMenuJadwal();
                break;
            case 0:
                cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while(pilihan != 0);
}

int main() {
    initData();

    int pilihan;
    do {
        cout << "Authentikasi:" << endl;
        cout << "1. Login" << endl;
        cout << "0. Keluar" << endl;
        cout << "Masukkan pilihan: ";
        cin >> pilihan;
        cin.ignore();

        bool isLogin = false;
        switch (pilihan)
        {
        case 1: 
            isLogin = vLoginMember();
            if(isLogin) {
                menuUtama();
            }
            break;
        case 0:
            cout << "Terima kasih telah menggunakan aplikasi ini!" << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
            break;
        }


    } while(pilihan != 0);
    return 0;
}
