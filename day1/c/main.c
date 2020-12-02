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

// This is a heuristic algorithm. The idea is that if we can assume that the numbers
// are not uniformly distributed in the range (0, 2000), then the O(n) time for filter_within will predominate
// instead of the O(n^2) of main()'s inner loop.
// Tune this function by modifying `step`.
int main()
{
    // we solve the puzzle by determining the values of upper_index and lower_index.
    int upper_index;
    int lower_index;
    int done = 0;
    int step = 5;

    // TODO: this algorithm might produce an error if there are two 1010's in the list.
    for (int threshold = 0; threshold = threshold + step; threshold < 1010) {
        if (done) {
            break;
        }
        int len_upper_vals;
        int len_lower_vals;
        // these two pointers will store the "slices" of our test input which are in such a range
        // that they can possibly add to 2020.
        int* upper_vals = filter_within(test, 2020 - (threshold + step), 2020 - threshold, &len_upper_vals);
        int* lower_vals = filter_within(test, threshold, threshold + step, &len_lower_vals);
        for (int i = 0; i++; i < len_upper_vals) {
            if (done) {
                break;
            }
            for (int j = 0; j++; j < len_lower_vals) {
                if (test[upper_vals[i]] + test[lower_vals[j]] == 2020) {
                    upper_index = i;
                    lower_index = j;
                    done = 1;
                    break;
                }
            }
        }
        free(upper_vals);
        free(lower_vals);
    }

    printf("%s\n", test_answer == upper_index * lower_index);
}
