#include <stdio.h>
#include <string.h>

struct Process {
    char name[20];
    int at;
    int bt;
    int wt;
    int tat;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    struct Process p[100];

    for (int i = 0; i < n; i++) {
        scanf("%s %d %d", p[i].name, &p[i].at, &p[i].bt);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    int currentTime = 0;
    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++) {
        if (currentTime < p[i].at) {
            currentTime = p[i].at;
        }
        
        p[i].wt = currentTime - p[i].at;
        p[i].tat = p[i].wt + p[i].bt;
        currentTime += p[i].bt;

        totalWT += p[i].wt;
        totalTAT += p[i].tat;
    }

    for (int i = 0; i < n; i++) {
        printf("%s %d %d\n", p[i].name, p[i].wt, p[i].tat);
    }

    printf("%.2f\n", totalWT / n);
    printf("%.2f\n", totalTAT / n);

    return 0;
}