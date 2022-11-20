#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class process
{

public:
    int burst_time;
    int arrival_time = 0;
};

void computesjf(process parray[], int n)
{
    int min;
    for (int i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (parray[j].burst_time < parray[min].burst_time)
            {
                min = j;
            }
        }
        swap(parray[min].burst_time, parray[i].burst_time);
    }

    int wt[n];
    int tat[n];
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + parray[i - 1].burst_time;
    }

    for (int i = 0; i < n; i++)
    {
        tat[i] = wt[i] + parray[i].burst_time;
    }
    int totalwt = 0, totaltat = 0;
    for (int i = 0; i < n; i++)
    {
        totalwt += wt[i];
    }
    for (int i = 0; i < n; i++)
    {
        totaltat += tat[i];
    }
    cout << "avg wt :" << (float)totalwt / (float)n << "\n";
    cout << "avg tat :" << (float)totaltat / (float)n;
}

int main()
{
    int n;
    cout << "Enter no of processes :";
    cin >> n;
    process parray[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter burst time of " << i + 1 << " process :";
        cin >> parray[i].burst_time;
    }
    computesjf(parray, n);
}