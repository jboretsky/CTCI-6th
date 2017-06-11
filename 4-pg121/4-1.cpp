#include "tree.h"

int main() {
   vector<int> nums = {1,2,3,4,5};
   Tree* tree = new Tree();
   tree->root = tree->buildTree(nums);
   return 0;
}
