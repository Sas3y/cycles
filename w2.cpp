#include <iomanip>
#include <vector>
#include <list>
#include <deque> //for future in case I forget
#include <iostream>
#include <algorithm> //sort

#define maxbreak 10 //for limited runtime - needs fixing for sure

using namespace std;

/*TODO:
 Sort by connections for major performance boost
 -Fix maxbreak
 
 
 
 And much more! :)
*/


//MAIN PROBLEM - DELETING NOT FULLY USED GRAPH AND RIP
//POSSIBLE SOLUTIONS - CHECK BOTH ENDS OF VECTOR AND THEN DELETE
// _OR_ 
//SORT 2 EDGED VECTORS AND CONSTRUCT 1X TO ALL 1Y'S TO XY (X<Y) (REALLY INTERFERES IMPLEMENTING TODO(1) - can be sorted at the start and replaces by order)

int main(){
	
	//used vector-to construct a list of arrays(maybe should use list? -prob much slower)
	//second vector-to construct the graphs themselves(look into possibility of list - might be faster to connect)
	//couldve used char instead of int, but shouldnt impact performance for simplicity
	//gr for GRaphs, but should be CYcles - this stores basically everything in itself, apart from completed
	vector<vector<int> > gr;
	//should contain list of cycles (list because why not for now) //vector bcs cy[i] doesnt work
	vector<vector<int> > cy;
	//temporary graph
	vector<int> tgr;
	
	
	//---input---
	//needs improvement for sure
	int edgesAmount;
	char node1,node2;//used temporary for input purpose
	cin>>edgesAmount;
	for(int i=0; i<edgesAmount;i++){
		cin>>node1>>node2;//inputs 2 nodes (connected)
		gr.push_back({int(node1),int(node2)}); //connects those nodes
	}
	
	vector<vector<int>>::iterator it; //looked useful
	vector<vector<int>>::iterator itv; //more temporary iterator
	vector<int>::iterator itsp1; //SPecific
	vector<int>::iterator itsp2;
	
	int endVector; //maybe should be pointer?
	int tempsize;
	
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
	//for(auto it=gr.begin();it!=gr.end();++it){//runs through whole (gr.end() changes)
	
	for(int h=0;h!=gr.size();h++){ //h because didnt want to confuse with j and already did i :|
		
		
		//sort (needs to sort by First number)
		for (int i = 0; i < gr.size(); i++) //reorders 2x1 to 1x2
		{
			if(gr[i][0]>gr[i][size(gr[i])-1]){
				swap(gr[i][0],gr[i][size(gr[i])-1]);
			}    
		}
		sort(gr.begin(), gr.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
		//gpt help ^ //sorts by the first element
		
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
		
		for(int i=h+1;i<tempsize;i++){ //why maxbreak? - needs fixing later (to certain amount) //maybe use size(gr) ? //size(gr) changes
			
			printf("gr[h][0] = %i\n",gr[h][0]);//TESTS
			printf("gr[i][0] = %i\n",gr[i][0]);
			
			
			if(gr[h][0]!=gr[i][0]){//if h's end its gg
				//Needs to delete the element just cycled
				//maybe it should be 0 instead of h
				//itv = gr.begin();
				//gr.erase(itv); //seems to fuck up main for
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
				
				
				//prints out tgr for TESTS
				for(int j:tgr){
					cout<<j<<' ';
				}
				cout<<endl;
				
				//tgr.insert(tgr.end(), gr[i].begin, gr[i].end);
				
				//Checks for full cycle
				if(tgr[0]==tgr[size(tgr)-1]){
					cout<<"\nCYCLE "<<endl;
					
					cy.push_back(tgr);
					
				}else{
					
					gr.push_back(tgr);//adds vector to main vector
					
				}

				tgr.clear();
				
				/*
				gr[endVector].insert(gr[endVector].begin(), gr[h].rbegin(), gr[h].rend());//inserts into main vector "ba"
				gr[endVector].insert(gr[endVector].end(), gr[i].begin, gr[i].end);//so it SHOULD add the "ac" (without a), to the existing inserted vector
				*/
				//itv = gr.end();
				
				
				
				/*used insert instead of this mess
				for(int itd=gr[i].rbegin();itd!=gr[i].rend();++itd){//reverse begin to reverse end- reads
					
					cout<<"Test: "<<itd<<endl;//TESTS
					
					gr.insert();
				}
				*/
				
				
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
		cout<<"\nCycle list:\n";
        for (int j = 0; j < cy[i].size(); j++)
        {
            cout << cy[i][j] << " " << char(cy[i][j]) << " - ";
        }    
        cout << endl;
    }
	
	
	return 0;
}