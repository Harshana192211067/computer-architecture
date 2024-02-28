#include <stdio.h>
int main()  
{  
    long num, binary_num, decimal_num = 0, base = 1, rem;  
    printf (" Enter a binary number with the combination of 0s and 1s \n");  
    scanf (" %ld", &num); 
    binary_num = num; 
    while ( num > 0)  
    {  
        rem = num % 10; 
        decimal_num = decimal_num + rem * base;  
        num = num / 10;  
        base = base * 2;  
    }  
  
    printf ( " The binary number is %ld \t", binary_num); 
    printf (" \n The decimal number is %ld \t", decimal_num);   
    int n=decimal_num;
     printf (" \n The decimal number is %x \t", n);   
}

