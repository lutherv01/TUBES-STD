#include <iostream>
#include "tubes.h"
#include <string>

using namespace std;

int main()
{
    ListDriver L;
    createListDriver(L);
    menu();
    int input;
    while(true){
        cout << "Pilihan Menu: ";
        cin >> input;
        if(cin.fail()){
            cout << "Input Salah Harap Masukkan Angka!" << endl;
            cin.clear();
            cin.ignore();
        }else if (input < 1 || input > 12){
            while (input < 1 || input > 12){
                cout << "Input Salah, Harap Pilih kembali: ";
                cin >> input;
            }
            break;
        } else {
            break;
        }
    }

    while(input != 12){
        switch(input){
        case 1:{
            infotypeD x;
            cin.ignore();
            cout << "Masukkan ID Driver: ";
            getline(cin, x.id_driver);

            cout << "Masukkan Nama Driver: ";
            getline(cin, x.nama);

            cout << "Masukkan Nomor Handphone Driver: ";
            getline(cin, x.no_hp);

            cout << "Masukkan Plat Nomor Motor Driver: ";
            getline(cin, x.plat_nomor);

            cout << "Masukkan Jenis Motor Driver: ";
            cin >> x.jenis_motor;
            cin.ignore();

            cout << "Insert First / Insert Last (F/L): ";
            string choose;
            cin >> choose;

            while(choose != "F" && choose != "L"){
                cout << "Pilihan Insert Salah, Silahkan Pilih Kembali: ";
                cin >> choose;
            }
            if(choose == "F"){
                insertFirstDriver(L, createElemenDriver(x));
            }else if(choose == "L"){
                insertLastDriver(L, createElemenDriver(x));
            }
            break;
        }

        case 2:{
            if (First(L) == NULL){
                cout << "Tidak ada Driver!" << endl;
            } else {
                cout << "Masukkan ID Driver: ";
                string ID;
                cin >> ID;
                adrDriver D = searchDriver(L, ID);
                if (D != NULL){
                    cout << "Driver Ditemukan!" << endl;
                    cout << "ID: " << info(D).id_driver << endl;
                    cout << "Nama: " << info(D).nama << endl;
                    cout << "Nomor Kontak: " << info(D).no_hp << endl;
                    cout << "Nomor Plat Motor: " << info(D).plat_nomor << endl;
                    cout << "Jenis Motor: " << info(D).jenis_motor << endl;
                    cout << endl;
                } else {
                    cout << "Driver tidak ditemukan!" << endl;
                }
            }
            break;
        }

        case 3: {
            cin.ignore();
            cout << "Masukkan ID Data Driver Yang Ingin Diubah: ";
            string ID;
            getline(cin, ID);
            updateDriver(L, ID);
            break;
        }

        case 4:{
            showDriver(L);
            break;
        }


        case 5:{
            cin.ignore();
            cout << "Masukkan ID Driver Yang Ingin Dihapus: ";
            string ID;
            cin.ignore();
            getline(cin, ID);
            adrDriver P;
            deleteDriver(L, ID, P);
            break;
        }

        case 6:{
            showAll(L);
            break;
        }

        case 7:{
            string nama;
            infotypeP x;
            cout << "Masukkan ID Driver: ";
            string ID;
            cin >> ID;
            adrDriver D = searchDriver(L, ID);
            if (D == NULL){
                cout << "Driver Tidak Ditemukan!" << endl;
            } else {
                cout << "Masukkan Nama Penumpang: ";
                cin.ignore();
                getline(cin, x.nama);
                cout << "Masukkan Nomor Handphone Penumpang: ";
                cin >> x.no_hp;
                cout << "Masukkan Lokasi Penjemputan: ";
                cin.ignore();
                getline(cin, x.dari);
                cout << "Masukkan Lokasi Pengantaran: ";
                cin.ignore();
                getline(cin, x.ke);
                cout << "Masukkan Biaya Pengantaran: ";
                cin >> x.biaya;
                adrPenumpang P = searchPenumpang(L, ID, nama);
                adrPenumpang Q = createElemenPenumpang(x);
                insertPenumpang(L, Q, ID);
            }
            break;
        }

        case 8: {
            cout << "Masukkan ID Driver: ";
            string ID, nama;
            cin >> ID;
            adrDriver D = searchDriver(L, ID);
            if (D == NULL){
                cout << "Driver tidak ditemukan!" << endl;
            } else {
                cout << "Masukkan Nama Penumpang Yang Ingin Dicari: ";
                cin.ignore();
                getline(cin, nama);
                adrPenumpang P = searchPenumpang(L, ID, nama);
                if (P == NULL){
                    cout << "Penumpang Tidak Ditemukan" << endl;
                } else {
                    cout << "Penumpang Ditemukan" << endl;
                    cout << "ID Driver: " << ID << endl;
                    cout << "Nama: " << info(P).nama << endl;
                    cout << "Nomor Handphone: " << info(P).no_hp << endl;
                    cout << "Lokasi Penjemputan: " << info(P).dari << endl;
                    cout << "Lokasi Pengantaran: " << info(P).ke << endl;
                    cout << "Biaya Pengantaran: " << info(P).biaya << endl;
                    cout << endl;
                }
            }

            break;
        }

        case 9:{
            cin.ignore();
            cout << "Masukkan ID Driver: ";
            string ID, nama;
            cin >> ID;
            adrDriver D = searchDriver(L, ID);
            if (D == NULL){
                cout << "Driver tidak ditemukan!" << endl;
            } else {
                cout << "Masukkan Nama Penumpang Yang Ingin Diubah: ";
                cin.ignore();
                getline(cin, nama);
                updatePenumpang(L, nama, ID);
            }
            break;
        }

        case 10:{
            adrPenumpang P;
            cout << "Masukkan ID Driver: ";
            string ID, nama;
            cin >> ID;
            adrDriver D = searchDriver(L, ID);
            if (D == NULL){
                cout << "Driver tidak ditemukan!" << endl;
            } else {
                cout << "Masukkan Nama Penumpang Yang Ingin Dihapus: ";
                cin.ignore();
                getline(cin, nama);
                deletePenumpang(L, nama, ID, P);
            }
            break;
        }

        case 11:{
            int total = totalTransaksi(L);
            cout << "Total Pendapatan: " << total << endl;
            break;
        }
        }
        menu();
        while(true){
        cout << "Pilihan: ";
        cin >> input;
        if(cin.fail()){
            cout << "Inputan Salah Harap Masukkan Angka!" << endl;
            cin.clear();
            cin.ignore();
        }else if (input < 1 || input > 12){
            while (input < 1 || input > 12){
                cout << "Input Salah, Harap Pilih kembali: ";
                cin >> input;
            }
            break;
        } else {
            break;
        }
    }

    }
    cout << "Terima Kasih" << endl;
    return 0;
}
