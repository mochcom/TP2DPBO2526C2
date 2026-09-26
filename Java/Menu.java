// Definisi Base Class (Level 1): Menu
public class Menu {
    protected String idMenu;    // Variabel ID Menu (bisa diakses subclass)
    protected String namaMenu;  // Variabel Nama Menu (bisa diakses subclass)
    protected double hargaMenu; // Variabel Harga Menu (bisa diakses subclass)

    // Constructor Default tanpa parameter
    public Menu() {
        this.idMenu = "";    // Inisialisasi string kosong
        this.namaMenu = "";  // Inisialisasi string kosong
        this.hargaMenu = 0.0; // Inisialisasi angka 0.0
    }

    // Constructor Parameterized untuk mengisi data awal
    public Menu(String idMenu, String namaMenu, double hargaMenu) {
        this.idMenu = idMenu;       // Mengisi nilai atribut idMenu
        this.namaMenu = namaMenu;   // Mengisi nilai atribut namaMenu
        this.hargaMenu = hargaMenu; // Mengisi nilai atribut hargaMenu
    }

    // Setter untuk idMenu
    public void setIdMenu(String idMenu) { this.idMenu = idMenu; }
    
    // Setter untuk namaMenu
    public void setNamaMenu(String namaMenu) { this.namaMenu = namaMenu; }
    
    // Setter untuk hargaMenu
    public void setHargaMenu(double hargaMenu) { this.hargaMenu = hargaMenu; }

    // Getter untuk idMenu
    public String getIdMenu() { return this.idMenu; }
    
    // Getter untuk namaMenu
    public String getNamaMenu() { return this.namaMenu; }
    
    // Getter untuk hargaMenu
    public double getHargaMenu() { return this.hargaMenu; }
}