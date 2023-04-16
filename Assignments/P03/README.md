## P03-Graphviz Class
### Delton Hughes
### Description:

- Writing a class that implements a psuedo Graphviz syntax. It will
visualize specific representations of linked list using node format.
Node format will be separated from data and pointers. We will create
several different methods to implement this. 



### Files

|   #   | File      | Description                      |
| :---: | --------- | -------------------------------- |
|   1   | main.cpp  | Main driver of my list program . |
|   2   | Banner.cpp| Banner uploaded.                 |                  
|   3   | output.txt| Text File                        |
### Instructions

- Use the commented instructions on how to use method commands.
- Need #include <ofstream> library
- Need #include <map>
- Need #include <vector>
- Creates a output.txt 
- Layout is like below

### Example Command
- GraphViz G("LinkedList", "LL");  // Create an instance of a Graphviz
- The code snippet below allows us to make default paramters
```
 map<string, string> Record;
 Attribute A;
 Record["shape"] = "record"; 
 A.addAttributes(Record);
```
- int nodeId = G.addNode(Record);     //Make a node 
- G.updateNode(2, "shape", "circle"); //Update a node
- G.addEdge(0, 1, Arrow);             //Make an edge
- G.updateEdge(0,"arrowhead","crow"); //Update a edge
- fout 
