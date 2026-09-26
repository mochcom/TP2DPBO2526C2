#include <iostream>  // Library input/output standar
#include <vector>    // Library untuk struktur data dynamic array (vector)
#include <string>    // Library manipulasi string
#include <algorithm> // Library fungsi matematika (std::max)
#include <iomanip>   // Library format tampilan angka/teks (setw)
#include <limits>    // Library untuk mereset buffer input (numeric_limits)
#include "Kopi.cpp"  // Mengimpor class Kopi

using namespace std; // Menggunakan namespace std

// Trigger untuk mengecek apakah ID Menu sudah terdaftar
bool isIdExist(const vector<Kopi>& daftarKopi, const string& id) {
    for (const auto& kopi : daftarKopi) { // Iterasi setiap item pada daftar kopi
        if (kopi.getIdMenu() == id) {     // Jika ID ditemukan sama persis
            return true;                  // Kembalikan true (ID sudah terpakai)
        }
    }
    return false;                         // Kembalikan false (ID unik/belum ada)
}

// Trigger error handling untuk input angka tipe double (seperti Harga)
double inputDouble(const string& prompt) {
    double value; // Variabel penampung masukan angka
    while (true) { // Loop hingga input valid
        cout << prompt; // Tampilkan pesan petunjuk input
        if (cin >> value && value >= 0) { // Cek apakah input berupa angka valid dan bernilai positif
            return value; // Kembalikan nilai jika valid
        } else { // Jika pengguna memasukkan huruf atau nilai tidak valid
            cout << "[ERROR] Input tidak valid! Harap masukkan angka yang benar.\n"; // Tampilkan pesan error
            cin.clear(); // Bersihkan flag error pada stream cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Hapus sisa karakter salah di buffer
        }
    }
}

// Trigger error handling untuk input angka tipe integer (seperti Volume & Kafein)
int inputInt(const string& prompt) {
    int value; // Variabel penampung masukan angka
    while (true) { // Loop hingga input valid
        cout << prompt; // Tampilkan pesan petunjuk input
        if (cin >> value && value >= 0) { // Cek apakah input berupa angka bulat valid
            return value; // Kembalikan nilai jika valid
        } else { // Jika pengguna memasukkan huruf/karakter salah
            cout << "[ERROR] Input tidak valid! Harap masukkan angka bulat yang benar.\n"; // Pesan error
            cin.clear(); // Bersihkan flag error pada cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Hapus buffer salah
        }
    }
}

// Fungsi pembantu untuk membuat garis horizontal tabel
void printLine(const vector<int>& colWidths) {
    cout << "+"; // Mencetak sudut kiri garis
    for (int w : colWidths) { // Looping setiap lebar kolom
        for (int i = 0; i < w + 2; i++) cout << "-"; // Mencetak karakter '-' sebanyak lebar kolom
        cout << "+"; // Mencetak pembatas antar kolom
    }
    cout << "\n"; // Garis baru
}

// Fungsi utama untuk menampilkan tabel dinamis
void tampilkanTabel(const vector<Kopi>& daftarKopi) {
    vector<string> headers = {
        "ID Menu", "Nama Menu", "Harga (Rp)", "Volume (ml)", 
        "Tingkat Manis", "Suhu Sajian", "Biji Kopi", "Metode Seduh", "Kafein (mg)"
    };

    vector<int> colWidths(headers.size()); // Array penampung panjang maksimal teks kolom
    for (size_t i = 0; i < headers.size(); i++) {
        colWidths[i] = headers[i].length(); // Set awal sebesar panjang teks header
    }

    // Hitung panjang teks terpanjang per kolom
    for (const auto& kopi : daftarKopi) {
        colWidths[0] = max(colWidths[0], (int)kopi.getIdMenu().length());
        colWidths[1] = max(colWidths[1], (int)kopi.getNamaMenu().length());
        colWidths[2] = max(colWidths[2], (int)to_string((long long)kopi.getHargaMenu()).length());
        colWidths[3] = max(colWidths[3], (int)to_string(kopi.getVolumeMl()).length());
        colWidths[4] = max(colWidths[4], (int)kopi.getTingkatManis().length());
        colWidths[5] = max(colWidths[5], (int)kopi.getSuhuSajian().length());
        colWidths[6] = max(colWidths[6], (int)kopi.getJenisBijiKopi().length());
        colWidths[7] = max(colWidths[7], (int)kopi.getMetodeSeduh().length());
        colWidths[8] = max(colWidths[8], (int)to_string(kopi.getKadarKafeinMg()).length());
    }

    // Cetak Header Tabel
    printLine(colWidths);
    cout << "|";
    for (size_t i = 0; i < headers.size(); i++) {
        cout << " " << left << setw(colWidths[i]) << headers[i] << " |";
    }
    cout << "\n";
    printLine(colWidths);

    // Cetak Isi Baris Data Tabel
    for (const auto& kopi : daftarKopi) {
        cout << "| " << left << setw(colWidths[0]) << kopi.getIdMenu()
             << " | " << left << setw(colWidths[1]) << kopi.getNamaMenu()
             << " | " << left << setw(colWidths[2]) << (long long)kopi.getHargaMenu()
             << " | " << left << setw(colWidths[3]) << kopi.getVolumeMl()
             << " | " << left << setw(colWidths[4]) << kopi.getTingkatManis()
             << " | " << left << setw(colWidths[5]) << kopi.getSuhuSajian()
             << " | " << left << setw(colWidths[6]) << kopi.getJenisBijiKopi()
             << " | " << left << setw(colWidths[7]) << kopi.getMetodeSeduh()
             << " | " << left << setw(colWidths[8]) << kopi.getKadarKafeinMg()
             << " |\n";
    }
    printLine(colWidths);
}

// Fungsi utama program
int main() {
    // Inisialisasi 5 data awal
    vector<Kopi> daftarKopi = {
        Kopi("KOP01", "Espresso Single", 18000, 30, "None", "Panas", "Arabika", "Espresso", 63),
        Kopi("KOP02", "Iced Americano", 22000, 240, "Normal", "Dingin", "Arabika", "Espresso", 150),
        Kopi("KOP03", "Caffe Latte", 28000, 300, "Less Sugar", "Panas", "Blend", "Espresso", 75),
        Kopi("KOP04", "V60 Manual Brew", 25000, 200, "None", "Panas", "Arabika", "Pour Over", 110),
        Kopi("KOP05", "Cold Brew Float", 32000, 350, "Normal", "Dingin", "Robusta", "Cold Drip", 200)
    };

    // Tampilkan tabel 5 data awal
    cout << "===========================================================\n";
    cout << "             DAFTAR MENU KOPI AWAL (5 DATA)                \n";
    cout << "===========================================================\n";
    tampilkanTabel(daftarKopi);

    char ulang = 'y'; // Variabel penanda perulangan input
    while (ulang == 'y' || ulang == 'Y') { // Loop utama perulangan masukan user
        cout << "\n>>> MASUKKAN DATA KOPI BARU <<<\n";
        string id, nama, manis, suhu, biji, metode;
        double harga;
        int volume, kafein;

        // Trigger validasi ID Unik
        while (true) {
            cout << "ID Menu        : "; cin >> id; // Input ID
            if (isIdExist(daftarKopi, id)) { // Jika ID sudah dipakai
                cout << "[ERROR] ID '" << id << "' sudah terdaftar! Harap gunakan ID unik lain.\n";
            } else {
                break; // Keluar loop jika ID valid/unik
            }
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer newline
        cout << "Nama Menu      : "; getline(cin, nama);      // Input Nama Menu (bisa spasi)
        
        // Input Angka dengan Error Handling
        harga = inputDouble("Harga (Rp)     : "); // Validasi input angka harga
        volume = inputInt("Volume (ml)    : ");   // Validasi input angka volume
        
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        cout << "Tingkat Manis  : "; getline(cin, manis);  // Input Tingkat Manis
        cout << "Suhu Sajian    : "; getline(cin, suhu);   // Input Suhu Sajian
        cout << "Jenis Biji Kopi: "; getline(cin, biji);   // Input Jenis Biji Kopi
        cout << "Metode Seduh   : "; getline(cin, metode); // Input Metode Seduh
        
        kafein = inputInt("Kadar Kafein(mg): "); // Validasi input angka kadar kafein

        // Tambahkan data baru ke daftar
        daftarKopi.push_back(Kopi(id, nama, harga, volume, manis, suhu, biji, metode, kafein));
        cout << "[SUKSES] Data Kopi baru berhasil ditambahkan!\n";
        tampilkanTabel(daftarKopi);
        
        // Menanyakan kepada pengguna apakah ingin input data lagi
        cout << "\nApakah Anda ingin memasukkan data lagi? (y/n): ";
        cin >> ulang; // Membaca jawaban user
    }
    
    // Menampilkan tabel akhir yang sudah di-update
    cout << "\n===========================================================\n";
    cout << "          DAFTAR MENU KOPI SETELAH PENAMBAHAN             \n";
    cout << "===========================================================\n";
    tampilkanTabel(daftarKopi);

    return 0; // Program selesai
}