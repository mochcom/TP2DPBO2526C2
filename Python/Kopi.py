from Minuman import Minuman # Import class Minuman dari file minuman.py

# Definisi Derived Class (Level 3): Kopi (Inherits Minuman)
class Kopi(Minuman):
    def __init__(self, id_menu="", nama_menu="", harga_menu=0.0, volume_ml=0, tingkat_manis="", suhu_sajian="", jenis_biji_kopi="", metode_seduh="", kadar_kafein_mg=0):
        super().__init__(id_menu, nama_menu, harga_menu, volume_ml, tingkat_manis, suhu_sajian) # Panggil constructor Minuman
        self.__jenis_biji_kopi = jenis_biji_kopi # Atribut privat jenis_biji_kopi
        self.__metode_seduh = metode_seduh       # Atribut privat metode_seduh
        self.__kadar_kafein_mg = kadar_kafein_mg # Atribut privat kadar_kafein_mg

    # Getter & Setter untuk jenis_biji_kopi
    def get_jenis_biji_kopi(self): return self.__jenis_biji_kopi
    def set_jenis_biji_kopi(self, jenis_biji_kopi): self.__jenis_biji_kopi = jenis_biji_kopi

    # Getter & Setter untuk metode_seduh
    def get_metode_seduh(self): return self.__metode_seduh
    def set_metode_seduh(self, metode_seduh): self.__metode_seduh = metode_seduh

    # Getter & Setter untuk kadar_kafein_mg
    def get_kadar_kafein_mg(self): return self.__kadar_kafein_mg
    def set_kadar_kafein_mg(self, kadar_kafein_mg): self.__kadar_kafein_mg = kadar_kafein_mg