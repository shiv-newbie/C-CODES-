/*
 
 Problem A
 Everlasting...? 
 Input: A.txt
 Everlasting Sa-Ga, a new, hot and very popular role-playing game, is out on October 19, 2008. Fans have been looking
 forward to a new title of Everlasting Sa-Ga.
 Little Jimmy is in trouble. He is a seven-year-old boy, and he obtained the Everlasting Sa-Ga and is attempting to reach
 the end of the game before his friends. However, he is facing difficulty solving the riddle of the first maze in this
 game — Everlasting Sa-Ga is notorious in extremely hard riddles like Neverending Fantasy and Forever Quest.
 The riddle is as follows. There are two doors on the last floor of the maze: the door to the treasure repository and the
 gate to the hell. If he wrongly opens the door to the hell, the game is over and his save data will be deleted.
 Therefore, he should never open the wrong door.
 So now, how can he find the door to the next stage? There is a positive integer given for each door — it is a great hint
 to this riddle. The door to the treasure repository has the integer that gives the larger key number. The key number of
 a positive integer n is the largest prime factor minus the total sum of any other prime factors, where the prime factors
 are the prime numbers that divide into n without leaving a remainder. Note that each prime factor should be counted only
 once.
 As an example, suppose there are doors with integers 30 and 20 respectively. Since 30 has three prime factors 2, 3 and
 5, its key number is 5 − (2 + 3) = 0. Similarly, since 20 has two prime factors 2 and 5, its key number 20 is 5 − 2 = 3.
 Jimmy therefore should open the door with 20.
 Your job is to write a program to help Jimmy by solving this riddle.
 Input
 The input is a sequence of datasets. Each dataset consists of a line that contains two integers a and b separated by a
 space (2 ≤ a, b ≤ 106). It is guaranteed that key numbers of these integers are always different.
 The input is terminated by a line with two zeros. This line is not part of any datasets and thus should not be processed.
 
 Output
 For each dataset, print in a line ‘a’ (without quotes) if the door with the integer a is connected to the treasure
 repository; print ‘b’ otherwise. No extra space or character is allowed.
 
 Sample Input
 10 15
 30 20
 0 0
 
 Output for the Sample Input
 a
 b
 */

#include <stdio.h>

int main()
{
    int a, b;
    int primes[1000002];
    primes[1] = 1;
    for(int i = 2; i*i <= 1000000; i++)
    {
        if(primes[i] == 1) continue;
        
        for(int j = 2*i; j <= 1000000; j+=i)
            primes[j] = 1;
    }
    
    while(true)
    {
        scanf("%d %d", &a, &b);
        int key1 = 0, key2 = 0, max1 = 0, max2 = 0;
        if(a == 0 && b == 0)
            break;
        
        for(int i = a; i >= 2; i--)
        {
            if(a%i == 0 && !primes[i])
            {
                key1 += i;
                if(i > max1)
                    max1 = i;
            }
        }
        key1 = 2*max1 - key1;
        
        for(int i = b; i >= 2; i--)
        {
            if(b%i == 0 && !primes[i])
            {
                key2 += i;
                if(i > max2)
                    max2 = i;

            }
        }
        key2 = 2*max2 - key2;
        
        printf("%c\n", key1 > key2 ? 'a' : 'b');
    }
    return 0;
}
