#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int random(int lowerBound, int upperBound) {
    int diff = upperBound - lowerBound + 1;
    return rand() % diff + lowerBound;
}
