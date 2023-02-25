/*Mirza Mohibul Hasan*/
/*CSE-19@JUST*/
#include <bits/stdc++.h>
using namespace std;

struct process
{
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int waiting_time;
};
int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;
    struct process p[n];
    float avg_waiting_time;
    int total_waiting_time = 0;
    int is_completed[n];
    memset(is_completed, 0, sizeof(is_completed));

    for (int i = 0; i < n; i++)
    {
        p[i].pid = i+1;
        cout << "Arrival time of " << i + 1 << ": ";
        cin >> p[i].arrival_time;
        cout << "Burst time of " << i + 1 << ": ";
        cin >> p[i].burst_time;
    }
    cout<<endl;
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while (completed != n)
    {
        int tempid = -1;
        int temp = 10000000;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrival_time <= current_time && is_completed[i] == 0)
            {
                if (p[i].burst_time < temp)
                {
                    temp = p[i].burst_time;
                    tempid = i;
                }
                if (p[i].burst_time == temp)
                {
                    if (p[i].arrival_time < p[tempid].arrival_time)
                    {
                        temp = p[i].burst_time;
                        tempid = i;
                    }
                }
            }
        }
        if (tempid != -1)
        {
            p[tempid].start_time = current_time;
            p[tempid].completion_time = p[tempid].start_time + p[tempid].burst_time;
            p[tempid].waiting_time = p[tempid].completion_time - p[tempid].arrival_time - p[tempid].burst_time;
            total_waiting_time = total_waiting_time + p[tempid].waiting_time;

            is_completed[tempid] = 1;
            completed++;
            current_time = p[tempid].completion_time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }
    avg_waiting_time = (float)total_waiting_time / n;
    for(int i = 0; i<n; i++){
        cout<<"Waitting time for process "<<i+1<<" :"<<p[i].waiting_time<<endl;
    }
    cout << "Total Waiting Time = " << total_waiting_time << endl;
    cout << setprecision(2) << fixed << "Average Waiting Time = " << avg_waiting_time << endl;
}