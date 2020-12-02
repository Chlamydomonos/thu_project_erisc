#ifndef LINEIDLIST_H
#define LINEIDLIST_H

namespace erisc
{
	class LineId;
}

namespace vm
{
	/**
	* @brief 创建行标识列表用的红黑树节点
	*/
	struct RBTreeNode
	{
		bool red;
		bool isLeftChild;
		erisc::LineId* value;
		RBTreeNode* father;
		RBTreeNode* leftChild;
		RBTreeNode* rightChild;
		RBTreeNode(erisc::LineId* value, RBTreeNode* father);
		~RBTreeNode();
		void reColor();
		RBTreeNode* getBrother();
		RBTreeNode* getGrandfather();
		RBTreeNode* getUncle();
		void spinLeft();
		void spinRight();
		void refresh();
	};

	/**
	* @brief 行标识列表，可以直接用形如“a["xxx"]”的形式获取行标识列表a中名为xxx的行标识
	*/
	class LineIdList
	{
	public:
		LineIdList();
		~LineIdList();

		/**
		* @brief 向行标识列表中添加一个行标识
		* @param id 要添加的行标识
		*/
		void add(erisc::LineId* id);

		/**
		* @brief 重载的[]运算符
		* @param name 要查找的行标识名称
		* @return 名称对应的行标识
		*/
		erisc::LineId* operator[](const char* name);
	private:
		RBTreeNode* root;
	};
}

#endif // !LINEIDLIST_H
