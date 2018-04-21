#include <iostream>

using namespace std;

class process
{
public:
     int n , twt=0 , t_t =0 ;
     int *p_a = new int[n] , *p_b=new int[n] , *p_p = new int[n] , *w_t = new int[n];
public:
    // initialize data
    void getData()
    {
        cout << "enter number of processes : ";
        cin >> n ;
        for (int i = 0 ; i < n ; i++)
            {
            cout<< "Arrival time for process->"<<i+1<<" ";
            cin >> p_a[i];
            }
        for (int i = 0 ; i < n ; i++)
            {
            cout<< "Burst time for process->"<<i+1<<" ";
            cin >> p_b[i];
            }
            for (int i = 0 ; i < n ; i++)
            {
            cout<< "Priority time for process->"<<i+1<<" ";
            cin >> p_p[i];
            }
        cout<<"Processes :\tArrivalTime\tBurstTime\tPriority\n";
        for (int i = 0 ; i < n ; i++)
            {
            cout<<"P["<<i+1<<"]"<<"\t\t"<<p_a[i]<<"\t\t"<<p_b[i]<<"\t\t"<<p_p[i]<<"\n";
            }
    }
    void FCFS()
    {
        cout<<"***First Come First Serve***\n";
        // first process wait time is when it came
        w_t[0]=p_a[0];
        // calculating waiting time for all processes
        for(int i = 1 ; i <n ; i++)
        {
            for(int j = 0 ; j<i ; j++)
            {
                w_t[i] += p_b[j];
            }
            w_t[i] = w_t[i] - p_a[i];
        }

        for (int i = 0 ; i< n ; i++)
        {
            t_t += p_b[i];
            twt += w_t[i];
        }

        double awt = twt / n ;
        cout<<"Average Waiting Time = "<<awt;
        cout<<"\nTotal Time = "<<t_t;
    }
};


int main()
{
    process test1;
    test1.getData();
    test1.FCFS();

    return 0;
}



