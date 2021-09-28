#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string toTime(int a){
    string s="";
    if(a/60<10) s+='0';
    s+=to_string(a/60);
    s+=':';
    if(a%60<10) s+='0';
    s+=to_string(a%60);
    return s;
}

int toMinute(string s){return stoi(s.substr(0))*60+stoi(s.substr(3));}

string solution(int n, int t, int m, vector<string> timetable) {
    vector<int> p(timetable.size());
    for(int i=0;i<p.size();i++)
        p[i]=toMinute(timetable[i]);
    sort(p.begin(),p.end());
    
    int last=0,cutLine,isSeat;
    for(int i=0;i<n;i++){
        cutLine=540+i*t;
        isSeat=m;
        while(isSeat&&last!=p.size()){
            if(p[last]>cutLine) break;
            last++;
            isSeat--;
        }
    }
    if(isSeat)  return toTime(cutLine);
    if(m==1)    return toTime(p[last-1]-1);
    if(p[last-2]==p[last-1])    return toTime(p[last-2]-1);
    else    return toTime(p[last-2]);
}