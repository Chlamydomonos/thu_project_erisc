#ifndef LINEIDLIST_H
#define LINEIDLIST_H

namespace erisc
{
	//Ϊ����ͷ�ļ��������ã���������LineId
	class LineId;
	//Ϊ����ͷ�ļ��������ã���������Param
	struct Param;
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
		* @brief ���ص�[]�������ͨ�����Ʋ��Ҷ�Ӧ���б�ʶ
		* @param name Ҫ���ҵ��б�ʶ����
		* @return ���ƶ�Ӧ���б�ʶ
		*/
		erisc::LineId* operator[](const char* name);

		/**
		* @brief ���ص�[]�������ͨ������������Ҷ�Ӧ���б�ʶ
		* @param name Ҫ���ҵ��б�ʶ��Ӧ�Ĳ���
		* @return ������Ӧ���б�ʶ
		*/
		erisc::LineId* operator[](erisc::Param* id);
	private:
		RBTreeNode* root;
	};
}

#endif // !LINEIDLIST_H
