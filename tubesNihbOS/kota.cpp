#include "kota.h" //sllcir

bool isEmptyKota(KotaList Lk){
    return Lk.first == NULL && Lk.last == NULL;
}
void createListKota(KotaList &Lk){
    Lk.first = NULL;
    Lk.last = NULL;
}
addressKota newElementKota(infotypeKota x){
    addressKota p = new elmKota;
    p->next = NULL;
    p->infokota = x;
    return p;
}
addressKota findElementKota(infotypeKota x){
    addressKota p;
    KotaList Lk;
    p = Lk.first;
    while(p->next != Lk.first && p->infokota != x){
        p = p->next;
    }
    if(p->infokota == x){
        return p;
    }
    return p;
}
void insertLastKota(KotaList &Lk,addressKota p){
    if(isEmptyKota(Lk)){
        Lk.first = p;
        Lk.last = p;
        Lk.first->next = Lk.first;
    }else{
        Lk.last->next = p;
        Lk.last = p;
        Lk.last->next = Lk.first;
    }
}
void deleteFirstKota(KotaList &Lk,addressKota &p){
    if(isEmptyKota(Lk)){
        cout << "Data Kosong";
    }else if(Lk.first->next == Lk.first){
        Lk.first = NULL;
        Lk.last = NULL;
    }else{
        p = Lk.first;
        Lk.first = p->next;
        p->next = NULL;
        Lk.last->next = Lk.first;
    }
}
void deleteLastKota(KotaList &Lk,addressKota &p){
    if(isEmptyKota(Lk)){
        cout << "Data Kosong";
    }else if(Lk.first->next == Lk.first){
        Lk.first = NULL;
        Lk.last = NULL;
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
    if(isEmptyKota(Lk)){
        cout << "Data kosong";
    }else if(Lk.first->infokota == x){
        deleteFirstKota(Lk,p);
    }else if(Lk.last->infokota == x){
        deleteLastKota(Lk,p);
    }else{
        q = Lk.first;
        acuan = findElementKota(x);
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
