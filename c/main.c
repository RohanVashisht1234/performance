#include <stdio.h>
#include <time.h>

#define LIMIT 100

void generateFibonacci(unsigned long long fib[], int n) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    // Start the timer
    const clock_t startTime = clock();

    unsigned long long fib[LIMIT];
    generateFibonacci(fib, LIMIT);

    // End the timer
    const clock_t endTime = clock();

    // Calculate the elapsed time in seconds and then convert to nanoseconds
    double elapsedTime = (double)(endTime - startTime) / CLOCKS_PER_SEC; // Time in seconds
    printf("C: %.6f nanoseconds.\n", elapsedTime * 1000000000.0); // Convert to nanoseconds

    return 0;
}
