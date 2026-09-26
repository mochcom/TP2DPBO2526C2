#include <iostream> // Header untuk input/output
#include <string>   // Header untuk tipe data string
#include "Menu.cpp" // Mengimpor file Menu.cpp sebagai Base Class

using namespace std; // Menggunakan namespace standar

// Definisi Intermediary Class (Level 2): Minuman (Mewarisi sifat dari Class Menu)
class Minuman : public Menu {
    protected: // Hak akses protected untuk atribut kelas Minuman
        int volume_ml;        // Menyiapkan variabel untuk ukuran volume dalam mililiter
        string tingkat_manis; // Menyiapkan variabel untuk kadar gula/manis
        string suhu_sajian;   // Menyiapkan variabel untuk opsi suhu (Panas/Dingin)

    public: // Hak akses public
        // Constructor default tanpa parameter
        Minuman() : Menu() { // Memanggil constructor default milik Base Class (Menu)
            this->volume_ml = 0;       // Inisialisasi volume_ml dengan nilai 0
            this->tingkat_manis = "";  // Inisialisasi tingkat_manis dengan string kosong
            this->suhu_sajian = "";    // Inisialisasi suhu_sajian dengan string kosong
        }

        // Constructor dengan parameter lengkap (termasuk atribut milik Base Class)
        Minuman(string id_menu, string nama_menu, double harga_menu, int volume_ml, string tingkat_manis, string suhu_sajian)
            : Menu(id_menu, nama_menu, harga_menu) { // Memanggil constructor berparameter milik Menu
            this->volume_ml = volume_ml;         // Mengisi atribut volume_ml
            this->tingkat_manis = tingkat_manis; // Mengisi atribut tingkat_manis
            this->suhu_sajian = suhu_sajian;     // Mengisi atribut suhu_sajian
        }

        // Setter untuk merubah volume_ml
        void setVolumeMl(int volume_ml) { this->volume_ml = volume_ml; }
        
        // Setter untuk merubah tingkat_manis
        void setTingkatManis(string tingkat_manis) { this->tingkat_manis = tingkat_manis; }
        
        // Setter untuk merubah suhu_sajian
        void setSuhuSajian(string suhu_sajian) { this->suhu_sajian = suhu_sajian; }

        // Getter untuk mengambil volume_ml
        int getVolumeMl() const { return this->volume_ml; }
        
        // Getter untuk mengambil tingkat_manis
        string getTingkatManis() const { return this->tingkat_manis; }
        
        // Getter untuk mengambil suhu_sajian
        string getSuhuSajian() const { return this->suhu_sajian; }

        // Destructor class Minuman
        ~Minuman() {}
};