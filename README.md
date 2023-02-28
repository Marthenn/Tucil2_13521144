# Tucil2_13521144
> Tugas Kecil 2 IF2211 - Strategi Algoritma menugaskan mahasiswa untuk membuat sebuah program sederhana untuk mencari pasangan titik terdekat dari suatu himpunan titik dalam tiga dimensi. Algoritma yang dituntut untuk digunakan adalah algoritma divide and conquer dengan algoritma bruteforce sebagai pembanding.

## Struktur Folder
- `bin` berisikan executable file (.exe karena dikompilasi pada os windows)
- `doc` berisikan laporan tugas kecil
- `src` berisikan source code dari program dalam bahasa c++
- `test` berisikan hasil output source code python dan plotting titik

## Program Environment
- MINGW64_NT-10.0-22621 version 3.3.6-341.x86_64
- MSYS_NT-10.0-22621 version 3.3.6-341.x86_64
- gcc version 11.3.0
- python 3.9.7
- matplotlib 3.4.3
- numpy 1.21.2
- GNU make 4.3
- Windows 11

## Cara Mengompilasi Program
1. Arahkan terminal pada direktori utama
2. Jalankan perintah `make build`

## Cara Menjalankan Program
1. Arahkan terminal pada direktori yang terdapat file hasil kompilasi program (contoh: folder bin yang memiliki file main.exe)
2. Jalankan perintah `make run` untuk menjalankan program utama
3. Jalankan perintah `make find` untuk menjalankan program pencarian bound optimal (pengambilan nilai bound dibebaskan sesuai keinginan berdasarkan hasil output program ini)

## Cara Menggunakan
1. Pertama program akan meminta jenis input yang akan digunakan
2. Jika input yang dipilih adalah file, maka program akan meminta path file yang akan diinputkan
3. Jika input yang dipilih adalah random atau manual, maka program akan meminta input jumlah titik dan dimensi titik yang akan diinputkan (bila manual maka kemudian akan meminta input titik satu persatu)
4. Program kemudian akan meminta jumlah titik minimal untuk penggunaan algoritma divide and conquer (bila jumlah titik kurang dari itu maka program akan menggunakan algoritma bruteforce) 
5. Setelah itu program akan menjalankan algoritma bruteforce diikuti dengan algoritma divide and conquer
6. Program akan menampilkan hasilnya beserta waktu eksekusinya
7. Bila dimensi yang digunakan adalah 2 atau 3 maka program akan menanyakan apakah ingin menampilkan plot titik
8. Jika ya, maka program akan menampilkan plot titik melalui matplotlib yang dijalankan pada python melalui berkas `plot.py` pada folder `test`

## Kontributor
1. [13521144 - Bintang Dwi Marthen](https://github.com/Marthenn)