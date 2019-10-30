/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "math.h"
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
SPI_HandleTypeDef hspi1;

TIM_HandleTypeDef htim4;

UART_HandleTypeDef huart1;
DMA_HandleTypeDef hdma_usart1_rx;
DMA_HandleTypeDef hdma_usart1_tx;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_DMA_Init(void);
static void MX_TIM4_Init(void);
static void MX_USART1_UART_Init(void);
static void MX_SPI1_Init(void);
/* USER CODE BEGIN PFP */
typedef uint32_t u32;
const float refFreq = 25000000.0;

void StartDefaultTask(void);
void AD9833reset(void);
void AD9833setFrequency(uint16_t frequency, uint16_t waveform);
void WriteRegister (uint16_t data);
void delay_us(u32 nus);
void AD9833setNote(uint16_t frequency);

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
int step = 0;
uint16_t pwm_value = 0;
void user_pwm_setvalue(uint16_t value);
uint8_t in[1];
char vt[4];
uint8_t tx_buff[] = {0,1,2,3};
uint8_t rx_buff[4];
uint16_t notes[] = {16,17,18,19,20,110,22,23,24,27,29,30,33,
                  34,36,39,41,43,46,48,51,55,58,65,69,73,
                  77,82,87,92,97,103,110,116,123,130,138,
                  146,155,168,174,185,196,208,220,260,280,300,
				  310,340,360,390,400,410,440,480,500,520,540
};



/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

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
  MX_DMA_Init();
  MX_TIM4_Init();
  MX_USART1_UART_Init();
  MX_SPI1_Init();
  /* USER CODE BEGIN 2 */
  HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);


   StartDefaultTask();

 // HAL_UART_IRQHandler(&huart1);


  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */



	//  HAL_Delay(10);

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

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
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
  * @brief SPI1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_SPI1_Init(void)
{

  /* USER CODE BEGIN SPI1_Init 0 */

  /* USER CODE END SPI1_Init 0 */

  /* USER CODE BEGIN SPI1_Init 1 */

  /* USER CODE END SPI1_Init 1 */
  /* SPI1 parameter configuration*/
  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_HIGH;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_32;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN SPI1_Init 2 */

  /* USER CODE END SPI1_Init 2 */

}

/**
  * @brief TIM4 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM4_Init(void)
{

  /* USER CODE BEGIN TIM4_Init 0 */

  /* USER CODE END TIM4_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM4_Init 1 */

  /* USER CODE END TIM4_Init 1 */
  htim4.Instance = TIM4;
  htim4.Init.Prescaler = 1080-1;
  htim4.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim4.Init.Period = 2000-1;
  htim4.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim4.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim4) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim4, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM4_Init 2 */


  /* USER CODE END TIM4_Init 2 */
  HAL_TIM_MspPostInit(&htim4);

}

/**
  * @brief USART1 Initialization Function
  * @param None
  * @retval None
  */
static void MX_USART1_UART_Init(void)
{

  /* USER CODE BEGIN USART1_Init 0 */

  /* USER CODE END USART1_Init 0 */

  /* USER CODE BEGIN USART1_Init 1 */

  /* USER CODE END USART1_Init 1 */
  huart1.Instance = USART1;
  huart1.Init.BaudRate = 31250;
  huart1.Init.WordLength = UART_WORDLENGTH_8B;
  huart1.Init.StopBits = UART_STOPBITS_1;
  huart1.Init.Parity = UART_PARITY_NONE;
  huart1.Init.Mode = UART_MODE_TX_RX;
  huart1.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart1.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN USART1_Init 2 */


  /* USER CODE END USART1_Init 2 */

}

/** 
  * Enable DMA controller clock
  */
static void MX_DMA_Init(void) 
{
  /* DMA controller clock enable */
  __HAL_RCC_DMA1_CLK_ENABLE();

  /* DMA interrupt init */
  /* DMA1_Channel4_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel4_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel4_IRQn);
  /* DMA1_Channel5_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(DMA1_Channel5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(DMA1_Channel5_IRQn);

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, LED_Pin|FSYNC_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : LED_Pin FSYNC_Pin */
  GPIO_InitStruct.Pin = LED_Pin|FSYNC_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	__NOP(); //check if we receive all data

}

void user_pwm_setvalue(uint16_t value)
  {
      TIM_OC_InitTypeDef sConfigOC;

      sConfigOC.OCMode = TIM_OCMODE_PWM1;
      sConfigOC.Pulse = value;
      sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
      sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
      HAL_TIM_PWM_ConfigChannel(&htim4, &sConfigOC, TIM_CHANNEL_1);
      HAL_TIM_PWM_Start(&htim4, TIM_CHANNEL_1);
  }

//void debugPrint(UART_HandleTypeDef *huart, char _out[]){
// HAL_UART_Transmit(huart, (uint8_t *) _out, strlen(_out), 10);
//}


//void debugPrintln(UART_HandleTypeDef *huart, char _out[]){
//HAL_UART_Transmit(huart, (uint8_t *) _out, strlen(_out), 10);
// char newline[2] = "\r\n";
// HAL_UART_Transmit(huart, (uint8_t *) newline, 2, 10);
//}

void delay_us(u32 nus)
{
	u32 temp;
	while(nus--)
	{
	   for(temp=0;temp<48;temp++);

	}
}

void StartDefaultTask(void)
 {
	 HAL_GPIO_WritePin(FSYNC_GPIO_Port, FSYNC_Pin, GPIO_PIN_SET);
//for(;;)
 // {

    // HAL_UART_Receive(&huart1, (uint8_t *)in, 1, 100);
    uint8_t i = 0;
	const uint16_t SINE = 0x2000;                    // Define AD9833's waveform register value.
	const uint16_t SQUARE = 0x2028;                  // When we update the frequency, we need to
	const uint16_t TRIANGLE = 0x2002;

	 AD9833reset();
	 WriteRegister(0x2168);
	 WriteRegister(0xC000);               // Phase register
     WriteRegister(TRIANGLE);
    for(;;)
     {
      HAL_UART_Receive(&huart1, (uint8_t *)in, 1, 1000);

         if (in[0] == 0x090)
          {
             HAL_UART_Receive(&huart1, (uint8_t *)in, 1, 1000);
             AD9833setNote(notes[in[0]]);
             while (in[0] != 0x090)
             {
            	 HAL_UART_Receive(&huart1, (uint8_t *)in, 1, 1000);
             }
             AD9833setNote(notes[in[0]]);



            //	 AD9833setFrequency(0, TRIANGLE);

             }
         //    HAL_UART_Transmit(&huart1, (uint8_t *)in, 1, 10);

          }

    }


void AD9833reset(void){
	     uint16_t sdata = 0x100;
	     WriteRegister (sdata);
	    delay_us (10);
	   //  HAL_Delay(10);

}

void AD9833setFrequency(uint16_t frequency, uint16_t waveform){

	 long FreqWord = (frequency * pow(2, 28)) / refFreq;

	  uint16_t MSB = ((FreqWord & 0xFFFC000) >> 14);    //Only lower 14 bits are used for data
	  uint16_t LSB = (FreqWord & 0x3FFF);

	  //Set control bits 15 ande 14 to 0 and 1, respectively, for frequency register 0
	  LSB |= 0x4000;
	  MSB |= 0x4000;


	  //  WriteRegister(0x2168);
	//  WriteRegister(0b0010000010001000);
	 // WriteRegister(0x2100);
	  WriteRegister(LSB);                  // Write lower 16 bits to AD9833 registers
	  WriteRegister(MSB);                  // Write upper 16 bits to AD9833 registers.
	  WriteRegister(0xC000);               // Phase register
	  WriteRegister(waveform);                                // Exit & Reset to SINE, SQUARE or TRIANGLE


}

void AD9833setNote(uint16_t frequency)
{

	 long FreqWord = (frequency * pow(2, 28)) / refFreq;

		  uint16_t MSB = ((FreqWord & 0xFFFC000) >> 14);    //Only lower 14 bits are used for data
		  uint16_t LSB = (FreqWord & 0x3FFF);

		  //Set control bits 15 ande 14 to 0 and 1, respectively, for frequency register 0
		  LSB |= 0x4000;
		  MSB |= 0x4000;

		  WriteRegister(LSB);                  // Write lower 16 bits to AD9833 registers
		  WriteRegister(MSB);                  // Write upper 16 bits to AD9833 registers.
		                               // Exit & Reset to SINE, SQUARE or TRIANGLE


}

void WriteRegister (uint16_t data){



	uint8_t   spi_tx_LB =  (uint8_t) data;  //Low Byte  ;
	uint8_t   spi_tx_MB =   data >> 8 ;  //High Byte;

	//    uint8_t   spi_tx_LB =  0b11111111;  //Low Byte  ;
	///	uint8_t   spi_tx_MB =  0b00000000 ;  //High Byte;


	 HAL_GPIO_WritePin(FSYNC_GPIO_Port, FSYNC_Pin, GPIO_PIN_RESET);
	 delay_us (10);

	 //  HAL_SPI_Transmit_IT(&hspi1, &spi_tx_MB, 1);
	    HAL_SPI_Transmit(&hspi1, &spi_tx_MB, 1, 1000);
	  // HAL_UART_Transmit(&huart1, &spi_tx_MB, 1, 1000);
	 //  HAL_SPI_Transmit_IT(&hspi1, &spi_tx_LB, 1);
	    HAL_SPI_Transmit(&hspi1, &spi_tx_LB, 1, 1000);
	 //  HAL_UART_Transmit(&huart1, &spi_tx_LB, 1, 1000);

	    delay_us (10);
	// HAL_Delay(1000);

	 HAL_GPIO_WritePin(FSYNC_GPIO_Port, FSYNC_Pin, GPIO_PIN_SET);
	// HAL_Delay(1000);
}





/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
