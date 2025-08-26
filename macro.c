#include <stdio.h>

#ifdef TRICK
#define TRICKORTREAT int main() { printf("TRICK!\n"); }
#elif defined TREAT
#define TRICKORTREAT int main() { printf("TREAT!\n"); }
#else
#define TRICKORTREAT int main() { printf("Oops?\n"); }
#endif

TRICKORTREAT
