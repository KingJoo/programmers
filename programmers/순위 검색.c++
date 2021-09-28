/*
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> data[3][2][2][2];
    string lang,task,career,food,score,tmp;
    int a,b,c,d;
    for(string &t : info){
        istringstream iss(t);
        iss>>lang>>task>>career>>food>>score;
        //lang
        if(lang[0]=='c')    a=0;
        else if(lang[0]=='j')   a=1;
        else    a=2;
        //task
        if(task[0]=='b')    b=0;
        else    b=1;
        //career
        if(career[0]=='j')  c=0;
        else    c=1;
        //food
        if(food[0]=='c')    d=0;
        else    d=1;
        data[a][b][c][d].push_back(stoi(score));
    }
    int as,bs,cs,ds;
    for(string &q : query){
        istringstream iss(q);
        iss>>lang>>tmp>>task>>tmp>>career>>tmp>>food>>score;
        //lang
        if(lang[0]=='-'){as=0;a=2;}
        else if(lang[0]=='c')  as=a=0;
        else if(lang[0]=='j')  as=a=1;
        else    as=a=2;
        //task
        if(task[0]=='-'){bs=0;b=1;}
        else if(task[0]=='b')  bs=b=0;
        else    bs=b=1;
        //career
        if(career[0]=='-'){cs=0;c=1;}
        else if(career[0]=='j')  cs=c=0;
        else    cs=c=1;
        //food
        if(food[0]=='-'){ds=0;d=1;}
        else if(food[0]=='c')  ds=d=0;
        else    ds=d=1;
        int point = stoi(score);
        int cnt=0;
        for(int i=as;i<=a;i++)
            for(int j=bs;j<=b;j++)
                for(int k=cs;k<=c;k++)
                    for(int l=ds;l<=d;l++)
                        for(int z : data[i][j][k][l])
                            if(z>=point)    cnt++;
        answer.push_back(cnt);
    }
    return answer;
}*/
/*
테스트 1 〉	통과 (0.05ms, 3.98MB)
테스트 2 〉	통과 (0.04ms, 3.96MB)
테스트 3 〉	통과 (0.15ms, 3.97MB)
테스트 4 〉	통과 (0.94ms, 3.96MB)
테스트 5 〉	통과 (1.78ms, 3.96MB)
테스트 6 〉	통과 (0.88ms, 3.89MB)
테스트 7 〉	통과 (2.13ms, 4.41MB)
테스트 8 〉	통과 (3.32ms, 4.36MB)
테스트 9 〉	통과 (3.31ms, 4.35MB)
테스트 10 〉	통과 (3.32ms, 4.57MB)
테스트 11 〉	통과 (1.17ms, 4.11MB)
테스트 12 〉	통과 (0.84ms, 3.94MB)
테스트 13 〉	통과 (2.12ms, 4.35MB)
테스트 14 〉	통과 (1.77ms, 4MB)
테스트 15 〉	통과 (1.99ms, 3.98MB)
테스트 16 〉	통과 (1.07ms, 4.15MB)
테스트 17 〉	통과 (0.83ms, 3.91MB)
테스트 18 〉	통과 (1.94ms, 3.96MB)
효율성  테스트
테스트 1 〉	통과 (201.84ms, 43.4MB)
테스트 2 〉	통과 (195.95ms, 44.1MB)
테스트 3 〉	통과 (549.74ms, 43.1MB)
테스트 4 〉	통과 (591.92ms, 43.3MB)
*/

#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<int> data[3][2][2][2];
    int a,b,c,d,i;
    for(string &t : info){
        i=0;
        //lang
        if(t[i]=='c'){
            a=0;
            i+=4;
        }
        else if(t[i]=='j'){
            a=1;
            i+=5;
        }
        else{
            a=2;
            i+=7;
        }
        //task
        if(t[i]=='b'){
            b=0;
            i+=8;
        }
        else{
            b=1;
            i+=9;
        }
        //career
        if(t[i]=='j'){
            c=0;
            i+=7;
        }
        else{
            c=1;
            i+=7;
        }
        //food
        if(t[i]=='c'){
            d=0;
            i+=8;
        }
        else{
            d=1;
            i+=6;
        }
        data[a][b][c][d].push_back(stoi(t.substr(i)));
    }

    int as,bs,cs,ds;
    for(string &q : query){
        i=0;
        //lang
        if(q[i]=='-'){
            as=0;
            a=2;
            i+=6;
        }
        else if(q[i]=='c'){
            as=a=0;
            i+=8;
        }
        else if(q[i]=='j'){
            as=a=1;
            i+=9;
        }
        else{
            as=a=2;
            i+=11;
        }
        //task
        if(q[i]=='-'){
            bs=0;
            b=1;
            i+=6;
        }
        else if(q[i]=='b'){
            bs=b=0;
            i+=12;
        }
        else{
            bs=b=1;
            i+=13;
        }
        //career
        if(q[i]=='-'){
            cs=0;
            c=1;
            i+=6;
        }
        else if(q[i]=='j'){
            cs=c=0;
            i+=11;
        }
        else{
            cs=c=1;
            i+=11;
        }
        //food
        if(q[i]=='-'){
            ds=0;
            d=1;
            i+=2;
        }
        else if(q[i]=='c'){
            ds=d=0;
            i+=8;
        }
        else{
            ds=d=1;
            i+=6;
        }
        int score = stoi(q.substr(i));
        int cnt=0;
        for(int i=as;i<=a;i++){
            for(int j=bs;j<=b;j++){
                for(int k=cs;k<=c;k++){
                    for(int l=ds;l<=d;l++){
                        for(int z : data[i][j][k][l]){
                            if(z>=score)    cnt++;
                        }
                    }
                }
            }
        }
        answer.push_back(cnt);
    }

    return answer;
}