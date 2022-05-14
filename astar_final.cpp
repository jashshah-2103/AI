/*Problem Statement:-Implement A star Algorithm for any game search problem.*/

#include <iostream>
using namespace std;

class puzzle
{
protected:
	int start[3][3];
	int goal[3][3];
	int g=0,f=0;
public:

	void input()
	{
		cout<<"\nEnter the start state matrix"<<endl;
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				cin>>start[i][j];
			}
		}
		cout<<"\nEnter the goal state matrix"<<endl;
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				cin>>goal[i][j];
			}
		}
	   display();
	   shuffle();
	}

	int cal_h(int start1[3][3])
	{
		int h=0;
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
                if (start1[i][j] != goal[i][j] and start1[i][j] != 0)
                {
                	h++;
                }
			}
		}
		return h;
	}

	void display()
	{
		cout<<"\n";
		for (int i=0;i<3;i++)
		{
			cout<<"\n";
			for (int j=0;j<3;j++)
			{
				cout<<start[i][j]<<" ";
			}
		}
		f=g+cal_h(start);
		cout<<"\n";
		cout<<"h: "<<cal_h(start)<<" g:"<<g<<" f:"<<f<<endl;

	}

	void find(int &x, int &y)
	{
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
                if (start[i][j] == 0)
                {
                	x=i;y=j;
                	break;
                }
                else
                {
                	continue;
                }
			}
		}
	}

	int minfind(int q[4])
	{
		int temp=q[0];
		for (int i=0;i<4;i++)
		{
			if (q[i]<temp and q[i]!=-1)
			{
				temp=q[i];
			}
		}
		return temp;
	}

	int move(int a,int b,int x,int y)
	{
		int h1=0;
		int temp[3][3]={};
		for (int i=0;i<3;i++)
		{
			for (int j=0;j<3;j++)
			{
				temp[i][j]=start[i][j];
			}
		}
		if ((x>=0 && x<3) && (y>=0 && y<3))
		{
			int t;
		t=temp[a][b];
		temp[a][b]=temp[x][y];
		temp[x][y]=t;
			h1=cal_h(temp);
			return h1;
		}
		else
		{
			return 1000;
		}
	}
	void swap(int temp[3][3],int a, int b,int x,int y)
	{
		int t;
		t=temp[a][b];
		temp[a][b]=temp[x][y];
		temp[x][y]=t;

	}
	void shuffle()
	{
		int h=cal_h(start);

		do
        {
		int x,y;
		int min=0;
		int a,b,h1,h2,h3,h4;
		find(a,b);

		h1=move(a,b,a-1,b);
		h2=move(a,b,a,b-1);
		h3=move(a,b,a+1,b);
		h4=move(a,b,a,b+1);

		int min1[4]={h1,h2,h3,h4};
		min=minfind(min1);
		if (min==min1[0])
		{
			x=a-1;
			y=b;
		}
		else if (min==min1[1])
		{
			x=a;
			y=b-1;
		}
		else if (min==min1[2])
		{
			x=a+1;
			y=b;
		}
		else if (min==min1[3])
		{
			x=a;
			y=b+1;
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
int main() {
	puzzle p;
	p.input();
	return 0;
}
