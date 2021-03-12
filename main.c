#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Queue.h"

typedef struct {
    char name[20];
    int price;
} OrderData;

OrderData OrderDataList[3] = {
    {"Ramen", 100},
    {"Somtum", 20},
    {"Fried Chicken", 50}
};

int main(int argc, char **argv) {
    Queue Q;
    Q.headPtr = NULL;
    Q.tailPtr = NULL;
    Q.size = 0;
    int i, customerN = 1, cost, pay;
    order x;

    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "x") == 0) {
            x = dequeue(&Q);
            printf("Customer no. %d:\n", customerN);
            if (x.order_number > 0 && x.order_number < 4) {
                printf("  %s x%d \n", OrderDataList[x.order_number-1].name, x.q);
                cost = OrderDataList[x.order_number-1].price*x.q;
                printf("  You have to pay %d$.\n", cost);
                pay = 0;
                while (pay < cost) {
                    printf("  Cash: ");
                    scanf("%d", &pay);
                }
                printf("  Thank you!\n");
                if (pay > cost) printf("  Changes are %d$\n", pay-cost);
            } else {
                printf("  Order unavailable.\n");
            }
            customerN++;
        } else {
            enqueue(&Q, atoi(argv[i]), atoi(argv[i+1]));
            printf("My order is %d\n", atoi(argv[i]));
            i++;
        }
    }
    printf("=========================================\n");
    if (Q.size > 1) printf(" There are %d persons left in the queue.\n", Q.size);
    else if (Q.size == 1) printf(" There is 1 person left in the queue.\n");
    else printf(" The queue is empty.\n");

    return 0;
}
