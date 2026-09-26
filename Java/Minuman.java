// Definisi Intermediary Class (Level 2): Minuman (Inherits/Extends Menu)
public class Minuman extends Menu {
    protected int volumeMl;        // Variabel volume minuman (ml)
    protected String tingkatManis; // Variabel tingkat rasa manis
    protected String suhuSajian;   // Variabel suhu penyajian (Panas/Dingin)

    // Constructor Default
    public Minuman() {
        super();                // Memanggil constructor default milik superclass (Menu)
        this.volumeMl = 0;      // Inisialisasi volume integer 0
        this.tingkatManis = ""; // Inisialisasi string kosong
        this.suhuSajian = "";   // Inisialisasi string kosong
    }

    // Constructor Parameterized berantai dengan superclass
    public Minuman(String idMenu, String namaMenu, double hargaMenu, 
                   int volumeMl, String tingkatManis, String suhuSajian) {
        super(idMenu, namaMenu, hargaMenu); // Memanggil constructor parameter milik Menu
        this.volumeMl = volumeMl;         // Mengisi nilai volumeMl
        this.tingkatManis = tingkatManis; // Mengisi nilai tingkatManis
        this.suhuSajian = suhuSajian;     // Mengisi nilai suhuSajian
    }

    // Setter untuk volumeMl
    public void setVolumeMl(int volumeMl) { this.volumeMl = volumeMl; }
    
    // Setter untuk tingkatManis
    public void setTingkatManis(String tingkatManis) { this.tingkatManis = tingkatManis; }
    
    // Setter untuk suhuSajian
    public void setSuhuSajian(String suhuSajian) { this.suhuSajian = suhuSajian; }

    // Getter untuk volumeMl
    public int getVolumeMl() { return this.volumeMl; }
    
    // Getter untuk tingkatManis
    public String getTingkatManis() { return this.tingkatManis; }
    
    // Getter untuk suhuSajian
    public String getSuhuSajian() { return this.suhuSajian; }
}