
#include <stdlib.h>
#include <memory.h>
#include <malloc/malloc.h>

void * reallocate(void * ptr, size_t size)
{
    void * new_ptr;
    if (size == 0) {
        free(ptr);
        return NULL;
    }
    if (ptr == NULL) {
        return new_ptr = malloc(size);
    } else {
        if (malloc_size(ptr) < size) {
            new_ptr = malloc(size);
            memcpy(new_ptr, ptr, malloc_size(ptr));
            free(ptr);
        } else {
            new_ptr = ptr;
        }
    }
    return new_ptr;
}

int main() {
    int n = 10;
    int * arr = (int *) malloc(sizeof(int));
    for (int i = 0; i < n; i++) {
        arr = (int *) myrealloc(arr, sizeof(int) * (i + 1));
        arr[i] = i;
        for (int j = 0; j <= i; j++) {
            printf("%d ", arr[j]);
        }
        printf ("\n");
    }
    free(arr);
}