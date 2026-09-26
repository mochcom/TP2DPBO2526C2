# Definisi Base Class (Level 1): Menu
class Menu:
    def __init__(self, id_menu="", nama_menu="", harga_menu=0.0):
        self._id_menu = id_menu        # Inisialisasi atribut terproteksi id_menu
        self._nama_menu = nama_menu    # Inisialisasi atribut terproteksi nama_menu
        self._harga_menu = harga_menu  # Inisialisasi atribut terproteksi harga_menu

    # Getter & Setter untuk id_menu
    def get_id_menu(self): return self._id_menu
    def set_id_menu(self, id_menu): self._id_menu = id_menu

    # Getter & Setter untuk nama_menu
    def get_nama_menu(self): return self._nama_menu
    def set_nama_menu(self, nama_menu): self._nama_menu = nama_menu

    # Getter & Setter untuk harga_menu
    def get_harga_menu(self): return self._harga_menu
    def set_harga_menu(self, harga_menu): self._harga_menu = harga_menu