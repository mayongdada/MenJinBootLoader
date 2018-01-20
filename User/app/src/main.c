/*
*********************************************************************************************************
*
*	模块名称 : 主程序入口
*	文件名称 : main.c
*	版    本 : V1.0
*	说    明 : CPU内部Flash读写例子
*	修改记录 :
*		版本号  日期       作者    说明
*		V1.0    2015-08-30 armfly  首发
*
*	Copyright (C), 2015-2016, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#include "bsp.h"				/* 底层硬件驱动 */

/* 变量 */
typedef  void (*pFunction)(void);
pFunction Jump_To_Application;
uint32_t JumpAddress;


#define IAP_PAGE_SIZE 2048//为了能够兼容F103 所以提出了2K这个更新大小
#define APP_START_ADDR (uint32_t)0x08010000 

/*
*********************************************************************************************************
*	函 数 名: main
*	功能说明: c程序入口
*	形    参：无
*	返 回 值: 错误代码(无需处理)
*********************************************************************************************************
*/
int main(void)
{
	/*
		ST固件库中的启动文件已经执行了 SystemInit() 函数，该函数在 system_stm32f4xx.c 文件，主要功能是
	配置CPU系统的时钟，内部Flash访问时序，配置FSMC用于外部SRAM
	*/
	bsp_Init();		/* 硬件初始化 */

	/* 主程序大循环 */
	while (1)
	{

	}
}


/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
