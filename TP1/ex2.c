#include <stdio.h>
#include <stdlib.h>

void fill_list (int *list, int *n) 
{
    for (int i = 1; i <= *n; i++) {
        list[i] = i;
    }
}

void print_list (int *list, int *n)
{
    for (int i = 1; i <= *n; i++) {
        printf("%d\n", list[i]);
    }
}

void crible_erath (int *list, int *n)
{
    for (int i = 1; i <= *n; i++) {
        if (list[i] == 1) {
            *n = *n - 1;
            for (int j = i; j <= *n; j++) {
                list[j] = list[j + 1];
            }
            i--;
        } else {
            int pivot = list[i];
            for (int j = i + 1; j <= *n; j++) {
                int x = 1;
                while (list[i] * x <= list[j]) {
                    if (list[i] * x == list[j]) {
                        *n = *n - 1;
                        for (int z = j; z <= *n; z++) {
                            list[z] = list[z + 1];
                        }
                        j--;
                    } else {
                        x++;
                    }
                }
            }
        }
    }
}

int main (void)
{
    int *n = calloc(1, sizeof(int));
    *n = 1000;

    int list[*n];
    fill_list(list, n);

    crible_erath(list, n);
    print_list(list, n);
    
    free(n);
    
    return 0;
}
