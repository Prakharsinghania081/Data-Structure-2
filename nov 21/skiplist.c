/* In mordern lifts like in marina bay singapore, lifts dont go to each floor Instead they go on to the multiples. Say you want to go to floor 34 and life goes to multiple of 5
so we go to floor 30 with the express lift, change lift and take a smaller one for the 4 floors. */

struct Nodetype {
  int val;
  struct Nodetype *Next; //normal node 
}

//in our express 

struct Nodetype {
  int val;
  struct Nodetype **E; // or struct Nodetype *Next[]; (address of next) which is an array. a -> Next[0] -> Next[1] .......
}


int *a;
a = (int*) malloc (sizeof(int)*100) // array of size 100 karan doubt **Next pointer to a pointer
  
  
/*

[7][]
[6]
[5]
[4][]
[3]
[2]
[1][]

*/ 
// the lift concept and the numbwe of elevators accisible. 
  /*
// 1 - 2 - 3-4-5-6-7-8-9-10-11-12-13-14-15-16-17=18=19=-20-21-22-23-24-25-26-27-28-29-30 
lift 1: 1 - 2 - 3-4-5-6-7-8-9-10-11-12-13-14-15-16-17=18=19=-20-21-22-23-24-25-26-27-28-29-30 [c = head; c -> next[0] 
lift 2: 1-5-10-15-20-25-30 [c=head; c->next[1] 
lift 3: 1-10-20-30 [c = head; c-> next[2] 

to find where is 26, we go to fastest lift lift 3, 20<26 and 30>26 so we know 26 between 20 and 30 and stop at  20 
now go to lift 2: 25<26<30 
lift 3 25<26<27 you get your floor 

*/
  
//if anyone knows ur sizes of jumps he can kill so we randomise the jumps. 
  //generate particular number and generate an array 
x = (0,1)
numE = 1 
if (x<0.2) numE +=1; 1 //every 5th size 2 and every 10th size 3 array if number is 0.15 u get 2 elvators in location (numE = 1+1 ) 
if (x<0.1) numE +=1; //if number is less than 0.1 say 005 numE = 1+1+1 = 3 so u have 3 elevators in that location. 

typedef struct NodeType * NodeAddress;
E = (NodeAddress*)malloc(

  //first generate a p
//skiplists common interview questions. quadtrees, 
  //interview question: given entire code and elevator positions now how to connect them tell. 






  





