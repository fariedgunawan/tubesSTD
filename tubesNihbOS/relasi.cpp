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
        addressKota adrkot = findElementKota(Lk, kota);
        p = Rl.first;

        while (p != NULL) {
            if (p->up == adrkot) {
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

void deleteAfterRelation(addressRelasi prec,addressRelasi &p){
    if(prec == NULL){
        cout << "prec null";
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}

void deleteCityandRelation(RelasiList &Rl, KotaList &Lk, string kota) {
    addressKota adrkot;
    addressRelasi p, q, prec;
    int i = 0;
    int s = 0;

    if (Rl.first == NULL) {
        cout << "Relasi Kosong";
    } else {
        adrkot = findElementKota(Lk, kota);
        p = Rl.first;

        while (p != NULL) {
            if (p->up == adrkot) {
                i++;
            }
            p = p->next;
        }

        while (s != i) {
            p = Rl.first;
            while (p != NULL) {
                if (Rl.first->up == adrkot) {
                    deleteFirstRelation(Rl, q);
                } else if (p->next == NULL && p->up == adrkot) {
                    deleteLastRelation(Rl, q);
                } else if (p->next != NULL && p->next->up == adrkot) {
                    prec = p;
                    deleteAfterRelation(prec, q);
                }
                p = p->next;
            }
            s++;
        }
        removeKota(Lk, kota);
        showInfoRelasi(Rl);
    }
}


void deleteStreetbyCity(RelasiList &Rl, KotaList &Lk, JalanList &Lj, string kota) {
    addressRelasi p, q, prec;
    string targetjalan;

    searchStreetByCity(Rl, Lk, kota);
    cout << "Anda Akan Menghapus jalan apa?";
    cin >> targetjalan;

    p = Rl.first;

    if (Rl.first != NULL && Rl.first->down->infojalan == targetjalan && Rl.first->up->infokota == kota) {
        deleteFirstRelation(Rl, q);
    } else {
        p = Rl.first;
        while (p != NULL && !(p->down->infojalan == targetjalan && p->up->infokota == kota)) {
            prec = p;
            p = p->next;
        }

        if (p != NULL) {
            if (p->next == NULL) {
                deleteLastRelation(Rl, q);
            } else {
                deleteAfterRelation(prec, q);
            }
        } else {
            cout << "Jalan tidak ditemukan." << endl;
        }
    }

    showInfoRelasi(Rl);
}

void countCityByStreet(RelasiList Rl,string jalan){
    addressRelasi p;
    int i = 0;
    if(Rl.first == NULL){
        cout << "Relasi tidak ada";
    }else{
        p = Rl.first;
        while(p != NULL){
            if(p->down->infojalan == jalan){
                cout << p->up->infokota << endl;
                i++;
            }
            p = p->next;
        }
    }
    cout << "Terdapat " << i << " Kota" << " Yang Memiliki Jalan " << jalan;
    cout << endl;
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
