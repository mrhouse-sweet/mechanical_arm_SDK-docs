---
sort: 3
---
# 环境安装

运动控制程序可以在Ubuntu 18.04以上的X86架构下的linux平台运行，

建议使用 Ubuntu22.04

首先在终端中输入以下命令下载SDK：

cd ~

git clone https://github.com/mrhouse-sweet/mechanical_arm_SDK-docs.git
## 依赖安装

+ `libspdlog-dev`
+ `libopencv-dev`
+ `libudev-dev`

```bash
sudo apt install -y libspdlog-dev libopencv-dev libudev-dev
```
+ `将usrlib中的libcontrolcan.so  libmylibscan.so libmylibti5.so文件拷贝到/usr/lib/下`

```bash
cd mechanical_arm_5_0_SDK/code/usrlib
sudo cp * /usr/lib
```

+ [pybind11](https://pybind11.readthedocs.io/en/stable/)

如果需要使用python接口，需安装pybind11

```bash
# Install pybind11
git clone https://github.com/pybind/pybind11.git
cd pybind11
mkdir build && cd build
cmake .. -DPYBIND11_TEST=OFF
make -j
sudo make install
```
# SDK运行

## 实机控制

**①** 首先对机械臂进行通电 

**②** 编译src文件夹下的文件，生成可执行文件，例：

```shell
首次编译需要执行以下两条命令
cd mechanical_arm_5_0_SDK/code/src
export CPLUS_INCLUDE_PATH=~/mechanical_arm_5_0_SDK/code/include:$CPLUS_INCLUDE_PATH
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:~/mechanical_arm_5_0_SDK/code/include/can

然后进行编译：
sudo sh ./gcc.sh
或者使用：
g++ main.cpp  -L./include -lmylibti5 -L./include/can -lmylibscan -lcontrolcan -lspdlog -lfmt -ludev -o move_sov
```

**③** 执行`sudo ./move_sov`

当执行该条命令后，终端会打印`找到的 CAN 设备序列号：USBCAN-31F10001C21`语句(这里的设备号会随着不同的can设备改变不是固定的)，我们可以看到已经成功连接can设备，并于机械臂建立了通讯。
接下来机械臂会按照程序执行相应的动作。

