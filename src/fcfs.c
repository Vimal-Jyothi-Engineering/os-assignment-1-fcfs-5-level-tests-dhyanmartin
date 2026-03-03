#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 0) return 0;

    int at[100], bt[100];
    int wt[100], tat[100];

    for (int i = 0; i < n; i++) {
        char pname[20];
        scanf("%s %d %d", pname, &at[i], &bt[i]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                int t;
                t = at[j]; at[j] = at[j + 1]; at[j + 1] = t;
                t = bt[j]; bt[j] = bt[j + 1]; bt[j + 1] = t;
            }
        }
    }

    int current = 0;

    for (int i = 0; i < n; i++) {
        if (current < at[i])
            current = at[i];

        wt[i] = current - at[i];
        tat[i] = wt[i] + bt[i];

        current += bt[i];
    }

    double avgWT = 0, avgTAT = 0;

    for (int i = 0; i < n; i++) {
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    printf("Waiting Time:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", wt[i]);

    printf("Turnaround Time:\n");
    for (int i = 0; i < n; i++)
        printf("%d\n", tat[i]);

    printf("Average Waiting Time: %.2f\n", avgWT);
    printf("Average Turnaround Time: %.2f\n", avgTAT);

    return 0;
}