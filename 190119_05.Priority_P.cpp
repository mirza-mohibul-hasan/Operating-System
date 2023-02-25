/*Mirza Mohibul Hasan*/
/*CSE-19@JUST*/
/*Preemptive Priority Scheduling */
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
struct process {
    int pid;
    int arrival_time;
    int burst_time;
    int priority;
    int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    struct process p[n];
    float avg_waiting_time;
    int total_waiting_time = 0;
    int burst_remaining[100];
    int is_completed[100];
    memset(is_completed,0,sizeof(is_completed));
    cout << "Enter arrival times: ";
    for(int i = 0; i < n; i++) {
        cin>>p[i].arrival_time;
    }
    cout << "Enter burst times: ";
    for(int i = 0; i < n; i++) {
        cin>>p[i].burst_time;
        burst_remaining[i] = p[i].burst_time;
    }
    cout << "Enter priorities: ";
    for(int i = 0; i < n; i++) {
        cin >> p[i].priority;
        p[i].pid = i + 1;
    }

    int current_time = 0;
    int completed = 0;
    while(completed != n) {
        int idx = -1;
        int mx = -1;
        for(int i = 0; i < n; i++) {
            if(p[i].arrival_time <= current_time && is_completed[i] == 0) {
                if(p[i].priority > mx) {
                    mx = p[i].priority;
                    idx = i;
                }
                if(p[i].priority == mx) {
                    if(p[i].arrival_time < p[idx].arrival_time) {
                        mx = p[i].priority;
                        idx = i;
                    }
                }
            }
        }

        if(idx != -1) {
            if(burst_remaining[idx] == p[idx].burst_time) {
                p[idx].start_time = current_time;
            }
            burst_remaining[idx] -= 1;
            current_time++;
            if(burst_remaining[idx] == 0) {
                p[idx].completion_time = current_time;
                p[idx].turnaround_time = p[idx].completion_time - p[idx].arrival_time;
                p[idx].waiting_time = p[idx].turnaround_time - p[idx].burst_time;
                total_waiting_time += p[idx].waiting_time;

                is_completed[idx] = 1;
                completed++;
            }
        }
        else {
             current_time++;
        }  
    }
    avg_waiting_time = (float) total_waiting_time / n;
    cout << "Process ID\tArrival time\tBurst time\tPriority\tWaiting time\n";
    for (int i = 0; i < n; i++){
        cout << p[i].pid << "\t\t" << p[i].arrival_time<< "\t\t"<< p[i].burst_time<<"\t\t" <<p[i].priority<<"\t\t"<< p[i].waiting_time << nl;
    }
    cout << "Average waiting time:" << setprecision(2) << avg_waiting_time << nl;
}