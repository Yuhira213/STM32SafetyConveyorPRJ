#include "photoelectric.h"

/*
 * Rule: DCL31-C
 * Variabel hanya dideklarasikan saat dibutuhkan dan langsung digunakan.
 */
void Photoelectric_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    // Aktifkan clock port sensor
    __HAL_RCC_GPIOA_CLK_ENABLE();  // MSC30-C: hindari akses tanpa clock

    GPIO_InitStruct.Pin = PHOTOELECTRIC_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(PHOTOELECTRIC_GPIO_PORT, &GPIO_InitStruct);
}

/*
 * Rule: EXP33-C
 * Jangan gunakan variabel tak diinisialisasi atau nilai tak terdefinisi.
 * Rule: INT13-C
 * Gunakan operasi logika dan pembandingan dengan tepat.
 */
uint8_t Photoelectric_Read(void) {
    GPIO_PinState state = HAL_GPIO_ReadPin(PHOTOELECTRIC_GPIO_PORT, PHOTOELECTRIC_PIN);

    if (state == GPIO_PIN_RESET) {
        return 1U;  // Terhalang (aktif LOW)
    } else {
        return 0U;  // Tidak terhalang
    }
}
