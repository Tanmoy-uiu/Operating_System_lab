#include <iostream>
#include <vector>
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

    Process(int id, int at, int bt)
    {
        this->id = id;
        arrival_time = at;
        burst_time = bt;

        completion_time = 0;
        turnaround_time = 0;
        response_time = 0;
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

void sjf(vector<Process> &procs)
{
    int n = procs.size();

    vector<bool> completed(n, false);

    int current_time = 0;
    int done = 0;

    while (done < n)
    {
        int idx = -1;
        int mn = 1e9;

        for (int i = 0; i < n; i++)
        {
            if (!completed[i] &&
                procs[i].arrival_time <= current_time)
            {
                if (procs[i].burst_time < mn)
                {
                    mn = procs[i].burst_time;
                    idx = i;
                }
            }
        }

        if (idx == -1)
        {
            current_time++;
            continue;
        }

        procs[idx].response_time =
            current_time - procs[idx].arrival_time;

        current_time += procs[idx].burst_time;

        procs[idx].completion_time = current_time;

        procs[idx].turnaround_time =
            current_time - procs[idx].arrival_time;

        completed[idx] = true;

        done++;
    }

    print_results(procs);
}

int main()
{
    vector<Process> process_list;

    process_list.push_back(Process(1, 0, 8));
    process_list.push_back(Process(2, 1, 4));
    process_list.push_back(Process(3, 2, 9));
    process_list.push_back(Process(4, 3, 5));

    sjf(process_list);
}