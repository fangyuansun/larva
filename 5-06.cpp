//pat 5-06. 航空公司VIP客户查询
#include<stdio.h>
#include<string>
#include<vector>
using namespace std;
#define HASH_LENGTH 200003
typedef struct {
    long long key;
    int value;
} node;

node p[HASH_LENGTH];
long long getkey(char * a)
{
    long long key=0;
    for(int i=0;a[i]!='\0';i++)
    {
        key*=10;
        if(a[i]=='x')
        {
            key*=10;
            key+='x';
        }else
        key+=a[i]-'0';
    }
    return key;
}

void hashinsert(long long key,int value)
{
    long long orikey=key;
   while(p[key%HASH_LENGTH].key!=-1 && p[key%HASH_LENGTH].key!=orikey)
   {
       key++;
   }
   
    p[key%HASH_LENGTH].key=orikey;
    p[key%HASH_LENGTH].value+=value;
    
}

int search(long long key)
{
    long long orikey=key;
  while(p[key%HASH_LENGTH].key!=-1&&p[key%HASH_LENGTH].key!=orikey)
  {
      key++;
  }
    if(p[key%HASH_LENGTH].key!=orikey)
        return -1;
    
        return p[key%HASH_LENGTH].value;
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    char id[20];
    for(int i=0;i<HASH_LENGTH+1;i++)
    {
        p[i].key=-1;
        p[i].value=0;
    }
    
    while(n--)
    {
    
        int kilo;
        scanf("%s %d",id,&kilo);
        if(kilo<k)
            kilo=k;
        long long key=getkey(id);
        hashinsert(key,kilo);
    }
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%s",id);
        long long key=getkey(id);
        int value=search(key);
        if(value==-1)
            printf("No Info\n");
        else
            printf("%d\n",value);
    }
}
