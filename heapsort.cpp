#include "stdio.h"
#include "stdlib.h"
#include <iostream>
using namespace std;

void Prit_Array(int arr[], int n)
{
    int i = 0;
    printf("\n");
    for (i = 0; i < n; i++)
        printf(" %d ", arr[i]);
    printf("\n\n");
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void Max_Heapify(int arr[], int n, int i)
{

    int Largest_Index = i;
    int Left_Index = 2 * i + 1;
    int Right_Index = 2 * i + 2;

    if (Left_Index < n && arr[Largest_Index] < arr[Left_Index])
        Largest_Index = Left_Index;
    if (Right_Index < n && arr[Largest_Index] < arr[Right_Index])
        Largest_Index = Right_Index;

    if (Largest_Index != i)
    {
        swap(&arr[i], &arr[Largest_Index]);
        Max_Heapify(arr, n, Largest_Index);
    }
}

int main()
{
    int i = 0;
    int n = 0;
    int *a = NULL;
    cout<<"NAME-RISHABH SONI"<<"\t"<<"SCHOLAR NO.-20U03004"<<endl;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    a = (int *)malloc(sizeof(int) * n);
    for (i = 0; i < n; i++)
    {
        printf("Enter element [%d] : ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("given array\n");
    Prit_Array(a, n);

    for (i = n / 2; i >= 0; i--)
    {
        Max_Heapify(a, n, i);
    }
    printf("1st Time heapified array\n");
    Prit_Array(a, n);

    for (i = n - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        Max_Heapify(a, i, 0);
    }
    printf("sorted array\n");
    Prit_Array(a, n);

    // printf("\n Program by             \n");

    return 0;
}