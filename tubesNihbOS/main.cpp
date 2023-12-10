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

    cout << "Tubes Nih Deck" << endl;
    cout << "======PLANOLOGI SYSTEM======" << endl;
    cout << "Pilih Opsi dibawah ini:" << endl;
    cout << "1.INPUT KOTA" << endl;
    cout << "2.INPUT JALAN" << endl;
    cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
    cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
    cout << "5.SHOW RELASI" << endl;
    cout << "6.SHOW KOTA" << endl;
    cout << "7.SHOW JALAN" << endl;
    cout << "8.DELETE CITY AND RELATION" << endl;
    cout << "0.EXIT" << endl;
    int opsi;
    cout << "Masukan Opsi: ";
    cin >> opsi;
    createListKota(Lk);
    createListJalan(Lj);
    createListRelasi(Rl);
    while(opsi != 0){
        if(opsi == 1){
            int jumlahdata;
            cout << "Masukan Jumlah data kota yang ingin dimasukan: ";
            cin >> jumlahdata;

            int n = 0;
            while(n != jumlahdata){
                cout << "Masukan Data Kota: ";
                cin >> y;
                insertLastKota(Lk,newElementKota(y));
                n++;
            }

            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;

        }else if(opsi == 2){
            int jumlahdata;
            cout << "Masukan Jumlah data jalan yang ingin dimasukan: ";
            cin >> jumlahdata;
            int i = 0;
            while(i != jumlahdata){
                cout << "Masukan Data Jalan: ";
                cin >> x;
                insertLastJalan(Lj,newElementJalan(x));
                i++;
            }

            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;
        }else if (opsi == 3){

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
            cout << "Input Relasi Selesai" << endl;

            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;

        }else if (opsi == 4){
            cout << "Anda ingin mencari data jalan pada kota? :";
            cin >> targetkota;
            cout << "Data jalan pada kota tersebut adalah:" << endl;

            searchStreetByCity(Rl,Lk,targetkota);

            cout << endl;

            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;
        }else if (opsi == 5){
            cout << "ISI RELASI:" << endl;
            showInfoRelasi(Rl);
            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;
        }else if (opsi == 6){
            cout << "ISI DATA LIST KOTA:" << endl;
            printInfoKota(Lk);
            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;
        }else if(opsi == 7){
            cout << "ISI DATA LIST JALAN:" << endl;
            printInfoJalan(Lj);
            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;
        }else{
            cout << "Anda akan menghapus data kota: ";
            cin >> targetkota;
            deleteCityandRelation(Rl,Lk,targetkota);
            cout << "Pilih Opsi dibawah ini:" << endl;
            cout << "1.INPUT KOTA" << endl;
            cout << "2.INPUT JALAN" << endl;
            cout << "3.RELASIKAN KOTA DAN JALAN" << endl;
            cout << "4.SEARCH JALAN BERDASARKAN KOTA" << endl;
            cout << "5.SHOW RELASI" << endl;
            cout << "6.SHOW KOTA" << endl;
            cout << "7.SHOW JALAN" << endl;
            cout << "8.DELETE CITY AND RELATION" << endl;
            cout << "0.EXIT" << endl;
            cout << "Masukan Opsi: ";
            cin >> opsi;
        }
    }
    return 0;
}
