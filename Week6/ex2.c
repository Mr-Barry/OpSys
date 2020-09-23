#include <stdio.h>
#include <stdlib.h>
//#include <>

int proc;
int *arr, *burst, *ct, *tat, *wt, *st;

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

int find_best (int curr_time) {
    for (int i=0; i < proc; i++) {
        //if process arrived, not completed
        if (arr[i] <= curr_time && ct[i] == 0) return i;
        //then return it, because burst is sorted and first located process is the fastest available
    }
}

int main()
{
    int proc_left, curr_exec_time = 0, curr_exec = 0, time = 0;
    double avg_tat = 0.0, avg_wt = 0.0;
    scanf("%i",&proc);
    proc_left = proc;
    arr = (int*) calloc(proc, sizeof(int));
    burst = (int*) calloc(proc, sizeof(int));
    ct = (int*) calloc(proc, sizeof(int));
    tat = (int*) calloc(proc, sizeof(int));
    wt = (int*) calloc(proc, sizeof(int));
    st = (int*) calloc(proc, sizeof(int));
    for (int i=0; i < proc; i++) {
        scanf("%i%i", &arr[i], &burst[i]);
    }
    bubble_sort(burst,proc,arr);

    //This loop imitate processor work, each iteration is 1 ms
    curr_exec = find_best(0);
    curr_exec_time = burst[curr_exec];
    st[curr_exec] = time;

    while(proc_left > 0 || curr_exec_time > 0) {
        //printf("[%i]",time);
        if(curr_exec_time == 0 && time != 0) {
            ct[curr_exec] = time;
            curr_exec = find_best(time);
            st[curr_exec] = time;
            curr_exec_time = burst[curr_exec]; //processor now busy for next process execution time
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
