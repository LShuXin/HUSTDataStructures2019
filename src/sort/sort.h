#ifndef SORT_H
#define SORT_H


typedef int simpleSort_elemType;

void simpleSort_swap(simpleSort_elemType *a, simpleSort_elemType *b);

void bubbleSort_F2E_v1(int arr[], int n);

void bubbleSort_F2E_v2(simpleSort_elemType arr[], int n);

void bubbleSort_E2F_v1(simpleSort_elemType arr[], int n);

void bubbleSort_E2F_v2(simpleSort_elemType arr[], int n);

void perform_bubbleSort();



void mergeSort_recursive_v1(simpleSort_elemType arr[], simpleSort_elemType temp[], int start, int end);

void mergeSort_v1(simpleSort_elemType arr[], const int n);

void mergeSort_merge_v2(simpleSort_elemType arr[], simpleSort_elemType temp[], int leftBegin, int rightBegin, int rightEnd);

void mergeSort_v2_recursive(simpleSort_elemType arr[], simpleSort_elemType temp[], int leftBegin, int rightEnd);

void mergeSort_v2(simpleSort_elemType arr[], int len);

void perform_mergeSort();

void insertSort_v1(int arr[], int len);

void insertSort_v2(int arr[], int len);


void perform_insertSort();



void selectSort_swap(int *a, int *b);


void selectSort(int arr[], int len);



void perform_selectSort();


#endif