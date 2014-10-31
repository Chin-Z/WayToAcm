#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define MAX 300
using namespace std;
const char weekdays[10][20] = {"","Monday.","Tuesday.","Wednesday.","Thursday.","Friday.","Saturday.","Sunday."};
 
struct Complex{
    int effect;
    int weekday;
    int from,person;
    bool opt;
    Complex() {
        weekday = 0;
        effect = 0;
    }
}info[MAX];
 
int points,lies,sens;
char src[MAX][50];
char temp[MAX];
 
inline void Work(char *s,int pos);
inline void GetString(char *&s,char *aim);
inline bool Check(int guilty,int week);
inline bool Lie(Complex information,int guilty);
 
int main()
{
    cin >> points >> lies >> sens;
    for(int i = 1;i <= points; ++i)
        scanf("%s",src[i]);
    getchar();
    for(int i = 1;i <= sens; ++i) {
        fgets(temp,1000,stdin);
        Work(temp,i);
    }
    bool found = false;
    int ans = -1;
    for(int i = 1;i <= points; ++i) {
        bool temp = false;
        for(int j = 1;j <= 7; ++j) {
            if(Check(i,j))
                temp = true;
        }
        if(temp && !found)
            ans = i,found = true;
        else if(temp) {
            printf("Cannot Determine");
            return 0; 
        }
    }
    if(ans == -1)   printf("Impossible");
    else    printf("%s",src[ans]);
    return 0;
}
 
inline void Work(char *s,int pos)
{
    char temp[MAX];
    GetString(s,temp);
    temp[strlen(temp) - 1] = '\0';
    for(int i = 1;i <= points; ++i)
        if(!strcmp(temp,src[i]))
            info[pos].from = i;
    GetString(s,temp);
    if(!strcmp(temp,"Today")) {
        info[pos].effect = 1;
        GetString(s,temp);
        GetString(s,temp);
        for(int i = 1;i <= 7; ++i)
            if(!strcmp(temp,weekdays[i]))
                info[pos].weekday = i;
        if(*s != '\0' && *s != '\n')    info[pos].effect = 0;
    }
    else if(!strcmp(temp,"I")) {
        info[pos].effect = 2;
        info[pos].person = info[pos].from;
        GetString(s,temp);
        if(!strcmp(temp,"is")) {
            int p = 0;
            for(int i = 1;i <= points; ++i) 
                if(!strcmp("I",src[i]))
                    p = i;
            info[pos].person = p;
        }
        GetString(s,temp);
        if(!strcmp(temp,"not"))
            info[pos].opt = false,GetString(s,temp);
        else if(!strcmp(temp,"guilty."))
            info[pos].opt = true;
        else    info[pos].effect = 0;
        if(*s != '\0' && *s != '\n')    info[pos].effect = 0;
    }
    else {
        int p = 0;
        for(int i = 1;i <= points; ++i)
            if(!strcmp(temp,src[i]))
                p = i;
        if(p) {
            info[pos].effect = 2;
            info[pos].person = p;
            GetString(s,temp);
            GetString(s,temp);
            if(!strcmp(temp,"not"))
            info[pos].opt = false,GetString(s,temp);
            else if(!strcmp(temp,"guilty."))
                info[pos].opt = true;
            else    info[pos].effect = 0;
            if(*s != '\0' && *s != '\n')    info[pos].effect = 0;
        }
    }
}
 
inline void GetString(char *&s,char *aim)
{
    sscanf(s,"%s",aim);
    s += strlen(aim) + 1;
}
 
inline bool Check(int guilty,int week)
{
    static int status[MAX];
    memset(status,-1,sizeof(status));
    for(int i = 1;i <= sens; ++i) {
        if(info[i].effect == 1) {
            if(info[i].weekday != week) {
                if(status[info[i].from] == 1)
                    return false;
                else    status[info[i].from] = 0;
            }
            else {
                if(status[info[i].from] == 0)
                    return false;
                else    status[info[i].from] = 1;
            }
        }
        else if(info[i].effect == 2) {
            if(!Lie(info[i],guilty)) {
                if(status[info[i].from] == 1)
                    return false;
                else    status[info[i].from] = 0;               
            }
            else {
                if(status[info[i].from] == 0)
                    return false;
                else    status[info[i].from] = 1;
            }
        }
    }
    int cnt = 0;
    for(int i = 1;i <= points; ++i)
        if(!status[i])  cnt++;
    if(cnt > lies)   return false;
    for(int i = 1;i <= points; ++i)
        if(status[i] == -1) cnt++;
    if(cnt < lies)   return false;
    return true;
}
 
inline bool Lie(Complex information,int guilty)
{
    if(information.opt) {
        if(information.person != guilty)    return false;
        else    return true;
    }
    else {
        if(information.person == guilty)    return false;
        else    return true;
    }
}
