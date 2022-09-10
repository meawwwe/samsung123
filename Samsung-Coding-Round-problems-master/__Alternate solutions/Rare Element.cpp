#include<iostream>
using namespace std ;
int N,C ;
int road[4][21][21] ;
int elem[4][2] ;
int mat[21][21] ;

struct Pair
{
    int first ;
    int second ;
};

Pair Make_pair(int x,int y)
{
        Pair res ;
        res.first = x;
        res.second = y ;
        return res ;
}

template<class T>
class Queue
{
    struct node
    {
        T item ;
        node* next ;
        node(T i)
        {
            item = i;
            next = NULL ;
        }
    };
    node *head ;
    node *tail ;
    int size;
public:
    Queue()
    {
        head = NULL ;
        tail = NULL ;
        size = 0 ;
    }

    void push(T item)
    {
        node* temp = tail ;
        tail = new node(item) ;
        if(head == NULL)
        {
            head = tail ;
        }
        else
        {
            temp->next = tail ;
        }
        size++ ;
    }
    T pop()
    {
        size-- ;
        T temp = head->item ;
        head = head->next ;
        if(head == NULL)
            tail == NULL ;
        return temp ;
    }
    bool empty()
    {
        return size==0 ;
    }
};

void bfs(int n, int x, int y)
{
    Queue<Pair> q ;
    Pair p ;
    p.first = x;
    p.second = y ;
    q.push(p) ;

    int a[] = {0,1,0,-1} ;
    int b[] = {1,0,-1,0} ;
    road[n][x][y] = 0 ;
    while(!q.empty())
    {
        p = q.pop() ;

        for(int i=0;i<4;i++)
        {
            int I = p.first + a[i] ;
            int J = p.second + b[i] ;

            if(I>=0 && J>=0 && I<N && J<N && mat[I][J]==1 && road[n][I][J]==-1)
            {
                road[n][I][J] = road[n][p.first][p.second] + 1 ;
                Pair t ;
                t.first = I;
                t.second = J ;
                q.push(t) ;
            }
        }
    }
}


int main()
{
    int T ;
    cin>>T ;
    while(T--)
    {
        cin>>N>>C;

        for(int i=0;i<C;i++)
        {
            cin>>elem[i][0]>>elem[i][1] ;
            elem[i][0]--;
            elem[i][1]-- ;
        }
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cin>>mat[i][j] ;
                for(int k=0;k<C;k++)
                    road[k][i][j] = -1 ;
            }
        }

        for(int i=0;i<C;i++)
        {
            bfs(i,elem[i][0],elem[i][1]) ;
        }

        int max_dist,t_sum,max_ans=-1 ;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                t_sum = 0 ;
                for(int k=0,m=0;k<C;k++)
                {
                    if(road[k][i][j]==-1)
                        break ;
                    t_sum += road[k][i][j] ;
                    m = max(m,road[k][i][j]) ;

                    if(k==C-1)
                    {
                        if(max_ans == -1)
                        {
                            max_ans =  t_sum ;
                            max_dist = m ;
                        }
                        else if(t_sum <max_ans)
                        {
                            max_ans = t_sum ;
                            max_dist = m ;
                        }
                    }
                }
            }
        }
        cout<<"#"<<max_dist<<endl ;
    }
}
