#include <marsTime.h>

/*
    x = earth seconds - k
    y = x - (x >> 3) - (x / 53) + (x / 19820)
    mars seconds = x - (y >> 5)
*/
marsSol = firstMarsSol;
