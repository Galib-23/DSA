#include <bits/stdc++.h>
using namespace std;

struct Process
{
    int id, arrival, burst, remaining, completion, turnaround, waiting;
};

int main()
{
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    char c;
    cout << "Do you want to give arrival time? (y/n): ";
    cin >> c;
    cout << endl;

    if (c == 'y' || c == 'Y')
    {
        // with Arrival Time
        int TQ;
        cout << "Enter the time quantum (TQ): ";
        cin >> TQ;

        vector<Process> processes(n);
        queue<int> q;
        map<int, int> gantt;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter arrival time and burst time for process P" << i + 1 << ": ";
            cin >> processes[i].arrival >> processes[i].burst;
            processes[i].id = i + 1;
            processes[i].remaining = processes[i].burst;
        }

        sort(processes.begin(), processes.end(), [](Process a, Process b)
             { return a.arrival < b.arrival; });

        int time = 0, index = 0;
        q.push(0);
        vector<bool> inQueue(n, false);
        inQueue[0] = true;

        while (!q.empty())
        {
            int i = q.front();
            q.pop();

            if (processes[i].remaining <= TQ)
            {
                time += processes[i].remaining;
                processes[i].remaining = 0;
                processes[i].completion = time;
                gantt[processes[i].id] = time;
            }
            else
            {
                time += TQ;
                processes[i].remaining -= TQ;
            }

            while (index + 1 < n && processes[index + 1].arrival <= time)
            {
                index++;
                if (!inQueue[index])
                {
                    q.push(index);
                    inQueue[index] = true;
                }
            }

            if (processes[i].remaining > 0)
            {
                q.push(i);
            }
        }

        double totalTAT = 0, totalWT = 0;
        cout << "\nProcess  Arrival  Burst  Completion  Turnaround  Waiting\n";
        for (auto &p : processes)
        {
            p.turnaround = p.completion - p.arrival;
            p.waiting = p.turnaround - p.burst;
            totalTAT += p.turnaround;
            totalWT += p.waiting;

            cout << "P" << p.id << "       " << p.arrival << "       " << p.burst << "       "
                 << p.completion << "          " << p.turnaround << "          " << p.waiting << "\n";
        }

        cout << "\nAverage Turnaround Time: " << totalTAT / n << endl;
        cout << "Average Waiting Time: " << totalWT / n << endl;
    }
    else
    {
        //with Arrival Time
        int TQ;
        cout << "Enter the time quantum (TQ): ";
        cin >> TQ;

        vector<int> burstTimes(n);
        queue<pair<int, int>> q1;
        map<int, int> gantt;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter the burst time of process P" << (i + 1) << ": ";
            cin >> burstTimes[i];
            q1.push({i + 1, burstTimes[i]});
        }

        int time = 0;
        while (!q1.empty())
        {
            int process = q1.front().first;
            int processBurst = q1.front().second;
            q1.pop();

            if (processBurst <= TQ)
            {
                time += processBurst;
                gantt[process] = time;
            }
            else
            {
                time += TQ;
                processBurst -= TQ;
                q1.push({process, processBurst});
            }
        }

        int totalTAT = 0;
        cout << "\nProcess  Burst  Completion  Turnaround\n";
        for (const auto &it : gantt)
        {
            int TAT = it.second;
            cout << "P" << it.first << "       " << burstTimes[it.first - 1] << "       "
                 << it.second << "         " << TAT << "\n";
            totalTAT += TAT;
        }

        cout << "\nAverage Turnaround Time: " << (double)totalTAT / n << endl;
    }
}
