
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#endif


/**
 * Kill classroom control process
 * 关闭电子教室控制进程
 * @param processName The name of the process to kill / 要关闭的进程名称
 * @return 1 if successful, 0 if failed / 成功返回1，失败返回0
 */
int KillClassroomProcess(const char* processName) {
#ifdef _WIN32
    // Windows platform implementation / Windows平台实现
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "taskkill /F /IM %s.exe 2>nul", processName);
    int result = system(cmd);
    return (result == 0); 
#else
    // macOS/Linux platform implementation / macOS/Linux平台实现
    char cmd[256];
    snprintf(cmd, sizeof(cmd), "pkill -f %s", processName);
    int result = system(cmd);
    return (result == 0); 
#endif
}


/**
 * Enable network connection
 * 开启网络连接
 * @return Always returns 1 / 始终返回1
 */
int EnableNetworkConnection() {
#ifdef _WIN32
    // Enable network adapters on Windows / 在Windows上启用网络适配器
    system("powershell -command \"Get-NetAdapter | Where-Object {$_.Status -eq 'Disabled'} | Enable-NetAdapter\" 2>nul");
    printf("注意：此功能需要管理员权限才能正常工作\n"); // Note: This feature requires administrator privileges to work properly
    return 1;
#else
    // Enable Wi-Fi on macOS / 在macOS上启用Wi-Fi
    system("networksetup -setairportpower en0 on 2>/dev/null");
    printf("注意：此功能需要管理员权限才能正常工作\n"); // Note: This feature requires administrator privileges to work properly
    return 1;
#endif
}

/**
 * Disable network connection
 * 关闭网络连接
 * @return Always returns 1 / 始终返回1
 */
int DisableNetworkConnection() {
#ifdef _WIN32
    // Disable network adapters on Windows / 在Windows上禁用网络适配器
    system("powershell -command \"Get-NetAdapter | Where-Object {$_.Status -eq 'Up'} | Disable-NetAdapter -Confirm:$false\" 2>nul");
    printf("注意：此功能需要管理员权限才能正常工作\n"); // Note: This feature requires administrator privileges to work properly
    return 1;
#else
    // Disable Wi-Fi on macOS / 在macOS上禁用Wi-Fi
    system("networksetup -setairportpower en0 off 2>/dev/null");
    printf("注意：此功能需要管理员权限才能正常工作\n"); // Note: This feature requires administrator privileges to work properly
    return 1;
#endif
}

/**
 * Display the main menu
 * 显示主菜单
 */
void ShowMenu() {
    printf("===== 飞机哥电子教室控制程序 =====\n"); // Feijige Classroom Control Program
    printf("1. 脱空（关闭电子教室控制）\n");      // 1. Break free (Close classroom control)
    printf("2. 开启网络\n");                    // 2. Enable network
    printf("3. 关闭网络\n");                    // 3. Disable network
    printf("0. 退出程序\n");                    // 0. Exit program
    printf("请选择功能: ");                     // Please select a function:
}

/**
 * Clear the input buffer
 * 清除输入缓冲区
 */
void clearInputBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/**
 * Clear the console screen
 * 清除控制台屏幕
 */
void clearScreen() {
#ifdef _WIN32
    // Clear screen on Windows / 在Windows上清屏
    system("cls");
#else
    // Clear screen on macOS/Linux / 在macOS/Linux上清屏
    system("clear");
#endif
}

/**
 * Main function - Program entry point
 * 主函数 - 程序入口点
 * @return 0 on successful execution / 成功执行返回0
 */
int main() {
    int choice;      // User's menu choice / 用户的菜单选择
    int running = 1;  // Program running flag / 程序运行标志
    char buffer[10];  // Input buffer / 输入缓冲区
    
    // Main program loop / 主程序循环
    while (running) {
        clearScreen(); 
        ShowMenu();
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            choice = atoi(buffer);
        } else {
            choice = -1;
        }
        
        // Process user choice / 处理用户选择
        switch (choice) {
            case 1: { // Close classroom control / 关闭电子教室控制
                printf("正在尝试关闭电子教室控制...\n"); // Attempting to close classroom control...
                const char* processes[] = {"StudentMain", "ClassroomStudent", "MasterHelper", "ClassIn"};
                int success = 0;
                int i;
                
                // Try to kill each process / 尝试关闭每个进程
                for (i = 0; i < 4; i++) {
                    if (KillClassroomProcess(processes[i])) {
                        printf("成功关闭 %s 进程!\n", processes[i]); // Successfully closed process!
                        success = 1;
                    }
                }
                
                if (!success) {
                    printf("未找到电子教室进程或无法关闭。\n"); // No classroom processes found or unable to close.
                }
                
                printf("按Enter键继续..."); // Press Enter to continue...
                clearInputBuffer();
                getchar();
                break;
            }
            case 2: { // Enable network / 开启网络
                printf("正在开启网络连接...\n"); // Enabling network connection...
                if (EnableNetworkConnection()) {
                    printf("网络连接已开启!\n"); // Network connection enabled!
                } else {
                    printf("开启网络连接失败。\n"); // Failed to enable network connection.
                }
                printf("按Enter键继续..."); // Press Enter to continue...
                clearInputBuffer();
                getchar();
                break;
            }
            case 3: { // Disable network / 关闭网络
                printf("正在关闭网络连接...\n"); // Disabling network connection...
                if (DisableNetworkConnection()) {
                    printf("网络连接已关闭!\n"); // Network connection disabled!
                } else {
                    printf("关闭网络连接失败。\n"); // Failed to disable network connection.
                }
                printf("按Enter键继续..."); // Press Enter to continue...
                clearInputBuffer();
                getchar();
                break;
            }
            case 0: // Exit program / 退出程序
                running = 0;
                break;
            default: // Invalid choice / 无效选择
                printf("无效选择，请重新输入!\n"); // Invalid choice, please try again!
                printf("按Enter键继续..."); // Press Enter to continue...
                clearInputBuffer();
                getchar();
                break;
        }
    }
    
    printf("程序已退出。\n"); // Program has exited.
    return 0;
}

/********************************************************************

	it got in feijige233                                            *
 
	url huafeiyun.techotakussavetheworld.com                        *
	
	forum feijige.net                                               *
	
	please don't eat your computer                                  *
    
********************************************************************/
