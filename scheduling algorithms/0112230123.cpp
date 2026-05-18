#include <iostream>
#include <vector>

#include <algorithm>
#include <iomanip>

#include <cstdlib>

using namespace std;

struct Process

{

    int id;

    int arival_time;

    int burst_time;
    int prioriety; // count kori-->lotery ticket

    int cmpltion_time;

    int trn_arund_time;

    int rspnse_time;
    int first_run_time; // prothom bar cpu pabar -->time ta
                        /*int rspnse_time;
                        int first_run_time;*/

    Process(int id, int arival_time, int burst_time, int priority) : id(id),

                                                                     arival_time(arival_time),
                                                                     burst_time(burst_time),
                                                                     prioriety(priority),

                                                                     cmpltion_time(0),

                                                                     trn_arund_time(0),
                                                                     rspnse_time(0),

                                                                     first_run_time(-1)
    {
    }
};

void print_results(vector<Process> &procs)

{

    double avg_TA_time = 0;

    double avg_Resp_time = 0;

    cout << "\n";

    cout << "ID\tARRIVAL\tBURST\tTICKETS\tCOMPLESION\tTAT\tRESPONSE";
    cout << "\n";

    for (auto &tanmoy : procs) // tanmoy is a --> tempoerary holder
    {

        cout << "P" << tanmoy.id << "\t" << tanmoy.arival_time << "\t" << tanmoy.burst_time << "\t" << tanmoy.prioriety << "\t" << tanmoy.cmpltion_time << "\t\t"
             << tanmoy.trn_arund_time << "\t"
             << tanmoy.rspnse_time;
        cout << "\n";

        avg_TA_time = avg_TA_time + tanmoy.trn_arund_time;

        avg_Resp_time = avg_Resp_time + tanmoy.rspnse_time;
    }

    avg_TA_time = avg_TA_time / procs.size();

    avg_Resp_time = avg_Resp_time / procs.size();

    cout << fixed << setprecision(2);
    cout << "\n";

    cout << "avearage turn-around time: " << avg_TA_time;
    cout << endl;

    cout << "Avg response-time: " << avg_Resp_time;
    cout << endl;
}

void lottery(vector<Process> procs, int quontum)

{

    srand(42);

    int n = procs.size();

    vector<int> remainiing(n);

    int i;

    for (i = 0; i < n; i++)
    {

        remainiing[i] = procs[i].burst_time;
    }

    int current_time_unit = 0;
    int total_completed_process = 0;

    while (total_completed_process < n)
    {

        vector<int> eligible_process_list;

        int total_ticket_count = 0;

        for (int i = 0; i < n; i++)
        {

            if (procs[i].arival_time <= current_time_unit && remainiing[i] > 0)
            {

                eligible_process_list.push_back(i);

                total_ticket_count = total_ticket_count + procs[i].prioriety;
                // total_ticket_count += procs[i].prioriety;
            }
        }

        if (eligible_process_list.empty())

        {
            current_time_unit++;

            continue;
        }

        int winningTicket = rand() % total_ticket_count;

        int cumulative_ticket_sum = 0;

        int wining_proces_idx = -1;

        for (int current_process_index : eligible_process_list)
        {

            cumulative_ticket_sum = cumulative_ticket_sum + procs[current_process_index].prioriety;

            if (winningTicket < cumulative_ticket_sum)
            {

                wining_proces_idx = current_process_index;

                break;
            }
        }

        if (procs[wining_proces_idx].first_run_time == -1)

        {

            procs[wining_proces_idx].first_run_time = current_time_unit;

            procs[wining_proces_idx].rspnse_time = current_time_unit - procs[wining_proces_idx].arival_time;
        }

        int runTime = min(quontum, remainiing[wining_proces_idx]); // run kora hocche -->winner proc ke

        current_time_unit = current_time_unit + runTime;

        remainiing[wining_proces_idx] = remainiing[wining_proces_idx] - runTime;

        if (remainiing[wining_proces_idx] == 0)
        {

            procs[wining_proces_idx].cmpltion_time = current_time_unit;

            procs[wining_proces_idx].trn_arund_time = current_time_unit - procs[wining_proces_idx].arival_time;

            total_completed_process++;
            // total_completed_process+=1;
        }
    }

    print_results(procs);
}

int main()
{

    int quontum = 3;

    vector<Process> process_list;

    process_list.push_back(Process(1, 0, 8, 4));

    process_list.push_back(Process(2, 1, 4, 2));

    process_list.push_back(Process(3, 2, 9, 1));
    process_list.push_back(Process(4, 3, 5, 3));

    lottery(process_list, quontum);
}
