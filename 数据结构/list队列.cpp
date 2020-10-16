#include <iostream>
#include <assert.h>
using namespace std;

class MyQueue
{
public:
	class Node
	{
	public:
		int data;	//����
		Node *next; //ָ��
		Node()		//��ʼ��һ���ڵ��õ�
		{
			data = -1;
			next = nullptr;
		}
	};
	using Node_P = Node *;
	Node *start;
	int length;
	Node_P *END;   //���������������ָ���
	bool IsEmpty() //�ж���������Ƿ�Ϊ��
	{
		if (start == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void push(int item) //��ʵ��Ҳ������
	{
		if (IsEmpty()) //�����������ǿյ�
		{
			start = new Node;
			END = &start; //���ݵ���start�ı���
			(*END)->data = item;
			END = &((*END)->next); //END����ȡ���һ���ڵ��next�ĵ�ַ
			length++;
		}
		else //������ǿյ�
		{
			*END = new Node; //����ռ�
			(*END)->data = item;
			END = &((*END)->next); //�����������������β��
			length++;
		}
	}
	void pop() //����Ӧ��������
	{
		if (IsEmpty())
		{
			cout << "errror" << endl;
		}
		else //˵��start!=nullptr
		{
			Node_P *temp = &start;
			start = start->next;
			delete *temp; //ɾ���������ָ��Ķ���
			assert(start != nullptr);
			length--;
		}
	}
	int top()
	{
		if (IsEmpty())
		{
			cout << "errror" << endl;
			return -1;
		}
		else
		{
			assert(start != nullptr);
			int bottom = start->data;
			assert(bottom != -1);
			return bottom;
		}
	}
	int size()
	{
		return length;
	}
	MyQueue(Node_P start_ = nullptr, Node_P *END_ = nullptr, int length_ = 0) : start(start_), END(END_), length(length_) //��δ�����ô��д���캯��?
	{
	}
	~MyQueue()
	{
		if (start != nullptr)
		{
			while (IsEmpty()) //�����е�Ԫ���ͷŵ�
			{
				pop();
			}
		}
		if (END != nullptr)
		{
			delete END;
		}
	}
};

int main()
{
	MyQueue q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << q.top() << endl;
	cout << q.top() << endl;
	cout << q.size() << endl;
	cout << "code is over" << endl;
	return 0;
}