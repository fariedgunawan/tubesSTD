#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "kota.h"
#include "jalan.h"

#include <iostream>
using namespace std;

typedef struct elmRelasi * addressRelasi;
typedef string infotypeRelasi;

struct elmRelasi{
    infotypeRelasi inforelasi;
    addressRelasi next;
    addressRelasi up;
    addressRelasi down;
};

struct RelasiList{
    addressRelasi first;
    addressRelasi last;
};

void createListRelasi(RelasiList &Rl);
bool isEmptyRelasi(RelasiList Rl);
addressRelasi newElementRelasi(infotypeKota kota,infotypeJalan jalan);
void insertLastRelasi(RelasiList &Rl,addressRelasi p);
void showInfoRelasi(RelasiList Rl,KotaList Lk,JalanList Lj);



#endif // RELASI_H_INCLUDED
