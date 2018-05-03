#include<iostream>

using namespace std;

int n=0; // nodes
int m=0; // edges
int k=0; // outputs

class chainNode
{
public:
    chainNode(){
        next=0;
        data=0;
    }
    chainNode(int value, chainNode* n=0)
    {
        data=value;
        next=n;
    }
    int data;
    chainNode* next;
    int x;
    int y;
};

class array2d
{
public:
    array2d(int r, int c)
    {
        row=r;
        col=c;
    }
    int a[100][100];
    int col;
    int row;
};

int dTraversal(chainNode* graph[], int cur, int visited[], int nodeLatency[]
               , array2d edges, int endNode, int path[], int& pathLength, int& cost)
{
    if(cur==endNode)
    {
        int tempCost=0;
        for(int i=0;i<pathLength-1;i++)
        {
            tempCost+=nodeLatency[path[i]];
            tempCost+=edges.a[path[i]][path[i+1]];
            cout<<path[i]<<" ";
        }
        cout<<path[pathLength]<<" "<<cur<<" ";
        tempCost+=nodeLatency[path[pathLength]];
        tempCost+=edges.a[path[pathLength]][cur];
        tempCost+=nodeLatency[cur];
        cout<<cost<<endl;
        if(tempCost<cost) cost=tempCost;
        return 0;
    }

    chainNode* temp=graph[cur];
    while(temp!=0)
    {
        if(visited[temp->data]==0&&temp->data!=0){
        visited[temp->data]=1;
        path[pathLength]=cur;
        pathLength++;

        dTraversal(graph, temp->data, visited, nodeLatency, edges
                   , endNode, path, pathLength, cost);

        path[pathLength]=0;
        pathLength--;
        visited[temp->data]=0;

        }
        temp=temp->next;
    }
    return 0;
}

int main()
{
    cin>>n;
    cin>>m;
    cin>>k;
    n=n+1;

    //adjacency list, for traversal
    chainNode* graphList[n]={0};
    //adjacency matrix, for storing edge latency
    int graphMatrix[n][n];
    //node latency time, for storing node latency
    int nodeLatency[n];
    // output chainNode.x chainNode.y's edge's latency
    chainNode output[k];
    // same as graphMatrix
    array2d edges=array2d(n, n);


    for(int i=1;i<n;i++)
    {
        cin>>nodeLatency[i];
    }

    for(int i=0;i<m;i++)
    {
        int tempa;
        int tempb;
        int temp;
        cin>>tempa;
        cin>>tempb;
        cin>>temp;

        edges.row=n;
        edges.col=n;

        edges.a[tempa][tempb]=temp;
        edges.a[tempb][tempa]=temp;


        {
            if(graphList[tempa]==0)
            {
                graphList[tempa]=new chainNode(tempb, 0);
            }
            else{
            chainNode* temp=graphList[tempa];
            while(temp->next!=0) {temp=temp->next;}
            temp->next=new chainNode(tempb, 0);
            }
        }
        {
            if(graphList[tempb]==0)
            {
                graphList[tempb]=new chainNode(tempa, 0);
            }
            else{
            chainNode* temp=graphList[tempb];
            while(temp->next!=0) {temp=temp->next;}
            temp->next=new chainNode(tempa, 0);
            }
        }
    }

    //test
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<edges.a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;



    for(int i=0;i<k;i++)
    {
        int path[100]={0};
        int pathLength=0;
        int cost=100000;
        int startp=0;
        int endp=0;
        int visited[n]={0};
        cin>>startp;
        cin>>endp;
        dTraversal(graphList, startp, visited, nodeLatency, edges, endp
                   , path, pathLength, cost);
        cout<<cost<<endl;
    }


}
