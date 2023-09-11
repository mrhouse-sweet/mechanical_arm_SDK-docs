#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include<sstream>
#include<fstream>
#include<cmath>
#include<iostream>
#include <unistd.h>
#include <cstdlib>

#include "Ti5MOVE.h"
#include "Ti5BASIC.h"
#include "Ti5LOGIC.h"
#include "communication.h"
#include "mathfunc.h"
#include "tool.h"
#include "clamping_jaw.h"

#include <csignal>
//#include <conio.h>

using namespace std;

float i=11.4373;//机械臂码垛：用坐标点的物体的高

void signalHandler(int signum)
{
    
    char aaa;
    cout << "Interrupt signal (" << signum << ") received.\n";
    aaa = scanKeyboard();
    brake();  
    cout << "stop!!" << endl;
    // switch (aaa)
    // {
    //     case 'b':
    //     {
    //         brake();  
    //         cout << "stop!!" << endl;
    //         break;
    //     }
    // }
    inspect_brake();

    // 清理并关闭
    // 终止程序  
    logout();
    exit(signum);

 
}


//实时补丁，用ubuntu2204 启动实时操作系统



int main()
{
    vector<string> productSerialNumbers = query_can();
    if (productSerialNumbers.empty()) {
        cout << "未找到任何 USB 设备。" << endl;
    } else {
        cout << "找到的 CAN 设备序列号：" << endl;
        for (const string& serialNumber : productSerialNumbers) {
            cout << serialNumber << endl;
        }
    }
    // string qqq=query_can();
    // cout<<"qqq="<<qqq<<endl;
    cout<<"qweqwdsaradasd"<<endl;
    signal(SIGINT, signalHandler);
    login();
    mechanical_arm_origin();
    show_value("pos:",TH.pos);
    cout<<"*************************"<<endl;
    current_angle();
    float qqq[6];
    current_pose(qqq);
    cout<<"*************************"<<endl;
    sleep(3);
    string ip=ip_address();
    // Point start({90,300,300});
    // Point end({-90,300,300});
    /////////////////////////////直线运动///////////////////////////////////
    /*Point start[1];
    Point end[1];
    cout << "请输入起始点坐标x, y, z" << endl;
	for (int i = 0; i < 1; i++)
	{
		cin >> start[i].x;
		cin >> start[i].y;
		cin >> start[i].z;
	}

	cout << "请输入终点坐标x, y, z" << endl;
	for (int j = 0; j < 1; j++)
	{
		cin >> end[j].x;
		cin >> end[j].y;
		cin >> end[j].z;
	}
    linear_move(start[0],end[0],10);*/
    /////////////////////////////直线运动///////////////////////////////////

    
	// keyboard_controller();
    /*
    // 定义起点和终点
    PathPoint start = {-205, 0, 550, 0, 0, 0};
    PathPoint end = {205, 0, 550, 0, 0, 0};

    // 定义圆弧半径和插值步长
    double radius = 30.0;
    double stepSize = 0.1;

    // 调用圆弧路径规划函数
    std::vector<PathPoint> path = planCircularPath(start, end, radius, stepSize);

    // 输出路径点信息
    for (const auto& point : path) {
        std::cout << "Position: (" << point.x << ", " << point.y << ", " << point.z << "), ";
        std::cout << "Orientation: (" << point.roll << ", " << point.pitch << ", " << point.yaw << ")" << std::endl;
        TH.pos[0]=point.x;
        TH.pos[1]=point.y;
        TH.pos[2]=point.z;
        TH.pos[3]=point.roll;
        TH.pos[4]=point.pitch;
        TH.pos[5]=point.yaw;
        show_value("TH.pos:",TH.pos);
        move_to_pos(0);
    }*/

    
        // mechanical_arm_origin();
        // show_value("POS:",TH.pos);
        // float OOO[] = { 50,20,100 };
        // float UUU[] = { 80,80,100 };
        // float Kkk = 3.14;
        // float startN[] = { 40,140,386,0,-1.5708,0 };
        // circle_move(OOO, UUU, Kkk, startN);

        // circle_move(OOO, UUU, Kkk, startN);
        // cout << "Going to sleep...." << endl;
        // sleep(1);
    
    
    
    /*float OOO[]={0,0,255};
    float UUU[]={0,0,-1};
    float Kkk=2*3.14;
    float startN[] = {0,125,255,0,pi/2,0};
    circle_move(OOO,UUU,Kkk,startN);*/

    // float arr[]={0,125,255,0,1.57,0};
    // pos_movement(arr);
    // // SDK_version();
    // // // yuan_test();
    // // test_point();
    // sleep(5);
    // brake();
    // IsBrake();
    // float angl[6];
    // current_angle(angl);
    // float posz[6];
    // current_pose(posz);

    // float arr[6] = {-1.51795, 0.348368, -1.81652, 6.64592e-06, -1.0451, -3.79698e-05}; 
    // joint_movement(arr);
    // brake();

    // float arr2[6] = {-1.51795, 0.746512, -1.8414, 0.0497746, -0.572304, 0.024846};
    // joint_movement(arr2);

    // float arr3[6] = {0.472769, -0.423036, -1.96582, 0.0497746, -0.572304, -0.024846};
    // joint_movement(arr3);
    // brake();

    // float arr4[6] = {0.472769, 0.970468, -1.39349, 0.0497746, -0.721608, -0.024846};
    // joint_movement(arr4);
    // brake();

    keyboard_save_point();
    // load_program();


    /*加载运行文件*/
    // string filename;
	// cout<<"请输入要加载的文件：";
	// cin >> filename;
    // for(int i=0;i<100;i++)
    // {
    //     load_program(filename);
    // }



    //////////////////////////////////////机械臂码垛：用角度////////////////////////////
    /*while (1)
    {
        float arr[6] = {-3.13, -0.24884, 1.89118, 0.049768, -0.597216, -2.70697};
        joint_movement(arr);
        brake();
        sleep(0.5);
        clamp_jaw_open();

        float arr2[6] = {-3.13, -0.273724, 2.0156, 0.049768, -0.771404, -2.70697};
        joint_movement(arr2);
        brake();
        sleep(0.5);
        clamp_jaw_close();
        sleep(1);

        float arr3[6] = {-3.13, 0.696752, 2.0156, 0.149304, -0.771404, -2.70697};
        joint_movement(arr3);
        brake();

        // sleep(1);

        float arr4[6] = {-0.492298, 0.696752, 2.0156, 0.149304, -0.771404, -2.70697};
        joint_movement(arr4);
        brake();
        // sleep(1);

        float arr5[6] = {-0.492298, -1.11978, 1.2442, 0.049768, -0.821172, -2.70697};
        joint_movement(arr5);
        brake();
        clamp_jaw_open();
        sleep(1);
    }*/
    //////////////////////////////////////机械臂码垛 1kg ：用角度////////////////////////////
    /*while (1)
    {
        float arr[6] = {-1.51795, 0.348368, -1.81652, 6.64592e-06, -1.0451, -3.79698e-05}; 
        joint_movement(arr);
        brake();
        sleep(0.5);
        // sleep(2);
        clamp_jaw_open();
        // sleep(0.5);

        float arr2[6] = {-1.51795, 0.746512, -1.8414, 0.0497746, -0.572304, 0.024846};
        joint_movement(arr2);
        brake();
        sleep(0.5);
        clamp_jaw_close();
        sleep(1);

        float arr3[6] = {0.472769, -0.423036, -1.96582, 0.0497746, -0.572304, -0.024846};
        joint_movement(arr3);
        brake();

        float arr4[6] = {0.472769, 0.970468, -1.39349, 0.0497746, -0.721608, -0.024846};
        joint_movement(arr4);
        brake();
        clamp_jaw_open();
        sleep(1);
    }*/
    //////////////////////////////////////机械臂码垛 1kg ：用角度////////////////////////////
    ////////////////////////////////////////机械臂码垛：用坐标点////////////////////////////
    /*while (1)
    {
        
        float arr[6] = {-7.74078 ,328.817 ,223.455 ,-2.02142 ,-3.13438, 0.0495672 };

        pos_movement(arr);
        brake();
        sleep(0.5);
        // sleep(2);
        clamp_jaw_open();
        // sleep(0.5);

        // float arr2[6] = {-7.01863, 311.595 ,185.875 ,-2.02847, -3.11001, 0.0560048};
        float arr2[6] = {-7.01863, 311.595 ,2.588 ,-2.02847, -3.11001, 0.0560048};
        pos_movement(arr2);
        brake();
        sleep(0.5);
        clamp_jaw_close();
        sleep(1);

        float arr3[6] = {-12.2574 ,178.749 ,445.271 ,-2.36556 ,-2.35634, 0.759647};
        pos_movement(arr3);
        brake();

        // sleep(1);

        float arr4[6] = {-75.5724, -162.451, 445.271, 0.272141, -2.35634 ,0.759647};
        pos_movement(arr4);
        brake();
        // sleep(1);

        float arr5[6] = {-225.37, -427.045 ,i, 0.607701, -3.13148, 0.0431884};
        pos_movement(arr5);
        brake();
        clamp_jaw_open();
        sleep(1);
        i=i+10;//取决于物体的高度
    }*/

    // int ret;
    // wchar_t *script=L"2.py";
    // ret=py_init();
    // ret=py_exec(script);

    // show_value("TH.J:",TH.j);
    // test_A();
    // // linear_move_test();
    // float a[6]={0, 100, 450, 0.049768, -3.13849,  0};
    // float b[6]={0,  110, 450, 0.049768,  -3.13849, 0};
    // float c[6]={0, 120, 450, 0.049768, -3.13849,  0};
    // float d[]={ 0,  130, 450,  0.049768,  -3.13849,  0};
    // float e[]={0,  140, 450,  0.049768,  -3.13849,  0};
    // float f[]={ 0,  150, 450, 0.049768,  -3.13849,  0};
    // float g[]={ 0,  160,  450, 0.049768, -3.13849,  0};
    // float h[]={ 0,  170,  450, 0.049768, -3.13849,  0};
    // float i[]={ 0,  180,  450, 0.049768, -3.13849,  0};
    // float j[]={ 0,  190,  450, 0.049768, -3.13849,  0};
    // float k[]={ 0,  200,  450, 0.049768, -3.13849,  0};
    // float l[]={ 0,  201,  450, 0.049768, -3.13849,  0};
    // float m[]={ 0,  202,  450, 0.049768, -3.13849,  0};
    // float n[]={ 0,  203,  450, 0.049768, -3.13849,  0};
    // float o[]={ 0,  204,  450, 0.049768, -3.13849,  0};
    // float p[]={ 0,  205,  450, 0.049768, -3.13849,  0};
    // float q[]={ 0,  206,  450, 0.049768, -3.13849,  0};
    // float r[]={ 0,  207,  450, 0.049768, -3.13849,  0};
    // float s[]={ 0,  208,  450, 0.049768, -3.13849,  0};
    // float t[]={ 0,  209,  450, 0.049768, -3.13849,  0};
    // float u[]={ 0,  300,  450, 0.049768, -3.13849,  0};
    // float u2[]={ 0,  301,  450, 0.049768, -3.13849,  0};
    // float u3[]={ 0,  302,  450, 0.049768, -3.13849,  0};
    // float u4[]={ 0,  305,  450, 0.049768, -3.13849,  0};
    // float u5[]={ 0,  309,  450, 0.049768, -3.13849,  0};
    // float u6[]={ 0,  400,  450, 0.049768, -3.13849,  0};
    // float u7[]={ 0,  405,  450, 0.049768, -3.13849,  0};
    // float u8[]={ 0,  500,  450, 0.049768, -3.13849,  0};
    // float u9[]={ 0,  505,  450, 0.049768, -3.13849,  0};
    // pos_movement(a);
    // sleep(3);
    // pos_movement(b);
    // pos_movement(c);
    // pos_movement(d);
    // pos_movement(e);
    // pos_movement(f);
    // pos_movement(g);
    // pos_movement(h);
    // pos_movement(i);
    // pos_movement(j);
    // pos_movement(k);
    // pos_movement(l);
    // pos_movement(m);
    // pos_movement(n);
    // pos_movement(o);
    // pos_movement(p);
    // pos_movement(q);
    // pos_movement(r);
    // pos_movement(s);
    // pos_movement(t);
    // pos_movement(u);
    // pos_movement(u2);
    // pos_movement(u3);
    // pos_movement(u4);
    // pos_movement(u5);
    // pos_movement(u6);
    // pos_movement(u7);
    // pos_movement(u8);
    // pos_movement(u9);
    // // brake();

    // keyboard_controller_j();
    // keyboard_controller_pos();

    // while(1)
    // {   
    //     int a;
    //     cout<<"输入"<<endl;
    //     cin>>a;
    //     // keyboard_controller_j(a,0.025);
    //     keyboard_controller_pos(a,5,0.02);
    // }

    // draw_heart();
    //////////////////获取、设置电机参数////////////////////////////////////
    /*get_elc_info();
    set_elc_info(reg_position_kp,0,MotorTypeHelper::REG_POSITION_KP, 500);
    set_elc_info(reg_position_kp,1,MotorTypeHelper::REG_POSITION_KP, 700);
    set_elc_info(reg_position_kp,2,MotorTypeHelper::REG_POSITION_KP, 800);
    set_elc_info(reg_position_kp,3,MotorTypeHelper::REG_POSITION_KP, 900);
    set_elc_info(reg_position_kp,4,MotorTypeHelper::REG_POSITION_KP, 1000);
    set_elc_info(reg_position_kp,5,MotorTypeHelper::REG_POSITION_KP, 1100);
    get_elc_info();
    cout<<"sadsad:0=="<<reg_position_kp[0]<<endl;
    cout<<"sadsad:1=="<<reg_position_kp[1]<<endl;
    cout<<"sadsad:2=="<<reg_position_kp[2]<<endl;
    cout<<"sadsad:3=="<<reg_position_kp[3]<<endl;
    cout<<"sadsad:4=="<<reg_position_kp[4]<<endl;
    cout<<"sadsad:5=="<<reg_position_kp[5]<<endl;*/
    //////////////////获取、设置电机参数////////////////////////////////////
    // qqq_test();
    logout();
    return 0;
}
