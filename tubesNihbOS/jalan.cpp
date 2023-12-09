#include "jalan.h" // double ll

addressJalan newElementJalan(infotypeJalan x){
    addressJalan p = new elmJalan;
    p->next = NULL;
    p->prev = NULL;
    p->infojalan = x;
    return p;
}
void createListJalan(JalanList &Lj){
    Lj.first = NULL;
    Lj.last = NULL;
}
bool isEmptyJalan(JalanList Lj){
    return Lj.first == NULL && Lj.last == NULL;
}
addressJalan findElementJalan(JalanList Lj,infotypeJalan x){
    addressJalan p;
    p = Lj.first;
    while(p != NULL && p->infojalan != x){
        p = p->next;
    }
    return p;
}
void insertLastJalan(JalanList &Lj,addressJalan p){
    addressJalan last;
    if(isEmptyJalan(Lj)){
        Lj.first = p;
        Lj.last = p;
    }else{
       p->prev = Lj.last;
       Lj.last->next = p;
       Lj.last = p;
    }
}
void deleteFirstJalan(JalanList &Lj,addressJalan &p){
    if(isEmptyJalan(Lj)){
        cout << "Data Kosong";
    }else if(Lj.first == Lj.last){
        p = Lj.first;
        Lj.first = NULL;
        Lj.last = NULL;
    }else{
        p = Lj.first;
        Lj.first = p->next;
        p->next->prev = NULL;
        p->next = NULL;
    }
}
void deleteLastJalan(JalanList &Lj,addressJalan &p){
    if(isEmptyJalan(Lj)){
        cout << "Data Kosong";
    }else if(Lj.first == Lj.last){
        p = Lj.first;
        Lj.first = NULL;
        Lj.last = NULL;
    }else{
        p = Lj.last;
        Lj.last = p->prev;
        p->prev->next = NULL;
        p->prev = NULL;
    }
}
void deleteAfterJalan(addressJalan prec,addressJalan &p){
    if(prec == NULL){
        cout << "prec kosong";
    }else{
        p = prec->next;
        prec->next = p->next;
        prec->next->prev = prec;
        p->next = NULL;
        p->prev = NULL;
    }
}
void removeJalan(JalanList &Lj,infotypeJalan x){
    addressJalan p,q,acuan,prec;
    if(isEmptyJalan(Lj)){
        cout << "Data kosong";
    }else if(Lj.first->infojalan == x){
        deleteFirstJalan(Lj,p);
    }else if(Lj.last->infojalan == x){
        deleteLastJalan(Lj,p);
    }else{
        q = Lj.first;
        acuan = findElementJalan(Lj,x);
        while(q != NULL){
            if(q->next == acuan){
                prec = q;
            }
            q = q->next;
        }
        deleteAfterJalan(prec,p);
    }
}

void printInfoJalan(JalanList Lj){
    addressJalan p;
    p = Lj.first;
    if(isEmptyJalan(Lj)){
        cout << "Data Kosong";
    }else{
        while(p != NULL){
            cout << "Data jalan: " << p->infojalan << endl;
            p = p->next;
        }
    }
    cout << endl;
}
