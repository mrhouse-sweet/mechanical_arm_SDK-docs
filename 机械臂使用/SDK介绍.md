---
sort: 1
---

# SDK介绍

机械臂控制的代码code中，分别是`include`，`src`，`log`以及`usrlib`。

+ [include](https://github.com/mrhouse-sweet/mechanical_arm_SDK-docs/tree/main/code/include) 存储着机械臂所需的头文件。
+ [src](https://github.com/mrhouse-sweet/mechanical_arm_SDK-docs/tree/main/code/src) 一版控制机械臂的文件放在此处，其中main.cpp是一个示例程序。
+ [log](https://github.com/mrhouse-sweet/mechanical_arm_SDK-docs/tree/main/code/log) sdk中存放log的文件夹。
+ [usrlib](https://github.com/mrhouse-sweet/mechanical_arm_SDK-docs/tree/main/code/usrlib)包含SDK所需的so文件

## 1. include

除以下提到的文件外，用户无需查看该文件夹下的其他文件。

### 1.1 mathfunc.h
机械臂的数学模型函数


### 1.2 Ti5BASIC.h

机械臂控制基础库，包含了基本控制以及信息，用户在使用时需要根据自身使用方式自行选择调用。

### 1.3 Ti5LOGIC.h

该文件是机械臂的算法库，包括正逆解，碰撞检测，规划路径等。
使用方法：根据需求在规划机械臂运动的时候可以调用该库的函数。

### 1.4 Ti5MOVE.h

机械臂运动控制库，包含的功能有直线运动，圆弧运动，机械臂初始化，机械臂手动模式控制，机械臂关节运动，机械臂坐标运动，获取机械臂当前角度值，获取机械臂当前位姿，机械臂刹车，查看机械臂是否停止运动，机械臂手动规划路径点并记录到文件中，机械臂加载路径文件，机械臂画心形。
具体函数参数请查看该文件。

### 1.5 tool.h

该文件是一些tool，具体函数使用及参数请查看该文件。

## 2. can
该文件包含can通讯的头文件，机械臂是通过can通讯与控制机联通的，具体函数功能及参数请查看里面所包含的文件中注释了解函数作用。

## 3.src
### 3.1 main.cpp

该文件是一个简单的示例程序，调用了Ti5BASIC.h中的query_can()函数，首先查找是否连接了can设备，然后调用mechanical_arm_origin()让机械臂回到初始位置，接下来调用tool.h中的show_value()函数，显示此时的位姿信息，还有一个简单的类似码垛的动作。

### 3.2 编译

最后通过一下命令进行编译生成可执行文件move_sov。(注意：以下路径是默认路径，如果修改了路径要替换成自己的)
```
g++ main.cpp  -L./include -lmylibti5 -L./include/can -lmylibscan -lcontrolcan -lspdlog -lfmt -ludev -o move_sov
```
**运行**:

sudo ./move_sov
注意机械臂处在一个安全的环境中
