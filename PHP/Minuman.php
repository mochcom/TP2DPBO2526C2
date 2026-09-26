<?php
// Mengimpor file Menu.php sebagai parent class
require_once "Menu.php";

/**
 * Class Minuman
 * Merupakan Intermediary Class (Level 2) yang mewarisi (inherits) atribut dari class Menu.
 */
class Minuman extends Menu {
    // Definisi atribut spesifik untuk kategori minuman
    protected $volumeMl;     // Menyimpan takaran volume dalam mililiter (ml)
    protected $tingkatManis; // Menyimpan opsi kadar gula (misal: None, Normal, Less Sugar)
    protected $suhuSajian;   // Menyimpan suhu penyajian (misal: Panas, Dingin)

    /**
     * Constructor Parameterized berantai
     * Memanggil constructor parent (Menu) dan menginisialisasi atribut spesifik Minuman.
     */
    public function __construct($idMenu = "", $namaMenu = "", $hargaMenu = 0.0, $fotoMenu = "", $volumeMl = 0, $tingkatManis = "", $suhuSajian = "") {
        // Mengirimkan nilai atribut ke constructor parent class (Menu)
        parent::__construct($idMenu, $namaMenu, $hargaMenu, $fotoMenu);
        
        // Menginisialisasi atribut khusus kelas Minuman
        $this->volumeMl = $volumeMl;
        $this->tingkatManis = $tingkatManis;
        $this->suhuSajian = $suhuSajian;
    }

    // --- Method Setter & Getter untuk volumeMl ---
    public function setVolumeMl($volumeMl) { 
        $this->volumeMl = $volumeMl; // Mengubah nilai volumeMl
    }
    public function getVolumeMl() { 
        return $this->volumeMl;      // Mengembalikan nilai volumeMl
    }

    // --- Method Setter & Getter untuk tingkatManis ---
    public function setTingkatManis($tingkatManis) { 
        $this->tingkatManis = $tingkatManis; // Mengubah nilai tingkatManis
    }
    public function getTingkatManis() { 
        return $this->tingkatManis;          // Mengembalikan nilai tingkatManis
    }

    // --- Method Setter & Getter untuk suhuSajian ---
    public function setSuhuSajian($suhuSajian) { 
        $this->suhuSajian = $suhuSajian; // Mengubah nilai suhuSajian
    }
    public function getSuhuSajian() { 
        return $this->suhuSajian;        // Mengembalikan nilai suhuSajian
    }
}
?>