#include<iostream> 
#include<stdio.h>
int n;
void print(int i)
{
switch(i)
{
case 0:{printf("2(0)");break;}
case 1:{printf("2");break;}
case 2:{printf("2(2)");break;}
case 3:{printf("2(2+2(0))");break;}
case 4:{printf("2(2(2))");break;}
case 5:{printf("2(2(2)+2(0))");break;}
case 6:{printf("2(2(2)+2)");break;}
case 7:{printf("2(2(2)+2+2(0))");break;}
case 8:{printf("2(2(2+2(0)))");break;}
case 9:{printf("2(2(2+2(0))+2(0))");break;}
case 10:{printf("2(2(2+2(0))+2)");break;}
case 11:{printf("2(2(2+2(0))+2+2(0))");break;}
case 12:{printf("2(2(2+2(0))+2(2))");break;}
case 13:{printf("2(2(2+2(0))+2(2)+2(0))");break;}
case 14:{printf("2(2(2+2(0))+2(2)+2)");}
}
}
void bijiao()
{
int i,t;
while(n!=0)
{
t=1;
i=0;
while(n>=t*2) {
t=t*2; ++i;
}
n=n-t;
print(i);
if(n!=0) printf("+");
}
}
int main()
{
scanf("%d",&n);
bijiao();
return 0;
}
