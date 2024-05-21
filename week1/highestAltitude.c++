#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int size=gain.size();
        int difference[size+1];
        int adjusteddifference[size+1];
        int i=0;
        int highest=0;
        for(i;i<size+1;i++){
            if(i==0)
                difference[i]=0;
            else{
                difference[i]=difference[i-1]-gain[i-1];
            }
            adjusteddifference[i]=-difference[i];
            if(adjusteddifference[i]>=highest){
                highest=adjusteddifference[i];
            }
            
        }
        
        return highest;
    }
};