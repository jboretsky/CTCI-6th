#include <cstddef>
#include <vector>

using namespace std;

struct TreeNode {
   TreeNode* left;
   TreeNode* right;
   int val;
   TreeNode(int value) : val(value) {}
};

class Tree {
   public:
      TreeNode* root;
      TreeNode* buildTree( vector<int> );
};

TreeNode* Tree::buildTree( vector<int> nodes ) {
   if( nodes.size() == 0 ) return NULL;
   TreeNode* root = new TreeNode(nodes[0]);
   nodes.erase(nodes.begin());
   int mid = nodes.size()/2;

   vector<int> low_half( nodes.begin(), nodes.begin() + mid );
   vector<int> high_half( nodes.begin() + mid, nodes.end() );

   root->left = buildTree( low_half );
   root->right = buildTree( high_half );

   return root;
}

