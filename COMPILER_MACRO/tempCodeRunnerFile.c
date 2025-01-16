#include <stdio.h>
                #define CREATE_VAR(name)    \
                int int_##name;             \
                double double_##name

                int main()
                {
                    CREATE_VAR(abc);
                    int_abc =1;
                    double_abc =2.5;
                    printf("%d %f\n", int_abc, double_abc);
                    return 0;
                }