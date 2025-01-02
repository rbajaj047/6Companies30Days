class Solution {
public:
    bool checkOverlap(int r, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //shift centre of circle to origin
        x1-=xCenter;
        y1-=yCenter;
        x2-=xCenter;
        y2-=yCenter;

        int x=((x1*x2)<=0)?0:min(x1*x1,x2*x2);
        int y=((y1*y2)<=0)?0:min(y1*y1,y2*y2);

        return (x+y<=(r*r));
    }
};