#include "relasi.h"


void createListRelasi(RelasiList &Rl){
    Rl.first = NULL;
}

bool isEmptyRelasi(RelasiList Rl){
    return Rl.first == NULL;
}

addressRelasi newElementRelasi(){
    addressRelasi p = new elmRelasi;
    p->up = NULL;
    p->down = NULL;
    p->next = NULL;
    return p;
}
void insertLastRelasi(RelasiList &Rl,addressRelasi p){
    addressRelasi last;
    if(isEmptyRelasi(Rl)){
        Rl.first = p;
    }else{
        last = Rl.first;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = p;
    }
}

void newRelation(RelasiList &Rl,KotaList Lk,JalanList Lj,string kota,string jalan){
    addressKota adrkot;
    addressJalan adrjal;
    addressRelasi p;

    adrkot = findElementKota(Lk,kota);
    adrjal = findElementJalan(Lj,jalan);

    if(adrkot != NULL && adrjal != NULL){
        p = newElementRelasi();
        p->up = adrkot;
        p->down = adrjal;
        insertLastRelasi(Rl,p);
    }else{
        cout << "Data kota atau jalan tidak tersedia";
    }
}

void searchStreetByCity(RelasiList Rl, KotaList Lk, string kota) {
    addressRelasi p;
    if (isEmptyRelasi(Rl)) {
        cout << "Tidak ada relasi kemana pun";
    } else {
        p = Rl.first;
        while (p != NULL) {
            addressKota adrkot = findElementKota(Lk, kota);
            if (adrkot != NULL && p->up == adrkot) {
                cout << p->down->infojalan << endl;
            }
            p = p->next;
        }
    }
}

void deleteFirstRelation(RelasiList &Rl,addressRelasi &p){
    if(isEmptyRelasi(Rl)){
        cout << "Relasi tidak ada";
    }else if (Rl.first->next == NULL){
        p = Rl.first;
        Rl.first = NULL;
    }else{
        p = Rl.first;
        Rl.first = p->next;
        p->next = NULL;
    }
}

void deleteLastRelation(RelasiList &Rl,addressRelasi &p){
    if(isEmptyRelasi(Rl)){
        cout << "Data Kosong";
    }else if(Rl.first->next == NULL){
        p = Rl.first;
        Rl.first = NULL;
    }else{
        addressRelasi q;
        p = Rl.first;
        while(p->next != NULL){
            q = p;
            p = p->next;
        }
        q->next = NULL;
    }
}

void deleteCityandRelation(RelasiList &Rl,KotaList &Lk,string kota){
    addressRelasi p;
    if(isEmptyRelasi(Rl)){
        cout << "Relasi Tidak ada";
    }else{
        p = Rl.first;
        while(p != NULL){
            addressKota adrkot = findElementKota(Lk,kota);
            if(adrkot == Rl.first->up){
                deleteFirstRelation(Rl,p);
            }else if(Rl.first->up != adrkot && p->next == NULL && p->up == adrkot){
                deleteLastRelation(Rl,p);
            }
        }
        removeKota(Lk,kota);
    }
}
void showInfoRelasi(RelasiList Rl){
    addressRelasi p;
    if(isEmptyRelasi(Rl)){
        cout << "Relasi tidak ada";
    }else{
        p = Rl.first;
        while(p != NULL){
            cout << "Kota: " << p->up->infokota << " Berelasi dengan jalan " << p->down->infojalan << endl;
            p=p->next;;
        }
    }
    cout << endl;
}
