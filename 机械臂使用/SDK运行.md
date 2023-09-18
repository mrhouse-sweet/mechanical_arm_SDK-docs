---
sort: 3
---

# SDK运行

## 实机控制

**①** 首先对机械臂进行通电

**②** 编译src文件夹下的文件，生成可执行文件，例：

```shell
./gcc.sh
或者使用：
g++ main.cpp  -L./include -lmylibti5 -L./include/can -lmylibscan -lcontrolcan -lspdlog -lfmt -ludev -o move_sov
```

**③** 执行`sudo ./move_sov`

当执行该条命令后，终端会打印`找到的 CAN 设备序列号：USBCAN-31F10001C21`语句(这里的设备号会随着不同的can设备改变不是固定的)，我们可以看到已经成功连接can设备，并于机械臂建立了通讯。
接下来机械臂会按照程序执行相应的动作。
