class Solution {
public:
    double angleClock(int hour, int minutes) {
        double h = (hour*30)%360 + (double)minutes/2;
        double m = minutes*6;
        double dif = min(abs(h-m), 360-abs(h-m));
        return dif;
    }
};
