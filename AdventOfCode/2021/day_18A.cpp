#include <bits/stdc++.h>
#include <optional>

using namespace std;
typedef long long ll;

class Node {
public:
	ll value;
	Node *left, *right;
	Node *next, *prev;
	Node* parent;

	Node (int __value = -1) : value(__value) {
		left = right = next = prev = parent = nullptr;
	}

	Node (string cad, Node* __parent = nullptr) {	
		parent = __parent;
		next = prev = nullptr;

		if(cad.size() == 1) {
			value = cad.front() - '0';
			left = right = nullptr;
			return;
		}

		cad = cad.substr(1); cad.pop_back();
		int counter = 0, middle;
		for(int i=0; i<cad.size(); ++i) {
			if(cad[i] == '[') ++counter;
			else if(cad[i] == ']') --counter;
			else if(cad[i] == ',' && counter == 0) {
				middle = i;
				break;
			}
		}
		
		value = -1;
		left = new Node(cad.substr(0, middle), this);
		right = new Node(cad.substr(middle+1), this);
	}

	void insertLeafsInto(vector<Node*> &leafs) {
		if(value != -1) {
			leafs.push_back(this);
		} else {
			left->insertLeafsInto(leafs);
			right->insertLeafsInto(leafs);
		}
	}
	
	Node* getFirstPairReducedByExplode(int deep = 0) {
		if(value != -1)
			return (deep > 4 ? this : nullptr);

		Node* target = left->getFirstPairReducedByExplode(deep + 1);	
		return (target ? target : right->getFirstPairReducedByExplode(deep + 1));
	}

	Node* getFirstPairReducedBySplit() {
		if(value != -1)
			return (value > 9 ? this : nullptr);

		Node* target = left->getFirstPairReducedBySplit();
		return (target ? target : right->getFirstPairReducedBySplit());
	}

	ll getSum() {
		if(value != -1)
			return value;

		return 3*left->getSum() + 2*right->getSum();
	}

	void connectTo(Node* other) {
		next = other;
		other->prev = this;
	}

	void clear() {
		if(left != nullptr) {
			left->clear();
			delete left;
		}

		if(right != nullptr) {
			right->clear();
			delete right;
		}
	}

	void print() {
		if(value != -1) {
			cout << value;

			if(left != nullptr || right != nullptr)
				cout << "there is a leaf with children: " << value << endl;
			return;
		}
		cout << '[';
		left->print();
		cout << ',';
		right->print();
		cout << ']';
	}
};

class SnailfishNumber {
public:
	Node* root;
	Node* front;
	Node* back;

	SnailfishNumber(string cad) {		
		root = new Node(cad);

		vector<Node*> leafs;
		root->insertLeafsInto(leafs);	
		for(int i=0; i<leafs.size()-1; ++i)
			leafs[i]->connectTo(leafs[i+1]);

		front = leafs.front();
		back = leafs.back();
	}

	void operator += (SnailfishNumber other) {
		Node* aux = new Node();	
		aux->left = root;
		aux->right = other.root;
		aux->left->parent = aux->right->parent = aux;
	
		back->connectTo(other.front);	
		back = other.back;
		root = aux;
	}

	bool reduceExplode() {
		Node* target = root->getFirstPairReducedByExplode();
		//print();
		//cout << "explode " << (target ? target->value : -1) << endl;
		if(target) {
			explode(target);
			return true;
		}

		return false;
	}

	bool reduceSplit() {
		Node* target = root->getFirstPairReducedBySplit();
		//print();
		//cout << "split " << (target ? target->value : -1) << endl;
		if(target) {
			split(target);
			return true;
		}
		return false;
	}

	bool explode(Node* target) {
		try {
			Node* brother = target->next;
			Node* parent1 = target->parent;
			Node* parent2 = brother->parent;
			if(parent1 != parent2)
				throw "[EXPLODE] they are not in the same pair";
			Node* grandParent = parent1->parent;
			Node* newLeaf = new Node(0);

			newLeaf->parent = grandParent;
			if(grandParent->left == parent1)
				grandParent->left = newLeaf;
			else
				grandParent->right = newLeaf;

			if(target->prev) {
				target->prev->value += target->value;
				target->prev->connectTo(newLeaf);
			} else {
				front = newLeaf;
			}

			if(brother->next) {
				brother->next->value += brother->value;
				newLeaf->connectTo(brother->next);
			} else {
				back = newLeaf;
			}

			delete target;
			delete brother;
			delete parent1;
		}
		catch(exception& e)
		{
			cerr << "[EXPLODE]" << e.what() << endl;
			return false;
		}
		return true;
	}
	
	bool split(Node* target) {
		try {
			target->left = new Node(target->value / 2);	
			target->right = new Node((target->value + 1)/ 2);

			target->left->parent = target->right->parent = target;
			target->left->connectTo(target->right);
			if(target->prev)
				target->prev->connectTo(target->left);
			else
				front = target->left;

			if(target->next)
				target->right->connectTo(target->next);
			else
				back = target->right;

			target->value = -1;
			target->prev = target->next = nullptr;
		}
		catch(exception& e) {
			cerr << "[SPLIT] " << e.what() << endl;
			return false;
		}

		return true;
	}

	void reduce() {	
		while(reduceExplode() || reduceSplit());
	}

	void clear() {
		if(root) {
			root->clear();
			delete root;
		}
	}

	void print() {
		root->print();
		cout << endl;
	}
};

int main() {
	vector<string> nums;
	string cad;
	cin >> cad;
	ll ans = 0;
	
	while(cin >> cad) 
		nums.push_back(cad);

	for(int i=0; i<nums.size(); ++i) {
		for(int j=0; j<nums.size(); ++j) {
			if(i == j) continue;

			SnailfishNumber current(nums[i]);	
			current += SnailfishNumber(nums[j]);
			current.reduce();
			
			ans = max(ans, current.root->getSum());
		}
	}
	cout << ans << endl;
	return 0;
}
