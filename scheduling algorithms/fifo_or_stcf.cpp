#include <iostream>
#include <vector>
#include <algorithm>
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

void fifo(vector<Process> &procs)
{
    sort(procs.begin(), procs.end(),
         [](Process &a, Process &b)
         {
             return a.arrival_time < b.arrival_time;
         });

    int current_time = 0;

    for (int i = 0; i < procs.size(); i++)
    {
        if (current_time < procs[i].arrival_time)
        {
            current_time = procs[i].arrival_time;
        }

        procs[i].response_time =
            current_time - procs[i].arrival_time;

        current_time += procs[i].burst_time;

        procs[i].completion_time = current_time;

        procs[i].turnaround_time =
            current_time - procs[i].arrival_time;
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

    fifo(process_list);
}