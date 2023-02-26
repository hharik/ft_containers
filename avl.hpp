#ifndef AVL_HPP_
#define AVL_HPP_
#include "pair.hpp"
#include <iostream>
#include "vector.hpp"
#include <map>
#define SPACE 10


//doesn't allocate anything
namespace ft{
template <class T1, class T2> 
class TreeNode {
	public:
		ft::pair<const T1, T2>	*data; // needs to be allocated 
		TreeNode	*left;
		TreeNode	*right;
		TreeNode 	*parent;
		int height;
		TreeNode() : data(), left(NULL), right(NULL), height(0), parent(NULL) {}
		TreeNode(const TreeNode &other) : data(other.data), left(other.left), right(other.right), parent(other.parent), height(other.height) {}


		TreeNode(int high, TreeNode *left, TreeNode *right, TreeNode *parent, ft::pair<const T1, T2> *dat) \
		: data(dat), left(left), right(right), parent(parent), height(high){}
		
		~TreeNode() {}
};

//init starts by allocating for root 
//and then allocate the data which pair

template <class T1, class T2, class Compare, class Allocator = std::allocator<ft::pair<const T1, T2> > >
class AVL {

	public:
		typedef T1					key_type;
		typedef	ft::pair<T1, T2>	value_type;
		typedef TreeNode<T1, T2>	_node_type;
		typedef	TreeNode<T1,T2>*	pointer;
		typedef	Allocator	alloc_pair;
		typedef Compare		comp;
		typedef typename Allocator::template rebind<_node_type >::other	alloc_type;

		AVL() : root(NULL), size_(0), alloc_node(), alloc_pair_(), compare_(){}
		AVL(const AVL &other) : root(other.root), size_(other.size_), alloc_node(other.alloc_node), alloc_pair_(other.alloc_pair_), compare_(other.compare_) {}
		~AVL() {if (size_) destory_avl(); }


		pointer	init_first(int Height, const value_type &val, _node_type *parent) { 
			pointer tmp = alloc_node.allocate(1);
			tmp->data = alloc_pair_.allocate(1);
			alloc_pair_.construct(tmp->data, val);
			alloc_node.construct(tmp, TreeNode<T1, T2>(Height, NULL, NULL, parent, tmp->data));
			return tmp;
		}

		// void	print2D(_node_type *r, int space){
		// 	if (r == NULL) return;
		// 	space += SPACE; // increase distance between levels of the tree 
		// 	print2D(r->right, space);
		// 	std::cout << std::endl;
		// 	for (int i = SPACE; i < space; i++)
		// 		std::cout << " ";
		// 	std::cout << r->data->first << " " <<std::endl;
		// 	print2D(r->left, space);
		// }

		// void print(){
		// 	print2D(root, 10);
		// }

		int Height(pointer r)
		{
			if (r == NULL)
				return 0;
			return r->height;
		}

		int getbalanceFactor(pointer r) 
		{
			if (r == NULL)
				return -1;
			return Height(r->left) - Height(r->right);
		}
		
		pointer	insert_avl(pointer r, const value_type &val)
		{
			if (r == NULL)
			{
				size_++;
				return init_first(1, val, NULL);
			}
			if (compare_(val.first, r->data->first)) //val < r
			{
				r->left = insert_avl(r->left, val);
				r->left->parent = r;
			}
			else if (compare_(r->data->first, val.first)) //r > val
			{
				r->right = insert_avl(r->right, val);
				r->right->parent = r;
			}
			else  // if its not less or greater then it will be equal to and we can have duplicates
			{
				return r;
			}
			//if the balance factor is positive we need to right rotate the nodes
			//if the balance factor is negative we need to left rotate the nodes;
			r->height = 1 + max(Height(r->left), Height(r->right));
			int balance = getbalanceFactor(r);
			if (balance > 1 && compare_(val.first, r->left->data->first)) // val < left // for right rotate the tree 
				return rightRotate(r);
			else if (balance < -1 && compare_(r->right->data->first, val.first)) // val > r->right // left rotate the tree 
				return leftRotate(r);
			else if (balance > 1 && compare_(r->left->data->first, val.first)) // val > r->left // left right rotate the tree
			{
				r->left = leftRotate(r->left);
				return rightRotate(r);
			}
			else if (balance < -1 && compare_(val.first, r->right->data->first)) // val < r->right // right left rotate
			{
				r->right = rightRotate(r->right);
				return leftRotate(r);
			}
			return r;
		}

		void	destroy_tree(pointer node)
		{
			if (node == NULL)
				return ;

			if (node->parent && node->parent->left == node)
				node->parent->left = NULL;
			else if (node->parent && node->parent->right == node)
				node->parent->right = NULL;
			

			alloc_pair_.destroy(node->data);
			alloc_node.destroy(node);
			alloc_pair_.deallocate(node->data, 1);
			alloc_node.deallocate(node, 1);

			if (root == node)
				root = NULL;
			else
				node = NULL;
			size_--;	
		}
		void	destroy_avl_base(pointer node)
		{
			if (node == NULL) return ;
			destroy_avl_base(node->left);
			destroy_avl_base(node->right);
			destroy_tree(node);
		}
		void 	destory_avl()
		{
			if (size_ )
				destroy_avl_base(root);
		}
		int     max(int a, int b)
        {
			if (a > b)
				return a;
			return b;
        }
		pointer		rightRotate(pointer _node)
		{

			pointer	_p_node = _node->parent; // parent
			pointer x = _node->left; // l_node;
			pointer t1 = x->right; // r_node;
			//rotate the tree
			if (t1 != NULL)
				t1->parent = _node;
			x->right = _node;
			_node->left = t1;

			//assign parents
			x->parent = _p_node;
			_node->parent = x;
		
			_node->height = max(Height(_node->left), Height(_node->right)) + 1;
			x->height = max(Height(x->left), Height(x->right)) + 1;
			return x;
		}
		
		pointer leftRotate(pointer _node)
		{
			pointer _p_node = _node->parent;
			pointer x = _node->right;//r_node
			pointer t1 = x->left;// l_node

			if (t1 != NULL)
				t1->parent = _node;
	
			x->left = _node;
			_node->right = t1;
			//
			x->parent = _p_node;
			_node->parent = x;

            _node->height = max(Height(_node->left), Height(_node->right)) + 1;
            x->height = max(Height(x->left), Height(x->right)) + 1;
			return x;
		}

		pointer nMin(pointer r)
		{
			if (r->left == NULL)
				return r;
			return nMin(r->left);
		}
		pointer Delete_avl(pointer _root, const key_type _val)
		{
   				if (!_root)
                    return _root;
                if (compare_(_val, _root->data->first))
                    _root->left = Delete_avl(_root->left, _val);
                else if (compare_(_root->data->first, _val))
                    _root->right = Delete_avl(_root->right, _val);
                else
                {
                    if (!_root->left || !_root->right)
                    {
						pointer temp = NULL ;
						if (_root->left != NULL)
							temp = _root->left;
						else
							temp = _root->right;
                        
                        if (temp == NULL)
                        {
                            temp = _root;
                            _root = NULL;
                        }
                        else
                        {
                            alloc_pair_.destroy(_root->data);
                            alloc_pair_.construct(_root->data, *(temp->data));
                            _root->left = temp->left;
                            _root->right = temp->right;
                        }

                        destroy_avl_base(temp);
                    }
                    else
                    {
                        pointer     temp = nMin(_root->right);

                        alloc_pair_.destroy(_root->data);
                        alloc_pair_.construct(_root->data, *(temp->data));

                        _root->right = Delete_avl(_root->right, temp->data->first);
					}
                }
                if (_root == NULL)
                    return _root;
                _root->height = 1 + max(Height(_root->left), Height(_root->right)); // might still need it 
				int balance = getbalanceFactor(_root);
				if (balance == 2 && getbalanceFactor(_root->left) >= 0) // left heavy 
					return rightRotate(_root);
				else if (balance == 2 && getbalanceFactor(_root->left) == -1) // for left right rotation
				{
					_root->left = leftRotate(_root->left);
					return rightRotate(_root);
				}
				else if (balance == -2 && getbalanceFactor(_root->right) <= 0) // for right heavy
					return leftRotate(_root);
				else if (balance == -2 && getbalanceFactor(_root->right) == 1) //for right left rotation 
				{
					_root->right = rightRotate(_root->right);
					return leftRotate(_root);
				} 

                return _root;
			// if (r == NULL)
			// 	return r;
			// if (compare_(val, r->data->first))
			// 	r->left = Delete_avl(r->left, val);
			// else if (compare_(r->data->first, val))
			// 	r->right = Delete_avl(r->right, val);
			// else {
			// 	if (r->left == NULL)
			// 	{
			// 		pointer tmp = r->right;
			// 		alloc_pair_.destroy(r->data);
			// 		alloc_node.destroy(r);
			// 		alloc_pair_.deallocate(r->data, 1);
			// 		alloc_node.deallocate(r, 1);
			// 		// size_--;
			// 		return tmp;
			// 	}
			// 	else if (r->right == NULL)
			// 	{
			// 		pointer tmp = r->left;
			// 		alloc_pair_.destroy(r->data);
			// 		alloc_node.destroy(r);
			// 		alloc_pair_.deallocate(r->data, 1);
			// 		alloc_node.deallocate(r, 1);
			// 		// size_--;
			// 		return tmp;
			// 	}
			// 	else {
			// 		// here we need to traverse to the wanted node and find the nMIN node value in the right subtree and replacing 
			// 		// the value of the root
			// 		pointer tmp = nMin(r->right);
			// 		alloc_pair_.destroy(r->data);
			// 		alloc_pair_.construct(r->data, *(tmp->data));
			// 		r->right = Delete_avl(r->right, tmp->data->first);
			// 		size_--;
			// 	}
			// }
			// return r;
		}

		pointer	delete_p(const key_type val) 
		{
			root =  Delete_avl(root, val);
			return root;
		}
		pointer insert(const value_type &val)
		{
			root = insert_avl(root, val);
			return root;
		}
		pointer search_avl(pointer r, const key_type val) const
		{
			if (r == NULL  || r->data->first == val) 
				return r;
			else if (compare_(val, r->data->first))
				return search_avl(r->left, val);
			return search_avl(r->right, val); 
		}
		pointer	search(const key_type val) const
		{
			return search_avl(root, val);
		}
		pointer	begin() const //return the smallest node in this case
		{
			pointer tmp = root;
			if (tmp == NULL)
				return NULL;
			while (tmp && tmp->left)
				tmp = tmp->left;
			return tmp;
		}
		
		pointer end() const { // return the largest node in this case
			pointer tmp = root;
			if (tmp == NULL) return NULL;
			while (tmp && tmp->right)
				tmp = tmp->right;
			return tmp;
		}
		
		pointer		upper_bound(const key_type val) const { 
			pointer tmp = root;
			pointer r = NULL;

			while (tmp != NULL)
			{
				if (compare_(val, tmp->data->first))
				{
					r = tmp;
					tmp = tmp->left; 
				}
				else
					tmp = tmp->right;
			}
			return r;
		}
		
		pointer lower_bound(const key_type val) const { 
			pointer tmp = root;
			pointer r = NULL;
			while (tmp != NULL)
			{

				 if (compare_(tmp->data->first, val) == false )
				{
					r = tmp;
					tmp = tmp->left;
				}
				else
					tmp = tmp->right;
			}
			return r;
		}
		void	swap(_node_type ot)
		{
			_node_type tmp = ot;
			ot = root;
			root = tmp;
		}
		_node_type 		*root;
		size_t size_;
		private:
		alloc_type		alloc_node;
		alloc_pair		alloc_pair_;
		comp			compare_;
};

};
#endif