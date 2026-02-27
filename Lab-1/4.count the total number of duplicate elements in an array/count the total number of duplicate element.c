#include <stdio.h>

int main() {
    int n, i, j, count = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n], visited[n];
    printf("Enter Elements:");

    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        visited[i] = 0;
    }

    for(i = 0; i < n; i++) {
        if(visited[i] == 1)
            continue;

        int dup = 0;
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                dup = 1;
                visited[j] = 1;
            }
        }

        if(dup)
            count++;
    }

    printf("Total duplicate elements = %d", count);
    return 0;
}


