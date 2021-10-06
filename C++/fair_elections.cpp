// Fair Elections Problem Code: FAIRELCT - (find the question followinf the code)



#include <bits/stdc++.h>
using namespace std;

int sumA(int A[],int N)
{
    int sum=0;
    for (int i=0;i<N;i++)
    {
        sum=sum+A[i];
    }
    return sum;
}

int sumB(int B[],int M)
{
    int sum=0;
    for (int i=0;i<M;i++)
    {
        sum=sum+B[i];
    }
    return sum;
}

int main()
{
    int T;
    cin>>T;
    for (int i=0; i<T; i++)
   {
       int N,M;
       cin>>N>>M;
       int A[N], B[M];
       int sum1=0, sum2=0;
       for(int i=0;i<N;i++)
       {
           cin>>A[i];
           sum1=sum1+A[i];
       }
       for(int i=0;i<M;i++)
       {
           cin>>B[i];
           sum2=sum2+B[i];
       }
       
       if(sum1>sum2)
       {
           cout<<0;
           cout<<endl;
       }
       else
       {
           sort(A,A+N);
           sort(B,B+M);
           reverse(B,B+M);
           int j=0,count=0;
           
           for(int i=0; i<N; ++i)
           {
               if(j<M)
               {
                   sum1=sum1-A[i]+B[j];
                   sum2=sum2-B[j]+A[i];
                   swap(A[i],B[j]);
                   count++;
                   j++;
                   if(sum1>sum2)
                   {
                       break;
                   }
               }
           }
           if(sum1>sum2)
                   {
                       cout<<count<<endl;
                   }
            else{
                cout<<-1<<endl;
            }
           
       }
       
   }
   return 0;
}


/*
Elections are coming soon. This year, two candidates passed to the final stage. One candidate is John Jackson and his opponent is Jack Johnson.

During the elections, everyone can vote for their favourite candidate, but no one can vote for both candidates. Then, packs of votes which went to the same candidate are formed. You know that for John Jackson, there are N packs containing A1,A2,…,AN votes, and for Jack Johnson, there are M packs containing B1,B2,…,BM votes.

The winner is the candidate that has strictly more votes than the other candidate; if both have the same number of votes, there is no winner. You are a friend of John Jackson and you want to help him win. To do that, you may perform the following operation any number of times (including zero): choose two packs of votes that currently belong to different candidates and swap them, i.e. change the votes in each of these packs so that they would go to the other candidate.

You are very careful, so you want to perform as few swaps as possible. Find the smallest number of operations you need to perform or determine that it is impossible to make John Jackson win.

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers N and M.
The second line contains N space-separated integers A1,A2,…,AN.
The third line contains M space-separated integers B1,B2,…,BM.
Output
For each test case, print a single line containing one integer ― the smallest number of swaps needed to make John Jackson win, or −1 if it is impossible.

Constraints
1≤T≤103
1≤N,M≤103
1≤Ai≤106 for each valid i
1≤Bi≤106 for each valid i
the sum of N over all test cases does not exceed 104
the sum of M over all test cases does not exceed 104
Subtasks
Subtask #1 (20 points):

A1=A2=…=AN
B1=B2=…=BM
Subtask #2 (80 points): original constraints

Sample Input 1 
2
2 3
2 2
5 5 5
4 3
1 3 2 4
6 7 8
Sample Output 1 
2
1
Explanation
Example case 1: We can perform two swaps ? each time, we swap a pack of 2 votes from A and a pack of 5 votes from B. After that, John Jackson gets 5+5=10 votes and Jack Johnson gets 2+2+5=9 votes.

Example case 2: We can swap the pack of 1 vote from A and the pack of 8 votes from B. After that, John Jackson gets 8+3+2+4=17 votes and Jack Johnson gets 6+7+1=14 votes.
*/