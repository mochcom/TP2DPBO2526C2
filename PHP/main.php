<?php
// Mengimpor file definisi class Kopi beserta seluruh kelas induknya
require_once "Kopi.php";

/**
 * Instansiasi Array dari Objek Kopi.
 * Format path gambar disesuaikan menggunakan ekstensi .jpg (image/foto_[nama_menu].jpg).
 */
$daftarKopi = [
    new Kopi("KOP01", "Espresso Single", 18000, "image/foto_espresso_single.jpg", 30, "None", "Panas", "Arabika", "Espresso", 63),
    new Kopi("KOP02", "Iced Americano", 22000, "image/foto_iced_americano.jpg", 240, "Normal", "Dingin", "Arabika", "Espresso", 150),
    new Kopi("KOP03", "Caffe Latte", 28000, "image/foto_caffe_latte.jpg", 300, "Less Sugar", "Panas", "Blend", "Espresso", 75),
    new Kopi("KOP04", "V60 Manual Brew", 25000, "image/foto_v60_manual_brew.jpg", 200, "None", "Panas", "Arabika", "Pour Over", 110),
    new Kopi("KOP05", "Cold Brew Float", 32000, "image/foto_cold_brew_float.jpg", 350, "Normal", "Dingin", "Robusta", "Cold Drip", 200)
];
?>

<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Kopi Studio — Menu Catalog</title>
    
    <!-- Import Google Fonts (Playfair Display & Poppins) -->
    <link rel="preconnect" href="https://fonts.googleapis.com">
    <link rel="preconnect" href="https://fonts.gstatic.com" crossorigin>
    <link href="https://fonts.googleapis.com/css2?family=Playfair+Display:wght@600;700&family=Poppins:wght@300;400;500;600&display=swap" rel="stylesheet">
    
    <!-- Menghubungkan file stylesheet eksternal style.css -->
    <link rel="stylesheet" href="style.css">
</head>
<body>

    <!-- Container Utama -->
    <div class="container">
        
        <!-- Header Halaman -->
        <header>
            <h1>Daftar Menu Kopi</h1>
            <p>Katalog varian kopi berkualitas dengan spesifikasi olahan lengkap</p>
            <div class="header-divider"></div>
        </header>

        <!-- Container Tabel Katalog Menu -->
        <div class="table-card">
            <div class="table-responsive">
                <table>
                    <thead>
                        <tr>
                            <th>Foto</th>
                            <th>ID</th>
                            <th>Nama Menu</th>
                            <th>Harga</th>
                            <th>Volume</th>
                            <th>Tingkat Manis</th>
                            <th>Suhu</th>
                            <th>Biji Kopi</th>
                            <th>Metode Seduh</th>
                            <th>Kafein</th>
                        </tr>
                    </thead>
                    <tbody>
                        <!-- Perulangan foreach untuk menampilkan setiap objek Kopi dari array -->
                        <?php foreach ($daftarKopi as $kopi): ?>
                        <tr>
                            <!-- Kolom Foto Produk -->
                            <td>
                                <?php 
                                    // Mendapatkan path foto menggunakan getter getFotoMenu()
                                    $imgPath = $kopi->getFotoMenu();
                                    
                                    // Mengecek keberadaan file gambar di server, jika tidak ada gunakan gambar fallback Unsplash
                                    $imgSrc = file_exists($imgPath) ? $imgPath : "https://images.unsplash.com/photo-1509042239860-f550ce710b93?w=150&auto=format&fit=crop&q=80";
                                ?>
                                <!-- Menampilkan elemen img dengan class product-img agar ukuran seragam -->
                                <img src="<?= $imgSrc ?>" class="product-img" alt="<?= htmlspecialchars($kopi->getNamaMenu()) ?>">
                            </td>

                            <!-- Kolom ID Menu -->
                            <td><span class="badge-id"><?= htmlspecialchars($kopi->getIdMenu()) ?></span></td>
                            
                            <!-- Kolom Nama Menu -->
                            <td class="menu-title"><?= htmlspecialchars($kopi->getNamaMenu()) ?></td>
                            
                            <!-- Kolom Harga Menu (diformat ke Rupiah) -->
                            <td class="price">Rp <?= number_format($kopi->getHargaMenu(), 0, ',', '.') ?></td>
                            
                            <!-- Kolom Volume Minuman -->
                            <td><?= htmlspecialchars($kopi->getVolumeMl()) ?> ml</td>
                            
                            <!-- Kolom Level Sweetness -->
                            <td><?= htmlspecialchars($kopi->getTingkatManis()) ?></td>
                            
                            <!-- Kolom Suhu Sajian (dengan logika penentuan class CSS warna tag) -->
                            <td>
                                <?php $suhuClass = (strtolower($kopi->getSuhuSajian()) === 'panas') ? 'tag-panas' : 'tag-dingin'; ?>
                                <span class="tag-temp <?= $suhuClass ?>"><?= htmlspecialchars($kopi->getSuhuSajian()) ?></span>
                            </td>
                            
                            <!-- Kolom Spesifikasi Biji Kopi -->
                            <td><?= htmlspecialchars($kopi->getJenisBijiKopi()) ?></td>
                            
                            <!-- Kolom Metode Penyeduhan -->
                            <td><?= htmlspecialchars($kopi->getMetodeSeduh()) ?></td>
                            
                            <!-- Kolom Estimasi Kafein -->
                            <td><?= htmlspecialchars($kopi->getKadarKafeinMg()) ?> mg</td>
                        </tr>
                        <?php endforeach; ?>
                    </tbody>
                </table>
            </div>
        </div>

        <!-- Footer yang Menampilkan Informasi Total Item -->
        <footer>
            Total Varian Terdaftar: <strong><?= count($daftarKopi) ?> Item</strong>
        </footer>
    </div>

</body>
</html>