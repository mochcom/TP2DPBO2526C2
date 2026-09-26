<?php
// Mengimpor file Minuman.php sebagai parent class lanjutan
require_once "Minuman.php";

/**
 * Class Kopi
 * Merupakan Derived Class (Level 3) yang mewarisi atribut dari Minuman (dan secara tak langsung dari Menu).
 */
class Kopi extends Minuman {
    // Definisi atribut spesifik untuk produk kopi
    private $jenisBijiKopi; // Menyimpan jenis varietas biji kopi (misal: Arabika, Robusta, Blend)
    private $metodeSeduh;   // Menyimpan metode penyeduhan (misal: Espresso, Pour Over, Cold Drip)
    private $kadarKafeinMg; // Menyimpan estimasi kadar kafein dalam miligram (mg)

    /**
     * Constructor Parameterized berantai
     * Memanggil constructor parent (Minuman) dan menginisialisasi atribut khusus Kopi.
     */
    public function __construct($idMenu = "", $namaMenu = "", $hargaMenu = 0.0, $fotoMenu = "", $volumeMl = 0, $tingkatManis = "", $suhuSajian = "", $jenisBijiKopi = "", $metodeSeduh = "", $kadarKafeinMg = 0) {
        // Mengirimkan atribut level Menu dan Minuman ke parent constructor
        parent::__construct($idMenu, $namaMenu, $hargaMenu, $fotoMenu, $volumeMl, $tingkatManis, $suhuSajian);
        
        // Menginisialisasi atribut khusus kelas Kopi
        $this->jenisBijiKopi = $jenisBijiKopi;
        $this->metodeSeduh = $metodeSeduh;
        $this->kadarKafeinMg = $kadarKafeinMg;
    }

    // --- Method Setter & Getter untuk jenisBijiKopi ---
    public function setJenisBijiKopi($jenisBijiKopi) { 
        $this->jenisBijiKopi = $jenisBijiKopi; // Mengubah jenis biji kopi
    }
    public function getJenisBijiKopi() { 
        return $this->jenisBijiKopi;          // Mengembalikan jenis biji kopi
    }

    // --- Method Setter & Getter untuk metodeSeduh ---
    public function setMetodeSeduh($metodeSeduh) { 
        $this->metodeSeduh = $metodeSeduh; // Mengubah metode seduh
    }
    public function getMetodeSeduh() { 
        return $this->metodeSeduh;        // Mengembalikan metode seduh
    }

    // --- Method Setter & Getter untuk kadarKafeinMg ---
    public function setKadarKafeinMg($kadarKafeinMg) { 
        $this->kadarKafeinMg = $kadarKafeinMg; // Mengubah kadar kafein
    }
    public function getKadarKafeinMg() { 
        return $this->kadarKafeinMg;          // Mengembalikan kadar kafein
    }
}
?>