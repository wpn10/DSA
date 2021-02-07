#include<bits/stdc++.h>
using namespace std;
class player{
public:
    int x , y;
    int speed;
    void move(int xa, int ya){
    x+= xa + speed;
    y+= ya +speed;
}
//private:
};
class Log{
    void setlevel(int level){
        
    }
    void warn(const char* messege){
        
    }
};
int main(){
    player p1;
    p1.x = 5;
    p1.y = 3;
    int speed = 2;
    p1.move(1,2);
    cout<<p1.x<<" "<<p1.y;
    Log log;
    log.setlevel(loglevelwarning);
    log.warn ("pari");
    return 0;
}
