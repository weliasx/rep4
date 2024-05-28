#include <stdio.h>
#include <stdbool.h>

int getFactorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * getFactorial(n - 1);
}

int num_of_trajectories;

void getTrajectories(int *P, int n, int *M, int i, int size, int
arr_of_trajectories[][n]) {
    for (int j = 0; j < size; j++) {
        int x = M[j];
        P[i] = x;
        if (i + 1 == n) {
            for (int k = 0; k < n; k++)
                arr_of_trajectories[num_of_trajectories][k] = P[k];
            num_of_trajectories++;
        } else {
            int m[n - 1];
            for (int k = 0; k < j; k++)
                m[k] = M[k];
            for (int k = j + 1; k < size; k++)
                m[k - 1] = M[k];
            getTrajectories(P, n, m, i + 1, size - 1,
                            arr_of_trajectories);
        }
    }
}

void printTrajectories(int size, int arr_of_trajectories[][size]) {
    for (int i = 0; i < num_of_trajectories; i++) {
        bool is_new_trajectory = true;
        for (int k = 0; k < i && is_new_trajectory; k++) {
            int coincidences = 0;
            for (int h = 0; h < size; h++) {
                if (arr_of_trajectories[i][h] ==
                    arr_of_trajectories[k][h])
                    coincidences++;
            }
            if (coincidences == size)
                is_new_trajectory = false;
        }
        if (is_new_trajectory) {
            for (int j = 0; j < size; j++)
                printf("%d ", arr_of_trajectories[i][j]);
            printf("\b\b\n");
        }
    }
}

int main() {
    int x, y;
    printf("Enter x and y:\n");
    scanf("%d %d", &x, &y);
    int size = x + y;
    int vector[size];
    for (int i = 0; i < size; i++) {
        if (i < x) {
            vector[i] = 1;
        }else {
            vector[i] = 0;
        }
    }
    int trajectory[size];
    int arr_of_trajectories[getFactorial(size)][size];
    num_of_trajectories = 0;
    getTrajectories(trajectory, size, vector, 0, size,
                    arr_of_trajectories);
    printTrajectories(size, arr_of_trajectories);
}
