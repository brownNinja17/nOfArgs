#include <stdio.h>
#include <stdarg.h>
#include <nArgs.h>

#define minimum(...) minimum_(nArgs(__VA_ARGS__),__VA_ARGS__)
int minimum_ (int numberOfArguments,   ... );

#define maximum(...) maximum_(nArgs(__VA_ARGS__),__VA_ARGS__)
int maximum_(int numberOfArguments,  ... );

#define average(...) average_(nArgs(__VA_ARGS__),__VA_ARGS__)
float average_(int numberOfArguments,  ... );


int main(void)
{
	int n =	nArgs(3,2,3,4);
    
    printf("Number of arguments is: %d \n", n);	
	printf("Minimum value is :  %d \n", minimum(-3,2,3,-4));
	printf("Maximum value is :  %d \n", maximum(-3,2,3,7,8,9,100,-4));
	printf("Average value is :  %.2f \n", average(-3,2,3,7,8,9,100,-4));
    return 0;
}

int minimum_(int n,  ... )
{
	va_list variable_list;
    int temp_minimum = 2147483647;
	int temp;
    va_start(variable_list, n);
    for (int i = 0; i < n; i++) {
        temp = va_arg(variable_list, int);
        if(temp_minimum > temp)
        {temp_minimum = temp;}
    }
    va_end(variable_list);
	return temp_minimum;
}

int maximum_ (int n, ... )
{
	va_list variable_list;
    int temp_maximum = -2147483648;
	int temp;
    va_start(variable_list, n);
    for (int i = 0; i < n; i++) {
        temp = va_arg(variable_list, int);
        if(temp_maximum < temp)
        {temp_maximum = temp;}
    }
    va_end(variable_list);
	return temp_maximum;
}

float average_ (int n, ... )
{
	va_list variable_list;
    int temp = 0;
    va_start(variable_list, n);
    for (int i = 0; i < n; i++) {
        temp += + va_arg(variable_list, int);
    }
    va_end(variable_list);
	return (float)temp/(float)n;
} 
