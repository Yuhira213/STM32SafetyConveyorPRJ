#include "relay.h"

void Relay_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();  // MSC30-C: pastikan clock aktif

    GPIO_InitStruct.Pin = RELAY_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
    GPIO_InitStruct.Pull = GPIO_NOPULL;
    GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(RELAY_GPIO_PORT, &GPIO_InitStruct);

    HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY_PIN, GPIO_PIN_RESET);  // DCL31-C
}

void Relay_Control(uint8_t state) {
    if (state != 0U) {
        HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY_PIN, GPIO_PIN_SET);   // ON
    } else {
        HAL_GPIO_WritePin(RELAY_GPIO_PORT, RELAY_PIN, GPIO_PIN_RESET); // OFF
    }
}
