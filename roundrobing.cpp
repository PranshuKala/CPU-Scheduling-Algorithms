#include <iostream>
using namespace std;
class process
{
public:
    int pid;
    int burst_time;
    int arrival_time = 0;
};
void compute_rr(process parray[], int n, int time){
    int burst_time_copy[n];
    int wt[n];
    int tat[n];
    int track_time = 0;
    for (int i = 0; i < n; i++){
        burst_time_copy[i] = parray[i].burst_time;
    }
    do
    {
        bool exit = true;
        for (int i = 0; i < n; i++)
        {
            if (burst_time_copy[i] > 0){
                exit = false;
                if (burst_time_copy[i] > time)
                {
                    track_time += time;
                    burst_time_copy[i] -= time;
                }
                else
                {
                    track_time += burst_time_copy[i];
                    wt[i] = track_time - parray[i].burst_time;
                    burst_time_copy[i] = 0;
                }
            }
        }
        if (exit == true){
            break;
        }

    }while (true);

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
    cout << "avg waiting time :" << (float)totalwt / (float)n << "\n";
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
    int time;
    cout << "Enter time quantum :";
    cin >> time;
    compute_rr(parray, n, time);
}