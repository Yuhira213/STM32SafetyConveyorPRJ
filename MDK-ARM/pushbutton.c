#include "pushbutton.h"

void PushButton_Init(void) {
    GPIO_InitTypeDef GPIO_InitStruct = {0};

    __HAL_RCC_GPIOA_CLK_ENABLE();  // MSC30-C

    GPIO_InitStruct.Pin = BUTTON_PIN;
    GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
    GPIO_InitStruct.Pull = GPIO_NOPULL;

    HAL_GPIO_Init(BUTTON_GPIO_PORT, &GPIO_InitStruct);
}

uint8_t PushButton_Read(void) {
    GPIO_PinState state = HAL_GPIO_ReadPin(BUTTON_GPIO_PORT, BUTTON_PIN);

    return (state == GPIO_PIN_RESET) ? 1U : 0U;  // 1 = ditekan (aktif LOW)
}
