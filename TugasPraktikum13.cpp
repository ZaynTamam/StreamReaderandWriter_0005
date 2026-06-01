#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <stdexcept>

using namespace std;

class TokoElektronik {
private:
    array<string, 3> etalase;
    string namaFile = "DB_GibranJaya.txt";

public:
    TokoElektronik() {
        etalase[0] = "Laptop Gaming Solo";
        etalase[1] = "Monitor 3periode 24 Inch";
        etalase[2] = "Keyboard Mechanical OWI";
    }

    string ambilProduk(size_t nomorRak) {
        try {
            return etalase.at(nomorRak);
        } catch (const out_of_range& e) {
            string pesanError = "Gagal Mengambil Barang : Rak nomor " + to_string(nomorRak) + " kosong atau tidak tersedia!";
            throw runtime_error(pesanError);
        }
    }

    void tampilkanGudang() {
        ifstream file(namaFile);
        cout << "\n=== Daftar Barang di Gudang (DB_GibranJaya.txt) ===\n";
        
        if (!file.is_open()) {
            cout << "[ Gudang masih kosong / file belum dibuat ]\n";
            return;
        }

        string baris;
        int nomor = 1;
        bool adaIsi = false;
        
        while (getline(file, baris)) {
            cout << nomor << ". " << baris << "\n";
            nomor++;
            adaIsi = true;
        }
        
        if (!adaIsi) cout << "[ Gudang kosong ]\n";
        file.close();
    }

    void tambahBarang(const string& namaBarang) {
        ofstream file(namaFile, ios::app); 
        if (file.is_open()) {
            file << namaBarang << "\n";
            file.close();
            cout << ">> Sukses: Barang '" << namaBarang << "' ditambahkan ke gudang!\n";
        } else {
            cout << ">> Error: Gagal membuka file gudang.\n";
        }
    }