#include <iostream>    // Header input/output
#include <string>      // Header tipe data string
#include "Minuman.cpp" // Mengimpor file Minuman.cpp sebagai Intermediary Class

using namespace std; // Menggunakan namespace standar

// Definisi Derived Class (Level 3): Kopi (Mewarisi sifat dari Class Minuman)
class Kopi : public Minuman {
    private: // Hak akses private khusus atribut milik class Kopi
        string jenis_biji_kopi; // Menyiapkan variabel jenis biji kopi (Arabika/Robusta/Blend)
        string metode_seduh;    // Menyiapkan variabel teknik penyeduhan (Espresso/V60/Cold Brew)
        int kadar_kafein_mg;    // Menyiapkan variabel estimasi kadar kafein dalam miligram

    public: // Hak akses public
        // Constructor default tanpa parameter
        Kopi() : Minuman() { // Memanggil constructor default milik Minuman
            this->jenis_biji_kopi = ""; // Inisialisasi jenis_biji_kopi dengan string kosong
            this->metode_seduh = "";    // Inisialisasi metode_seduh dengan string kosong
            this->kadar_kafein_mg = 0;  // Inisialisasi kadar_kafein_mg dengan 0
        }

        // Constructor dengan parameter lengkap seluruh hierarki class
        Kopi(string id_menu, string nama_menu, double harga_menu, int volume_ml, string tingkat_manis, string suhu_sajian, string jenis_biji_kopi, string metode_seduh, int kadar_kafein_mg)
            : Minuman(id_menu, nama_menu, harga_menu, volume_ml, tingkat_manis, suhu_sajian) { // Memanggil constructor berparameter Minuman
            this->jenis_biji_kopi = jenis_biji_kopi; // Mengisi atribut jenis_biji_kopi
            this->metode_seduh = metode_seduh;       // Mengisi atribut metode_seduh
            this->kadar_kafein_mg = kadar_kafein_mg; // Mengisi atribut kadar_kafein_mg
        }

        // Setter untuk jenis_biji_kopi
        void setJenisBijiKopi(string jenis_biji_kopi) { this->jenis_biji_kopi = jenis_biji_kopi; }
        
        // Setter untuk metode_seduh
        void setMetodeSeduh(string metode_seduh) { this->metode_seduh = metode_seduh; }
        
        // Setter untuk kadar_kafein_mg
        void setKadarKafeinMg(int kadar_kafein_mg) { this->kadar_kafein_mg = kadar_kafein_mg; }

        // Getter untuk jenis_biji_kopi
        string getJenisBijiKopi() const { return this->jenis_biji_kopi; }
        
        // Getter untuk metode_seduh
        string getMetodeSeduh() const { return this->metode_seduh; }
        
        // Getter untuk kadar_kafein_mg
        int getKadarKafeinMg() const { return this->kadar_kafein_mg; }

        // Destructor class Kopi
        ~Kopi() {}
};