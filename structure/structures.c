#include <stdio.h> 


struct Yuyuhiei {
        int studnum;
        char name[10][20];
        char crsyr[10];
        float GWA;
};

    int main(){
    struct Yuyuhiei me;
    struct Yuyuhiei you;

    me.GWA = 10.21;
    you.studnum = 202234075; 
    

    printf("GWA and Student number: %f %d", me.GWA, you.studnum);
}