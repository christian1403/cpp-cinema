#ifndef MEMBER_DATABASE_H
#define MEMBER_DATABASE_H
#include <string>
using namespace std;

struct Member {
    string nama;
    string telp;
    string email;
    string password;
};

Member members[100];
int nMember = 0;
#endif