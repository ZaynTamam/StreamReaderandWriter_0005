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