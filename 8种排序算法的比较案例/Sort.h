#pragma once

// 建立数据表
void CreateData(int n, long long*& Data);
void show(int n, long long*& Data);

//交换辅助函数
void Swap(long long& i, long long& j);

//冒泡排序
void BubbleSort(long long& SwapTime, long long*& Data, int n);
//选择排序
void SelectSort(long long& SwapTime, long long*& Data, int n);
//直接插入排序
void InsertSort(long long& SwapTime, long long*& Data, int n);
//希尔排序
void ShellSort(long long& SwapTime, long long*& Data, int n);
//快速排序
int Partition(int low, int high, long long*& Data, int n, long long& SwapTime);
void QuickSort(int low, int high, long long*& Data, int n, long long& SwapTime);
//堆排序
void ShiftDown(int start, int end, long long SwapTime, long long*& Data);
void HeapSort(long long SwapTime, long long*& Data, int n);

//归并排序
void Merge(long long*& L1, long long*& L2, int left, int right, int mid, long long& JudgeTime);

void MergeSort(long long*& L1, long long*& L2, int left, int right, long long& JudgeTime);
//基数排序
int GetMaxExp(long long*& Data, int n);
void RadixSort(long long SwapTime, long long*& Data, int n);