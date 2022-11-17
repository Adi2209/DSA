//Daily Challenge for 17 Nov 2022

class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        //area of 1st + 2nd rect.
        int area = (abs(ax1-ax2)*abs(ay1-ay2))+(abs(bx1-bx2)*abs(by1-by2));
         

         int overX1 = max(ax1,bx1);   
         int overY1 = max(ay1,by1);   
         int overX2 = min(ax2,bx2);   
         int overY2 = min(ay2,by2);   
         //if the rectanagles are overlapping then subtract the common area
          if(overX2>overX1 && overY2>overY1){
              area -= (abs(overX1-overX2)*abs(overY1-overY2));
          }

         return area;
    }
};
