#include <stdio.h>
#include <stdbool.h>
#include <values.h>

int page_frames;
bool search_in_frame(int page_num, int frame[]) {
    for (int i = 0; i < page_frames; i++) {
        if (frame[i] == page_num) return true;
    }
    return false;
}

int find_most_aged_ind(int *age) {
    int min = MAXINT;
    int i = 0;
    int ind = 0;
    for (i = 0; i < page_frames; i++) {
        if (age[i] < min) {
            min = age[i];
            ind = i;
        }
    }
    return ind;
}

void shift_age(int age[], int page_num, int frame[]) {
    for (int i = 0; i < page_frames; i++) {
        if (frame[i] == page_num) age[i] = MAXINT;
        else
            age[i] = age[i]>>1;
    }
}

int main() {
    printf("%s", "Number of page frames: ");
    int hit;
    int miss;

    scanf("%d", &page_frames);
    int frame[page_frames];
    int age[page_frames];

    for (int i = 0; i < page_frames; i++) {
        frame[i] = 0;
    }

    for (int i = 0; i < page_frames; i++) {
        age[i] = 0;
    }

    FILE *file = fopen("input.txt", "r");
    int page_num;

    while (!feof(file)) {
        fscanf(file, "%d", &page_num);
        bool nhit = search_in_frame(page_num, frame);
        if (nhit) {
            hit++;
            shift_age(age, page_num, frame);
        } else {
            miss++;
            int most_aged_ind = find_most_aged_ind(age);
            frame[most_aged_ind] = page_num;
            age[most_aged_ind] = 0;
            shift_age(age, page_num, frame);
        }
    }
    printf("%s%d\n", "Hit: ", hit);
    printf("%s%d\n", "Miss: ", miss);
    fclose(file);
}
