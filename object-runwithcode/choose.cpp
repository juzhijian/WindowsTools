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
    1. ��������\n\
    2. ��װ�Զ����·���\n\
    3. ж���Զ����·���\n\
    4. ����Hosts�ļ�\n\
    5. ����Hosts�ļ�(����ΪĬ�������ļ�)\n\
    6. ��ʾ������Ϣ\n\
    7. �򿪵���ģʽ����������\n\
    8. ֹͣ����\n\
    9. ��������\n\
   10. �� \".ini\" �ļ�\n\
   11. ��װ�Զ����½���(ͨ������ģʽ����)\n\
    ";
const int max_input_int=11;


TCHAR _[20]=_T("");

int _tmain(int,TCHAR const **){
	SetConsoleTitle(_T("����ִ��"));
	int inputn;
	const TCHAR * str=_T("");
	_tprintf(_T("����ģʽ�б�:\n%s\n"),showNotice);
	_tprintf(_T("������Ҫ���е�����:"));
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
