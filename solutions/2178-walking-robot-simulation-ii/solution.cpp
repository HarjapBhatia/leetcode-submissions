class Robot {
private:
    int h=0,w=0,x=0,y=0,cnt=0,p=0;
    string v[4] = {"East", "North", "West", "South"};
public:
    Robot(int width, int height) {
        h=height; w=width; p=2*(w+h-2);
    }
    
    void step(int num) {
        num %= p; // simplifyin the calc to least calculatns
        
        if(num==0 && x==0 && y==0) {cnt = 3; return;}
        
        while(num>0){
            if(cnt%4 == 0){
                int m = min(num, w-1-x); //e
                x += m; num -= m;
                if(num > 0) cnt++;
            }
            else if(cnt%4 == 1){
                int m = min(num, h-1-y); //n
                y += m; num -= m;
                if(num > 0) cnt++;
            }
            else if(cnt%4 == 2){
                int m = min(num, x); // w
                x -= m; num -= m;
                if(num > 0) cnt++;
            }
            else{
                int m = min(num, y); // s
                y -= m; num -= m;
                if(num > 0) cnt++; 
            }
        }
    }
    
    vector<int> getPos() {
        return {x,y};
    }
    
    string getDir() {
        return v[cnt%4];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
