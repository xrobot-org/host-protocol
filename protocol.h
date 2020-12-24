/*
  视觉与电控通信协议
*/

#include <stdint.h>

/* 电控 -> 视觉 数据结构体*/
typedef struct {
  struct {
    float yaw; /* 偏航角（Yaw angle） */
    float pit; /* 俯仰角（Pitch angle） */
    float rol; /* 翻滚角（Roll angle） */
  } imu;       /* IMU计算的欧拉角 */

  uint32_t notice; /* 控制命令 */

  float ball_speed; /* 子弹初速度 */

  struct {
    float left;
    float right;
  } distance; /* 左右距离(哨兵) */

  float chassis_speed; /* 底盘速度(哨兵) */
} Protocol_MCU_t;

/* 视觉 -> 电控 数据结构体*/
typedef struct {
  struct {
    float yaw;    /* 偏航角（Yaw angle） */
    float pit;    /* 俯仰角（Pitch angle） */
    float rol;    /* 翻滚角（Roll angle） */
  } gimbal_delta; /* 欧拉角的变化量 */

  uint32_t notice; /* 控制命令 */

  float chassis_speed_setpoint; /* 底盘速度(哨兵) */
} Protocol_AI_t;