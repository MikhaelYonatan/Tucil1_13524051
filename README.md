# Tucil1_13524051 | Strate Algoritma - Queens Game

## Deskripsi Singkat
Program ini dibuat untuk menyelesaikan Queens Game, yaitu menempatkan N Queens pada papan persegi berukuran N x N sehingga terdapat hanya satu Queenn pada setiap baris, kolom, dan daerah warna. Selain itu, antarQueen tidak dapat ditempatkan bersebelahan maupun diagonal.
Program ini menggunakan pendekatan algoritma **brute force**, yaitu mencoba semua kemungkinan penempatan ratu sesuai dengan aturan yang telah didefinisikan.

## Requirement & Instalasi
Pastikan sistem Anda memiliki
1.  **C++ Compiler**: Mendukung standar C++17.
2.  **CMake**: Versi 3.10 atau lebih baru. [Download CMake](https://cmake.org/download/)
3.  **OpenCV Library**: Versi 4.1.2. Pastikan path library sudah terkonfigurasi. [Download OpenCV](https://opencv.org/releases/)

## Struktur Direktori
```text
TUCIL1_13524051/
├── bin/
│   ├── opencv_world4120.dll
│   ├── QueensGame.exe
│   └── QueensGame.pdb
|
├── doc/
|
├── src/
│   ├── fileproc.cpp
│   ├── fileproc.h
│   ├── imgproc.cpp
│   ├── imgproc.h
│   ├── main.cpp
│   ├── queen.cpp
│   ├── queen.h
│   └── queen.png
|
├── test/
|
├── CMakeLists.txt
└── README.md
````

## Cara Kompilasi (Build)
Lakukan kompilasi dari *root directory* proyek (folder `TUCIL1_13524051`).

1.  Buka terminal di root folder.

2.  Konfigurasi project dengan CMake:
    ```
    cmake -S . -B build
    ```

3.  Lakukan proses build (Disarankan menggunakan mode Release agar program berjalan cepat):
    ```
    cmake --build build --config Release
    ```

Setelah berhasil, file executable `QueensGame.exe` akan muncul di dalam folder `bin/`.

## Cara Menjalankan Program
**PENTING:** Agar program dapat membaca file input (`test/`) dengan benar, program **HARUS dijalankan dari Root Folder** (`TUCIL1_13524051`), bukan dari dalam folder `bin`!

Gunakan perintah berikut di terminal:

**Untuk Windows (PowerShell):**
````
./bin/QueensGame.exe
````

### Panduan dan Batasan Penggunaan
1. Pastikan file input sudah ada dalam folder `test/`.
2. Ekstensi file input yang dapat diterima adalah txt, png, dan jpg.
3. Saat diminta nama file, cukup ketik nama filenya saja (contoh: `file1.txt`).
4. Untuk input gambar, pastikan gambar fokus pada papan permainan saja (minimalisir gambar di luar bingkai papan).
5. Input gambar hanya akan berjalan dengan baik jika papan permainan kosong dan input ukuran (N) benar.

## Pembuat: Mikhael Andrian Yonatan