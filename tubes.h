#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
#include <string>
#define First(L) L.First
#define Last(L) L.Last
#define info(P) P->info
#define next(P) P->next
#define prev(P) P->prev
#define firstP(P) P->firstP

using namespace std;

struct Driver {
    string id_driver;
    string nama;
    string no_hp;
    string plat_nomor;
    string jenis_motor;
};

struct Penumpang {
    string nama;
    string no_hp;
    string dari;
    string ke;
    int biaya;
};

typedef Driver infotypeD;
typedef Penumpang infotypeP;

typedef struct elemenDriver *adrDriver;
typedef struct elemenPenumpang *adrPenumpang;

struct elemenDriver {
    infotypeD info;
    adrDriver next;
    adrDriver prev;
    adrPenumpang firstP;
};

struct elemenPenumpang {
    infotypeP info;
    adrPenumpang next;
    adrPenumpang firstP;
};

struct ListDriver {
    adrDriver First;
    adrDriver Last;
};


void menu();
void createListDriver(ListDriver &L);
adrDriver createElemenDriver(infotypeD x);
adrPenumpang createElemenPenumpang(infotypeP x);
void insertFirstDriver(ListDriver &L, adrDriver P);
void insertLastDriver(ListDriver &L, adrDriver P);
void deleteDriver(ListDriver &L, string id_driver, adrDriver &D);
adrDriver searchDriver(ListDriver L, string id_driver);
void showDriver(ListDriver L);
void insertPenumpang(ListDriver &L, adrPenumpang P, string Driver);
void showAll(ListDriver &L);
void updateDriver(ListDriver &L, string id_driver);
void updatePenumpang(ListDriver &L, string nama, string id_driver);
void deletePenumpang(ListDriver &L, string nama, string id_driver, adrPenumpang &p);
int totalTransaksi(ListDriver L);
adrPenumpang searchPenumpang(ListDriver &L, string ID, string nama);


#endif // TUBES_H_INCLUDED
