<?php
/**
 * Class Menu
 * Mengalokasikan Base Class (Level 1) dalam hirarki inheritance OOP.
 * Menampung atribut umum yang dimiliki oleh seluruh item menu.
 */
class Menu {
    // Definisi properti/atribut dengan enkapsulasi protected agar dapat diakses oleh class turunan
    protected $idMenu;    // Menyimpan ID unik menu (contoh: KOP01)
    protected $namaMenu;  // Menyimpan nama item menu
    protected $hargaMenu; // Menyimpan harga menu dalam format angka
    protected $fotoMenu;  // Menyimpan path/lokasi file foto menu (contoh: image/foto_espresso_single.jpg)

    /**
     * Constructor Parameterized
     * Menginisialisasi nilai awal dari properti saat objek dibuat.
     */
    public function __construct($idMenu = "", $namaMenu = "", $hargaMenu = 0.0, $fotoMenu = "") {
        $this->idMenu = $idMenu;
        $this->namaMenu = $namaMenu;
        $this->hargaMenu = $hargaMenu;
        $this->fotoMenu = $fotoMenu;
    }

    // --- Method Setter & Getter untuk idMenu ---
    public function setIdMenu($idMenu) { 
        $this->idMenu = $idMenu; // Mengubah nilai idMenu
    }
    public function getIdMenu() { 
        return $this->idMenu;    // Mengembalikan nilai idMenu
    }

    // --- Method Setter & Getter untuk namaMenu ---
    public function setNamaMenu($namaMenu) { 
        $this->namaMenu = $namaMenu; // Mengubah nilai namaMenu
    }
    public function getNamaMenu() { 
        return $this->namaMenu;      // Mengembalikan nilai namaMenu
    }

    // --- Method Setter & Getter untuk hargaMenu ---
    public function setHargaMenu($hargaMenu) { 
        $this->hargaMenu = $hargaMenu; // Mengubah nilai hargaMenu
    }
    public function getHargaMenu() { 
        return $this->hargaMenu;        // Mengembalikan nilai hargaMenu
    }

    // --- Method Setter & Getter untuk fotoMenu ---
    public function setFotoMenu($fotoMenu) { 
        $this->fotoMenu = $fotoMenu; // Mengubah nilai fotoMenu
    }
    public function getFotoMenu() { 
        return $this->fotoMenu;      // Mengembalikan nilai fotoMenu
    }
}
?>