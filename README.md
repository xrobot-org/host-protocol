# qdu-rm-protocol

#### 介绍
青岛大学未来战队机器人通信协议，包含了MCU与AI之间串口通信的宏定义和结构体  
## AI_NOTICE
定义数据结构体中的notice对应位所代表的功能   
## AI_ID
MCU向AI发送Protocol_Referee_t和Protocol_MCU_t两个数据包，AI通过包头的AI_ID区分包类型。AI发送Protocol_AI_t到MCU，无AI_ID;  
## 数据结构
* ID
* DATA
    * 数据1
    * 数据2
    * ……
* CRC16
