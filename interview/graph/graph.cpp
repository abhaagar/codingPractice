#define MAXV 1000

class Node {
   private:
      int _y;
      int _weigth;
      int _degree;
      class Node* _next;
   public:
      int y() { return _y;}
      int weigth() { return _weight;}
      int degree() { return _degree;}
};


class Graph {
   private:
      class Node *_nodes[MAXV+1];
      int _nNodes;
      int _nEdges;
      bool _directed;
   public:
      Graph(int nNodes_,int nEdges_,bool directed_);
      int nNodes() { return _nNodes;}
      int nEdges() { return _nEdges;}
      bool directed() { return _directed;}
};

Graph::Graph(int nNodes_,int nEdges_,bool directed_) {
   _nNodes = nNodes_;
   _nEdges = nEdges_;
   _directed = directed_;
   for i in MAXV+1;
      _nodes[i] = NULL;
}

int main() {
   Graph g(5,6,false); 
   return 0;
}
