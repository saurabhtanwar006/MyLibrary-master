typedef int KeyType;

struct Node {
	int size, priority;
	KeyType key;

	Node *left, *right;

	Node(KeyType _key) :size(1), priority(rand()), key(_key), left(NULL), right(NULL) { }

	void setLeft(Node *node) {
		left = node;
		calcSize();
	}

	void setRight(Node *node) {
		right = node;
		calcSize();
	}

	void calcSize() {
		size = 1;
		if (left != NULL) size += left->size;
		if (right != NULL) size += right->size;
	}
};

typedef pair<Node *, Node *> NodePair;

NodePair split(Node *root, KeyType key) {
	if (root == NULL) return NodePair(NULL, NULL);

	if (root->key < key) {
		NodePair splitedNode = split(root->right, key);
		root->setRight(splitedNode.first);
		return NodePair(root, splitedNode.second);
	}
	else {
		NodePair splitedNode = split(root->left, key);
		root->setLeft(splitedNode.second);
		return NodePair(splitedNode.first, root);
	}
}

bool find1(Node *root, int data){
	if(root==NULL)
		return 0;
	if(root->key==data)
		return 1;
	if(root->key>data){
		return find1(root->left,data);
	}
	else return find1(root->right,data);
}
Node* insert(Node *root, Node *node) {
	if (root == NULL) return node;
	if (root->priority < node->priority) {
		NodePair splitedNode = split(root, node->key);
		node->setLeft(splitedNode.first);
		node->setRight(splitedNode.second);
		return node;
	}

	if (root->key < node->key) {
		root->setRight(insert(root->right, node));
	}
	else {
		root->setLeft(insert(root->left, node));
	}
	return root;
}

Node* merge(Node *a, Node *b) {
	if (a == NULL) return b;
	if (b == NULL) return a;

	if (a->priority > b->priority) {
		a->setRight(merge(a->right, b));
		return a;
	}
	else {
		b->setLeft(merge(a, b->left));
		return b;
	}
}

Node* erase(Node* root, KeyType key) {
	if (root == NULL) return NULL;

	if (root->key == key) {
		Node *node = merge(root->left, root->right);
		delete root;
		return node;
	}

	if (root->key < key) {
		root->setRight(erase(root->right, key));
	}
	else {
		root->setLeft(erase(root->left, key));
	}
	return root;
}

Node* kth(Node* root, int k){
	if(root==NULL) return NULL;
	int leftSize = 0;
	if (root->left != NULL) leftSize = root->left->size;
	if (leftSize >= k) return kth(root->left, k);

	if (leftSize + 1 == k){
		//cout<<"HI"<<endl;
		return root;
	}
	return kth(root->right, k - leftSize - 1);
}

int countLessThan(Node *root, KeyType key) {
	if (root == NULL) return 0;
	if (root->key >= key) return countLessThan(root->left, key);
	int leftSize = ((root->left != NULL) ? root->left->size : 0);
	return leftSize + 1 + countLessThan(root->right, key);
}

