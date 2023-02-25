/*Mirza Mohibul Hasan*/
/*CSE-19@JUST*/
#include <bits/stdc++.h>
using namespace std;

struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

bool compareArrival(process p1, process p2) 
{ 
    return p1.arrival_time < p2.arrival_time;
}
bool compareID(process p1, process p2) 
{  
    return p1.pid < p2.pid;
}
int main() {

    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    struct process p[100];
    float avg_waiting_time;
    int total_waiting_time = 0;

    cout << setprecision(2) << fixed;

    for(int i = 0; i < n; i++) {
        cout<<"Enter arrival time of P "<<i+1<<": ";
        cin>>p[i].arrival_time;
        cout<<"Enter burst time of P "<<i+1<<": ";
        cin>>p[i].burst_time;
        p[i].pid = i+1;
    }
    sort(p,p+n,compareArrival);

    for(int i = 0; i < n; i++) {
        p[i].start_time = (i == 0)?p[i].arrival_time:max(p[i-1].completion_time,p[i].arrival_time);
        p[i].completion_time = p[i].start_time + p[i].burst_time;
        p[i].turnaround_time = p[i].start_time + p[i].burst_time - p[i].arrival_time;
        p[i].waiting_time = p[i].turnaround_time - p[i].burst_time;
        total_waiting_time += p[i].waiting_time;
    }
    avg_waiting_time = (float) total_waiting_time / n;
    sort(p,p+n,compareID);
    for(int i = 0; i < n; i++) {
        cout<<"Waitting time for P"<<p[i].pid<<" : "<<p[i].waiting_time<<endl;
    }
    cout<<"Total Waiting Time = "<<total_waiting_time<<endl;
    cout<<"Average Waiting Time = "<<avg_waiting_time<<endl;

}