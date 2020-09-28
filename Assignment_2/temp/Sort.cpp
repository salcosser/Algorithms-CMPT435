#include "Sort.h"
#include <iostream>
#include <string>

static void Sort::Insertion(string &s) {
    int n = s.length();
    for (int j = 2; j < n; j++) {
        int key = s[j];
        int i = j - 1;
        while ((i > 0) && (s[i] > key)) {
            s[i + 1] = s[i];
            i = i - 1;

        }
        s[i + 1] = key;
    }
    return;
}