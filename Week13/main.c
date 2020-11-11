#include <stdio.h>
#include <stdlib.h>

//function finds number of deadlocks and returns it
int find_deadlocks (FILE *in) {
    int i,j; //temp variables
    if (!(in = fopen("input_ok.txt", "r"))) {
        printf("Some error occurred");
    };

    //since program should work with any number of resources, we have to know num of processes and res
    int res_total, proc_total;
    fscanf(in, "%d", &res_total);
    fscanf(in, "%d", &proc_total);

    int *res_Exist = malloc(res_total * sizeof(int));        // E array
    for (i=0; i < res_total; ++i) fscanf(in, "%d", &res_Exist[i]);

    int *res_Avaliable = malloc(res_total * sizeof(int));    // A array
    for (i=0; i < res_total; ++i) fscanf(in, "%d", &res_Avaliable[i]);

    int **curr_alloc = malloc(proc_total * sizeof(int*));
    for (i=0; i < proc_total; ++i) {
            curr_alloc[i] = malloc(res_total * sizeof(int));
            for (j=0; j < res_total; ++j) fscanf(in, "%d", &curr_alloc[i][j]);
    }

    int **request = malloc(proc_total * sizeof(int*));
    for (i=0; i < proc_total; ++i) {
            request[i] = malloc(res_total * sizeof(int));
            for (j=0; j < res_total; ++j) fscanf(in, "%d", &request[i][j]);
    }

    // Array of flags, 0 is not terminated, 1 is terminated
    unsigned short *terminated_proc = calloc(proc_total, sizeof(int));
    int terminated_proc_num = 0; // how many proc terminated
    int prev_term_proc_num = -1; // equal prev number on prev iteration

    while (terminated_proc_num < proc_total) {
        // If after 1 iteration no process was terminated
        if (terminated_proc_num == prev_term_proc_num) {
            // then there is deadlock
            break;
        }
        prev_term_proc_num = terminated_proc_num;

        for (i=0; i < proc_total; ++i) {
            if (terminated_proc[i]) continue;
            unsigned short flag = 0;
            // check if current
            for (j=0; j < res_total; ++j) {
                // if process require more than avaliable, it will not be terminated
                if (request[i][j] > res_Avaliable[j]) {
                    flag = 1;
                    break;
                }
            }
            // if this process require avaliable resources
            if (!flag) {
                terminated_proc[i] = 1;
                terminated_proc_num++;
                for (j=0; j < res_total; ++j) {
                    res_Avaliable[j] += curr_alloc[i][j];
                }
            }
        }
    }

    return proc_total - terminated_proc_num;
}

int main() {
    int dlocks1, dlocks2;

    FILE *in_ok = fopen("input_ok.txt", "r");
    dlocks1 = find_deadlocks(in_ok);
    fclose(in_ok);

    FILE *in_dlock = fopen("input_dlock.txt", "r");
    dlocks2 = find_deadlocks(in_dlock);
    fclose(in_dlock);

    FILE *out_ok = fopen("output_ok.txt", "w");
    if (dlocks1 == 0) {
        fprintf(out_ok, "No deadlocks has found");
    } else {
        fprintf(out_ok, "There is %d deadlocks", dlocks1);
    }

    FILE *out_dlock = fopen("output_dlock.txt", "w");

    if (dlocks2 == 0) {
        fprintf(out_dlock, "No deadlocks has found");
    } else {
        fprintf(out_dlock, "There is %d deadlocks", dlocks2);
    }

    return(0);
}
