# Graph-Theory-Project-Template
Project template of course - Graph Theory (EE6622E) in National Cheng Kung University.


## TODO - Your descriptions about solutions/algorithms/results
### Abstract
The Chinese postman problem is a route inspection problem, it wants to find the shortest route, that needs to meet the following criteria:
* It is a closed circuit, and it ends at the same point it starts.
* It needs to go through every vertex at least once.
 
And the ideal solution is the Euler path.This time I completed the undirected Chinese postman solution.
### Algorithms and Code Description
First, we need to find the number of odd vertices, if have no odd vertex that means it is the euler circuit which is the solution to this problem. 
And if have odd vertices, we need to add the edge between two odd vertices, make the odd vertices turn into the even vertices.

I use Dijkstra's algorithm to find the shortest path between two odd vertices.
first I find the distance of a vertex to each vertex, and according to the distance find the shortest path between two odd vertices and connect them.

And I use Hierholzer algorithm to find Euler path, first choose a vertex push into stack`recordpath`, walk along the adjacent edge to the next vertex and push the vertex into stack`recordpath` and disconnect the edge that walked, and so on.
If no edge can walk, pop the vertex from stack`recordpath` and push this vertex into another stack`finalpath`, and go back to the previous vertex continue the step.

Finally, I push the content of stack`recordpath` into stack`finalpath`, according to the content of stack`finalpath`, we can have our solution.
### File Name Identification
* `main.cc`: The main program.
* `topo.txt`: The input graph.
* `input.dot`: The dot file of input graph.
* `input.png`: The png file of input graph.
* `plot.dot`: The dot file of result.
* `output.png`: The png file of result.
* `final_result.txt`: The txt file of result.

