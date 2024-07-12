template <class T> class BinaryTree;
template <class T>
class BinaryTreeNode{
	template <class U>
	friend void Visit(BinaryTreeNode<U> *);
	template <class U>
	friend void InOrder(BinaryTreeNode<U> *);
	template <class U>
	friend void PreOrder(BinaryTreeNode<U> *);
	template <class U>
	friend void PostOrder(BinaryTreeNode<U> *);
	template <class U>
	friend void LevelOrder(BinaryTreeNode<U> *);
	// friend void Deklarasi();
public:
	BinaryTreeNode(){
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e, const T& m){
		data1 = e;
    data2 = m;
		LeftChild = RightChild = 0;
	}
	BinaryTreeNode(const T& e,const T& m, BinaryTreeNode *l, BinaryTreeNode *r){
		data1 = e;
    data2 = m;
		LeftChild = l;
		RightChild = r;
	}

	T data1, data2;
	BinaryTreeNode<T> *LeftChild, *RightChild;
};