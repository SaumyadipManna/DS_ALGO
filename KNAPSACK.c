#include <stdio.h>
#include <stdlib.h>

int max(int a, int b)
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int knapshak(int n, int cost[], int weight[], int w_max)
{
    if (n == 0 || w_max == 0)
    {
        return 0;
    }
    else if (weight[n - 1] > w_max)
    {
        return knapshak(n - 1, cost, weight, w_max);
    }
    else
    {
        return max(cost[n - 1] + knapshak(n - 1, cost, weight, w_max - weight[n - 1]), knapshak(n - 1, cost, weight, w_max));
    }
}

int main(int argc, char const *argv[])
{
    int n, w_max;
    printf("\nEnter the max weight: ");
    scanf("%d", &w_max);
    printf("\nEnter the number of items: ");
    scanf("%d", &n);
    int cost[n], weight[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter the cost of %d item: ", i + 1);
        scanf("%d", &cost[i]);
        printf("\nEnter the weight of %d item: ", i + 1);
        scanf("%d", &weight[i]);
    }
    printf("The solution is: %d", knapshak(n, cost, weight, w_max));

    return 0;
}