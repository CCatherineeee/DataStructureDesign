#pragma once

// �������ݱ�
void CreateData(int n, long long*& Data);
void show(int n, long long*& Data);

//������������
void Swap(long long& i, long long& j);

//ð������
void BubbleSort(long long& SwapTime, long long*& Data, int n);
//ѡ������
void SelectSort(long long& SwapTime, long long*& Data, int n);
//ֱ�Ӳ�������
void InsertSort(long long& SwapTime, long long*& Data, int n);
//ϣ������
void ShellSort(long long& SwapTime, long long*& Data, int n);
//��������
int Partition(int low, int high, long long*& Data, int n, long long& SwapTime);
void QuickSort(int low, int high, long long*& Data, int n, long long& SwapTime);
//������
void ShiftDown(int start, int end, long long SwapTime, long long*& Data);
void HeapSort(long long SwapTime, long long*& Data, int n);

//�鲢����
void Merge(long long*& L1, long long*& L2, int left, int right, int mid, long long& JudgeTime);

void MergeSort(long long*& L1, long long*& L2, int left, int right, long long& JudgeTime);
//��������
int GetMaxExp(long long*& Data, int n);
void RadixSort(long long SwapTime, long long*& Data, int n);