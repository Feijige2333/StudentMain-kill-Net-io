# 电子教室控制程序

这是一个基于windows系统的电子教室控制工具，可以帮助用户实现"脱空"（摆脱教师屏幕控制）和网络连接管理功能。

## 功能特点

1. **脱空功能**：关闭常见电子教室软件的进程，暂时摆脱教师的屏幕控制
2. **网络管理**：开启或关闭网络连接

## 使用方法

### 编译程序

使用g++或其他C++编译器编译`ClassroomControl.cpp`文件：

```
g++ ClassroomControl.cpp -o ClassroomControl
```

### 运行程序

在终端中运行编译好的`ClassroomControl`程序。

### 菜单选项

程序运行后会显示以下菜单：

```
===== 飞机哥电子教室控制程序 =====
1. 脱空（关闭电子教室控制）
2. 开启网络
3. 关闭网络
0. 退出程序
请选择功能:
```

- 选择`1`：尝试关闭电子教室控制软件进程
- 选择`2`：开启网络连接
- 选择`3`：关闭网络连接
- 选择`0`：退出程序

## 注意事项

1. 本程序需要管理员权限才能正常运行，特别是网络管理功能
2. 程序默认尝试关闭几种常见电子教室软件的进程，如需添加其他软件，请修改源代码中的进程名列表
3. 网络管理功能默认操作Wi-Fi接口，如需修改，请调整源代码中的接口名称

## 免责声明

本程序仅供学习和研究使用，请勿用于非法用途。使用本程序可能违反学校规定，请在合法合规的情况下使用。

---

# Classroom Control Program

This is a windows-based electronic classroom control tool that helps users "break free" (escape teacher's screen control) and manage network connections.

## Features

1. **Break Free Function**: Close common electronic classroom software processes to temporarily escape teacher's screen control
2. **Network Management**: Enable or disable network connections

## Usage Instructions

### Compile the Program

Use g++ or other C++ compiler to compile the `ClassroomControl.cpp` file:

```
g++ ClassroomControl.cpp -o ClassroomControl
```

### Run the Program

Run the compiled `ClassroomControl` program in terminal.

### Menu Options

After running the program, the following menu will be displayed:

```
===== Feijige Classroom Control Program =====
1. Break Free (Close Classroom Control)
2. Enable Network
3. Disable Network
0. Exit Program
Please select a function:
```

- Select `1`: Attempt to close electronic classroom control software processes
- Select `2`: Enable network connection
- Select `3`: Disable network connection
- Select `0`: Exit program

## Notes

1. This program requires administrator privileges to run properly, especially for network management functions
2. The program attempts to close several common electronic classroom software processes by default; to add other software, please modify the process name list in the source code
3. The network management function operates on the Wi-Fi interface by default; to modify this, please adjust the interface name in the source code

## Disclaimer

This program is for learning and research purposes only. Do not use it for illegal purposes. Using this program may violate school regulations; please use it in compliance with laws and regulations.



*********************************************************************

	it got in feijige233                                            *
 
	url huafeiyun.techotakussavetheworld.com                        *
	
	forum feijige.net                                               *
	
	please don't eat your computer                                  *
    
*********************************************************************
