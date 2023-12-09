#include "jalan.h"
#include "kota.h"
#include "relasi.h"

int main()
{
    JalanList Lj;
    KotaList Lk;
    RelasiList Rl;
    infotypeJalan x,targetjalan;
    infotypeKota y,targetkota;
    int jumlahdata;
    int i = 0;

    createListJalan(Lj);
    cout << "Tubes Nih Deck" << endl;

    cout << "Masukan Jumlah data jalan yang ingin dimasukan: ";
    cin >> jumlahdata;

    while(i != jumlahdata){
        cout << "Masukan Data Jalan: ";
        cin >> x;
        insertLastJalan(Lj,newElementJalan(x));
        i++;
    }

    cout << "ISI DATA LIST JALAN:" << endl;
    printInfoJalan(Lj);


    createListKota(Lk);

    cout << "Masukan Jumlah data kota yang ingin dimasukan: ";
    cin >> jumlahdata;

    int n = 0;
    while(n != jumlahdata){
        cout << "Masukan Data Kota: ";
        cin >> y;
        insertLastKota(Lk,newElementKota(y));
        n++;
    }

    cout << "ISI DATA LIST KOTA:" << endl;
    printInfoKota(Lk);

    createListRelasi(Rl);

    int jumlahrelasi;
    cout << "Relasikan Kota dan jalan: " << endl;
    cout << "Berapa relasi yang anda inginkan? ";
    cin >> jumlahrelasi;

    int s = 0;
    string kota;
    string jalan;
    while(s != jumlahrelasi){
        cout << "Hubungkan Kota: ";
        cin >> kota;
        cout << "Dengan Jalan: ";
        cin >> jalan;
        newRelation(Rl,Lk,Lj,kota,jalan);
        s++;
    }

    cout << "ISI RELASI:" << endl;
    showInfoRelasi(Rl);

    cout << "Anda ingin mencari data jalan pada kota? :";
    cin >> targetkota;
    cout << "Data jalan pada kota tersebut adalah:" << endl;

    searchStreetByCity(Rl,Lk,kota);

    cout << endl;

    string deleteKota;
    cout << "Anda akan menghapus kota? ";
    cin >> deleteKota;

    deleteCityandRelation(Rl,Lk,deleteKota);

    cout << "ISI RELASI:" << endl;
    showInfoRelasi(Rl);
    return 0;
}
