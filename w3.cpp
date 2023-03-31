#include <iomanip>
#include <vector>
//#include <list>
//#include <deque> //unneeded but maybe for future
#include <iostream>
#include <algorithm> //sort


using namespace std;

/*TODO:
 -Sort by connections for major performance boost
 -Fix maxbreak
 
 Sort by connections in ascending order (for supposed time reduction) and change them accordingly (keep the list to reverse)
 Used a lot of size functions, but could try to record them sometimes (it is constant complexity though)
 -Remove xAyzAx cases, where A shouldnt repeat in a cycle
 xABx and xBAx or even xABx appears in final cy (needs fix!)
 
 Maybe look into qsort instead of sort
 
 And much more! :)
*/


int main(){
	
	//used vector-to construct a list of arrays(maybe should use list? -prob much slower)
	//second vector-to construct the graphs themselves(look into possibility of list - might be faster to connect)
	//couldve used char instead of int, but shouldnt impact performance for simplicity
	//gr for GRaphs - this stores basically everything in itself, apart from completed
	vector<vector<int> > gr;
	//should contain list of cycles (list because why not for now) //vector bcs cy[i] doesnt work
	vector<vector<int> > cy;
	//temporary graph, for easier insertion (could be removed for time, but kept for simplicity)
	vector<int> tgr;
	
	
	//input
	//needs improvement for sure
	int edgesAmount;
	char node1,node2;//used temporary for input purpose
	cin>>edgesAmount;
	for(int i=0; i<edgesAmount;i++){
		cin>>node1>>node2;//inputs 2 nodes (connected)
		gr.push_back({int(node1),int(node2)}); //connects those nodes
	}
	
	
	int tempsize;
	bool valid=1;
	
	//output test
	for (int i = 0; i < gr.size(); i++)
    {
        for (int j = 0; j < gr[i].size(); j++)
        {
            cout << gr[i][j] << " ";
        }    
        cout << endl;
    }
	printf("\nCycle Begins:\n");
	
	//main for or ---processing of data---
	for(int h=0;h!=gr.size();h++){ //h because didnt want to confuse with j and already did i :|
		
		
		//sort (needs to sort by First number)
		for (int i = 0; i < gr.size(); i++) //reorders 2xy1 to 1xx2
		{
			if(gr[i][0]>gr[i][size(gr[i])-1]){
				//swap(gr[i][0],gr[i][size(gr[i])-1]);
				reverse(gr[i].begin(), gr[i].end());
			}    
		}
		//with gpt help //sorts by the first element
		sort(gr.begin(), gr.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
		
		//output test
		for (int i = 0; i < gr.size(); i++)
		{
			for (int j = 0; j < gr[i].size(); j++)
			{
				cout << gr[i][j] << " ";
			}    
			cout << endl;
		}
		
		
		printf("\nT1 size(gr) = %i\n\n", size(gr));
		
		tempsize=size(gr);//tempsize so it doesnt check with newly added
		
		for(int i=h+1;i<tempsize;i++){ //size(gr) changes so used tempsize
			
			printf("gr[h][0] = %i\n",gr[h][0]);//TESTS
			printf("gr[i][0] = %i\n",gr[i][0]);
			
			
			if(gr[h][0]!=gr[i][0]){//if h's end its gg
				//Needs to delete the element just cycled
				//maybe it should be 0 instead of h
				//gr.erase(0); //seems to fuck up main for
				break;
			}
			else{ //connects a match
				printf("Match is found\n");
				//tgr.insert(tgr.begin(), gr[h].rbegin(), gr[h].rend());
				
				
				//mess to avoid insert problems
				for(int j=size(gr[i])-1;j>0;j--){
					
					cout<<"Test1: "<<gr[i][j]<<endl;//TESTS
					
					tgr.push_back(gr[i][j]);
				
				} 
				for(int j=0;j<size(gr[h]);j++){
					
					cout<<"Test2: "<<gr[h][j]<<endl;//TESTS
					
					tgr.push_back(gr[h][j]);
				
				} 
				
				//Shitty check for xAyzAx cases (needs improvement probably)
				//could add if size >5 but tiny graphs shouldnt impact too much
				valid=1;
				
				cout<<"T00";
				for(int j=1;j<tgr.size()-2;j++){
					cout<<"T01";
					for(int k=j+1;k<tgr.size()-1;k++){
						
						cout<<"TESTS 01: "<<tgr[j]<<" and "<<tgr[k]<<endl;
						
						if(tgr[j]==tgr[k]){
							cout<<"Bad cycle E01 !\n";
							valid=0; break;
							
						}
						
					}
				}
				
				
				//Checks for full cycle
				if(valid){
					if(tgr[0]==tgr[size(tgr)-1]){
						cout<<"\nCYCLE\n";
						
						cy.push_back(tgr);//adds vector to list of completed cycles
						
					}else{
						
						gr.push_back(tgr);//adds vector to main vector
						
					}
				}
				tgr.clear();
			}
		}
	}

	
	//output test
	cout<<"\nLast gr vectors:\n";
	for (int i = 0; i < gr.size(); i++)
    {
        for (int j = 0; j < gr[i].size(); j++)
        {
            cout << gr[i][j] << " ";
        }    
        cout << endl;
    }
	
	for (int i = 0; i < cy.size(); i++)
    {
		cout<<"\nCycle list ("<<i+1<<"):\n";
        for (int j = 0; j < cy[i].size(); j++)
        {
            cout << char(cy[i][j]) << "(" << cy[i][j] << ") - ";
        }    
        cout << endl;
    }
	
	
	return 0;
}