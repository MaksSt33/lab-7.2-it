// Lab_7_2_1.cpp
// <прізвище, ім’я автора>
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 15

#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;

void Create(int** a, const int k, const int n, const int Low, const int High);
void Print(int** a, const int k, const int n);
void SwapMaxMinInOddRows(int** a, const int k, const int n);
int FindMinIndex(int* row, const int n);
int FindMaxIndex(int* row, const int n);

int main()
{
    srand((unsigned)time(NULL));
    int Low = 1;
    int High = 100;
    int k, n;
    cout << "k  = "; cin >> k;
    cout << "n = "; cin >> n;

    int** a = new int* [k];
    for (int i = 0; i < k; i++)
        a[i] = new int[n];

    Create(a, k, n, Low, High);
    Print(a, k, n);
    SwapMaxMinInOddRows(a, k, n);
    cout << "Modified\n";
    Print(a, k, n);

    for (int i = 0; i < k; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}

void Create(int** a, const int k, const int n, const int Low, const int High)
{
    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = Low + rand() % (High - Low + 1);
}

void Print(int** a, const int k, const int n)
{
    cout << endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << a[i][j];
        cout << endl;
    }
    cout << endl;
}

int FindMinIndex(int* row, const int n)
{
    int minIndex = 0;
    for (int j = 1; j < n; j++)
        if (row[j] < row[minIndex]) 
            minIndex = j;
    return minIndex;
}

int FindMaxIndex(int* row, const int n)
{
    int maxIndex = 0;
    for (int j = 1; j < n; j++)
        if (row[j] > row[maxIndex]) 
            maxIndex = j;
    return maxIndex;
}

void SwapMaxMinInOddRows(int** a, const int k, const int n)
{
    for (int i = 1; i < k; i += 2) 
    {
        int minIndex = FindMinIndex(a[i], n);
        int maxIndex = FindMaxIndex(a[i], n);

        if (minIndex != maxIndex)
        {
            swap(a[i][minIndex], a[i][maxIndex]);
        }
    }
}
