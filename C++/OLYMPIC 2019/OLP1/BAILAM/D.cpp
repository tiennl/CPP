#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;



struct Node
{

	Node *parent;
	vector<Node*> children;
	int value;

	
};
struct Tree
{

	vector<Node> nodes;


	void addNode(int n, int parent){	
		
		 Node *node = this->findNode(n);
		 Node *parentNode = this->findNode(parent);

		 if(node == NULL){
		 	//cout << "node of " << n << "is empty" << endl;
		 	return;
		 }

		 if(parentNode == NULL){
		 	//cout << "parent of " << n << "is empty" << endl;
		 	return;
		 }
		 parentNode->children.push_back(node);
		 node->parent = parentNode;


	}

	Node *findNode(int value){

		for (int i = 0; i < nodes.size(); ++i){
			if(nodes[i].value == value){
				return &nodes[i]; 
			}
		}

		return NULL;
	}


	bool hasParent(Node *node, int parent){


		if(node->parent == NULL){
			
			return false;
		}

		

		if(node->parent->value == parent){
			return true;
		}

		return hasParent(node->parent, parent);

	}
	bool check(int parent, int child){

	//	cout << "check:" << parent << " chid:" << child;
			
		for (int i = 0; i < nodes.size(); ++i){
			if(nodes[i].value == child){

					return hasParent(&nodes[i],parent);
			}
		}

		return false;
	}
};


Tree tree;

int main(){
	
	int n,parent;
	cin >> n;


	for (int i = 1; i <= n; ++i){
		Node node;

		node.parent = NULL;
		

		node.value = i;
		tree.nodes.push_back(node);
	}

	for (int i = 1; i <= n; ++i){
		cin >> parent;
		tree.addNode(i, parent);
		
		
	}



	int q, q1,q2;

	cin>>q;
	for (int i = 0; i < q; ++i){
		cin >> q1 >> q2;
		if (tree.check(q1,q2)){
			cout << "Yes" << endl;

		}else{

			cout << "No" << endl;
		}

	}
	return 0;
}
