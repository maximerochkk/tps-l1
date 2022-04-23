#include <stdio.h>
#include <stdlib.h>

void fill_list (int *list, int n) 
{
    for (int i = 1; i <= n; i++) {
        list[i] = i;
    }
}

void print_list (int *list, int n)
{
    for (int i = 1; i <= n; i++) {
        printf("%d\n", list[i]);
    }
}

void crible_erath (int *list, int *n)
{
    int pivot, x;
    for (int i = 1; i <= *n; i++) {
        if (list[i] == 1) {
            --*n;
            for (int j = i; j <= *n; j++) {
                list[j] = list[j + 1];
            }
            i--;
        } else {
            pivot = list[i];
            for (int j = i + 1; j <= *n; j++) {
                x = 1;
                while (list[i] * x <= list[j]) {
                    if (list[i] * x == list[j]) {
                        --*n;
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
    int list[1000 + 1];
    int size = (sizeof(list) / sizeof(int)) - 1;

    fill_list(list, size);
    crible_erath(list, &size);
    print_list(list, size);

    return 0;
}