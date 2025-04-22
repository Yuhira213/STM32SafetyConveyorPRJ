/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* SEI CERT C RULE: DCL30-C. Deklarasikan objek dengan durasi penyimpanan yang sesuai.
       Penjelasan: Objek harus dideklarasikan dengan durasi penyimpanan yang benar sesuai dengan penggunaan yang dimaksud untuk menghindari masalah seperti kebocoran memori atau akses yang tidak valid. */
/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
	/* SEI CERT C RULE: EXP34-C. Jangan dereferensikan pointer null.
   Penjelasan: Dereferensikan pointer null dapat menyebabkan perilaku yang tidak terdefinisi dan bisa menyebabkan crash atau kerentanannya. Pastikan pointer valid sebelum dereferensinya. */

  /* USER CODE BEGIN 1 */
	/* SEI CERT C RULE: EXP34-C. Jangan dereferensikan pointer null.
   Penjelasan: Dereferensikan pointer null dapat menyebabkan perilaku yang tidak terdefinisi dan bisa menyebabkan crash atau kerentanannya. Pastikan pointer valid sebelum dereferensinya. */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
    /* USER CODE END WHILE */
while (1)
{
    // Cek status dari sensor photoelectric (Photoelectric_Pin)
    GPIO_PinState photoelectric_state = HAL_GPIO_ReadPin(Photoelectric_GPIO_Port, Photoelectric_Pin);
    
    // Cek status dari push button (Push_Button_Pin)
    GPIO_PinState push_button_state = HAL_GPIO_ReadPin(Push_Button_GPIO_Port, Push_Button_Pin);
    
		/* SEI CERT C RULE: EXP39-C. Jangan mengakses variabel melalui pointer dari tipe yang tidak kompatibel.
       Penjelasan: Menggunakan pointer untuk mengakses variabel yang tidak kompatibel dengan tipe data dapat menyebabkan perilaku yang tidak terdefinisi dan masalah keamanan. Pastikan kompatibilitas tipe saat menggunakan pointer. */
    // Jika sensor fotoelektrik mendeteksi objek (intervensi manusia)
    if (photoelectric_state == GPIO_PIN_SET)
    {
				/* SEI CERT C RULE: MEM30-C. Jangan mengakses memori yang sudah dibebaskan.
					Penjelasan: Mengakses memori yang telah dibebaskan dapat menyebabkan perilaku yang tidak terduga, korupsi memori, dan kerentanannya. Pastikan memori tidak diakses setelah dibebaskan. */
        // Matikan relay dan hidupkan buzzer
        HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_RESET);  // Mematikan relay
        HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_SET);  // Menyalakan buzzer
        
			/* SEI CERT C RULE: EXP45-C. Jangan melakukan penugasan di dalam pernyataan seleksi.
				Penjelasan: Melakukan penugasan dalam kondisi dapat membuat kode menjadi tidak jelas dan memperkenalkan kesalahan yang sulit dideteksi. Lakukan penugasan di luar pernyataan seleksi seperti if/else. */
        // Jika push button ditekan (untuk menghidupkan relay kembali)
        if (push_button_state == GPIO_PIN_SET)
        {
            // Cek apakah sensor tidak mendeteksi objek (sensor dalam keadaan bebas)
            if (HAL_GPIO_ReadPin(Photoelectric_GPIO_Port, Photoelectric_Pin) == GPIO_PIN_RESET)
            {
                // Hidupkan relay dan matikan buzzer
                HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_SET);  // Menyalakan relay
                HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);  // Mematikan buzzer
            }
        }
    }
    // Jika sensor tidak mendeteksi objek (normal)
    else
    {
        // Relay tetap menyala dan buzzer mati
        HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_SET);  // Menyalakan relay
        HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);  // Mematikan buzzer
        
        // Jika push button ditekan (untuk menghidupkan relay kembali)
        if (push_button_state == GPIO_PIN_SET)
        {
            // Cek apakah sensor tidak mendeteksi objek (sensor dalam keadaan bebas)
            if (HAL_GPIO_ReadPin(Photoelectric_GPIO_Port, Photoelectric_Pin) == GPIO_PIN_RESET)
            {
                // Hidupkan relay dan matikan buzzer (hanya jika sensor tidak mendeteksi objek)
                HAL_GPIO_WritePin(Relay_GPIO_Port, Relay_Pin, GPIO_PIN_SET);  // Menyalakan relay
                HAL_GPIO_WritePin(Buzzer_GPIO_Port, Buzzer_Pin, GPIO_PIN_RESET);  // Mematikan buzzer
            }
        }
    }

    // Tambahkan delay jika diperlukan (misalnya untuk debouncing atau penanganan kecepatan polling)
    HAL_Delay(100);  // Delay 100 ms
}
    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 2;
  RCC_OscInitStruct.PLL.PLLR = 2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, Relay_Pin|Buzzer_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Photoelectric_Pin */
  GPIO_InitStruct.Pin = Photoelectric_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(Photoelectric_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : Push_Button_Pin */
  GPIO_InitStruct.Pin = Push_Button_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Push_Button_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : USART_TX_Pin USART_RX_Pin */
  GPIO_InitStruct.Pin = USART_TX_Pin|USART_RX_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_VERY_HIGH;
  GPIO_InitStruct.Alternate = GPIO_AF7_USART2;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : LD2_Pin */
  GPIO_InitStruct.Pin = LD2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(LD2_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Relay_Pin Buzzer_Pin */
  GPIO_InitStruct.Pin = Relay_Pin|Buzzer_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
    while (1) {
        // Loop error ? bisa tambahkan LED blink
    }
}
//apabila error tambahkan } disini
  /* USER CODE END Error_Handler_Debug */


#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
