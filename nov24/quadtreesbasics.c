/* Quadtrees -> FMM ->. NN 

I have a table with 1 billion dots. each being x,y. To make it easier it can be seen as 2 arrays. x[0] and y[0] and there 1 billion values.
if same index then its a particular point. 

kNN, let k=40 find 40 nearest points to each point x,y. if we need to find for each point then u will have an array of size 40 for all 1 billion x,y 

no reci[procal relation. to find the 40 points u will have to find all distances. 

*/

