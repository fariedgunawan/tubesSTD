#include "jalan.h"
#include "kota.h"

int main()
{
    JalanList Lj;
    KotaList Lk;
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

    cout << "Anda ingin menghapus data jalan?";
    cin >> targetjalan;

    removeJalan(Lj,targetjalan);

    cout << "ISI DATA LIST SETELAH DILAKUKAN REMOVE JALAN:" << endl;
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

    cout << "Anda ingin menghapus data kota?";
    cin >> targetkota;

    removeKota(Lk,targetkota);

    cout << "ISI DATA LIST SETELAH DILAKUKAN REMOVE KOTA:" << endl;
    printInfoKota(Lk);

    return 0;
}
