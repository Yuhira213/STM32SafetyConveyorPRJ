#include <stdio.h>

// Deklarasi fungsi untuk menanggapi intervensi sensor dan tombol
void test_system(int photoelectric, int push_button, int* relay, int* buzzer);

int main(void) {
    int relay = 1;  // Relay dalam keadaan aktif
    int buzzer = 0; // Buzzer dalam keadaan mati
    int photoelectric; // Status sensor fotoelektrik (0 = tidak ada objek, 1 = objek terdeteksi)
    int push_button; // Status tombol (0 = tidak ditekan, 1 = ditekan)

    // Input dari pengguna
    printf("Masukkan status sensor fotoelektrik (0 = tidak ada objek, 1 = objek terdeteksi): ");
    scanf("%d", &photoelectric);

    printf("Masukkan status tombol (0 = tidak ditekan, 1 = ditekan): ");
    scanf("%d", &push_button);

    // Menjalankan logika sistem berdasarkan input pengguna
    test_system(photoelectric, push_button, &relay, &buzzer);

    // Output hasil kontrol relay dan buzzer
    printf("Relay: %d (0 = dimatikan, 1 = dinyalakan)\n", relay);
    printf("Buzzer: %d (0 = mati, 1 = menyala)\n", buzzer);

    return 0;
}

void test_system(int photoelectric, int push_button, int* relay, int* buzzer) {
    // Jika sensor mendeteksi objek (intervensi manusia)
    if (photoelectric == 1) {
        // Matikan relay dan hidupkan buzzer
        *relay = 0;
        *buzzer = 1;

        // Jika tombol ditekan, hidupkan relay jika sensor tidak mendeteksi objek
        if (push_button == 1) {
            if (photoelectric == 0) {  // Hanya hidupkan relay jika sensor tidak mendeteksi objek
                *relay = 1;
                *buzzer = 0;
            }
        }
    } else {
        // Sensor tidak mendeteksi objek, hidupkan relay dan matikan buzzer
        *relay = 1;
        *buzzer = 0;

        // Jika tombol ditekan, hidupkan relay dan matikan buzzer
        if (push_button == 1) {
            *relay = 1;
            *buzzer = 0;
        }
    }
}
