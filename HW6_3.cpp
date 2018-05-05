#include<iostream>

using namespace std;

int choose(int input[], int n, int index, int t, int curSum
           , int output[], int outputLength, int& lock)
{
    if(curSum==t&&lock==0)
    {
        for(int i=0;i<outputLength;i++)
        {
            if(i!=0)
                cout<<" ";
            cout<<output[i];
        }
        cout<<endl;
        lock=1;
        return 0;
    }

    if(index<n)
    {
        //take
        output[outputLength]=input[index];
        outputLength++;
        choose(input, n, index+1, t, curSum+input[index]
               , output, outputLength, lock);

        //don't take
        output[outputLength]=0;
        outputLength--;
        choose(input, n, index+1, t, curSum
               , output, outputLength, lock);
    }
}

int main()
{
    int k=0;
    cin>>k;
    for(int y=0;y<k;y++)
    {
        int t=0;
        int n=0;
        cin>>t;
        cin>>n;
        int input[n]={0};
        for(int q=0;q<n;q++)
        {
            cin>>input[q];
        }

        int output[n]={0};
        int outputLength=0;
        int curSum=0;
        int lock=0;
        choose(input, n, 0, t, 0, output, outputLength, lock);
        if(lock==0)
        {
            cout<<"impossible"<<endl;
        }



    }

}
