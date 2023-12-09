#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include "kota.h"
#include "jalan.h"

#include <iostream>
using namespace std;

typedef struct elmRelasi * addressRelasi;

struct elmRelasi{
    addressRelasi next;
    addressKota up;
    addressJalan down;
};

struct RelasiList{
    addressRelasi first;
};

void createListRelasi(RelasiList &Rl);
bool isEmptyRelasi(RelasiList Rl);
addressRelasi newElementRelasi();
void deleteCityandRelation(RelasiList &Rl,KotaList &Lk,string kota);
void deleteLastRelation(RelasiList &Rl,addressRelasi &p);
void deleteFirstRelation(RelasiList &Rl,addressRelasi &p);
void insertLastRelasi(RelasiList &Rl,addressRelasi p);
void newRelation(RelasiList &Rl,KotaList Lk,JalanList Lj,string kota,string jalan);
void searchStreetByCity(RelasiList Rl,KotaList Lk,string jalan);
void showInfoRelasi(RelasiList Rl);



#endif // RELASI_H_INCLUDED
