/*********************************************************************
 *
 *  Author:           Delton Hughes
 *  Email:            dlhughes0129@my.msutexas.edu
 *  Label:            P03
 *  Title:            Graphviz
 *  Course:           CMPS 2143
 *  Semester:         Spring 2023
 *
 *  Description:
 *    This program is to create and compile the syntax for the 
 *    Graphviz online compiler. Essentially we will make a program
 *    which will link nodes and style said nodes. Whether that be an
 *    edge or the node itself. Then it will print out syntax to 
 *    the compiler and the "outfile.txt".
 * 
 *  Usage:
 *       -Allows the user to dynamicall create a linked list or a Vector
 *       -Also allows for user to +,-,*, print to outfile using fout <<, 
 *         print to console using cout <<, use [] to insert an integer, 
 *         and lastly check if 2 vectors are equivalent using ==. 
 *
 *  Files:
 *       main.cpp      :driver program
 *       output.txt    :txt file printint program output
 **********************************************************************/
#include <fstream>
#include <iostream>
#include <map>
#include <vector>

using namespace std;


/***********************************************************
 * Attribute
 *
 * Description:
 *      - Lays the ground work for attributes to be added and 
 *  to be manipulated.      
 *
 * Private Methods:
 *      - None
 *
 * Public Methods:
 *      -  void addAttribute(string key, string val)
 *      -  Attribute()
 *      -  void addAttributes(map<string, string> atts)
 *      -  friend ostream &operator<<(ostream &os, Attribute &e)
 *      -  friend fstream &operator<<(fstream &fout, Attribute &e)
 * 
 * Usage:
 *
 *      -  is used tangently in various other class 
 *  because class Attribute is inherited.    
 * 
 **************************************************************/
class Attribute
{
protected:
    map<string, string> att; // attributes

public:
    /*
   * Public :Attribute()
   *
   * Description: 
   *  - does nothing
   * 
   * Params:
   *      -nothing
   *
   * Returns:
   *      -nothing
   */
    Attribute() {}


   /*
   * Public :void addAttribute(string key, string val)
   *
   * Description: 
   *  - adds attributes to based of the key and value
   * 
   * Params:
   *      - string key
   *      - string val
   *
   * Returns:
   *      -nothing
   */
    void addAttribute(string key, string val) { att[key] = val; }

   /*
   * Public :addAttributes(map<string, string> atts)
   *
   * Description: 
   *  - Adds the value to the key that is entered.
   * 
   * Params:
   *      - map<string, string> atts
   *
   * Returns:
   *      -nothing
   */
    void addAttributes(map<string, string> atts){
        for (auto const &x : atts) {   //run through the maps
            att[x.first] = x.second;   //check the key and the value
        }
    }

   /*
   * Public :friend ostream &operator<<(ostream &os, Attribute &e)
   *
   * Description: 
   *  Overloads the << operator to print the [] syntax that 
   * is required in GraphViz editor.
   *  
   *  
   *
   * Params:
   *      - ostream& os
   *      - Attribute &e
   *
   * Returns:
   *      -os ---> returns to console
   */
    friend ostream &operator<<(ostream &os, Attribute &e){

        os << "[";

        int i = 0;
        for (auto const &x : e.att){
            os << x.first << "="
               << "\"" << x.second << "\"";

            if (i < e.att.size() - 1) {
                os << ", ";
            }
            i++;
        }
        os << "]";

        return os;
    }

    /*
   * Public : ofriend fstream &operator<<(ofstream &fout, Attribute &e)
   *
   * Description: 
   *  Overloads the << operator to print to a output file the [] 
   * syntax that is required in GraphViz editor.
   *
   * Params:
   *      - ostream& os
   *      - Attribute &e
   *
   * Returns:
   *      -fout ---> returns to output file
   */
    friend ofstream &operator<<(ofstream &fout, Attribute &e) {

        fout << "[";
        int i = 0;
        for (auto const &x : e.att) {
            fout << x.first << "="
                 << "\"" << x.second << "\"";
            if (i < e.att.size() - 1) {

                fout << ", ";
            }
            i++;
        }

        fout << "]";
        return fout;
    }

};

/***********************************************************
 * Edge : public Attribute
 *
 * Description:
 *      -Lays the ground work for edges, meaning it gives
 * an edge a start and end point. So it can point from 
 * one node to the next. 

 * Private Methods:
 *      - None
 *
 * Public Methods:
 *      -  Edge()
 *      -  Edge(string color, string arrow,string arrowhead)
 *      -  Edge(int start, int end)
 *      -  friend ostream &operator<<(ostream &os, Edge &e)
 *      -  friend fstream &operator<<(fstream &fout, Attribute &e)
 * 
 * Usage:
 *
 *      -  Edges uses attributes to addEdges() and also 
 * manipulate edges.
 *
 **************************************************************/
class Edge : public Attribute {
    int eid;
    int start; //makes start point an int
    int end;   //makes end point an int

public:
    /*
   * Public :Edge()
   *
   * Description: 
   *  - sets defaults values to an edge
   * 
   * Params:
   *      -nothing
   *
   * Returns:
   *      -nothing
   */
    Edge(){
        att["color"] = "black";    // default color
        att["arrow_type"] = "vee"; // default arrow shape
        att["arrowhead"] = "normal";
    }

    /*
   * Public :Edge(string color, string arrow,string arrowhead)
   *
   * Description: 
   *  - passes in the color to color(attributes),
   *  arrow to arrow(attributes), arrowhead to arrowhead(attributes).
   * 
   * Params:
   *      -string color
   *      -string arrow
   *      -string arrowhead
   *
   * Returns:
   *      -nothing
   */
    Edge(string color, string arrow,string arrowhead){
        att["color"] = color;      // default color
        att["arrow_type"] = arrow; // default arrow shape
        att["arrowhead"] = arrowhead;
    }
     /*
   * Public :Edge(int start, int end)
   *
   * Description: 
   *  - Passes start to this->start and 
   *  end to this->end. 
   * 
   * Params:
   *      -int start
   *      -int end
   *
   * Returns:
   *      -nothing
   */
    Edge(int start, int end){
        this->start = start;
        this->end = end;
    }
     /*
   * Public :ostream &operator<<(ostream &os, Edge &e)
   *
   * Description: 
   *  - makes the syntaxt possible for Graphviz and for an edge.
   *    For printing to console.
   * 
   * Params:
   *      -ostream &os
   *      -Edge &e
   * Returns:
   *      -os
   */
    friend ostream &operator<<(ostream &os, Edge &e){
        os << e.start << "->" << e.end << " ";
        os << "[";

        int i = 0;
        for (auto const &x : e.att){
            os << x.first << "="
               << "\"" << x.second << "\"";

            if (i < e.att.size() - 1){
                os << ", ";
            }
            i++;
        }
        os << "]";

        return os;
    }
    /*
   * Public :ofstream &operator<<(ofstream &fout, Edge &e)
   *
   * Description: 
   *   - makes the syntaxt possible for Graphviz and for an edge.
   *    For printing to console.
   * 
   * Params:
   *      -ostream &fout
   *      -Edge &e
   * Returns:
   *      -fout
   */
    friend ofstream &operator<<(ofstream &fout, Edge &e){
        fout << e.start << "->" << e.end << " ";
        fout << "[";

        int i = 0;
        for (auto const &x : e.att){
            fout << x.first << "="
               << "\"" << x.second << "\"";

            if (i < e.att.size() - 1){
                fout << ", ";
            }
            i++;
        }
        fout << "]";

        return fout;
    }
};

/***********************************************************
 * Node  : Node : public Attribute
 *
 * Description:
 *      - Lays the foundation for us to manipulate nodes.
 *
 * Private Methods:
 *      - None
 *
 * Public Methods:
 *      -  Node()
 *      -  Node(map<string, string> atts)
 * 
 * Usage:
 *
 *      -  not much usage just sets the default values to a node 
 *  and runs through the map of a node. 
 *
 **************************************************************/
class Node : public Attribute {
    int nid;

public:
 /*
   * Public :Node()
   *
   * Description: 
   *  - sets default values for a node 
   *  for example color=black and shape = record.
   * 
   * Params:
   *      -nothing
   *
   * Returns:
   *      -nothing
   */
    Node(){
        att["color"] = "black";  // default color
        att["shape"] = "record"; // default arrow shape
    }
/*
   * Public :Node(map<string, string> atts)
   *
   * Description: 
   *  - runs through maps and checks the value for 
   *   key.
   * Params:
   *      -map<string, string> atts
   *
   * Returns:
   *      -nothing
   */
    Node(map<string, string> atts){
        for (auto const &x : atts)
        {
            att[x.first] = x.second;
        }
    }
};

/***********************************************************
 * GraphViz
 *
 * Description:
 *      - GraphViz's main purpose is to allow the user to 
 *  create the backbone of the syntax a basic GraphViz program. 
 * It will allow the user to add nodes and edges to connect them, 
 * but also will allow them to change the attributes to the said
 * edges and nodes. 
 *
 * Private Methods:
 *      - None
 *
 * Public Methods:
 *      -  GraphViz()
 *      -  GraphViz(string graph_name, string graph_shape)
 *      -  int addNode()
 *      -  int addNode(map<string, string> atts)
 *      -  void updateNode(int id, string key, string value)
 *      -  void updateEdge(int id, string key, string value)
 *      -  void addEdge(int start, int end)
 *      -  void addEdge(int start, int end, map<string, string> att)
 *      -  friend ostream &operator<<(ostream &consl, GraphViz &g)
 *      -  friend ofstream &operator<<(ofstream &fout, GraphViz &g)
 * 
 * Usage:
 *
 *      - This is where all of the usage is implemented. This allows us
 *  to addNodes, addEdges, update both edges and nodes.
 *
 *
 **************************************************************/
class GraphViz {
    int edgeId;         //instance of id for edge
    int nodeId;         //instance of id for nodes
    vector<Edge> Edges; //a list of edges 
    vector<Node> Nodes; //a list of nodes 
    string graphName;   
    string graphShape;  

public:
    /*
   * Public :GraphViz()
   *
   * Description: 
   *  - sets edgeId and nodeId to 0 and sets 
   *   graphName to default to foo. 
   * 
   * Params:
   *      -nothing
   *
   * Returns:
   *      -nothing
   */
    GraphViz() {
        edgeId = 0;
        nodeId = 0;
        graphName = "foo";
    }
     /*
   * Public :GraphViz(string graph_name, string graph_shape)
   *
   * Description: 
   *  - Passes in id to 0 and passes graph_name to graphName
   * and graph_shape to graphShape.
   * 
   * Params:
   *      -string graph_name
   *      -string graph_shape
   *
   * Returns:
   *      -nothing
   */
    GraphViz(string graph_name, string graph_shape) {
        edgeId = 0;
        nodeId = 0;
        graphName = graph_name;
        graphShape = graph_shape;
    }
     /*
   * Public :int addNode()
   *
   * Description: 
   *  - It will add a node to the back of the list.  
   * 
   * Params:
   *      -nothing
   *
   * Returns:
   *      -returns int, using the vector called Nodes and 
   * decrements its size by one.
   */
    int addNode() {
        Nodes.push_back(Node());
        return Nodes.size() - 1;
    }
   /*
   * Public :int addNode(map<string, string> atts) 
   *
   * Description: 
   *  - It will add a node and its attribute with the key
   * and value to the back of the list.  
   * 
   * Params:
   *      -map<string, string> atts
   *
   * Returns:
   *      -returns int, using the vector called Nodes and 
   * decrements its size by one.
   */
    int addNode(map<string, string> atts) {
        Nodes.push_back(Node(atts));

        return Nodes.size() - 1;
    }
     /*
   * Public :void updateNode(int id, string key, string value)
   *
   * Description: 
   *  - Updates the nodes attributes by passing in the nodeId,
   *  key ex."shape", value ex."circle". 
   * 
   * Params:
   *      -int id
   *      -string key
   *      -string value
   *
   * Returns:
   *      -nothing
   */
    void updateNode(int id, string key, string value) {
        Nodes[id].addAttribute(key, value);
    }
     /*
   * Public :void updateEdge(int id, string key, string value)
   *
   * Description: 
   *  - Updates the edge attributes by passing in the edgeId,
   *  key ex."color", value ex."red". 
   * 
   * Params:
   *      -int id
   *      -string key
   *      -string value
   *
   * Returns:
   *      -nothing
   */
      void updateEdge(int id, string key, string value) {
        Edges[id].addAttribute(key, value);
    }
     /*
   * Public :void addEdge(int start, int end)
   *
   * Description: 
   *  - You add an edge by entering the start point of 
   * the edge based on the node and end point based on the 
   * next node. 
   * 
   * Params:
   *      -int start
   *      -int end
   *
   * Returns:
   *      -nothing
   */
    void addEdge(int start, int end) {
      // make and edge constructor that receives two ints so you
      // can print them out
        Edges.push_back(Edge(start, end));
    }
     /*
   * Public :void addEdge(int start, int end, map<string, string> att)
   *
   * Description: 
   *  - Allows for you to add the attributes to the edge based on 
   * the start and end point.
   * 
   * Params:
   *      -int start
   *      -int end
   *      -map<string, string> att
   *
   * Returns:
   *      -nothing
   */
    void addEdge(int start, int end, map<string, string> att) {

        Edges.push_back(Edge(start, end));
        Edges[Edges.size() - 1].addAttributes(att);
    }

 /*
   * Public :friend ostream &operator<<(ostream &consl, GraphViz &g)
   *
   * Description: 
   *  - allows us to cout a node and edge
   * 
   * Params:
   *      -ostream &consl
   *      -GraphViz &g
   *
   * Returns:
   *      -returns consl 
   */
    friend ostream &operator<<(ostream &consl, GraphViz &g) {
        for (int i = 0; i < g.Nodes.size(); i++){
            consl << i << " " << g.Nodes[i] << endl;
        }
        for (int i = 0; i < g.Edges.size(); i++){
            consl << g.Edges[i] << endl;
        }
        return consl;
    }

 /*
   * Public :friend ofstream &operator<<(ofstream &fout, GraphViz &g)
   *
   * Description: 
   *  - allows us to cout a node and edge
   * 
   * Params:
   *      -ofstream &fout
   *      -GraphViz &g
   *
   * Returns:
   *      -returns fout
   */
    friend ofstream &operator<<(ofstream &fout, GraphViz &g){  
        
        for (int i = 0; i < g.Nodes.size(); i++){
            fout << i << " " << g.Nodes[i] << endl;
        }
        for (int i = 0; i < g.Edges.size(); i++){
            fout << g.Edges[i] << endl;
        }
        return fout;
    }
};

int main()
{
    ofstream fout;
    fout.open("test.out");
    fout<<"Delton Hughes "<<endl;
    fout<<"3/7/2023"<<endl;
    fout<<"Spring 2023"<<endl;
    // create graphviz instances with specific shapes
    GraphViz G("LinkedList", "LL");         //LinkedList instance
    GraphViz D("DoublyLinkedList", "DLL");  //DoublyLinkedList instance
    GraphViz B("BinarySearchTree", "BST");  //BinarySearchTree instance

    
    map<string, string> Record; // allows us to load attributes to a node
    map<string, string> Arrow;  // allows us to load attributes to a edge
    // Gets a map of Attribute and
    // adds them to "A"
    Attribute A;
    //Setting default attributes to record
    Record["shape"] = "record"; 
    Record["color"] = "blue";
    Record["opacity"] = "0.8";
    A.addAttributes(Record);
    //Setting default attributes to Arrow
    Arrow["color"] = "black";
    Arrow["arrow_type"] = "vee";
    Arrow["arrowhead"] = "normal";
    A.addAttributes(Arrow);
    fout<<"digraph LinkedList { "<<endl;
    fout<<"rankdir=LR"<<endl; 
    //making back bone of nodes for a Linked List
    int nodeId = G.addNode(Record);     
    nodeId = G.addNode(Record);         
    nodeId = G.addNode(Record);
    nodeId = G.addNode(Record);
    nodeId = G.addNode(Record);
    //Making the Linked List look pretty
    //setting shape to circle
    G.updateNode(2, "shape", "circle");
    G.updateNode(4, "shape", "star");
    //setting color of nodes red
    G.updateNode(0, "color", "red");
    G.updateNode(1, "color", "red");
    G.updateNode(2, "color", "red");
    G.updateNode(3, "color", "red");
    G.updateNode(4, "color", "red");
    //setting label to have data in left side of a record
    G.updateNode(0,"label", "{<data> A | <ref> }");
    G.updateNode(1,"label", "{<data> B | <ref> }");
    G.updateNode(2,"label", "C");
    G.updateNode(3,"label", "{<data> D | <ref> }");
    G.updateNode(4,"label", "E");

    //adding Edges from one node to another
    G.addEdge(0, 1, Arrow);
    G.addEdge(1, 2, Arrow);
    G.addEdge(2, 3, Arrow);
    G.addEdge(3, 4, Arrow);
    //editing an edge because I can
    G.updateEdge(0,"arrowhead","crow");
    cout<<G;
    fout << G;
    fout<<"}"<<endl<<endl;
   
    
  
    // making the doubly linked list
    // and sending in default colors and shapes
    fout<<"digraph DoublyLinkedList { "<<endl;
    fout<<"rankdir=LR"<<endl; 
    nodeId = D.addNode(Record);
    nodeId = D.addNode(Record);
    nodeId = D.addNode(Record);
    nodeId = D.addNode(Record);
    nodeId = D.addNode(Record);
    //setting color to purple
    G.updateNode(0, "color", "purple");
    G.updateNode(1, "color", "purple");
    G.updateNode(2, "color", "purple");
    G.updateNode(3, "color", "purple");
    G.updateNode(4, "color", "purple");
    D.updateNode(0,"label", "{<data> A | <ref> }");
    D.updateNode(1,"label", "{<data> B | <ref> }");
    D.updateNode(2,"label", "{<data> C | <ref> }");
    D.updateNode(3,"label", "{<data> D | <ref> }");
    D.updateNode(4,"label", "{<data> E | <ref> }");
    //adding the edges to the Doubly linked list
    D.addEdge(0, 1, Arrow);
    D.addEdge(1, 0, Arrow);
    D.addEdge(1, 2, Arrow);
    D.addEdge(2, 1, Arrow);
    D.addEdge(2, 3, Arrow);
    D.addEdge(3, 2, Arrow);
    D.addEdge(3, 4, Arrow);
    D.addEdge(4, 3, Arrow);
    cout << G;
    fout << D;
    fout<<"}"<<endl<<endl;
    fout<<"digraph BinarySearchList { "<<endl;
    fout<<"rankdir=LR"<<endl; 
    //Creating the nodes for a Binary Search Tree
    nodeId = B.addNode(Record);
    nodeId = B.addNode(Record);
    nodeId = B.addNode(Record);
    nodeId = B.addNode(Record);
    nodeId = B.addNode(Record);
    nodeId = B.addNode(Record);
    nodeId = B.addNode(Record);
    //setting data values in the record for each node
    B.updateNode(0,"label", "{<data> A | <ref> }");
    B.updateNode(1,"label", "{<data> B | <ref> }");
    B.updateNode(2,"label", "{<data> C | <ref> }");
    B.updateNode(3,"label", "{<data> D | <ref> }");
    B.updateNode(4,"label", "{<data> E | <ref> }");
    B.updateNode(5,"label", "{<data> F | <ref> }");
    B.updateNode(6,"label", "{<data> G | <ref> }");
    //connecting nodes with edges 
    B.addEdge(0, 1, Arrow);
    B.addEdge(0, 2, Arrow);
    B.addEdge(1, 3, Arrow);
    B.addEdge(1, 4, Arrow);
    B.addEdge(2, 5, Arrow);
    B.addEdge(2, 6, Arrow);
    //Editing edges to different color and arrowhead
    B.updateEdge(0,"arrowhead","tee");
    B.updateEdge(1,"arrowhead","tee");
    B.updateEdge(0,"color","orange");
    B.updateEdge(1,"color","orange");
    B.updateEdge(2,"color","orange");
    B.updateEdge(3,"color","orange");
    B.updateEdge(4,"color","orange");
    B.updateEdge(5,"color","orange");
    cout<<B;
    fout << B;
    fout<<"}"<<endl<<endl;

    fout.close(); 
}

