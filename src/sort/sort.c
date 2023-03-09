#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "sort.h"


void simpleSort_swap(simpleSort_elemType *a, simpleSort_elemType *b) {
    simpleSort_elemType temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// 从前向后的冒泡排序版本1
void bubbleSort_F2E_v1(int arr[], int n) {
    int i, j;
    bool flag;

    for(i = 0; i <= n - 1; ++i) {
        flag = false;
        for(j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                flag = true;
                simpleSort_swap(&arr[j], &arr[j + 1]);
            }
        }
        if (!flag) {
            break;
        }
    }
}

// 从前向后的冒泡排序版本2
void bubbleSort_F2E_v2(simpleSort_elemType arr[], int n) {
    int i, j;
    bool flag;

    for (i = n - 2; i >= 0; --i) {
        flag = false;

        for (j = 0; j <= i; ++j) {
            if(arr[j] > arr[j + 1]) {
                simpleSort_swap(&arr[j], &arr[j + 1]);
                flag = true;
            }
        }
        if(!flag) {
            break;
        }
    }
}

// 从后向前的冒泡排序版本1
void bubbleSort_E2F_v1(simpleSort_elemType arr[], int n) {
    int i, j;
    bool flag;

    for (i = 0; i < n - 1; ++i) {
        flag = false;

        for (j = n - 1; j >= i + 1; --j) {
            if (arr[j] < arr[j - 1]) {
                simpleSort_swap(&arr[j], &arr[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

// 从后向前的冒泡排序版本2
void bubbleSort_E2F_v2(simpleSort_elemType arr[], int n) {
    int i, j;
    bool flag;

    for (i = 1; i <= n - 1; ++i) {
        flag = false;

        for (j = n - 1; j >= i; --j) {
            if(arr[j] < arr[j - 1]) {
                simpleSort_swap(&arr[j], &arr[j - 1]);
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}

void perform_bubbleSort() {
    int i;
    int arr1[11] = {56, 5, 61, 65, 12, 31, 15, 43, 22, 8, 4};
    int arr2[11] = {56, 5, 61, 65, 12, 31, 15, 43, 22, 8, 4};
    int arr3[11] = {56, 5, 61, 65, 12, 31, 15, 43, 22, 8, 4};
    int arr4[11] = {56, 5, 61, 65, 12, 31, 15, 43, 22, 8, 4};

    bubbleSort_F2E_v1(arr1, 11);
    bubbleSort_F2E_v2(arr2, 11);
    bubbleSort_E2F_v1(arr3, 11);
    bubbleSort_E2F_v2(arr4, 11);

    for (i = 0; i < 11; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (i = 0; i < 11; ++i) {
        printf("%d ", arr2[i]);
    }
    printf("\n");

    for (i = 0; i < 11; ++i) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    for (i = 0; i < 11; ++i) {
        printf("%d ", arr4[i]);
    }
}









// 归并排序实现1：递归的方式，固定分配内存
// simpleSort_elemType用于存放排序最终结果
void mergeSort_v1(simpleSort_elemType arr[], const int n) {
    // 用于临时存储
    simpleSort_elemType req[n];
    mergeSort_recursive_v1(arr, req, 0, n - 1);
}

void mergeSort_recursive_v1(simpleSort_elemType arr[], simpleSort_elemType temp[], int start, int end) {
    if (start >= end) {
        return;
    }
    int len = end - start;
    int mid = start + (len >> 1);
    int start1 = start;
    int end1 = mid;
    int start2 = mid + 1;
    int end2 = end;
    mergeSort_recursive_v1(arr, temp, start1, end1);
    mergeSort_recursive_v1(arr, temp, start2, end2);

    int k = start;

    // 合并相同长度的部分
    while(start1 <= end1 && start2 <= end2) {
        temp[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    }

    // 剩下的直接接到尾部
    while(start1 <= end1) {
        temp[k++] = arr[start1++];
    }
    while(start2 <= end2) {
        temp[k++]= arr[start2++];
    }
    //归并完成后再复制到原数组
    for (k = start; k <= end; ++k) {
        arr[k] = temp[k];
    }
}


// 实现二：递归的方式，动态内存分配
// 第一部分，合并函数
void mergeSort_merge_v2(simpleSort_elemType arr[], simpleSort_elemType temp[], int leftBegin, int rightBegin, int rightEnd) {
    int k = leftBegin;    // 合并计数器
    int leftEnd = rightBegin - 1;
    int numOfElements = rightEnd - leftBegin + 1;
    int i;

    // 相同最小长度归并
    while (leftBegin <= leftEnd &&  rightBegin <= rightEnd) {
        temp[k++] = arr[leftBegin] <= arr[rightBegin] ? arr[leftBegin++] : arr[rightBegin++];
    }

    // 剩下的直接追加
    while (leftBegin <= leftEnd) {
        temp[k++] = arr[leftBegin++];
    }
    while (rightBegin <= rightEnd) {
        temp[k++] = arr[rightBegin++];
    }

    // 复制到原数组
    for (i = 1; i <= numOfElements; i++, --rightEnd) {
        arr[rightEnd] = temp[rightEnd];
    }
}

// 第二部分：核心递归函数
void mergeSort_v2_recursive(simpleSort_elemType arr[], simpleSort_elemType temp[], int leftBegin, int rightEnd) {
    if (leftBegin >= rightEnd) {
        return;
    }
    int center = (leftBegin + rightEnd) / 2;
    // 递归解决左边
    mergeSort_v2_recursive(arr, temp, leftBegin, center);
    //递归解决右边
    mergeSort_v2_recursive(arr, temp, center + 1, rightEnd);
    //合并
    mergeSort_merge_v2(arr, temp, leftBegin, center + 1, rightEnd);
}

// 第三部分：统一用户接口
void mergeSort_v2(simpleSort_elemType arr[], int len) {
    simpleSort_elemType *temp;
    temp = (simpleSort_elemType *)malloc(100 * sizeof(simpleSort_elemType));
    if (temp != NULL) {
        mergeSort_v2_recursive(arr, temp, 0, len - 1);
        free(temp);
    } else {
        printf("空间不足！");
    }
}

void perform_mergeSort() {
    int arr1[] = {2, 4, 7, 2, 3, 4};
    int arr2[] = {2, 4, 7, 2, 3, 4};
    mergeSort_v1(arr1, 6);
    mergeSort_v2(arr2, 6);

    int i;

    for (i = 0; i < 6; ++i) {
        printf("%d", arr1[i]);
    }
    printf("\n");

    for (i = 0; i < 6; ++i) {
        printf("%d", arr2[i]);
    }

}







// 插入排序实现1：
// 从下标为1的元素开始，假定前面的元素都是有序的
// 找到比当前元素小的元素，并将当前元素插入到他的前面
void insertSort_v1(int arr[], int len) {
    int i, j;
    int t;
    for (i = 1; i <= len - 1; ++i) {
        t = arr[i];
        for (j = i - 1; j >= 0 && t < arr[j]; --j) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = t;    //!!!!!
    }
}

// 插入排序实现2：
// 其实这种方案就是将临时变量t换成了数组的第一个元素，
// 这样数组的第一个元素就会被专门用来存放临时变量，数组的长度变大了一个
void insertSort_v2(int arr[], int len) {
    int i, j;
    for (i = 2; i <= len; ++i) {
        arr[0] = arr[i];    //  避免了申请临时变量
        for (j = i - 1; j >= 1 && arr[0] < arr[j]; --j) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = arr[0];
    }
}

void perform_insertSort() {
    int arr1[] = {1, 6556, 5646, 56, 51, 4945, 16454, 64, 894, 10, 3};
    int arr2[] = {-1, 1, 6556, 5646, 56, 51, 4945, 16454, 64, 894, 10, 3};
    int len1 = 11;
    int len2 = 11;
    insertSort_v1(arr1, len1);
    insertSort_v2(arr2, len2);

    int i;
    for (i = 0; i < len1; ++i) {
        printf("%d ", arr1[i]);
    }
    printf("\n");

    for (i = 1; i <= len2; ++i) {
        printf("%d ", arr2[i]);
    }

}














void selectSort_swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// 从第1个到倒数第2个，依次从后面的序列中找出最小的一个放到头部有序序列末尾
void selectSort(int arr[], int len) {
    int i, j, min;
    for (i = 0; i < len - 1; ++i) {
        min = i;
        for (j = i + 1; j < len; ++j) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        selectSort_swap(&arr[min], &arr[i]);
    }
}

void perform_selectSort() {
    int arr[] = {45, 5, 68, 5, 25, 1, 3, 5, 8, 9, 66, 999};
    int len = 12;
    selectSort(arr, 12);
    int i;
    for (i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
}










// 最大堆的概念
// 根结点的键值是所有堆结点键值中最大者
// 且每个结点的值都比其孩子的值大
// 左子节点的键值要大于右子节点的键值
//
// 堆排序的思路
// 1.首先所有的元素存放在一维数组中
// 2.将数组调整为一个最大堆
// 3.将堆顶元素（最大的元素）拿出放到最后，并将剩下的元素重新调整为一个最大堆
// 4.重复3直到堆中的全部元素都被取出
// 最后数组元素将按照升序排列
void array_heap_sort_swap(int *a, int *b)
{
    int t;
    t = *a;
    *a = *b;
    *b = t;
}

void array_heap_sort_perc_down(int arr[], int p, int len)
{
    // 将含有len个元素的数组arr调整成以p为根节点的最大堆
    // p 其实是数组的索引，在这里可以唯一标识一颗子树
    int x;
    int child, parent;
    // 拿出堆顶的最大元素
    x = arr[p];
    // len = 7
    /*
     实现A:       0                         实现B:           1
                / \                                       / \
               1   2                                     2   3
              / \ / \                                   / \ / \
             3  4 5  6(len-1)                          4  5 6  7（len）

     如图所示：当数组的第一个位置也被用作堆空间时             当数组的第一个位置不被用作堆空间时
        节点i的左子节点为 2 * i + 1                      节点i的左子节点为 2 * i
        最后一个父节点为 len / 2 - 1                     最后一个节点的父节点为 len / 2
        最后一个节点的索引为 len - 1                      最后一个节点的索引为 len
    */
    // 实现A
    for (parent = p; parent * 2 + 1 < len; parent = child) {
        // 左子节点
        child = parent * 2 + 1;
        // 找到子节点中最大的
        if ((child < len - 1) && arr[child] < arr[child + 1])
        {
            child++;
        }
        if (x >= arr[child]) {
            // 父节点大于子节点
            break;
        } else {
            arr[parent] = arr[child];
        }

    }
    // ？
    arr[parent] = x;
}


/// 正式的堆排序代码
void array_heap_sort(int arr[], int len)
{
    int i;
    // 第一次将原数组建立成最大堆, 从最后一个父节点开始
    for (i = len / 2 - 1; i >= 0; i--)
    {
        // 数组的名字直接可以用作指针
        array_heap_sort_perc_down(arr, i, len);
    }

    // 将最大堆调整为有序
    // 注意不是大于等于0，是大于零
    for (i = len - 1; i > 0; i--)
    {
        // 将最大的元素放到“最后”
        array_heap_sort_swap(&arr[i], &arr[0]);
        array_heap_sort_perc_down(arr, 0, i);
        // 重新调整最大堆，注意此时堆的大小已经发生了变化；
    }
}

void perform_array_heap_sort() {
    int arr[] = {0, 1, 4, 55, 45, 2, 65, 88, 89, 2, 4, 7, 852, 456, 588};
    // 第一个位置的元素有效
    int len = 15;
    array_heap_sort(arr, len);
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
}