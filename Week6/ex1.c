#include <stdio.h>
#include <stdlib.h>
//#include <>

void bubble_sort(int * data, int size, int * data_mirrow) {
    int i,j, temp;
    for (i=0; i < size-1; i++) {
        for (j=i+1; j < size; ++j) {
            if (data[i] > data[j]) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                temp = data_mirrow[i];
                data_mirrow[i] = data_mirrow[j];
                data_mirrow[j] = temp;
            }
        }
    }
}

int main()
{
    int proc, proc_left, curr_exec_time = 0, curr_exec = 0, time = 0;
    int *arr, *burst, *ct, *tat, *wt, *st;
    double avg_tat = 0.0, avg_wt = 0.0;
    scanf("%i",&proc);
    proc_left = proc;
    arr = (int*) malloc(sizeof(int) * proc);
    burst = (int*) malloc(sizeof(int) * proc);
    ct = (int*) malloc(sizeof(int) * proc);
    tat = (int*) malloc(sizeof(int) * proc);
    wt = (int*) malloc(sizeof(int) * proc);
    st = (int*) malloc(sizeof(int) * proc);
    for (int i=0; i < proc; i++) {
        scanf("%i%i", &arr[i], &burst[i]);
    }
    bubble_sort(arr,proc,burst);

    //This loop imitate processor work, each iteration is 1 ms
    while(proc_left > 0 || curr_exec_time > 0) {
        //printf("[%i]",time);
        if(curr_exec_time == 0) {
            st[curr_exec] = time;
            curr_exec_time = burst[curr_exec]; //processor now busy for next process execution time
            curr_exec++;
            proc_left--;    //how many processes left
        }
        curr_exec_time--;
        time++;
    }

    for (int i=0; i < proc; i++) {
        ct[i] = st[i] + burst[i];
        tat[i] = ct[i] - arr[i];
        wt[i] = st[i] - arr[i];
        avg_tat += tat[i];
        avg_wt += wt[i];
        printf("CT %i, TAT %i, WT %i\n",ct[i], tat[i], wt[i]);
    }
    printf("Average TAT %.4f, average WT %.4f\n", avg_tat/proc, avg_wt/proc);
    printf("Total time is %d\n",time);
    return 0;
}
