/*
*********************************************************************************************************
*
*	模块名称 : BSP模块
*	文件名称 : bsp.h
*	说    明 : 这是底层驱动模块所有的h文件的汇总文件。 应用程序只需 #include bsp.h 即可，
*			  不需要#include 每个模块的 h 文件
*
*	Copyright (C), 2013-2014, 安富莱电子 www.armfly.com
*
*********************************************************************************************************
*/

#ifndef _BSP_H_
#define _BSP_H

#define STM32_V4
//#define STM32_X2

/* 检查是否定义了开发板型号 */
#if !defined (STM32_V4) && !defined (STM32_X2)
	#error "Please define the board model : STM32_X2 or STM32_V4"
#endif

/* 定义 BSP 版本号 */
#define __STM32F1_BSP_VERSION		"1.1"

/* CPU空闲时执行的函数 */
//#define CPU_IDLE()		bsp_Idle()

/* 开关全局中断的宏 */
#define ENABLE_INT()	__set_PRIMASK(0)	/* 使能全局中断 */
#define DISABLE_INT()	__set_PRIMASK(1)	/* 禁止全局中断 */

/* 这个宏仅用于调试阶段排错 */
#define BSP_Printf		printf
//#define BSP_Printf(...)

#include "stm32f10x.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef TRUE
	#define TRUE  1
#endif

#ifndef FALSE
	#define FALSE 0
#endif

//app need
#define NC 0//继电器常闭--关门
#define NO 1//继电器常开--开门

#define DATA_LEN 1024

//包含网络状态和数据信息
typedef struct
{
    uint8_t status;//网线的link状态 
    uint16_t len;
    uint8_t buf[DATA_LEN+13];//1024字节数据+13字节协议
}NetData_T;

//运行时的信息，包括时间，互锁状态，多重卡状态，首卡等状态
typedef struct
{
    uint8_t remoteOpen;//远程开门，低4位为1开a门，高4位为1开b门
    uint8_t firstCardStatus;//写1表示首卡已经来了，写0表示必须等待
    uint16_t multipleCardStatus;//表示刷卡数
    uint8_t time[5];//时间
}RunInfo_T;

//网络参数枚举
enum NetCfg_Enum
{
    e_local_port,
    e_server_port,
    e_local_ip,
    e_server_ip,
    e_Link,
    e_NoLink
};

//开门方式枚举，4个
enum ReaderOrButton_Enum
{
    e_READER_A,//A读头
    e_READER_B,//B读头
    e_BUTTON_A,//A按键
    e_BUTTON_B //B按键
};

//ID类型枚举,9个
enum ID_Enum
{
    e_firstCardID,
    
    e_superCardID,
    e_superPasswordID,
    
    e_threatCardID,
    e_threatPasswordID,
    
    e_keyBoardID,
    
    e_multipleCardID,

    e_generalCardID,
    e_fingerID
};

//多种开门方式和开门/等待时长的枚举，10个
enum OpenCfg_Enum
{
    e_openTime,
    e_waitTime,
    e_interlock,
    e_firstCard,
    e_multipleCard,
    e_superCard,
    e_superPassword,
    e_threatCard,
    e_threatPassword,
    e_finger
};

#include "bsp_led.h"
#include "bsp_timer.h"

#include "bsp_cpu_flash.h"

#include "param.h"
#include "bsp_i2c_gpio.h"
#include "bsp_eeprom_24xx.h"

#include "bsp_spi_bus.h"
#include "bsp_spi_flash.h"
#include "key.h"
/* 提供给其他C文件调用的函数 */
void bsp_Init(void);
void bsp_Idle(void);

#endif

/***************************** 安富莱电子 www.armfly.com (END OF FILE) *********************************/
