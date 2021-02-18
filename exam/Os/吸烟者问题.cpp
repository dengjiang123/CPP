/*
Project:吸烟者问题
Date:    2018/08/05
Author:  Frank Yu
三个吸烟者在一个房间内,有一个香烟供应商.为了制造并抽烟,每个吸烟者必须具备：烟草、纸和火柴.
三个吸烟者中,第一个有烟草,第二个有纸,第三个有火柴.供应者有丰富的货物,
随机将两样东西放在桌子上名允许一个吸烟者进行对健康不利的吸烟.
当吸烟者完成吸烟后唤醒供应者,供应者再把两样东西放在桌子上,唤醒另一个吸烟者.
采用信号量编写他们同步工作的程序.
*/
#include<iostream>
#include<string>
#include<algorithm>
#include<Windows.h> //多线程编程
#include<process.h>
using namespace std;
//变量声明初始化**********************************************************************************
int randomnum = 0;//随机数 
HANDLE offer1, offer2, offer3;//三种材料的组合 纸和火柴 烟草和火柴 烟草和纸
HANDLE finish; //吸烟者吸完烟信号
//进程同步-供货商线程
unsigned __stdcall threadProvider(void*)
{
    for (int i = 0; ; i++) {
        randomnum = rand() % 3;//产生随机数
        if (randomnum == 0) ReleaseSemaphore(offer1, 1, NULL);//提供组合1给吸烟者1
        else if (randomnum == 1) ReleaseSemaphore(offer2, 1, NULL);//提供组合2给吸烟者2
        else ReleaseSemaphore(offer3, 1, NULL);//提供组合3给吸烟者3
        WaitForSingleObject(finish, INFINITE);//判断吸烟者是否吸完
        Sleep(1000);
    }
    return 1;
}
//进程同步-吸烟者1线程
unsigned __stdcall threadSmoker1(void*)
{
    for (int i = 0; ; i++) {
        WaitForSingleObject(offer1, INFINITE);//获得材料组合1
        cout << "吸烟者1在吸烟..." << endl;
        Sleep(100);
        ReleaseSemaphore(finish, 1, NULL);//给提供商信号
    }
    return 2;
}
//进程同步-吸烟者2线程
unsigned __stdcall threadSmoker2(void*)
{
    for (int i = 0; ; i++) {
        WaitForSingleObject(offer2, INFINITE);//获得材料组合2
        cout << "吸烟者2在吸烟..." << endl;
        Sleep(100);
        ReleaseSemaphore(finish, 1, NULL);//给提供商信号
    }
    return 3;
}
//进程同步-吸烟者3线程
unsigned __stdcall threadSmoker3(void*)
{
    for (int i = 0; ; i++) {
        WaitForSingleObject(offer3, INFINITE);//获得材料组合3
        cout << "吸烟者3在吸烟..." << endl;
        Sleep(100);
        ReleaseSemaphore(finish, 1, NULL);//给提供商信号
    }
    return 4;
}
//算法及功能*********************************************************************
//吸烟者算法模拟
void process_Smoker()
{
    //创建信号量
    offer1 = CreateSemaphore(NULL, 0, 1, NULL);//材料组合1，初值为0,最大值为1
    offer2 = CreateSemaphore(NULL, 0, 1, NULL);//材料组合2，初值为0,最大值为1
    offer3 = CreateSemaphore(NULL, 0, 1, NULL);//材料组合3，初值为0,最大值为1
    finish = CreateSemaphore(NULL, 0, 1, NULL);//材料组合3，初值为0,最大值为1
    HANDLE hth1, hth2, hth3, hth4;                     //线程句柄
    //创建线程
    hth1 = (HANDLE)_beginthreadex(NULL, 0, threadProvider, NULL, 0, NULL);//供应商线程
    hth2 = (HANDLE)_beginthreadex(NULL, 0, threadSmoker1, NULL, 0, NULL);//吸烟者1线程
    hth3 = (HANDLE)_beginthreadex(NULL, 0, threadSmoker2, NULL, 0, NULL);//吸烟者2线程
    hth4 = (HANDLE)_beginthreadex(NULL, 0, threadSmoker3, NULL, 0, NULL);//吸烟者3线程
    //等待子线程结束
    WaitForSingleObject(hth1, INFINITE);
    WaitForSingleObject(hth2, INFINITE);
    WaitForSingleObject(hth3, INFINITE);
    WaitForSingleObject(hth4, INFINITE);
    //一定要记得关闭句柄
    CloseHandle(hth1);
    CloseHandle(hth2);
    CloseHandle(hth3);
    CloseHandle(hth4);
    CloseHandle(offer1);
    CloseHandle(offer2);
    CloseHandle(offer3);
    CloseHandle(finish);
}
//主函数*********************************************************************
int main()
{
    cout << "*************欢迎进入吸烟者模拟程序****************" << endl;
    process_Smoker();
    return 0;
}