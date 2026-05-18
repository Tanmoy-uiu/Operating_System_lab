#include <iostream>
#include <vector>
#include <queue>
#include <iomanip>

using namespace std;

struct Process
{
    int id;
    int arrival_time;
    int burst_time;

    int completion_time;
    int turnaround_time;
    int response_time;
    int first_run_time;

    Process(int id, int at, int bt)
    {
        this->id = id;
        arrival_time = at;
        burst_time = bt;

        completion_time = 0;
        turnaround_time = 0;
        response_time = 0;
        first_run_time = -1;
    }
};

void print_results(vector<Process> &procs)
{
    double avg_tat = 0;
    double avg_resp = 0;

    cout << "\nID\tARR\tBURST\tCOMP\tTAT\tRESP\n";

    for (auto &p : procs)
    {
        cout << "P" << p.id << "\t"
             << p.arrival_time << "\t"
             << p.burst_time << "\t"
             << p.completion_time << "\t"
             << p.turnaround_time << "\t"
             << p.response_time << "\n";

        avg_tat += p.turnaround_time;
        avg_resp += p.response_time;
    }

    avg_tat /= procs.size();
    avg_resp /= procs.size();

    cout << fixed << setprecision(2);

    cout << "\nAverage TAT: " << avg_tat << endl;
    cout << "Average Response: " << avg_resp << endl;
}

void round_robin(vector<Process> &procs, int quantum)
{
    int n = procs.size();

    vector<int> remaining(n);

    for (int i = 0; i < n; i++)
    {
        remaining[i] = procs[i].burst_time;
    }

    queue<int> q;

    vector<bool> added(n, false);

    int current_time = 0;
    int completed = 0;

    q.push(0);
    added[0] = true;

    while (!q.empty())
    {
        int idx = q.front();
        q.pop();

        if (procs[idx].first_run_time == -1)
        {
            procs[idx].first_run_time = current_time;

            procs[idx].response_time =
                current_time - procs[idx].arrival_time;
        }

        int run =
            min(quantum, remaining[idx]);

        remaining[idx] -= run;

        current_time += run;

        for (int i = 0; i < n; i++)
        {
            if (!added[i] &&
                procs[i].arrival_time <= current_time)
            {
                q.push(i);
                added[i] = true;
            }
        }

        if (remaining[idx] > 0)
        {
            q.push(idx);
        }
        else
        {
            procs[idx].completion_time = current_time;

            procs[idx].turnaround_time =
                current_time - procs[idx].arrival_time;

            completed++;
        }
    }

    print_results(procs);
}

int main()
{
    int quantum = 3;

    vector<Process> process_list;

    process_list.push_back(Process(1, 0, 8));
    process_list.push_back(Process(2, 1, 4));
    process_list.push_back(Process(3, 2, 9));
    process_list.push_back(Process(4, 3, 5));

    round_robin(process_list, quantum);
}