

#include <iostream>
#include <string>
#include <queue>

using namespace std;

// A Huffman tree node
struct Node {
    char data;
    int freq;
    Node* lchild;
    Node* rchild;
};

Node* createNode(char data, int freq){
    Node* ptmpNode = new(Node);
    ptmpNode->data = data;
    ptmpNode->freq = freq;
    ptmpNode->lchild =NULL;
    ptmpNode->rchild = NULL;
    return ptmpNode;
}

// For comparison of
// two heap nodes (needed in min heap)
struct compare {
    
    bool operator()(Node* left, Node* right){
        if(left->freq > right->freq)
            return true;
        else
            return false;
    }

};

// Prints huffman codes from
// the root of Huffman Tree.

void preorder(Node* root, string str){
    if(root !=NULL){
        if(root->data != '$')
            printf("%c : %s \n", root->data, str.c_str());
        preorder(root->lchild, str+'0');
        preorder(root->rchild, str+'1');
    }
}

// The main function that builds a Huffman Tree and
// print codes by traversing the built Huffman Tree
void CreateHuffmanCodes(char data[], int freq[], int size)
{
    priority_queue <Node*, std::vector<Node*>, compare> pq;
    
    // populating the pq with Node* pointer
    
    for(int i=0; i< size; i++){
        pq.push(createNode(data[i], freq[i]));
    }
    
    // Now, build the Tree
    // If we traverse all initial nodes, then there will be only one Node left, that's a synthetic Node (made in intermediate steps)
    string str = "";
    
    Node * root;
    
    while( pq.size() != 1){
        
        Node* lchild = pq.top();
        pq.pop();
        Node* rchild = pq.top();
        pq.pop();
        
        // ceate a new node using the lchild and rchild
        root = createNode('$', (lchild->freq + rchild->freq));
        
        //connect (create link) with those lchild and rchild
        root->lchild = lchild;
        root->rchild = rchild;
        
        // push it to the pq        
        pq.push(root);
        
    }
    
    //Now we have the tree built and the root(top) Node
    
    preorder(pq.top(), "");

}

// Driver Code
int main()
{

	char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
	int freq[] = { 5, 9, 12, 13, 16, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	CreateHuffmanCodes(arr, freq, size);

	return 0;
}


