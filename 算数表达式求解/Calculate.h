#pragma once
#include"Stack.h"

//������
int getPow(int p, int e);
//ջ�����ȼ���
int inStack_priority(char tmp_iS);
//ջ�����ȼ���
int inComing_priority(char tmp_iC);
int DoCalculate(char tmp, LinkStack<int>& num_Stack);
//���Ʋ���
int Calculator(int& res);
