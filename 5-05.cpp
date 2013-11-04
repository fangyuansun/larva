#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<string>
using namespace std;
#define HASHLENGTH  100007
typedef struct qq{
long long  id;
string passw;
} qq;

qq data[HASHLENGTH];

int login(long long key,string passw)
{
  long long temp=key;
   while(data[temp%HASHLENGTH].id!=key &&data[temp%HASHLENGTH].id!=-1)
   {
     temp++;
   }
   if(data[temp%HASHLENGTH].id==-1)
     return 0;
   else if(data[temp%HASHLENGTH].passw==passw)
     return 1;
   else
     return 2;
}

int signup(long long key,string passw)
{
  long long temp=key;
   while(data[temp%HASHLENGTH].id!=key &&data[temp%HASHLENGTH].id!=-1)
   {
     temp++;
   }
   if(data[temp%HASHLENGTH].id==-1)
   {
  data[temp%HASHLENGTH].id=key;
  data[temp%HASHLENGTH].passw=passw;
     return 1;
   }
   else 
     return 0;
}


int main()
{
int n;
long long id;
string passw;
scanf("%d",&n);
char pw[18];

for(int i=0;i<HASHLENGTH;i++)
{
  data[i].id=-1;
}

while(n--)
{
  char sig;
   scanf("%c",&sig);
   scanf("%lld",&id);
   scanf("%s",pw);
   passw=pw;
   if(sig=='N')
   {
   int re=signup(id,passw);
   if(re)
     printf("New: OK\n");
   else
     printf("ERROR: Exist\n");

   }else
   {
   int re=login(id,passw);
   if(re==1)
     printf("Login: OK\n");
   else if(re==2)
     printf("ERROR: Wrong PW\n");
   else
     printf("ERROR: Not Exist\n");
   
   }


}

system("pause");
}
