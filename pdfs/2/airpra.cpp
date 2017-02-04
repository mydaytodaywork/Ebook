#include <iostream>
#include<cstdlib>
using namespace std;
int fno=1;
int lsize=0;
int dsize=0;
void operation();
class cqueue
{
	public :
		int dltc;
		int *flight ;
		int *fuel;
		int front, rear ;
		int MAX;
		cqueue( int maxsize = 2000 ) ;
		void addflight ( int item ) ;
		int delflight( ) ;
		void daddfuel(int item);
		int delfuel();
		void ldisplay( ) ;
		void ddisplay( ) ;
		void addfuel();
} ;
cqueue :: cqueue( int maxsize )
{
	MAX = maxsize ;
	flight = new int [ MAX ];
	fuel=new int [MAX];
	front = rear = -1 ;
	for ( int i = 0 ; i < MAX ; i++ ){
		flight[i] = 0 ;
		fuel[i]=0;
	}
}
void cqueue :: addflight ( int item )
{
	if ( ( rear + 1 ) % MAX == front )
	{
		cout << "\nQueue is full" ;
		return ;
	}
	rear = ( rear + 1 ) % MAX;
	flight[rear] = item ;
	if ( front == -1 )
		front = 0 ;
	lsize+=1;
}
void cqueue :: addfuel ()
{
	int fu=1+rand()%25;
	if ( ( rear + 1 ) % MAX == front )
	{
		cout << "\nQueue is full" ;
		return ;
	}
	rear = ( rear + 1 ) % MAX;
	fuel[rear] = fu ;
	if ( front == -1 )
		front = 0 ;
}
void cqueue :: daddfuel (int item)
{
	if ( ( rear + 1 ) % MAX == front )
	{
		cout << "\nQueue is full" ;
		return ;
	}
	rear = ( rear + 1 ) % MAX;
	fuel[rear] = item ;
	if ( front == -1 )
		front = 0 ;
}
int cqueue :: delflight( )
{
	int data ;
	if ( front == -1 )
	{
		cout << "\nQueue is empty" ;
		return NULL ;
	}
 	
	data = flight[front] ;
	flight[front] = 0 ;
	if ( front == rear )
	{
		front = -1 ;
		rear = -1 ;
	}
	else
		front = ( front + 1 ) % MAX;
	lsize-=1;
	dltc++;
	return data ;
}
int cqueue :: delfuel( )
{
	int data ;
	if ( front == -1 )
	{
		cout << "\nQueue is empty" ;
		return NULL ;
	}
 	
	data = flight[front] ;
	flight[front] = 0 ;
	fuel[front]=0;
	if ( front == rear )
	{
		front = -1 ;
		rear = -1 ;
	}
	else
		front = ( front + 1 ) % MAX;
	return data ;
}
/*void cqueue::ldisplay( )
{
	cout<<endl ;
	for (int i=0;i<lsize;i++ )
		cout << flight[i] << "\t"<<fuel[i]<<endl;
}
void cqueue::ddisplay( )
{
	cout<<endl ;
	for (int i=0;i<dsize;i++ )
		cout << flight[i] << "\t"<<fuel[i] ;
	cout << endl ;
}*/
cqueue lflight;
cqueue lfuel;
cqueue dflight;
cqueue dfuel;
int main(){
	for(int k=0;k<20;k++){
		cout<<"======INTERVAL"<<k<<"======="<<endl;
	for(int i=0;i<10;i++){
		lflight.addflight(i);
		lfuel.addfuel();
	}
	operation();
	cout<<"===========LANDING FLIGTS========"<<endl;
		for(int i=lflight.dltc;i<10;i++){
		cout<<lflight.flight[i]<<"\t"<<lfuel.fuel[i]<<endl;
	}
	cout<<"===========DEPARTING FLIGHTS======"<<endl;
		for(int i=dflight.dltc;i<dflight.dltc+6;i++){
		cout<<dflight.flight[i]<<"\t"<<endl;
	}}
	return 0;
}

void operation(){
	if(lsize==0){
		cout<<"No flights in air";
	}
	if(dsize==0){
		if(lsize<=6){
			for(int i=0;i<lsize;i++){
				int fn=lflight.delflight();
				int fu=lfuel.delfuel();
				dflight.addflight(fn);
				dfuel.daddfuel(fu);
			}
		}
		else{
			for(int i=0;i<=6;i++){
				int fn=lflight.delflight();
				int fu=lfuel.delfuel();
				dflight.addflight(fn);
				dfuel.daddfuel(fu);
			}
		}		
	}
	else if(dsize>0 && dsize<6){
		int no=2;
		//no=1+ rand()%10;
		for(int i=0;i<no;i++){
			dflight.delflight();
			dfuel.delfuel();
		}
		int entr=6-dsize-1;
		for(int i=0;i<entr;i++){
				int fn=lflight.delflight();
				int fu=lfuel.delfuel();
				dflight.addflight(fn);
				dfuel.daddfuel(fu);
		}	
	}else if(dsize==6){
		for(int i=0;i<5;i++){
			dflight.delflight();
			dfuel.delfuel();
		}
	}
}
