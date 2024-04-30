#include <stdio.h>
#include <stdlib.h>

// 500 copies of structures
#define MAXSIZE 500

// queue ka initialization
int front = -1, rear = -1;

// structure ka creation to hold int num and int memory
struct request
{
    int num;
    int mem;
};

struct request req[500]; // creating 500 copies of struct req type variable

// insert function for queue
void insert(int number, int memory)
{

    // checking for full/empty/insertion condition to insert
    if (rear == MAXSIZE - 1)
    {
        printf("Queue is full");
        exit(0);
    }
    else if (front == -1 && rear == -1)
    {
        front = 0;
        rear = 0;

        req[rear].num = number;
        req[rear].mem = memory;
    }
    else
    {
        rear++;
        req[rear].num = number;
        req[rear].mem = memory;
    }
}

// delete function for queue
struct request rem()
{
    // check if empty or not
    if (front == -1 || front > rear)
    {
        printf("NO ELEMENTS");
    }
    else
    {
        return req[front++];
    }
}

// main function
int main()
{
    int a_m = 3000;
    int num_in, mem_in;
    int no_req;
    struct request temp;
    printf("Enter number of requests\n");
    scanf("%d", &no_req);

    // take in all requeuests and allocating num_in and mem_in
    for (int i = 0; i < no_req; i++)
    {
        num_in = 1000 + rand() % 9000; // to get num_in >1000 and <100000
        mem_in = 100 + rand() % 900;

        // passing into function
        insert(num_in, mem_in);
        printf("The process %d has been allocated %d bytes\n", num_in, mem_in);
    }

    // request processing using remeove function and checking memeory storage avaiavalbitly while front<=rear

    while (front <= rear)
    {
        temp = rem();
        if (a_m >= temp.mem)
        {
            a_m = a_m - temp.mem;
            printf("Request number %d successfullly processed, Available cap is %d\n", temp.num, a_m);
        }
        else
        {
            printf("Request number %d cannot be processed due to shortage of memory,avaiable free space is %d\n", temp.num, a_m);
            break;
        }
    }
    return 0;
}
