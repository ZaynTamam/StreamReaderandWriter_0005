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