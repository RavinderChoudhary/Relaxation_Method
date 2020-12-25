#include<bits/stdc++.h>
#include <vector>
#include <iostream> 
#define vector vector
using namespace std;
int main(){
    std::vector<vector<float> > arr{
        {6,-3,1,11},
        {1,-7,1,10},
        {2,1,-8,-15}
    };
    
   int count = 1;
   float rx=arr[0][3],ry=arr[1][3],rz=arr[2][3];
   cout<<setw(28)<<"Rx"<<setw(20)<<"Ry"<<setw(20)<<"Rz"<<endl;
   cout<<"------------------------------------------------------------------------------------"<<endl;
   cout<<count<<"."<<setw(28)<<rx<<setw(20)<<ry<<setw(20)<<rz<<endl;
   count++;
 
   float x=0,y=0,z=0;
   while(true){
       
       float terx = 10000 * rx;
       float tery = 10000 * ry;
       float terz = 10000 * rz;
       
       float mx = max({abs(rx),abs(ry),abs(rz)});
       
       if(abs(rx) == mx){
          x += float(rx/arr[0][0]);
          float f = rx;
          rx = arr[0][3] - arr[0][0] * x - arr[0][1] * y - arr[0][2] * z;
          ry = arr[1][3] - arr[1][0] * x - arr[1][1] * y - arr[1][2] * z;
          rz = arr[2][3] - arr[2][0] * x - arr[2][1] * y - arr[2][2] * z;
          cout<<left<<count<<". dx = "<<setw(20)<<float(f/arr[0][0]);
       }
       else if(abs(ry) == mx){
          y += float(ry/arr[1][1]);
          float f = ry;
          rx = arr[0][3] - arr[0][0] * x - arr[0][1] * y - arr[0][2] * z;
          ry = arr[1][3] - arr[1][0] * x - arr[1][1] * y - arr[1][2] * z;
          rz = arr[2][3] - arr[2][0] * x - arr[2][1] * y - arr[2][2] * z;
          cout<<left<<count<<". dy = "<<setw(20)<<float(f/arr[1][1]);
       }
       else{
          z += float(rz/arr[2][2]);
          float f = rz;
          rx = arr[0][3] - arr[0][0] * x - arr[0][1] * y - arr[0][2] * z;
          ry = arr[1][3] - arr[1][0] * x - arr[1][1] * y - arr[1][2] * z;
          rz = arr[2][3] - arr[2][0] * x - arr[2][1] * y - arr[2][2] * z;
          cout<<left<<count<<". dz = "<<setw(20)<<float(f/arr[2][2]);
       }
       cout<<setw(20)<<rx<<setw(20)<<ry<<setw(20)<<rz<<endl;
       if(abs(terx) < 1.0 && abs(tery) < 1.0 && abs(terz) < 1.0)
         break;
       count++;
   }
   cout<<"x = "<<x<<" , y = "<<y<<" z = "<<z;
}