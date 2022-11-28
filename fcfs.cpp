#include <bits/stdc++.h>
using namespace std;
class process
{
public:
    int pid;
    int burst_time;
    int arrival_time = 0;
};

void computefcfs(process parray[], int n)
{
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
    cout << "Process ID \t Burst Time\t Waiting Time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << parray[i].pid << " \t\t " << parray[i].burst_time << " \t\t " << wt[i] << " \t\t "
             << "\n";
    }
    cout << "turn around time" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << tat[i] << " \t\t "
             << "\n";
    }

    cout << "\n";
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
        cout << "Enter process id of " << i + 1 << " process :";
        cin >> parray[i].pid;
        cout << "Enter burst time of " << i + 1 << " process :";
        cin >> parray[i].burst_time;
    }
    computefcfs(parray, n);
}