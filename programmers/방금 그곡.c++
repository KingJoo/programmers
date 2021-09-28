#include <string>
#include <vector>

using namespace std;

string convert(string s){
    string tmp="";
    for(int i=0;i<s.size();i++)
        if(s[i]!='#')   tmp+=s[i];
        else    tmp.back()=tolower(s[i-1]);
    return tmp;
}

string solution(string m, vector<string> musicinfos) {
    string answer = "(None)";
    m=convert(m);
    int postTime=0,idx;
    for(string &s : musicinfos){
        //playing time
        int time=stoi(s.substr(6))*60+stoi(s.substr(9))-stoi(s.substr(0))*60-stoi(s.substr(3))+1;
        //playing time < length of the music you want to find ===> skip
        if(time<m.size())   continue;
        //title
        string title="";
        idx=12;
        while(true){
            if(s[idx]==',')   break;
            title+=s[idx++];
        }
        //contents
        string music=convert(s.substr(++idx));
        int musicSize=music.size();
        for(int i=musicSize;i<time;i++)
            music+=music[i%musicSize];
        if(time<music.size())   music=music.substr(0,time);
        //search
        for(int i=0;i<=music.size()-m.size();i++){
            if(music.substr(i,m.size())==m){
                //long-played title
                if(postTime<time){
                    answer=title;
                    postTime=time;
                }
                break;
            }
        }
    }
    return answer;
}