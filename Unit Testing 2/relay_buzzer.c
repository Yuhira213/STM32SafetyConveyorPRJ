#include "relay_buzzer.h"  // Sertakan header untuk deklarasi

// Fungsi untuk mengontrol status relay dan buzzer
void control_relay_buzzer(int photoelectric, int push_button, int* relay, int* buzzer) {
    if (photoelectric == 1) {
        *relay = 0;
        *buzzer = 1;

        if (push_button == 1) {
            if (photoelectric == 0) { 
                *relay = 1;
                *buzzer = 0;
            }
        }
    } else {
        *relay = 1;
        *buzzer = 0;

        if (push_button == 1) {
            *relay = 1;
            *buzzer = 0;
        }
    }
}
