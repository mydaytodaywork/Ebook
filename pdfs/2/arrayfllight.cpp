#include<iostream>
#include<cstdlib>
using namespace std;
int flight[1000][2];
int count=1;
void createflight(){
	int fuel=0;
	fuel=1+ rand()%25;
	flight[count][1]=count;
	flight[count][2]==fuel;
	count++;
}
int main(){
	int nofe;
	nofe=1+ rand()%10;
	cout<<nofe;
	for(int i=0;i<nofe;i++){
		createflight();
	}
	for(int i=1;i<count;i++){
		cout<<flight[i][1]<<"\t"<<flight[i][2]<<endl;
	}
	return 0;
}
