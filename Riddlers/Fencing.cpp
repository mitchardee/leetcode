//Solution program for https://fivethirtyeight.com/features/en-garde-can-you-win-the-fencing-relay/

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

bool point(double d){
    return d >= ((double) rand())/RAND_MAX;
}

int main(int argc, char *argv[]){
    const int SIMS = argc > 1 ? atoi(argv[1]) : 1000;
    srand(time(0));

    double orders[6][3] = { {.25, .5, .75}, {.5, .25, .75},
     {.25, .75, .5}, {.5, .75, .25},
     {.75, .25, .5}, {.75, .5, .25}};

     int opp_score = 0, us_score = 0; 
     int wins[6] = {0, 0, 0, 0, 0, 0};

     for(int i=0; i < SIMS; i++){
         for(int scheme = 0; scheme < 6; scheme++){
            while(opp_score < 15 && us_score < 15){
                if(point(orders[scheme][0]))
                    us_score++;
                else opp_score++;
            }
            while(opp_score < 30 && us_score < 30){
                if(point(orders[scheme][1]))
                    us_score++;
                else opp_score++;
            }
            while(opp_score < 45 && us_score < 45){
                if(point(orders[scheme][2]))
                    us_score++;
                else opp_score++;
            }
            wins[scheme] += us_score == 45 ? 1 : 0;
            opp_score = 0;
            us_score = 0;
         }
     }
     for(int i = 0; i < 6; i++)
        cout<<wins[i]<<endl;
}