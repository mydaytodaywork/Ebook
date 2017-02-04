#include<iostream>
#include<list>
#include<cstdlib>
#include<ctime>
using namespace std;

int pnum=0;
int pc=0;
int fuel[10];
int arr[]={0,1,2,3,4,5,6,7,8,9};
int crash[10];
int siz=10;
class plane{
	public:	
			list<int> lndg;
			list<int> dept;
			
			int planeno(){
				if(pnum>=10)
					return 0;
				else
					return pnum++;
			}
		
			void arrival(){
					int number=planeno();
					srand(time(0));
					fuel[number] = (rand()%25)+1;
					lndg.push_back(planeno());
					if(dept.size()<6){
						dept.push_back(lndg.front());
						lndg.pop_front();
					}
					for(int i=0;i<lndg.size();i++){
						fuel[i]--;
						if(fuel[i]<2 && dept.size()>=6){
							crash[pc++]=arr[i];
							cout<< arr[i] <<" "<<"crashed"<<endl;
							for(int j=i; j<siz;j++){
								arr[j]=arr[j+1];
								siz=siz-1;
							}
						}	
					}
				}
				
				void departure(){
					dept.pop_front();
				}
				
			void intervals(){
				for(int i=0;i<1000;i++){
					if(dept.size()<6){
						arrival();
					}else{
						departure();
					}
				}
			}
};
int main(){
	plane p;
	p.intervals();
	return 0;
}
