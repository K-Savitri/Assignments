#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

//return only the gradient dE/dw

float gradientw1(float x1, float x2, float y, float w1, float w2)
{
    float doh1 = -2*(y - (w1*x1 + w2*x2))*x1;
    return doh1;
};

float gradientw2(float x1, float x2, float y, float w1, float w2)
{
    float doh2 = -2*(y - (w1*x1 + w2*x2))*x2;
    return doh2;
};
float updatew1(float w1, float arr[])
{
       float ld =0.1;
    float sum1;
     for(int i=0; i<4; i++)
    {
        sum1+=arr[i];
    }
    float avgGrad1 = sum1/4;
    return w1 -(ld*(avgGrad1));
}
float updatew2(float w2, float arr[])
{
       float ld =0.1;
        float sum2;
    for(int i=0; i<4; i++)
    {
        sum2+=arr[i];
    }
        float avgGrad2 = sum2/4;
    return w2 -(ld*(avgGrad2));
}
int main()
{
    int arr[4][3] ={{0,1,1},{2,1,9},{1,0,1},{-2,1,7}};
    int w1 = 4;
    int w2 = 3;
 
    float list1[4];
    float list2[4];

    int epoch;
    cout<<"Enter no of epochs :";
    cin>>epoch;

    for(int i=0; i<epoch;i++){
    for (int i = 0; i < 4; i++) {
        int k=0;

            int x1 = arr[i][k];
            int x2 = arr[i][k+1];
            int y = arr[i][k+2];
    //   cout << x1<<x2<<y<<endl;

    // int grad1= gradientw1( x1,  x2,  y,  w1,  w2);
    list1[i] = gradientw1( x1,  x2,  y,  w1,  w2);
    list2[i] = gradientw2( x1,  x2,  y,  w1,  w2);
    
    // int grad2= gradientw2( x1,  x2,  y,  w1,  w2);   
        }
        w1 = updatew1(w1,list1);
        w2 = updatew2(w2, list2);

       cout<<"This is epoch no "<<i+1<<" w1 is "<< w1<<" ---- w2 is "<<w2<<endl;

}      
}
    
    




