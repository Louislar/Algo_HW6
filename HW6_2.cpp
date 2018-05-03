#include<iostream>

using namespace std;

int main()
{
    while(1)
    {
        int bags=0;
        int input[6];
        for(int i=0;i<6;i++)
        {
            cin>>input[i];
        }

        //check for all 0's
        {
            int flag=1;
            for(int i=0;i<6;i++)
                if(input[i]!=0)
                    flag=0;
            if(flag) break;
        }

        // 6*6
        bags+=input[5];
        input[5]=0;

        //5*5
        bags+=input[4];
        while(input[0]>0&&input[4]>0)
        {
            int temp=input[0]/11;
            if(input[0]-temp>0)
            {
                input[0]-=temp;
                input[4]--;
            }
        }
        if(input[0]>0&&input[4]>0) input[0]=0;
        input[4]=0;

        //4*4
        bags+=input[3];
        while(input[1]>0 && input[3]>0)
        {
            int temp=input[1]/6;
            if(input[1]-temp>0)
            {
                input[1]-=temp;
                input[3]--;
            }
        }
        {
            int left=6-input[1];
            left*=4;
            left+=input[3]*20;
            input[0]-=left;
            if(input[0]<0) input[0]==0;
        }

        //3*3
        /************start from here*************/




    }
}
