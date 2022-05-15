#include <iostream>
using namespace std;

class puzzle{
    
    protected:
        int start[3][3];
        int goal[3][3];
        int f=0;
        int g=0;
        
    public:
        void input(){
            cout<<"\nEnter the start state of matrix:-\n";
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cin>>start[i][j];
                }
            }
             cout<<"\nEnter the goal state of matrix:-\n";
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cin>>goal[i][j];
                }
            }
            display();
            shuffle();

            
        }
        int calh(int start1[3][3]){
            int h=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(start1[i][j]!=goal[i][j] && start1[i][j]!=0){
                        h++;
                    }
                }
            }
            return h;

        }
        void display(){
            cout<<"\n";
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    cout<<start[i][j]<<" ";
                }
                cout<<"\n";
            }
            f=g+calh(start);
            cout<<"\nh: "<<calh(start)<<" g: "<<g<<" f: "<<f;
            cout<<"\n";
        }
        void find(int &x,int &y){
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(start[i][j]==0){
                        x=i;
                        y=j;
                        break;
                    }
                    else{continue;}
                }
            }
        }
        int findmin(int q[4]){
            int temp=q[0];
            for(int i=0;i<4;i++){
                if(q[i]<temp && q[i]!=-1){
                    temp=q[i];
                }
            }
            return temp;
        }
        int move(int a,int b,int x,int y){
            int h1=0;
            int temp[3][3]={};
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    temp[i][j]=start[i][j];
                }
            }
            if((x>=0 && x<3)&& (y>=0 && y<3)){
                int t;
                t=temp[a][b];
                temp[a][b]=temp[x][y];
                temp[x][y]=t;
                h1=calh(temp);
                return h1;
            }
            else{
                return 1000;
            }
        }
        void swap(int temp[3][3],int a,int b,int x,int y){
            int t;
            t=temp[a][b];
            temp[a][b]=temp[x][y];
            temp[x][y]=t;
        }
        void shuffle(){
            int h=calh(start);
            do{
                int x,y,a,b,h1,h2,h3,h4;
                int min=0;
                find(a,b);
                h1=move(a,b,a-1,b);
                h2=move(a,b,a,b-1);
                h3=move(a,b,a+1,b);
                h4=move(a,b,a,b+1);
                int min1[4]={h1,h2,h3,h4};
                min=findmin(min1);
                if(min==min1[0]){
                    x=a-1;
                    y=b;
                }
                else if(min==min1[1]){
                    x=a;y=b-1;
                }
                else if(min==min1[2]){
                    x=a+1;y=b;
                }
                else{
                    x=a;y=b+1;
                }
                swap(start,a,b,x,y);
                g++;
                h=min;
                cout<<"  *"<<endl;
                cout<<"  *"<<endl;
                cout<<"*****"<<endl;
                cout<<" ***"<<endl;
                cout<<"  *"<<endl;
                display();

            }while(h!=0);
            cout<<"\nGoal state reached"<<endl;
        }
    
};
int main(){
    puzzle p;
    p.input();
    return 0;
}
