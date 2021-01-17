/*
  视觉与电控通信协议
*/

#define AI_NOTICE_AOTUAIM (1 << 0)
#define AI_NOTICE_HITSWITCH (1 << 1)
#define AI_NOTICE_AUTOMATIC (1 << 2)
#define AI_NOTICE_FIRE (1 << 3)

#define AI_ID_MCU (0x01)
#define AI_ID_REF (0x02)

#include <stdint.h>

/* 电控 -> 视觉 MCU数据结构体*/
typedef struct {
  struct {
    float q0;
    float q1;
    float q2;
    float q3;
  } quaternion; /* 四元数 */

  uint8_t notice; /* 控制命令 */

  float ball_speed; /* 子弹初速度 */

  struct {
    float left;
    float right;
  } distance; /* 左右距离(哨兵) */

  float chassis_speed; /* 底盘速度(哨兵) */

  uint16_t crc16; /* crc校验 */
} Protocol_Data_MCU_t;

/* 电控 -> 视觉 裁判系统数据结构体*/
typedef struct {
  uint16_t example;

  uint16_t crc16; /* crc校验 */
} Protocol_Data_Referee_t;

/* 视觉 -> 电控 数据结构体*/
typedef struct {
  struct {
    float yaw;    /* 偏航角（Yaw angle） */
    float pit;    /* 俯仰角（Pitch angle） */
    float rol;    /* 翻滚角（Roll angle） */
  } gimbal_delta; /* 欧拉角的变化量 */

  uint8_t notice; /* 控制命令 */

  float chassis_speed_setpoint; /* 底盘速度(哨兵) */

  uint16_t crc16; /* crc校验 */
} Protocol_AI_t;

typedef struct {
  uint8_t id;

  Protocol_Data_MCU_t data;
} Protocol_MCU_t;

typedef struct {
  uint8_t id;

  Protocol_Data_Referee_t data;
} Protocol_Referee_t;