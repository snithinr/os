#include <stdio.h>
#include <stdbool.h>
bool contains(int *frame, int nof, int page)
{
    for (int i = 0; i < nof; i++)
    {
        if (frame[i] == page)
            return true;
    }
    return false;
}

bool isFull(int *frame, int nof)
{
    for (int i = 0; i < nof; i++)
    {
        if (frame[i] == -1)
            return false;
    }
    return true;
}

void append(int *frame, int n, int page)
{
    for (int i = 0; i < n; i++)
    {
        if (frame[i] == -1)
        {
            frame[i] = page;
            return;
        }
    }
}

void display(int *frame, int nof)
{
    printf(" [ ");
    for (int i = 0; i < nof; i++)
    {   
        if(frame[i] != -1) printf("%d ", frame[i]);
        else printf(" ");
    }
    printf(" ] ");
    printf("\n");
}

int main()
{
    int nof;
    printf("Enter no of frames : ");
    scanf(" %d", &nof);
    int frame[nof];
    int n;
    printf("enter no of page references : ");
    scanf(" %d", &n);
    int page[n];
    printf("enter page reference : ");
    for (int i = 0; i < n; i++)
    {
        scanf(" %d", &page[i]);
    }
    for (int i = 0; i < nof; i++)
    {
        frame[i] = -1;
    }
    int faults = 0, hits = 0, firstIn = 0;
    for (int i = 0; i < n; i++)
    {
        if (contains(frame, nof, page[i]))
        {
            printf("%d Hit ", page[i]);
            hits++;
        }
        else
        {
            printf("%d Miss ", page[i]);

            if (!isFull(frame, nof))
            {
                append(frame, n, page[i]);
            }
            else
            {
                frame[firstIn] = page[i];
                firstIn = (firstIn + 1) % nof;
            }
            faults++;
        }
        display(frame, nof);
    }
    printf("page faults : %d\n", faults);
    printf("Hits : %d\n", hits);
    return 0;
}