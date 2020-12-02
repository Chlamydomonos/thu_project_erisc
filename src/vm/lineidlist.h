#ifndef LINEIDLIST_H
#define LINEIDLIST_H

namespace erisc
{
	class LineId;
}

namespace vm
{
	/**
	* @brief �����б�ʶ�б��õĺ�����ڵ�
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
	* @brief �б�ʶ�б�����ֱ�������硰a["xxx"]������ʽ��ȡ�б�ʶ�б�a����Ϊxxx���б�ʶ
	*/
	class LineIdList
	{
	public:
		LineIdList();
		~LineIdList();

		/**
		* @brief ���б�ʶ�б������һ���б�ʶ
		* @param id Ҫ��ӵ��б�ʶ
		*/
		void add(erisc::LineId* id);

		/**
		* @brief ���ص�[]�����
		* @param name Ҫ���ҵ��б�ʶ����
		* @return ���ƶ�Ӧ���б�ʶ
		*/
		erisc::LineId* operator[](const char* name);
	private:
		RBTreeNode* root;
	};
}

#endif // !LINEIDLIST_H
