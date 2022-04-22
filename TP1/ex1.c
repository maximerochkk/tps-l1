#include <stdio.h>

typedef enum {false, true} bool;

void print_tab (int *tab, int size)
{
    for (int i = 0; i < size; i++) {
        printf("|%d|", tab[i]);
    }
    printf("\n");
}

void swap (int *a, int *b) 
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void insertion_sort (int *tab, int size) 
{
    for (int i = 1; i < size; i++) {
        int j = i - 1; 
        while (tab[j] > tab[i] && j >= 0) {
            swap(&tab[j], &tab[i]);
            i--, j--;
        }
    }
}

int main (void)
{
    int tab[] = {1, 9, 8, 7, 6, 1};
    int size = sizeof(tab) / sizeof(int);

    insertion_sort(tab, size);
    print_tab(tab, size);

    return 0;
}
