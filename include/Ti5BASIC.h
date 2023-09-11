#ifndef Ti5BASIC_H
#define Ti5BASIC_H

#include <stdio.h>
#include <stdlib.h>

#include <libudev.h>

#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netinet/in.h>
#include <arpa/inet.h>


#include "spdlog/spdlog.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/rotating_file_sink.h"


#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <map>

// #include "can/SingleCaninterface.h"
// #include "can/motortypehelper.h"

#include "Ti5LOGIC.h"
#include "Ti5MOVE.h"

#include "can/tcontrolcanfactor.h"


#define MAX_IP_ADDR_LEN 256 //存储IP地址的最大长度
//#define LOG_PATH "/mnt/hgfs/mechanical_arm/log/daily_logger.log" //log路径
#define INI_PATH "../config.ini" //config.ini文件路径

extern float arr_s[6];

extern bool flag;

extern uint32_t reg_position_kp[6];//位置环比例
extern uint32_t reg_position_kd[6];//位置环微分

extern uint32_t reg_speed_kp[6];    //速度环比例
extern uint32_t reg_speed_ki[6];    //速度环积分

extern uint32_t reg_max_curr_value[6]; //最大正电流
extern uint32_t reg_min_curr_value[6]; //最小负电流

extern uint32_t reg_max_app_speed[6]; //最大正向允许速度
extern uint32_t reg_min_app_speed[6]; //最小负向允许速度

extern uint32_t reg_max_app_position[6];//电机最大正向位
extern uint32_t reg_min_app_position[6];//电机最大负向位

// int32_t receiveData;
// int qqqq=TControlCanFactor::readParameter(MotorTypeHelper::REG_CURRENT_POSITION,receiveData);



extern string log_path;//log文件

extern string SDKversion;//SDK version

//保存当前位置为零点
void save_current_location(int i);

void read_qqq();
//查询机械臂是否停止运动
bool inspect_brake();

void exit_progrem();//退出程序

//void SDK_version();////SDK版本号
std::string SDK_version();//SDK版本号

//int ip_address();//获取IP地址
std::string ip_address();

void loggerinfo(string content);//添加log

//void udevice();//监测是哪个USB接口插入了设备
//const char* udevice();//添加了返回值的USB设备监测

std::string udevice();

/*return 1 进入调试模式，0未进入调试模式*/
bool select_SDK_Debugmode();//设置是否进入调试模式

/*控制机器人进入或者退出拖拽模式
  return 1 进入拖拽模式，0未进入*/
bool control_dragmode();

/*查询机器人是否处于拖拽模式
  return 1 进入拖拽模式，0未进入*/
bool inspect_dragmode();

void read_ini_information();//读取ini配置文件的内容

void plan_motion_path();//规划运动路径

void login();//登录can设备

void logout();//登出can设备

// std::string query_can();//查询can设备号
std::vector<std::string> query_can();

//获取电机参数
void get_elc_info();

/*设置电机参数
参数: 
  elc_parameterlist 要设置的对应电机
  elc_value 要设置的第n个电机
  parameterType 要设置的项目
  elc_value 新值
*/
void set_elc_info(uint32_t *elc_parameterlist,int elc_num, int parameterType,uint32_t elc_value);

#endif

