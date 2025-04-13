/*
  视觉与电控通信协议
*/

#pragma once

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define AI_ARM_INFANTRY (1 << 0)
#define AI_ARM_HERO (1 << 1)
#define AI_ARM_ENGINEER (1 << 2)
#define AI_ARM_DRONE (1 << 3)
#define AI_ARM_SENTRY (1 << 4)
#define AI_ARM_DART (1 << 5)
#define AI_ARM_RADAR (1 << 6)

#define AI_NOTICE_FIRE (1 << 1)
#define AI_NOTICE_BUFF (1 << 2)
#define AI_NOTICE_SNIPE (1 << 3)
#define AI_NOTICE_SLOPE (1 << 4)
#define AI_NOTICE_OUTPOST (1 << 5)
#define AI_NOTICE_SENTRY (1 << 6)
#define AI_NOTICE_BASE (1 << 7)

#define AI_NOTICE_AUTOATROL (3)
#define AI_NOTICE_AUTO_AIM (5)

#define AI_ID_MCU (0x5A)

#define AI_TEAM_RED (1 << 0)
#define AI_TEAM_BLUE (1 << 1)

#define AI_RACE_RMUC (1 << 0)
#define AI_RACE_RMUT (1 << 1)
#define AI_RACE_RMUL1 (1 << 2)
#define AI_RACE_RMUL3 (1 << 3)

#define AI_RFID_BUFF (1 << 0)
#define AI_RFID_SNIP (1 << 1)

typedef uint8_t Protocol_ID_t;

/*Electronically controlled to visual structures*/
typedef struct __attribute__((packed)) {
  struct __attribute__((packed)) {
    float yaw;
    float pit;
    float rol;
  } eulr;

  Protocol_ID_t notice;

  float ball_speed;

  float yaw;
  float pit;
  float rol;

  uint8_t game_progress; /* 比赛开始时间 */
  uint32_t rfid;         /* 增益地点 */
  uint16_t base_hp;      /* 基地血量 */
  uint16_t sentry_hp;    /* 哨兵血量 */
  uint16_t outpost_hp;
  uint16_t ballet_remain; /* 剩余弹量 */

  uint8_t recovery_buff;      /*机器人回血增益*/
  uint8_t cooling_buff;       /*机器人射击热量冷却倍率*/
  uint8_t defence_buff;       /*机器人防御增益*/
  uint8_t vulnerability_buff; /*机器人负防御增益*/
  uint16_t attack_buff;       /*机器人攻击增益*/
  uint8_t remaining_energy;   /*机器人剩余能量值反馈*/

  uint16_t hero_hp;
  uint16_t standard_3_hp;
  uint16_t standard_4_hp;
  uint16_t engineer_hp;

  float hero_x;
  float hero_y;
  float standard_3_x;
  float standard_3_y;
  float standard_4_x;
  float standard_4_y;
  float engineer_x;
  float engineer_y;

} Protocol_UpDataToHost_t;

/* 视觉 -> 电控 数据结构体*/
typedef struct __attribute__((packed)) {
  struct __attribute__((packed)) {
    float yaw; /* 偏航角(Yaw angle) */
    float pit; /* 俯仰角(Pitch angle) */
    float rol; /* 翻滚角(Roll angle) */
  } gimbal;    /* 欧拉角 */

  Protocol_ID_t notice; /* 控制命令 */
  struct __attribute__((packed)) {
    float vx; /* x轴移动速度 */
    float vy; /* y轴移动速度、哨兵沿轨道方向(正面面向战场，右为正方向) */
    float wz; /* z轴转动速度、哨兵射界(弧度0～pi) */
  } chassis_move_vec; /* 底盘移动向量 */

} Protocol_DownData_t;
typedef struct __attribute__((packed)) {
  uint8_t id;
  Protocol_UpDataToHost_t data;
  uint16_t crc16;
} Protocol_UpPackage_t;

typedef struct __attribute__((packed)) {
  Protocol_DownData_t data;
  uint16_t crc16;
} Protocol_DownPackage_t;

#ifdef __cplusplus
}
#endif
