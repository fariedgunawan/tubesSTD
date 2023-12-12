#include "kota.h" //sllcir

bool isEmptyKota(KotaList Lk){
    return Lk.first == NULL;
}
void createListKota(KotaList &Lk){
    Lk.first = NULL;
}
addressKota newElementKota(infotypeKota x){
    addressKota p = new elmKota;
    p->next = NULL;
    p->infokota = x;
    return p;
}

addressKota findElementKota(KotaList Lk, infotypeKota x) {
    addressKota p;
    p = Lk.first;

    if (p != NULL) {
        do {
            if (p->infokota == x) {
                return p;
            }
            p = p->next;
        } while (p != Lk.first);
    }

    return NULL;
}

void insertLastKota(KotaList &Lk,addressKota p){
    addressKota last;
    if(isEmptyKota(Lk)){
        Lk.first = p;
        Lk.first->next = Lk.first;
    }else{
        last = Lk.first;
        while(last->next != Lk.first){
            last = last->next;
        }
        last->next = p;
        p->next = Lk.first;
    }
}
void deleteFirstKota(KotaList &Lk,addressKota &p){
    addressKota q;
    if(isEmptyKota(Lk)){
        cout << "Data Kosong";
    }else if(Lk.first->next == Lk.first){
        Lk.first = NULL;
    }else{
        p = Lk.first;
        Lk.first = p->next;
        p->next = NULL;
        q = Lk.first;
        while(q->next != p){
            q = q->next;
        }
        q->next = Lk.first;
    }
}
void deleteLastKota(KotaList &Lk,addressKota &p){
    if(isEmptyKota(Lk)){
        cout << "Data Kosong";
    }else if(Lk.first->next == Lk.first){
        Lk.first = NULL;
    }else{
        addressKota q;
        p = Lk.first;
        while(p->next != Lk.first){
            q = p;
            p = p->next;
        }
        q->next = Lk.first;
        p->next = NULL;
    }
}
void deleteAfterKota(addressKota prec,addressKota &p){
    if(prec == NULL){
        cout << "Prec kosong";
    }else{
        p = prec->next;
        prec->next = p->next;
        p->next = NULL;
    }
}
void removeKota(KotaList &Lk,infotypeKota x){
    addressKota p,q,acuan,prec;
    acuan = findElementKota(Lk,x);
    if(isEmptyKota(Lk)){
        cout << "Data kosong";
    }else if(Lk.first->infokota == x){
        deleteFirstKota(Lk,p);
    }else if(acuan->next == Lk.first){
        deleteLastKota(Lk,p);
    }else{
        q = Lk.first;
        while(q->next != acuan){
            q = q->next;
        }
        prec = q;
        deleteAfterKota(prec,p);
    }
}
void printInfoKota(KotaList Lk){
    addressKota p;
    if(isEmptyKota(Lk)){
        cout << "Data kosong";
    }else{
        p = Lk.first;
        while(p->next != Lk.first){
            cout << "Data Kota: " << p->infokota << endl;
            p = p->next;
        }
        cout << "Data Kota: " << p->infokota << endl;
    }
    cout << endl;
}
