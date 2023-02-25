/*Mirza Mohibul Hasan*/
/*CSE-19@JUST*/
/* First Fit */
#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
int main()
{
    int blockSize[10], processSize[10], m, n, allocation[10];
    memset(allocation, -1, sizeof(allocation));

    cout << "Enter the number of memory blocks: ";
    cin >> m;
    cout << "Enter the number of processes: ";
    cin >> n;

    cout << "Enter the size of memory blocks: ";
    for (int i = 0; i < m; i++)
    {
        cin >> blockSize[i];
    }

    cout << "Enter the size of processes: ";
    for (int i = 0; i < n; i++)
    {
        cin >> processSize[i];
    }

    int lastBlock = -1;
    for (int i = 0; i < n; i++)
    {
        int j = lastBlock + 1;
        while (j != lastBlock)
        {
            if (j == m)
            {
                j = 0;
            }
            if (blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] = blockSize[j] - processSize[i];
                lastBlock = j;
                break;
            }
            j++;
        }
    }

    cout << "Process ID\tProcess Size\tBlock ID\n";
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << "\t\t" << processSize[i] << "\t\t";
        if (allocation[i] != -1)
        {
            cout << allocation[i] + 1;
        }
        else
        {
            cout << "Not Allocated";
        }
        cout << endl;
    }
    return 0;
}
