// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_value = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > max_value) {
            max_value = num;
        }
    }
    return max_value;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}

unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int longest_num = 0;
    unsigned int longest_len = 0;

    for (uint64_t i = lbound; i <= rbound; i++) {
        unsigned int len = collatzLen(i);
        if (len > longest_len) {
            longest_len = len;
            longest_num = i;
        }
    }

    *maxlen = longest_len;
    return longest_num;
}
