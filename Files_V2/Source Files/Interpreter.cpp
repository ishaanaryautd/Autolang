#include "../Header Files/ExpressionTree.h"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using program_vars::identifiers;

void print_n(int n)
{
	for (int i = 0; i < n; i++) cout << " ";
}

int main() 
{	
	string expression = "(f o g)[A U {1, 2}]";
	cout << "Parsing Expression: " << expression << endl << endl;
	

	vector<ExpressionTree *> * trees1 = new vector<ExpressionTree *>{new ExpressionTree(expression)};
	vector<ExpressionTree *> * trees2 = new vector<ExpressionTree *>;
	int level = 2;
	while (!trees1->empty())
	{
		while (!trees1->empty())
		{
			ExpressionTree *tree = (*trees1)[0];
			trees1->erase(trees1->begin());
			print_n(80/level);
			if (tree->root != nullptr) {
				cout << tree->root->token.lexeme;
				print_n(80 / level);
				if (tree->root->left != nullptr) 
					trees2->push_back(tree->root->left);
				else
					trees2->push_back(new ExpressionTree((string)""));
				if (tree->root->right != nullptr)
					trees2->push_back(tree->root->right);
				else
					trees2->push_back(new ExpressionTree((string)""));
			}
		}
		cout << "\n";
		swap(trees1, trees2);
		level *= 2;
	}
}