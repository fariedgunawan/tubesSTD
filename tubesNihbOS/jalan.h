#ifndef JALAN_H_INCLUDED
#define JALAN_H_INCLUDED

#include <iostream>
using namespace std;

typedef string infotypeJalan;
typedef struct elmJalan * addressJalan;

struct elmJalan{
    infotypeJalan infojalan;
    addressJalan next;
    addressJalan prev;
};

struct JalanList{
    addressJalan first;
    addressJalan last;
};

addressJalan newElementJalan(infotypeJalan x);
void createListJalan(JalanList &Lj);
bool isEmptyJalan(JalanList Lj);
addressJalan findElementJalan(JalanList Lj,infotypeJalan x);
void insertLastJalan(JalanList &Lj,addressJalan p);
void deleteFirstJalan(JalanList &Lj,addressJalan &p);
void deleteLastJalan(JalanList &Lj,addressJalan &p);
void deleteAfterJalan(addressJalan prec,addressJalan &p);
void removeJalan(JalanList &Lj,infotypeJalan x);
void printInfoJalan(JalanList Lj);

#endif // JALAN_H_INCLUDED
