#pragma once
#include"Stack.h"

//计算幂
int getPow(int p, int e);
//栈内优先级表
int inStack_priority(char tmp_iS);
//栈外优先级表
int inComing_priority(char tmp_iC);
int DoCalculate(char tmp, LinkStack<int>& num_Stack);
//控制操作
int Calculator(int& res);
