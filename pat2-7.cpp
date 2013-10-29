#include<stdio.h>
#include<string>
#include<math.h>
using namespace std;

int main()
{
long n;
scanf(“%ld”,&n);
printf(“%d=”,n);
if(n==1)
printf(“1″);
int prime=2;
bool first=true;
while(n!=1)
{
int time=0;
while(n%prime==0)
{
n=n/prime;
time++;
}
if(time!=0)
{
if(first==false)
printf(“*”);
first=false;
if(time>1)
printf(“%d^%d”,prime,time);
else
printf(“%d”,prime);
}
if(prime==2)
prime=3;
else
prime+=2;
}

system(“pause”);
}
