/*
 * This source code was published under GPL v3
 *
 * Copyright (C) 2016-2018 Too-Naive
 *
 */


#include <stdio.h>
#include <string.h>
#include <tchar.h>
#include <stdlib.h>
#include <windows.h>

#define WIN32_LEAN_AND_MEAN

#define ExecutableFileName _T("tool.exe")

TCHAR const *szParameters[]={
	_T("svc"),				//for backward compatibility
	_T("fi"),				//1
	_T("fu"),				//2
	_T("hardreset"),				//3
	_T("-debug-reset"),			//4
	_T("fi2"),				//5
	_T("?"),				//6
	_T("-debug-stop"),			//7
	_T("-debug-start"),			//8
	_T("-debug-reiu"),			//9
	_T("-debug-pipe"),			//10
	_T("--pipe"),				//11
	_T("r"),					//12
	_T("h"),
	_T("h2")
};

TCHAR const * showNotice="\
    1. 正常运行\n\
    2. 安装自动更新服务\n\
    3. 卸载自动更新服务\n\
    4. 重置Hosts文件\n\
    5. 重置Hosts文件(设置为默认主机文件)\n\
    6. 显示帮助消息\n\
    7. 打开调试模式以侦听服务\n\
    8. 停止服务\n\
    9. 启动服务\n\
   10. 打开 \".ini\" 文件\n\
   11. 安装自动更新进程(通过正常模式启动)\n\
    ";
const int max_input_int=11;


TCHAR _[20]=_T("");

int _tmain(int,TCHAR const **){
	SetConsoleTitle(_T("运行执行"));
	int inputn;
	const TCHAR * str=_T("");
	_tprintf(_T("程序模式列表:\n%s\n"),showNotice);
	_tprintf(_T("请输入要运行的数字:"));
	_tscanf(_T("%d"),&inputn);
	if (inputn>max_input_int || inputn<1) abort();
	switch (inputn){
		case 1:ShellExecute(NULL,_T("open"),ExecutableFileName,NULL,NULL,SW_SHOWNORMAL);
				exit(0);
		case 2:str=_T("fi");break;
		case 3:str=_T("fu");break;
		case 4:
		case 5:str=_T("r");break;
		case 6:str=_T("?");break;
		case 7:str=szParameters[10];break;
		case 8:str=szParameters[7];break;
		case 9:str=szParameters[8];break;
		case 10:ShellExecute(NULL,_T("open"),_T("notepad"),_T(" %windir%\\hstool.ini"),NULL,SW_SHOWDEFAULT);
			exit(0);
		case 11:str=szParameters[5];break;
//		case 12:str=szParameters[13];break;
	}
	if (inputn==5)
		_stprintf(_,_T("-%s %s"),str,szParameters[3]);
	else _stprintf(_,_T("-%s"),str);
	ShellExecute(NULL,_T("open"),ExecutableFileName,_,NULL,SW_SHOWNORMAL);
}
