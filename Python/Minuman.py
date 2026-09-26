from Menu import Menu # Import class Menu dari file menu.py

# Definisi Intermediary Class (Level 2): Minuman (Inherits Menu)
class Minuman(Menu):
    def __init__(self, id_menu="", nama_menu="", harga_menu=0.0, volume_ml=0, tingkat_manis="", suhu_sajian=""):
        super().__init__(id_menu, nama_menu, harga_menu) # Memanggil constructor superclass Menu
        self._volume_ml = volume_ml         # Inisialisasi volume_ml
        self._tingkat_manis = tingkat_manis # Inisialisasi tingkat_manis
        self._suhu_sajian = suhu_sajian     # Inisialisasi suhu_sajian

    # Getter & Setter untuk volume_ml
    def get_volume_ml(self): return self._volume_ml
    def set_volume_ml(self, volume_ml): self._volume_ml = volume_ml

    # Getter & Setter untuk tingkat_manis
    def get_tingkat_manis(self): return self._tingkat_manis
    def set_tingkat_manis(self, tingkat_manis): self._tingkat_manis = tingkat_manis

    # Getter & Setter untuk suhu_sajian
    def get_suhu_sajian(self): return self._suhu_sajian
    def set_suhu_sajian(self, suhu_sajian): self._suhu_sajian = suhu_sajian