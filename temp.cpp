#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;

int a[1000000];
int b[1000000];
bool compare(int a,int b)
{
return a>b;
}
int main()
{
long long result=0;
int n,m;
scanf("%d",&n);
for(int i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
scanf("%d",&m);
for(int i=0;i<m;i++)
{
  scanf("%d",&b[i]);
}

int maxindex=n;
if(n<m)
{
sort(a,a+n,compare);
int neg=n;
for(int i=0;i<n;i++)
{
 if(a[i]<=0)
 {
	 neg=i;
	 break;
 }
}
partial_sort(b,b+neg,b+m,compare);
partial_sort(b+neg,b+n,b+m,compare);

}
else
{
	maxindex=m;
sort(b,b+m,compare);
int neg=m;
for(int i=0;i<m;i++)
{
 if(b[i]<=0)
 {
	 neg=i;
	 break;
 }
}
partial_sort(a,a+neg,a+n,compare);
partial_sort(a+neg,a+m,a+n,compare);
}
for(int i=0;i<maxindex;i++)
{
	result+=(a[i]*b[i]<=0)?0:a[i]*b[i];
}
printf("%lld",result);
system("pause");
}
