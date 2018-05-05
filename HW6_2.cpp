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
        {
            int temp=input[4]*11;
            while(input[0]-1>0&&temp>0)
            {
                input[0]--;
                temp--;
            }
        }
        input[4]=0;

        //4*4
        bags+=input[3];
        {
            int temp=input[3]*5; // how many 2*2 empty block can fill in
            while(input[1]>0 && temp>0)
            {
                input[1]--;
                temp--;
            }

            temp=temp*4; // how many 1*1 empty block can fill in
            while(input[0]>0 && temp>0)
            {
                input[0]--;
                temp--;
            }
        }


        //3*3
        if(input[2]/4>0)
        {
            bags+=input[2]/4;
            input[2]-=(input[2]/4)*4;
        }
        if(input[2]==1)
        {
            bags++;
            int left=5;
            while(input[1]-1>=0 && left>0)
            {
                input[1]--;
                left--;
            }

            left=left*4+7;
            while(input[0]-1>=0 && left>0)
            {
                input[0]--;
                left--;
            }
        }
        else if(input[2]==2)
        {
            bags++;
            int left=3;
            while(input[1]-1>=0 && left>0)
            {
                input[1]--;
                left--;
            }

            left=left*4+6;
            while(input[0]-1>=0 && left>0)
            {
                input[0]--;
                left--;
            }
        }
        else if(input[2]==3)
        {
            bags++;
            int left=1;
            while(input[1]-1>=0 && left>0)
            {
                input[1]--;
                left--;
            }

            left=left*4+5;
            while(input[0]-1>=0 && left>0)
            {
                input[0]--;
                left--;
            }
        }

        //2*2
        if(input[1]/9>0)
        {
            bags+=input[1]/9;
            input[1]-=(input[1]/9)*9;
        }
        {
            int left=36-input[1]*4;
            while(input[0]>0 && left>0)
            {
                input[0]--;
                left--;
            }
        }

        //1*1
        if(input[0]/36>0)
        {
            bags+=input[0]/36;
            input[0]-=(input[0]/36)*36;
        }
        if(input[0]>0)
            bags++;

        cout<<bags<<endl;














    }// while end
}
