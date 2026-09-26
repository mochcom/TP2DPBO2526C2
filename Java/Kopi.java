// Definisi Derived Class (Level 3): Kopi (Inherits/Extends Minuman)
public class Kopi extends Minuman {
    private String jenisBijiKopi; // Variabel varietas biji kopi
    private String metodeSeduh;   // Variabel teknik penyeduhan
    private int kadarKafeinMg;    // Variabel kandungan kafein mg

    // Constructor Default
    public Kopi() {
        super();                 // Memanggil constructor default superclass (Minuman)
        this.jenisBijiKopi = ""; // Inisialisasi string kosong
        this.metodeSeduh = "";   // Inisialisasi string kosong
        this.kadarKafeinMg = 0;  // Inisialisasi integer 0
    }

    // Constructor Parameterized berantai dari Level 1 hingga Level 3
    public Kopi(String idMenu, String namaMenu, double hargaMenu, 
                int volumeMl, String tingkatManis, String suhuSajian, 
                String jenisBijiKopi, String metodeSeduh, int kadarKafeinMg) {
        super(idMenu, namaMenu, hargaMenu, volumeMl, tingkatManis, suhuSajian); // Panggil constructor Minuman
        this.jenisBijiKopi = jenisBijiKopi; // Mengisi jenisBijiKopi
        this.metodeSeduh = metodeSeduh;     // Mengisi metodeSeduh
        this.kadarKafeinMg = kadarKafeinMg; // Mengisi kadarKafeinMg
    }

    // Setter untuk jenisBijiKopi
    public void setJenisBijiKopi(String jenisBijiKopi) { this.jenisBijiKopi = jenisBijiKopi; }
    
    // Setter untuk metodeSeduh
    public void setMetodeSeduh(String metodeSeduh) { this.metodeSeduh = metodeSeduh; }
    
    // Setter untuk kadarKafeinMg
    public void setKadarKafeinMg(int kadarKafeinMg) { this.kadarKafeinMg = kadarKafeinMg; }

    // Getter untuk jenisBijiKopi
    public String getJenisBijiKopi() { return this.jenisBijiKopi; }
    
    // Getter untuk metodeSeduh
    public String getMetodeSeduh() { return this.metodeSeduh; }
    
    // Getter untuk kadarKafeinMg
    public int getKadarKafeinMg() { return this.kadarKafeinMg; }
}