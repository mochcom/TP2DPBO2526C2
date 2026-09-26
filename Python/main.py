from Kopi import Kopi # Mengimpor class Kopi dari modul models.py

# Trigger untuk mengecek duplikasi ID
def is_id_exist(daftar_kopi, id_check):
    for kopi in daftar_kopi: # Iterasi setiap data kopi
        if kopi.get_id_menu().upper() == id_check.upper(): # Cek kesamaan ID tanpa membedakan huruf besar/kecil
            return True # ID terdeteksi ganda
    return False # ID belum dipakai

# Trigger error handling untuk masukan tipe angka float/double
def input_float(prompt):
    while True: # Perulangan hingga input masukan benar
        try:
            val = float(input(prompt)) # Konversi masukan ke angka pecahan
            if val >= 0: return val # Mengembalikan nilai jika angka bernilai positif
            print("[ERROR] Angka tidak boleh negatif!") # Pesan jika angka negatif
        except ValueError: # Tangkap error jika masukan berupa huruf/karakter
            print("[ERROR] Input tidak valid! Harap masukkan angka yang benar.")

# Trigger error handling untuk masukan tipe angka integer
def input_int(prompt):
    while True: # Perulangan hingga input masukan benar
        try:
            val = int(input(prompt)) # Konversi masukan ke angka bulat
            if val >= 0: return val # Mengembalikan nilai jika angka bernilai positif
            print("[ERROR] Angka tidak boleh negatif!") # Pesan jika angka negatif
        except ValueError: # Tangkap error jika masukan berupa huruf/karakter
            print("[ERROR] Input tidak valid! Harap masukkan angka bulat yang benar.")

# Fungsi pembantu untuk membuat garis horizontal tabel
def print_line(col_widths):
    line = "+" + "+".join(["-" * (w + 2) for w in col_widths]) + "+" # Susun string garis
    print(line) # Cetak garis

# Fungsi untuk mencetak tabel dinamis
def tampilkan_tabel(daftar_kopi):
    headers = ["ID Menu", "Nama Menu", "Harga (Rp)", "Volume (ml)", "Tingkat Manis", "Suhu Sajian", "Biji Kopi", "Metode Seduh", "Kafein (mg)"]
    col_widths = [len(h) for h in headers] # Inisialisasi panjang awal dengan panjang header

    # Cari panjang teks terpanjang dari isi data
    for kopi in daftar_kopi:
        col_widths[0] = max(col_widths[0], len(kopi.get_id_menu()))
        col_widths[1] = max(col_widths[1], len(kopi.get_nama_menu()))
        col_widths[2] = max(col_widths[2], len(str(int(kopi.get_harga_menu()))))
        col_widths[3] = max(col_widths[3], len(str(kopi.get_volume_ml())))
        col_widths[4] = max(col_widths[4], len(kopi.get_tingkat_manis()))
        col_widths[5] = max(col_widths[5], len(kopi.get_suhu_sajian()))
        col_widths[6] = max(col_widths[6], len(kopi.get_jenis_biji_kopi()))
        col_widths[7] = max(col_widths[7], len(kopi.get_metode_seduh()))
        col_widths[8] = max(col_widths[8], len(str(kopi.get_kadar_kafein_mg())))

    # Cetak Header
    print_line(col_widths)
    header_row = "| " + " | ".join([f"{headers[i]:<{col_widths[i]}}" for i in range(len(headers))]) + " |"
    print(header_row)
    print_line(col_widths)

    # Cetak Baris Data
    for kopi in daftar_kopi:
        row = f"| {kopi.get_id_menu():<{col_widths[0]}} | {kopi.get_nama_menu():<{col_widths[1]}} | {int(kopi.get_harga_menu()):<{col_widths[2]}} | {kopi.get_volume_ml():<{col_widths[3]}} | {kopi.get_tingkat_manis():<{col_widths[4]}} | {kopi.get_suhu_sajian():<{col_widths[5]}} | {kopi.get_jenis_biji_kopi():<{col_widths[6]}} | {kopi.get_metode_seduh():<{col_widths[7]}} | {kopi.get_kadar_kafein_mg():<{col_widths[8]}} |"
        print(row)
    print_line(col_widths)

# Eksekusi Utama Program
def main():
    # Inisialisasi 5 data awal
    daftar_kopi = [
        Kopi("KOP01", "Espresso Single", 18000, 30, "None", "Panas", "Arabika", "Espresso", 63),
        Kopi("KOP02", "Iced Americano", 22000, 240, "Normal", "Dingin", "Arabika", "Espresso", 150),
        Kopi("KOP03", "Caffe Latte", 28000, 300, "Less Sugar", "Panas", "Blend", "Espresso", 75),
        Kopi("KOP04", "V60 Manual Brew", 25000, 200, "None", "Panas", "Arabika", "Pour Over", 110),
        Kopi("KOP05", "Cold Brew Float", 32000, 350, "Normal", "Dingin", "Robusta", "Cold Drip", 200)
    ]

    print("===========================================================")
    print("             DAFTAR MENU KOPI AWAL (5 DATA)                ")
    print("===========================================================")
    tampilkan_tabel(daftar_kopi)

    ulang = 'y' # Penanda opsi perulangan input
    while ulang.lower() == 'y': # Perulangan utama input pengguna
        print("\n>>> MASUKKAN DATA KOPI BARU <<<")
        
        # Validasi ID Unik
        while True:
            id_menu = input("ID Menu        : ").strip() # Membaca masukan ID
            if is_id_exist(daftar_kopi, id_menu): # Cek duplikasi
                print(f"[ERROR] ID '{id_menu}' sudah terdaftar! Harap gunakan ID unik lain.")
            else:
                break # Keluar dari loop jika ID unik
        
        nama_menu = input("Nama Menu      : ").strip() # Input Nama Menu
        harga_menu = input_float("Harga (Rp)     : ")   # Input Harga dengan Error Handling
        volume_ml = input_int("Volume (ml)    : ")    # Input Volume dengan Error Handling
        tingkat_manis = input("Tingkat Manis  : ").strip() # Input Tingkat Manis
        suhu_sajian = input("Suhu Sajian    : ").strip()   # Input Suhu Sajian
        jenis_biji = input("Jenis Biji Kopi: ").strip()    # Input Jenis Biji
        metode_seduh = input("Metode Seduh   : ").strip()  # Input Metode Seduh
        kadar_kafein = input_int("Kadar Kafein(mg): ")     # Input Kafein dengan Error Handling

        # Tambahkan objek Kopi baru ke daftar
        daftar_kopi.append(Kopi(id_menu, nama_menu, harga_menu, volume_ml, tingkat_manis, suhu_sajian, jenis_biji, metode_seduh, kadar_kafein))
        print("[SUKSES] Data Kopi baru berhasil ditambahkan!")
        tampilkan_tabel(daftar_kopi)
        
        # Menanyakan perulangan input
        ulang = input("\nApakah Anda ingin memasukkan data lagi? (y/n): ").strip()

    print("\n===========================================================")
    print("          DAFTAR MENU KOPI SETELAH PENAMBAHAN             ")
    print("===========================================================")
    tampilkan_tabel(daftar_kopi)

if __name__ == "__main__":
    main()