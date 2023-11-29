#include "relasi.h"


void createListRelasi(RelasiList &Rl){
    Rl.first = NULL;
    Rl.last = NULL;
}

bool isEmptyRelasi(RelasiList Rl){
    return Rl.first == NULL && Rl.last == NULL;
}

addressRelasi newElementRelasi(infotypeKota kota,infotypeJalan jalan){
    addressRelasi p = new elmRelasi;
    p->up = findElementKota(kota);
    p->down = findElementJalan(jalan);
    p->next = NULL;
    return p;
}
void insertLastRelasi(RelasiList &Rl,addressRelasi p){
    if(isEmptyRelasi(Rl)){
        Rl.first = p;
        Rl.last = p;
    }else{
        Rl.last->next = p;
        Rl.last = p;
    }
}
void showInfoRelasi(RelasiList Rl,KotaList Lk,JalanList Lj){
    addressRelasi p;
    if(isEmptyRelasi(Rl)){
        cout << "Relasi tidak ada";
    }else{
        p = Rl.first;
        while(p != NULL){
            cout << "Kota: " << p->up->inforelasi << " Dengan Jalan " << p->down->inforelasi << endl;

            addressJalan q = p->down;
            while(q != NULL){
                cout << "Jalan: " << q->infojalan << endl;
                q = q->next;
            }
            p = p->next;
        }
    }
}
