/*
 Prime(N) – Prime(N-1) = ?
 The sequence of n - 1 consecutive composite numbers (positive integers that are not prime and not equal to 1) lying between two successive prime numbers
 p and p + n is called a prime gap of length n. For example, (24, 25, 26, 27, 28) between 23 and 29 is a prime gap of length 6.
 
 Your mission is to write a program to calculate, for a given positive integer k, the length of the prime gap that contains k. For convenience, the
 length is considered 0 in case no prime gap contains k.
 
 Input
 The input is a sequence of lines each of which contains a single positive integer. Each positive integer is greater than 1 and less than or equal to the
 100000th prime number, which is 1299709. The end of the input is indicated by a line containing a single zero.
 
 Output
 The output should be composed of lines each of which contains a single non-negative integer. It is the length of the prime gap that contains the
 corresponding positive integer in the input if it is a composite number or `0' otherwise. No other characters should occur in the output.
 
 Sample Input
 10
 11
 27
 2
 492170
 0
 
 Sample Output
 4
 0
 6
 0 114
 */

#include <stdio.h>

int main()
{
    int num;
    
    int check[1299710] = {0};
    for(int i = 2; i*i <= 1299710; i++)
    {
        if(check[i] == 1) continue;
        
        for(int j = 2*i; j <= 1299710; j+=i)
            check[j] = 1;
    }
    
    int isTrue = 1;
    while(isTrue)
    {
        scanf("%d", &num);
        int min = num, max = num;
        if(num == 0)
            isTrue = 0;
        
        if(!check[num])
        {
            printf("%d\n", 0);
            continue;
        }
        
        while(min--)
        {
            if(!check[min])
                break;
        }
        
        while(max++)
        {
            if(!check[max])
                break;
        }
            
        printf("%d\n", max-min);
    }
    return 0;
}
