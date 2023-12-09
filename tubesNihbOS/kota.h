#ifndef KOTA_H_INCLUDED //SLLCIRCULAR
#define KOTA_H_INCLUDED

#include <iostream>
using namespace std;

typedef string infotypeKota;
typedef struct elmKota * addressKota;

struct elmKota{
    infotypeKota infokota;
    addressKota next;
};

struct KotaList{
    addressKota first;
};

void createListKota(KotaList &Lk);
bool isEmptyKota(KotaList Lk);
addressKota newElementKota(infotypeKota x);
addressKota findElementKota(KotaList Lk,infotypeKota x);
void insertLastKota(KotaList &Lk,addressKota p);
void deleteFirstKota(KotaList &Lk,addressKota &p);
void deleteLastKota(KotaList &Lk,addressKota &p);
void deleteAfterKota(addressKota prec,addressKota &p);
void removeKota(KotaList &Lk,infotypeKota x);
void printInfoKota(KotaList Lk);


#endif // KOTA_H_INCLUDED
