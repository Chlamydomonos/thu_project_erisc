#include "lineidlist.h"

using erisc::LineId;
using vm::RBTreeNode;

const char* exceptionHead = "Line identifier \"";
const char* exceptionTail = "\"does not exist";

vm::RBTreeNode::RBTreeNode(erisc::LineId* value, RBTreeNode* father)
{
	this->value = value;
	this->father = father;
	leftChild = nullptr;
	rightChild = nullptr;
	isLeftChild = value < father->value;
	if (isLeftChild)
		father->leftChild = this;
	else
		father->rightChild = this;

	red = true;
	refresh();
}

vm::RBTreeNode::~RBTreeNode()
{
	delete value;
	if (leftChild != nullptr)
		delete leftChild;
	if (rightChild != nullptr)
		delete rightChild;
}

void vm::RBTreeNode::reColor()
{
	red = !red;
}

vm::RBTreeNode* vm::RBTreeNode::getBrother()
{
	return isLeftChild ? father->rightChild : father->leftChild;
}

vm::RBTreeNode* vm::RBTreeNode::getGrandfather()
{
	return father->father;
}

vm::RBTreeNode* vm::RBTreeNode::getUncle()
{
	return father->isLeftChild ? getGrandfather()->rightChild : getGrandfather()->leftChild;
}

void vm::RBTreeNode::spinLeft()
{
}

void vm::RBTreeNode::spinRight()
{
}

void vm::RBTreeNode::refresh()
{
	red = true;
	if (father == nullptr)
	{
		red = false;
	}
	else if (father->red)
	{
		if (getUncle() != nullptr && getUncle()->red)
		{
			father->red = false;
			getUncle()->red = false;
			getGrandfather()->refresh();
		}
		else
		{
			if (father->isLeftChild)
			{
				if (isLeftChild)
				{
					father->red = false;
					getGrandfather()->red = true;
					getGrandfather()->spinRight();
				}
				else
				{
					father->spinLeft();
					father->refresh();
				}
			}
			else
			{
				if (!isLeftChild)
				{
					father->red = false;
					getGrandfather()->red = true;
					getGrandfather()->spinLeft();
				}
				else
				{
					father->spinRight();
					father->refresh();
				}
			}
		}
	}
}

vm::RBTreeNode* findFrom(vm::RBTreeNode* root, const char* name)
{
	if (root == nullptr)
	{
		int headLen = strlen(exceptionHead);
		int nameLen = strlen(name);
		int tailLen = strlen(exceptionTail);
		int len = headLen + nameLen + tailLen + 1;
		char* message = new char[len];
		for (int i = 0; i < headLen; i++)
			message[i] = exceptionHead[i];
		for (int i = headLen; i < headLen + nameLen; i++)
			message[i] = name[i - headLen];
		for (int i = headLen + nameLen; i < len - 1; i++)
			message[i] = exceptionTail[i - headLen - nameLen];
		message[len - 1] = 0;
		Exception e(message);
		throw e;
	}
	if (LineId::strBigger(name, root->value->getName()))
		return findFrom(root->rightChild, name);
	else if (LineId::strSmaller(name, root->value->getName()))
		return findFrom(root->leftChild, name);
	else
		return root;
}

vm::RBTreeNode* findFrom(vm::RBTreeNode* root, erisc::LineId* id)
{
	try
	{
		if (*id == *root->value)
			return nullptr;
		else if (*id < *root->value)
		{
			if (root->leftChild == nullptr)
				return root;
			return findFrom(root->leftChild, id);
		}
		else
		{
			if (root->rightChild == nullptr)
				return root;
			return findFrom(root->rightChild, id);
		}
	}
	catch (Exception& e)
	{
		throw e;
	}
}

vm::LineIdList::LineIdList()
{
	root = nullptr;
}

vm::LineIdList::~LineIdList()
{
	if (root != nullptr)
		delete root;
}

void vm::LineIdList::add(erisc::LineId* id)
{
	try
	{
		RBTreeNode* father = findFrom(root, id);
		RBTreeNode* temp = new RBTreeNode(id, father);
	}
	catch (Exception& e)
	{
		throw e;
	}
}

erisc::LineId* vm::LineIdList::operator[](const char* name)
{
	RBTreeNode* idNode;
	try
	{
		idNode = findFrom(root, name);
	}
	catch (Exception& e)
	{
		throw e;
	}
	return idNode->value;
}
