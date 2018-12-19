//Towers of Hanoi - Non-recursive solution

#include <iostream>
#include <vector>
using namespace std;
int main() {
  
  vector<int> t[3]; //declare an array of 3 vectors to represent the 3 towers
  int n, candidate=1, to, from=0, move=0; //move count starts at 0 because you haven't moved yet
  cout << "Enter the number of rings:";
  cin >> n;
  cout << endl;
  
  //the inital value of the "to" variable depends on whether n is even or odd 
  if(n%2==0) to=2; //if n is even, to=2 
  if(n%2==1) to=1; //if n is odd, to=1 
  
  //Initialize the 3 towers. The first tower, t[0], gets all of the rings to start. Since the .push_back() adds the elements (rings) to the end of the vector, you need to add the biggest number to your vector first using the for loop, in order that you can easily use .back() to retreive the smallest block
  for (int i=n+1; i>=1; i--){
    t[0].push_back(i);
  }
  t[1].push_back(n+1);
  t[2].push_back(n+1);
  
  //.size() returns th size of the vector
  while(t[1].size()<n+1){ //while t[1] does not yet contain all of the rings
    cout << "Move #" << ++move << ": Transfer ring " << candidate << " from tower " << char(from+'A') << " to tower "<< char(to+'A') <<"\n";
    t[to].push_back(t[from].back()); //Copy the last ring from the "from" tower to the "to" tower
    t[from].pop_back(); //delete the last ring from the "from" tower
    
    //from = the index of the tower with the candidate, the smallest available ring which was not just moved
    if (t[(to+1)%3].back() < t[(to+2)%3].back()) from=(to+1)%3;
    else from=(to+2)%3;
    
    candidate=t[from].back(); //the candidate is the ring on top of the "from" tower
    //to = index of the closest tower on which the candidate can be placed
    //compare the candidate with ring of the "closest" tower - the "closest" depends on whether n is odd or even
    if (n%2==1) { //if n is odd
      if (t[from].back() < t[(from+1)%3].back()) to=(from+1)%3;
      else to=(from+2)%3;
    }
    else { //if n is even
      if(t[from].back() < t[(from+2)%3].back()) to=(from+2)%3;
      else to=(from+1)%3;
    }
  } return 0;
}
