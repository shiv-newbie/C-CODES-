// Code by Shivam Haldiya

//Problem D: Above Average
//It is said that 90% of frosh expect to be above average in their class. You are to provide a reality check.
//The first line of standard input contains an integer
//C, the number of test cases. C data sets follow.
//Each data set begins with an integer, N, the
//number of people in the class (1 <= N <= 1000).
//N integers follow, separated by spaces or
//newlines, each giving the final grade (an integer
//between 0 and 100) of a student in the class. For
//each case you are to output a line giving the percentage of students whose grade is above average, rounded to 3 decimal places.
//Sample Input
//5
//5 50 50 70 80 100
//7 100 95 90 80 70 60 50
//3 70 90 80
//3 70 90 81
//9 100 99 98 97 96 95 94 93 91
//Output for Sample Input
//40.000%
//57.143%
//33.333%
//66.667%
//55.556%

#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        vector<int> here;
        int t, j;
        scanf("%d", &t);
        float average = 0;
        for(int i =0; i < t; i++)
        {
            scanf("%d", &j);
            average += j;
            here.push_back(j);
        }
        average = average/t;
        sort(here.begin(),here.end(), greater<int>());
        int i;
        for(i = 0; i < t; i++)
        {
            if(here[i] <= average)
                break;
        }
        printf("%.3f%%\n", float(i)*100/t);
    }
    return 0;
}
