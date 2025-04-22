![Pemrograman Kontroller](https://github.com/user-attachments/assets/977d7482-1f11-41cc-a148-aa2b2e7feb5b)
# “Sistem Safety Conveyor Packaging Minuman Botol Berbasis Sensor Photoelectric dan STM32F446RE dengan Fitur Deteksi Obstacle dan Penghentian Otomatis"
 
 Projek ini mendemonstrasikan bagaimana cara membuat program pada STM32 NUCLEO-F466RE dengan fungsi menghentikan Conveyor secara otomatis ketika mendeteksi adanya halangan yang terdeteksi, Guna meningkatkan Sistem Safety pada Conveyor

 ## Authors
1. Yudhistira Ananda Kuswantoro (2042231015)
2. Adam Fareliansah Malandi (2042231049)
3. Wildan Rizki Auzay (2042231061)
4. Ahmad Radhy (Supervisor)

## Features
1. **Testing Kinerja Interaktif Program melalui Compiler** : Dengan menggunakan Code C yang dapat dikompilasi pada C Compiler untuk mengasilkan output secara interaktif
2. **Unit Testing Unity dengan MSYS2 MINGW64** : Menggunakan aplikasi MSYS2 MINGW64 sebagai runner dari Unit Testing

## Requirements
### Software
1. STM32CubeMX
2. Keil µVision MDK
3. Visual Studio Code
4. MSYS2 MinGW64

### Extension and Library
1. C/C++ Extension Pack(di install dalam Visual Studio Code)
2. CMake Tools (Diinstall dalam Visual Studio Code)
3. GCC (install di dalam MSYS2 MinGW64) dengan menginput : ``` pacman -S mingw-w64-x86_64-gcc ```
4. Make (install di dalam MSYS2 MinGW64) dengan menginput : ``` pacman -S make ```
5. cmocka (install di dalam MSYS2 MinGW64) dengan menginput : ``` pacman -S mingw-w64-x86_64-cmocka ```

# Tutorial melakukan Testing 
### 1. Clone semua isi repository dengan unduh atau
```bash
git clone https://github.com/Yuhira213/STM32SafetyConveyorPRJ.git
```
## A. Unit Testing 1 - Untuk melakukan testing interaktif
### 2. Buka Visual Studio Code dengan melakukan open folder dari Unit Testing 1, lalu Copy semua isi dari ```main.c```
![image](https://github.com/user-attachments/assets/2c6e8b43-cc9f-4747-ad89-b2ac6363be3c)

### 3. Buka C Compiler website seperti https://www.onlinegdb.com/
### 4. Paste code yang telah dicopy tadi ke main.c pada web
![image](https://github.com/user-attachments/assets/34c756bd-294f-49b7-b45f-c2794ce288ad)


### 5. Klik Run pada website
![image](https://github.com/user-attachments/assets/a85101c5-047c-456a-922b-fdf17c03c4e3)

Kemudian setelah dirun maka akan muncul tampilan input seperti pada gambar
### 6. Interaksikan nilai pada Input hingga mendapat reply seperti pada contoh gambar
![image](https://github.com/user-attachments/assets/b6a7f1e8-8da2-43c7-a2c9-a409e1ccba64)
Klik Enter lagi untuk mengakhiri dan klik Run lagi untuk melakukan Interaksi dengan pola lain.

## B. Unit Testing 2 - Untuk melakukan Unit Testing melalui aplikasi MSYS2 MinGW64
### 2. Buka MSYS2 MinGW64
### 3. Masukkan directory dari folder Unit Testing 2
Sebagai contoh untuk saya menggunakan directory:
```bash 
cd "/c/STM32 Project/Conveyor_Safety/Unit Testing 2"
```
Atau bisa dilihat dalam file MSYS2 WINGW64 Directory
### kemudian klik enter
### 4. Kemudian masukkan command
```bash 
./relay_buzzer_test.exe
```
atau bisa dilihat di file MSYS2 WINGW64 Directory
### kemudian klik enter
### 5. Setelah itu akan muncul tampilan seperti pada gambar
![image](https://github.com/user-attachments/assets/f7ebce87-21e5-4ac3-9030-8f70814d8d13)
Yang menandakan bahwa sistem telah lolos test case pada unit testing 2
Seperti pada gambar:
![image](https://github.com/user-attachments/assets/3badce8c-2a92-45e0-b01b-e09aacc452cc)
Yang dimana :
1. Test Case pertama adalah ketika sistem dalam kondisi normal
2. Test Case kedua ketika Photoelectric mendeteksi adanya objek asing
3. Test Case ketiga ketika pushbutton ditekan ketika sensor sudah tidak mendeteksi adanya objek asing
4. Test Case keempat ketika pushbutton ditekan ketika sensor tetap mendeteksi adanya objek asing




