#include<iostream>
#include<queue>
#include<set>
#include<string>

using namespace std;
string goal = 123456780;

void printpuzzle(string s){
for(i = 0;i<9;i++)
{
	if(i == 0)
		cout<<" ";
	else
		cout<<s[i]<<endl;
	if( (i+1) % 3 == 0)
		cout<<endl;
}


}



void solve(string start){
	{

queue<string> q;
set<string> visited;
q.push(start);
visited.insert(start);


while(!q.empty())
{
	string current = q.front();
	q.pop();


         if(current == goal)
	 {
		 cout<<"solution found\n";
		 printpuzzle(current);
		 return;
          }



	}


}




int main(){






	return 0;
}
