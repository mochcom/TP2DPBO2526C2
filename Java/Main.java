import java.util.ArrayList; // Library untuk struktur data dynamic array (ArrayList)
import java.util.Scanner;   // Library untuk membaca masukan pengguna (Scanner)

public class Main {
    // Trigger untuk pengecekan ID unik
    private static boolean isIdExist(ArrayList<Kopi> daftarKopi, String id) {
        for (Kopi kopi : daftarKopi) {                  // Iterasi seluruh item kopi
            if (kopi.getIdMenu().equalsIgnoreCase(id)) { // Cek ID tanpa membedakan kapital/kecil
                return true;                            // Mengembalikan true jika ID terdeteksi ganda
            }
        }
        return false;                                   // Mengembalikan false jika ID belum terpakai
    }

    // Trigger error handling untuk input tipe Double (seperti Harga)
    private static double inputDouble(Scanner scanner, String prompt) {
        double value; // Variabel penampung nilai
        while (true) { // Loop hingga input valid
            System.out.print(prompt); // Tampilkan instruksi
            if (scanner.hasNextDouble()) { // Cek apakah masukan berupa double yang valid
                value = scanner.nextDouble(); // Ambil nilai
                if (value >= 0) return value; // Jika bernilai positif, kembalikan nilai
            }
            System.out.println("[ERROR] Input tidak valid! Harap masukkan angka yang benar."); // Pesan error
            scanner.nextLine(); // Clear buffer masukan yang salah
        }
    }

    // Trigger error handling untuk input tipe Integer (seperti Volume & Kafein)
    private static int inputInt(Scanner scanner, String prompt) {
        int value; // Variabel penampung nilai
        while (true) { // Loop hingga input valid
            System.out.print(prompt); // Tampilkan instruksi
            if (scanner.hasNextInt()) { // Cek apakah masukan berupa integer yang valid
                value = scanner.nextInt(); // Ambil nilai
                if (value >= 0) return value; // Jika bernilai positif, kembalikan nilai
            }
            System.out.println("[ERROR] Input tidak valid! Harap masukkan angka bulat yang benar."); // Pesan error
            scanner.nextLine(); // Clear buffer masukan yang salah
        }
    }

    // Method utilitas untuk mencetak garis pembatas horizontal
    private static void printLine(int[] colWidths) {
        System.out.print("+");
        for (int w : colWidths) {
            for (int i = 0; i < w + 2; i++) System.out.print("-");
            System.out.print("+");
        }
        System.out.println();
    }

    // Method utama untuk menggambar tabel dinamis
    private static void tampilkanTabel(ArrayList<Kopi> daftarKopi) {
        String[] headers = {
            "ID Menu", "Nama Menu", "Harga (Rp)", "Volume (ml)", 
            "Tingkat Manis", "Suhu Sajian", "Biji Kopi", "Metode Seduh", "Kafein (mg)"
        };

        int[] colWidths = new int[headers.length];
        for (int i = 0; i < headers.length; i++) {
            colWidths[i] = headers[i].length(); // Inisialisasi awal dengan panjang teks header
        }

        // Cari panjang karakter maksimal per kolom
        for (Kopi kopi : daftarKopi) {
            colWidths[0] = Math.max(colWidths[0], kopi.getIdMenu().length());
            colWidths[1] = Math.max(colWidths[1], kopi.getNamaMenu().length());
            colWidths[2] = Math.max(colWidths[2], String.valueOf((long)kopi.getHargaMenu()).length());
            colWidths[3] = Math.max(colWidths[3], String.valueOf(kopi.getVolumeMl()).length());
            colWidths[4] = Math.max(colWidths[4], kopi.getTingkatManis().length());
            colWidths[5] = Math.max(colWidths[5], kopi.getSuhuSajian().length());
            colWidths[6] = Math.max(colWidths[6], kopi.getJenisBijiKopi().length());
            colWidths[7] = Math.max(colWidths[7], kopi.getMetodeSeduh().length());
            colWidths[8] = Math.max(colWidths[8], String.valueOf(kopi.getKadarKafeinMg()).length());
        }

        // Cetak Garis Atas dan Header
        printLine(colWidths);
        System.out.print("|");
        for (int i = 0; i < headers.length; i++) {
            System.out.printf(" %-" + colWidths[i] + "s |", headers[i]);
        }
        System.out.println();
        printLine(colWidths);

        // Cetak Isi Baris Data
        for (Kopi kopi : daftarKopi) {
            System.out.printf("| %-" + colWidths[0] + "s | %-" + colWidths[1] + "s | %-" + colWidths[2] + "d | %-" 
                            + colWidths[3] + "d | %-" + colWidths[4] + "s | %-" + colWidths[5] + "s | %-" 
                            + colWidths[6] + "s | %-" + colWidths[7] + "s | %-" + colWidths[8] + "d |\n",
                            kopi.getIdMenu(),
                            kopi.getNamaMenu(),
                            (long)kopi.getHargaMenu(),
                            kopi.getVolumeMl(),
                            kopi.getTingkatManis(),
                            kopi.getSuhuSajian(),
                            kopi.getJenisBijiKopi(),
                            kopi.getMetodeSeduh(),
                            kopi.getKadarKafeinMg());
        }
        printLine(colWidths);
    }

    // Method main eksekusi utama
    public static void main(String[] args) {
        ArrayList<Kopi> daftarKopi = new ArrayList<>(); // Instansiasi daftar objek kopi

        // Initial 5 Data
        daftarKopi.add(new Kopi("KOP01", "Espresso Single", 18000, 30, "None", "Panas", "Arabika", "Espresso", 63));
        daftarKopi.add(new Kopi("KOP02", "Iced Americano", 22000, 240, "Normal", "Dingin", "Arabika", "Espresso", 150));
        daftarKopi.add(new Kopi("KOP03", "Caffe Latte", 28000, 300, "Less Sugar", "Panas", "Blend", "Espresso", 75));
        daftarKopi.add(new Kopi("KOP04", "V60 Manual Brew", 25000, 200, "None", "Panas", "Arabika", "Pour Over", 110));
        daftarKopi.add(new Kopi("KOP05", "Cold Brew Float", 32000, 350, "Normal", "Dingin", "Robusta", "Cold Drip", 200));

        // Tampilkan Tabel Awal
        System.out.println("===========================================================");
        System.out.println("             DAFTAR MENU KOPI AWAL (5 DATA)                ");
        System.out.println("===========================================================");
        tampilkanTabel(daftarKopi);

        Scanner scanner = new Scanner(System.in); // Instansiasi Scanner untuk baca input
        String ulang = "y"; // Variabel perulangan input

        while (ulang.equalsIgnoreCase("y")) { // Loop perulangan input masukan
            System.out.println("\n>>> MASUKKAN DATA KOPI BARU <<<");

            // Validasi ID Unik
            String id;
            while (true) {
                System.out.print("ID Menu        : "); id = scanner.next(); // Input ID
                if (isIdExist(daftarKopi, id)) { // Jika ID sudah ada
                    System.out.println("[ERROR] ID '" + id + "' sudah terdaftar! Harap gunakan ID unik lain.");
                } else {
                    break; // Keluar dari loop jika ID unik
                }
            }

            scanner.nextLine(); // Clear buffer newline
            System.out.print("Nama Menu      : "); String nama = scanner.nextLine(); // Input Nama

            // Input Angka dengan Error Handling
            double harga = inputDouble(scanner, "Harga (Rp)     : "); // Validasi input angka harga
            int volume = inputInt(scanner, "Volume (ml)    : ");   // Validasi input angka volume

            scanner.nextLine(); // Clear buffer
            System.out.print("Tingkat Manis  : "); String manis = scanner.nextLine(); // Input Manis
            System.out.print("Suhu Sajian    : "); String suhu = scanner.nextLine();  // Input Suhu
            System.out.print("Jenis Biji Kopi: "); String biji = scanner.nextLine();  // Input Biji
            System.out.print("Metode Seduh   : "); String metode = scanner.nextLine(); // Input Metode

            int kafein = inputInt(scanner, "Kadar Kafein(mg): "); // Validasi input angka kafein

            // Tambahkan objek ke ArrayList
            daftarKopi.add(new Kopi(id, nama, harga, volume, manis, suhu, biji, metode, kafein));
            System.out.println("[SUKSES] Data Kopi baru berhasil ditambahkan!");
            tampilkanTabel(daftarKopi);

            // Menanyakan opsi input lagi kepada user
            System.out.print("\nApakah Anda ingin memasukkan data lagi? (y/n): ");
            ulang = scanner.next(); // Membaca jawaban user
        }

        // Tampilkan Tabel Setelah Penambahan Data Selesai
        System.out.println("\n===========================================================");
        System.out.println("          DAFTAR MENU KOPI SETELAH PENAMBAHAN             ");
        System.out.println("===========================================================");
        tampilkanTabel(daftarKopi);

        scanner.close(); // Menutup scanner
    }
}