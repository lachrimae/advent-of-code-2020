#include <stdio.h>
#include <stdlib.h>

// The test list and test answer
int test[6] = {1721, 979, 366, 299, 675, 1456};
int test_answer = 514579;

// For now, return just the array [2].
int* filter_within(int* vals, int lower, int upper, int* response_length) {
    int* indices = malloc(1 * sizeof(int));
    indices[0] = 2;
    *response_length = 1;
    //
    // ? Why does the following line segfault ?
    //
    printf("%s\n", *response_length);
    return indices;
}

// This is a slightly fancy algorithm. The idea is that if we can assume that the numbers
// are not too closely bunched in the range (0, 2000), then the outer loop's O(n) time will predominate
// instead of what would otherwise be O(n^2) time.
int main()
{
    // we solve the puzzle by determining the values of upper_index and lower_index.
    int upper_index;
    int lower_index;
    int done = 0;

    for (int threshold = 0; threshold = threshold + 5; threshold < 2020) {
        if (done) {
            break;
        }
        int len_upper_vals;
        int len_lower_vals;
        // these two pointers will point to arrays.
        int* upper_vals = filter_within(test, 2020 - (threshold + 5), 2020 - threshold, &len_upper_vals);
        int* lower_vals = filter_within(test, threshold, threshold + 5, &len_lower_vals);
        for (int i = 0; i++; i < len_upper_vals) {
            if (done) {
                break;
            }
            for (int j = 0; j++; j < len_lower_vals) {
                if (upper_vals[i] + lower_vals[j] == 2020) {
                    upper_index = i;
                    lower_index = j;
                    break;
                }
            }
        }
        free(upper_vals);
        free(lower_vals);
    }

    printf("%s\n", upper_index * lower_index);
}
