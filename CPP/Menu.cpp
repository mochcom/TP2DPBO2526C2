#include <iostream> // Header untuk operasi input dan output (cout, cin)
#include <string>   // Header untuk mengelola tipe data string

using namespace std; // Menggunakan namespace std agar tidak perlu menulis std::

// Definisi Base Class (Level 1): Menu
class Menu {
    protected: // Hak akses protected agar atribut bisa diakses langsung oleh class turunan
        string id_menu;    // Menyiapkan variabel untuk menyimpan ID unik menu
        string nama_menu;  // Menyiapkan variabel untuk menyimpan nama menu
        double harga_menu; // Menyiapkan variabel untuk menyimpan harga menu

    public: // Hak akses public untuk method yang dapat dipanggil dari luar class
        // Constructor default tanpa parameter
        Menu() {
            this->id_menu = "";    // Inisialisasi id_menu dengan string kosong
            this->nama_menu = "";  // Inisialisasi nama_menu dengan string kosong
            this->harga_menu = 0.0; // Inisialisasi harga_menu dengan nilai 0.0
        }

        // Constructor dengan parameter untuk mengisi nilai awal atribut
        Menu(string id_menu, string nama_menu, double harga_menu) {
            this->id_menu = id_menu;       // Mengisi atribut id_menu dari parameter input
            this->nama_menu = nama_menu;   // Mengisi atribut nama_menu dari parameter input
            this->harga_menu = harga_menu; // Mengisi atribut harga_menu dari parameter input
        }

        // Method Setter untuk mengubah nilai id_menu
        void setIdMenu(string id_menu) { this->id_menu = id_menu; }
        
        // Method Setter untuk mengubah nilai nama_menu
        void setNamaMenu(string nama_menu) { this->nama_menu = nama_menu; }
        
        // Method Setter untuk mengubah nilai harga_menu
        void setHargaMenu(double harga_menu) { this->harga_menu = harga_menu; }

        // Method Getter untuk mengambil nilai id_menu
        string getIdMenu() const { return this->id_menu; }
        
        // Method Getter untuk mengambil nilai nama_menu
        string getNamaMenu() const { return this->nama_menu; }
        
        // Method Getter untuk mengambil nilai harga_menu
        double getHargaMenu() const { return this->harga_menu; }

        // Destructor class Menu
        ~Menu() {}
};