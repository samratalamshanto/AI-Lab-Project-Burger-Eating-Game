#include<bits/stdc++.h>
using namespace std;


int n;
int burger[100];
int dp[100];
int pos[100];

void initialize()
{
    for(int i=0; i<100; i++)
    {
        burger[i] = dp[i] = 0;
        pos[i] = -1;
    }
}

void countPos()
{
    int postSum = 0;
    dp[n-1] = burger[n-1];
    postSum = burger[n-1];
    pos[n-1] = n-1;

    for(int i= n-2; i>=0; i--)
    {
        dp[i] = max(dp[i+1],burger[i] + postSum - dp[i+1]);
        if((burger[i] + postSum - dp[i+1])>dp[i+1])
        {
            pos[i] = i;
        }
        else
        {
            pos[i] = pos[i+1];
        }

        postSum += burger[i];
    }

    for ( int i=0; i<n; i++){
        cout<<"Position "<<i+1<<" : "<< pos[i]+1<<endl;
    }
}

void showBox()
{

    for(int i=0; i<13; ++i)
        cout<<" ";

    for(int i=1; i<=5*n; ++i)
    {
        cout<<"_";
    }
    cout<<endl;
    cout<<"Box Number  |";
    for(int i=0; i<n; ++i)
    {
        printf("%4d|",i+1);
    }
    cout<<endl;
    //burger[0]=19;burger[1]=18;burger[2]=6;burger[3]=4;burger[4]=6;burger[5]=13;burger[6]=19;burger[7]=6;burger[8]=12;burger[9]=12;
    for(int i=0; i<12; ++i)
        cout<<" ";
    cout<<"|";
    for(int i=1; i<=5*n; ++i)
    {
        if(i%5==0)
            cout<<"|";
        else
            cout<<"_";
    }
    cout<<endl;

    cout<<"Burger Size |";
    for(int i=0; i<n; ++i)
    {
        printf("%4d|",burger[i]);
    }
    cout<<endl;
    for(int i=0; i<12; ++i) cout<<" ";
    cout<<"|";
    for(int i=1; i<=5*n; ++i)
    {
        if(i%5==0)
            cout<<"|";
        else
            cout<<"_";
    }
    cout<<endl;

}


void showResult(int &playerScore, int &aiScore)
{
    if(playerScore>aiScore)
    {
        cout<<"Player wins"<<endl;
    }
    else if(playerScore < aiScore)
    {
        cout<<"AI wins"<<endl;
    }
    else
    {
        cout<<"Match Draw"<<endl;
    }
    cout<<endl<<endl;
}


int main()
{
    while(1)
    {
label_1:
        initialize();
        cout<<"Enter the number of box filled with burgers : ";
        cin>>n;
        srand(time(NULL));
        int v1=rand()%50;
        for(int i=0; i<n; i++)
        {
            burger[i]=(rand()%501)%v1+1;
        }

        countPos();
        showBox();
        int playerScore = 0, aiScore = 0, nextOfAI = -1, index=-1;

        while(1)
        {
label_2:
            cout<<"Enter the index : ";
            cin>>index;
            if(index<1 || index>n)
            {
                cout<<"Index out of range"<<endl<<endl;
                showBox();
                goto label_2;
            }

            index = index -1;

            playerScore = playerScore + burger[index];
            burger[index] = 0;
            for(int i = nextOfAI+1; i<index; i++)
            {
                aiScore = aiScore + burger[i];
                burger[i] = 0;
            }

            cout<<"Player in : "<<index+1<<endl;
            cout<<"Player score : "<<playerScore<<endl;
            cout<<"AI score : "<<aiScore<<endl<<endl;

            nextOfAI = pos[index+1];
            //cout<<"next of AI : "<<nextOfAI<<endl;
            if(nextOfAI == -1)
            {
                //cout<<"Break works"<<endl;
                showResult(playerScore, aiScore);
                goto label_1;
            }

            aiScore = aiScore + burger[nextOfAI];
            burger[nextOfAI] = 0;

            for(int i = index+1; i<nextOfAI; i++)
            {
                playerScore = playerScore + burger[i];
                burger[i] = 0;
            }

            cout<<"AI in : "<<nextOfAI+1<<endl;
            cout<<"AI score : "<<aiScore<<endl;
            cout<<"Player score : "<<playerScore<<endl<<endl;

            if(nextOfAI>=n-1)
            {
                showResult(playerScore, aiScore);
/*
                if(playerScore>aiScore)
                {
                    cout<<"Player wins"<<endl;
                }
                else if(playerScore < aiScore)
                {
                    cout<<"AI wins"<<endl;
                }
                else
                {
                    cout<<"Match Draw"<<endl;
                }
                cout<<endl<<endl;
*/
                break;
            }
            cout<<endl;
            showBox();
        }


    }

    return 0;
}
