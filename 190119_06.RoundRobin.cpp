/*Mirza Mohibul Hasan*/
/*CSE-19@JUST*/
/*Round Robin*/
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
int main()
{
    int n;
    cout << "Enter number of process: ";
    cin >> n;

    int arrivalTime[n];
    int burstTime[n];
    int remainingTime[n];
    int waitingTime = 0;

    cout << "Enter the arrival times: ";
    for (int i = 0; i < n; i++){
        cin >> arrivalTime[i];
    }
    cout << "Enter the burst times: ";
    for (int i = 0; i < n; i++){
        cin >> burstTime[i];
        remainingTime[i] = burstTime[i];
    }

    int time_quantum;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;
    int temp = 0;
    int remainingProcess = n;
    int waitingArray[n];
    for (int i = 0, time = 0; remainingProcess != 0;){
        if (remainingTime[i] <= time_quantum && remainingTime[i] > 0){
            time = time + remainingTime[i];

            remainingTime[i] = 0;
            temp = 1;
        }

        else if (remainingTime[i] > 0){
            remainingTime[i] = remainingTime[i] - time_quantum;
            time = time + time_quantum;
        }

        if (remainingTime[i] == 0 && temp == 1){
            remainingProcess--;
            waitingArray[i] = time - arrivalTime[i] - burstTime[i];
            waitingTime = waitingTime + waitingArray[i];
            temp = 0;
        }

        if (i == n - 1){
            i = 0;
        }
        else if (arrivalTime[i + 1] <= time){
            i++;
        }
        else{
            i = 0;
        }
    }
    cout << "Process ID\tArrival time\tBurst time\tWaiting time\n";
    for (int i = 0; i < n; i++){
        cout << i + 1 << "\t\t\t" << arrivalTime[i] << "\t\t" << burstTime[i] << "\t\t" << waitingArray[i] << nl;
    }
    cout << "Average waiting time:" <<(double)waitingTime/ n << nl;

    return 0;
}