class Robot {
public:
    string dir ="East";
    vector<int> pos={0,0};
    int width;
    int height;
    int perimeter;

    Robot(int width, int height) {
        this->width=width;
        this->height=height;
        this->perimeter=((width-1)+(height-1))*2;
    }

    bool out_of_bounds(vector<int>& pos){
        int width=pos[0];
        int height=pos[1];
        if ((width<0) || (width>(this->width)-1) ||
            (height<0) || (height>(this->height)-1)){
                return true;
        }
        return false;
    }
    
    void step(int num) {
        int i=0;
        num=num%perimeter;
        if (num==0 && pos[0]==0 && pos[1]==0){
            dir="South";
        }
        while (i<num){
            int x=pos[0], y=pos[1];
            int leftover;
            if (dir=="East"){
                leftover=(width-1)-x;
                if (num<=leftover){
                    leftover=num;
                }
                else{
                    dir="North";
                }
                x=x+leftover;
            }
            else if (dir=="North"){
                leftover=(height-1)-y;
                if (num<=leftover){
                    leftover=num;
                }
                else{
                    dir="West";  
                }
                y=y+leftover;
            }
            else if (dir=="West"){
                leftover=x;
                if (num<=leftover){
                    leftover=num;
                }
                else{
                    dir="South";
                }
                x=x-leftover;
            }
            else{
                leftover=y;
                if (num<=leftover){
                    leftover=num;
                }
                else{
                    dir="East";
                }
                y=y-leftover;
            }
            pos={x,y};
            num-=leftover;
        }
    }
    
    vector<int> getPos() {
        return pos;
    }
    
    string getDir() {
        return dir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */