#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

// Function to find the height of the tree
int height(node* root){
    if(root == NULL) return 0;

    int lheight = height(root->left);
    int rheight = height(root->right);

    return max(lheight, rheight) + 1;
}

node* buildTree(node* Node){
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    Node = new node(data);

    if(data == -1){
        return NULL;
    }

    cout << "Enter the data for inserting in left of " << data << endl;
    Node->left = buildTree(Node->left);
    cout << "Enter the data for inserting in right of " << data << endl;
    Node->right = buildTree(Node->right);

    return Node;
}

void levelOrderTraversal(node* Node){

    queue<node*> q;
    q.push(Node);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){ 
            // purana level completely traverse ho chuka hai
            cout << endl;
            if(!q.empty()){ 
                // q still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout << temp->data << " ";
            if(temp -> left){
                q.push(temp -> left);
            }

            if(temp -> right){
                q.push(temp -> right);
            }
        } 
    }
}

// print nodes at given level
void printGivenLevel(node* root, int nodelevel, int reqLevel){

    if(root == NULL){
        return;
    }

    if(reqLevel == nodelevel){
        cout << root->data << " ";
    }

    printGivenLevel(root->left, nodelevel + 1, reqLevel);
    printGivenLevel(root->right, nodelevel + 1, reqLevel);
}

void reverseLevelOrder(node* root){
    int h = height(root);

    for(int i = h; i >= 1; i--){
        printGivenLevel(root, 1, i);
    }
}
/*void inorderTraversal(node* root){

    if(root == NULL){
        return;
    }

    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);

}*/

vector<int> inorderTraversal(node* root){
    vector<int> ans;
    stack<node* > s;
    node* curr = root;

    while(!s.empty() || curr != NULL){

        while (curr != NULL)
        {
            s.push(curr);
            curr = curr -> left;
        }
        curr = s.top();
        s.pop();
        ans.push_back(curr ->data);

        curr = curr->right;
    }
    return ans;
}

/*void preOrderTraversal(node* root){

    if(root == NULL){
        return;
    }

    cout << root->data << " ";

    preOrderTraversal(root->left);
    preOrderTraversal(root->right);

}*/

vector<int> preOrderTraversal(node* root){
    vector<int> ans;

    if(root == NULL){
        return ans;
    }
    stack<node*> s;
    node* curr = root;

    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            ans.push_back(curr->data);

            if(curr->right){
                s.push(curr->right);
            }
            curr = curr->left;
        }
        if(!s.empty()){
            curr = s.top();
            s.pop();
        }
    }
    return ans;
    
}

/*void postOrderTraversal(node* root){

    if(root == NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);

    cout << root->data << " ";
}*/




int main(){
    //                1
    //             /     \
    //          /         \
    //        3             5
    //      /   \         /    \
    //     7      11      17    -1
    //    / \     / \     / \
    //  -1  -1  -1  -1  -1  -1

    node* root = NULL;
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // creating a Tree
    root = buildTree(root);

    cout << "\nprinting level order traversal of tree " << endl;
    levelOrderTraversal(root);

    cout << "\nprinting level order traversal of tree " << endl;
    reverseLevelOrder(root);

    cout << "\nprinting inorder traversal of tree " << endl;
    vector<int> ans = inorderTraversal(root);

    for(int i: ans){
        cout << i << " ";
    }

    cout << "\nprinting preorder traversal of tree " << endl;
    vector<int> ans2 = preOrderTraversal(root);
    for(int i: ans2){
        cout << i << " ";
    }

    cout << "\nprinting postorder traversal of tree " << endl;
    //vector<int> ans3 = postOrderTraversal(root);

}
