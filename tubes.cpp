#include "tubes.h"
#include <iostream>

using namespace std;

void menu()
{
    cout << "==========MENU==========" << endl;
    cout << "|1. Input Driver       |" << endl;
    cout << "|2. Cari Driver        |"<< endl;
    cout << "|3. Update Driver      |"<< endl;
    cout << "|4. Show Driver        |" << endl;
    cout << "|5. Hapus Driver       |" << endl;
    cout << "|6. Show All Data      |" << endl;
    cout << "|======================|" << endl;
    cout << "|7. Input Penumpang    |" << endl;
    cout << "|8. Cari Penumpang     |" << endl;
    cout << "|9. Update Penumpang   |" << endl;
    cout << "|10. Hapus Penumpang   |" << endl;
    cout << "|11. Total Transaksi   |" << endl;
    cout << "|======================|" << endl;
    cout << "|12. Exit              |" << endl;
    cout << "========================" << endl;
}
void createListDriver(ListDriver &L)
{
    First(L) = NULL;
    Last(L) = NULL;
}
adrDriver createElemenDriver(infotypeD x)
{
    adrDriver d = new elemenDriver;
    info(d) = x;
    next(d) = NULL;
    firstP(d) = NULL;
    return d;
}
adrPenumpang createElemenPenumpang(infotypeP x)
{
    adrPenumpang p = new elemenPenumpang;
    info(p) = x;
    next(p) = NULL;
    return p;
}
void insertFirstDriver(ListDriver &L, adrDriver p)
{
    if (First(L) == NULL){
        First(L) = p;
        Last(L) = p;
    } else {
        next(p) = First(L);
        First(L) = p;
    }
}
void insertLastDriver(ListDriver &L, adrDriver p)
{
    if (First(L) == NULL){
        First(L) = p;
        Last(L) = p;
    } else {
        next(Last(L)) = p;
        Last(L) = p;
    }
}
void deleteDriver(ListDriver &L, string id_driver, adrDriver &D)
{
    if (First(L) == NULL){
        cout << "Tidak ada data Driver!" << endl;
    } else {
        adrDriver P = searchDriver(L, id_driver);
        if (P == NULL){
            cout << "Driver tidak dapat ditemukan!" << endl;
        } else {
            if (First(L) == Last(L)){
                First(L) == NULL;
                Last(L) == NULL;
            } else {
                adrDriver temp = First(L);
                while (next(temp) != P){
                    temp = next(temp);
                }
                if (next(temp) == Last(L)){
                    Last(L) = temp;
                    next(temp) = NULL;
                } else {
                    next(temp) = next(P);
                    next(P) = NULL;
                }
            }
            cout << "Driver telah dihapus!" << endl;
        }
    }
}
adrDriver searchDriver(ListDriver L, string id_driver)
{
    adrDriver p = First(L);
    if (p == NULL){

    } else {
        while (p != NULL){
            if (info(p).id_driver == id_driver){
                return p;
            }
            p = next(p);
        }
    }
    return NULL;
}
void showDriver(ListDriver L)
{
    adrDriver D = First(L);
    if (D == NULL){
        cout << "Tidak ada Driver!" << endl;
    } else {
        while (D != NULL){
            cout << "========================" << endl;
            cout << "Data Driver      : " << endl;
            cout << "ID               : " << info(D).id_driver << endl;
            cout << "Nama             : " << info(D).nama << endl;
            cout << "Nomor Kontak     : " << info(D).no_hp << endl;
            cout << "Nomor Plat Motor : " << info(D).plat_nomor << endl;
            cout << "Jenis Motor      : " << info(D).jenis_motor << endl;
            cout << "========================" << endl;
            D = next(D);
        }
    }
}
void insertPenumpang(ListDriver &L, adrPenumpang p, string Driver)
{
    adrDriver d = searchDriver(L, Driver);
    if (d == NULL){
        cout << "Tidak ada data Driver!" << endl;
    } else {
        if (firstP(d) == NULL){
            firstP(d) = p;
        } else {
            adrPenumpang temp = firstP(d);
            while(next(temp) != NULL){
                temp = next(temp);
            }
            next(temp) = p;
        }
    }
}
void showAll(ListDriver &L)
{
    adrDriver D = First(L);
    if (D == NULL){
        cout << "Tidak ada data Driver!" << endl;
    } else {
        cout << "Data Driver: " << endl;
        while (D != NULL){
            cout << "========================" << endl;
            cout << "ID Driver          : " << info(D).id_driver << endl;
            cout << "Nama Driver        : " << info(D).nama << endl;
            cout << "Nomor Kontak Driver: " << info(D).no_hp << endl;
            cout << "Nomor Plat Motor   : " << info(D).plat_nomor << endl;
            cout << "Jenis Motor        : " << info(D).jenis_motor << endl;
            cout << "========================" << endl;
            cout << endl;

            cout << "Data Penumpang Dari Driver " << info(D).id_driver <<  ": " << endl;
            cout << endl;
            adrPenumpang p = firstP(D);
            if (p == NULL){
                cout << "Tidak ada Penumpang!" << endl;
            } else {
                while (p != NULL){
                    cout << "========================" << endl;
                    cout << "Nama Penumpang    : " << info(p).nama << endl;
                    cout << "Nomor Kontak      : " << info(p).no_hp << endl;
                    cout << "Lokasi Penjemputan: " << info(p).dari << endl;
                    cout << "Lokasi Pengantaran: " << info(p).ke << endl;
                    cout << "Biaya Pengantaran : " << info(p).biaya << endl;
                    cout << "========================" << endl;
                    p = next(p);
                }
            }
            cout << endl;
            D = next(D);
        }

    }
}
void updateDriver(ListDriver &L, string id_driver)
{
    adrDriver p = searchDriver(L, id_driver);
    if(p == NULL){
        cout << "Driver tidak ditemukan!" << endl;
    }else{
        cout << "Masukkan ID Driver Baru: ";
        cin >> info(p).id_driver;
        cin.ignore();

        cout << "Masukkan Nama Driver Baru: ";
        getline(cin, info(p).nama);

        cout << "Masukkan Nomor Kontak Driver Baru: ";
        cin >> info(p).no_hp;
        cin.ignore();

        cout << "Masukkan Plat Nomor Driver Baru: ";
        getline(cin, info(p).plat_nomor);

        cout << "Masukkan Jenis Motor yang Digunakan Driver Baru: ";
        cin >> info(p).jenis_motor;
        cin.ignore();
    }
}
void updatePenumpang(ListDriver &L, string nama, string id_driver)
{
    adrDriver D = searchDriver(L, id_driver);
    if (D != NULL){
        adrPenumpang p = firstP(D);
        bool check = false;
        while (!check){
            if (info(p).nama == nama){
                check = true;
                break;
            }
            p = next(p);
        }
        cout << "Masukkan Nama Penumpang Baru: ";
        cin >> info(p).nama;
        cout << "Masukkan Nomor Kontak Penumpang Baru: ";
        cin >> info(p).no_hp;
        cin.ignore();
        cout << "Masukkan Lokasi Penjemputan Penumpang Baru: ";
        cin >> info(p).dari;
        cin.ignore();
        cout << "Masukkan Lokasi Pengantaran Penumpang Baru: ";
        cin >> info(p).ke;
        cin.ignore();
        cout << "Masukkan Biaya Pengantaran Penumpang Baru: ";
        cin >> info(p).biaya;
        cin.ignore();
        cout << "Data Penumpang Telah di Update" << endl;
    }
}
void deletePenumpang(ListDriver &L, string nama, string id_driver, adrPenumpang &p)
{
    adrPenumpang S = searchPenumpang(L, id_driver, nama);
    adrDriver D = searchDriver(L, id_driver);
    adrPenumpang P = firstP(D);
    if (S != NULL){
        if (S == P){
            P = next(S);
            next(S) = NULL;
            firstP(D) = P;
        } else if (next(S) == NULL){
            while (next(P) != S){
                P = next(P);
            }
            next(P) = NULL;
        } else {
            while(next(P) != S){
                P = next(P);
            }
            next(P) = next(S);
            next(P) = NULL;
        }
        cout << "Penumpang sudah dihapus!" << endl;
    } else {
        "Penumpang tidak ditemukan!";
    }
}
int totalTransaksi(ListDriver L)
{
    int total = 0;
    adrDriver D = First(L);
    while (D != NULL){
        int pendapatan = 0;
        cout << "Pendapatan Driver " << info(D).nama << endl;
        adrPenumpang P = firstP(D);
        while (P != NULL){
            pendapatan += info(P).biaya;
            P = next(P);
        }
        cout << pendapatan << endl;
        total += pendapatan;
        D = next(D);
    }
    return total;
}
adrPenumpang searchPenumpang(ListDriver &L,string id_driver, string nama)
{
    adrDriver D = searchDriver(L, id_driver);
    if(D != NULL){
        adrPenumpang p = firstP(D);
        bool check = false;
        while(p != NULL){
            if(info(p).nama == nama){
                check = true;
                return p;
            }
            p = next(p);
        }
    }
    return NULL;
}

