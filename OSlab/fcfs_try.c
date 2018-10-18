#include<stdio.h>

int main()
{
    int arr_time[5];
    int burst_time[5];
    int comp_time[5];
    int tat[5];
    int wt[5];
    int i;

    for(i = 0; i < 5; i += 1)
    {
        printf("Process : %d",i+1);
        printf("Arrival time :");
        scanf("%d",&arr_time[i]);
        printf("\n");

        printf("Burst time :");
        scanf("%d",&burst_time[i]);
        printf("\n");
    }

    int time = 0;
    for(i = 0; i < 5; i += 1)
    {
        time = time + burst_time[i];
        comp_time[i] = time;
        tat[i] = comp_time[i] - arr_time[i];
        wt[i] = tat[i] - burst_time[i];
        printf("\n");
    }

    printf("Process    : \tArrival Time  \tBurst Time  \tCompletion Time    \tTurnaround Time    \tWaiting Time    \n");
    for( i = 0 ; i < 5 ; i++ )
    {
        printf("Process %2d : \t\t%4d\t\t%4d\t\t%4d\t\t%4d\t\t%4d\n",i+1,arr_time[i],burst_time[i],comp_time[i],tat[i],wt[i]);
    }

    return 0;
}