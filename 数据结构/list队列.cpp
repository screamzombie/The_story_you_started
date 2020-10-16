#include <iostream>
#include <assert.h>
using namespace std;

class MyQueue
{
public:
	class Node
	{
	public:
		int data;	//数据
		Node *next; //指针
		Node()		//初始化一个节点用的
		{
			data = -1;
			next = nullptr;
		}
	};
	using Node_P = Node *;
	Node *start;
	int length;
	Node_P *END;   //这个才是用来操纵指针的
	bool IsEmpty() //判断这个队列是否为空
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
	void push(int item) //其实你也有问题
	{
		if (IsEmpty()) //如果这个队列是空的
		{
			start = new Node;
			END = &start; //操纵的是start的本体
			(*END)->data = item;
			END = &((*END)->next); //END重新取最后一个节点的next的地址
			length++;
		}
		else //如果不是空的
		{
			*END = new Node; //分配空间
			(*END)->data = item;
			END = &((*END)->next); //而你才是真正操作队尾的
			length++;
		}
	}
	void pop() //问题应该在这里
	{
		if (IsEmpty())
		{
			cout << "errror" << endl;
		}
		else //说明start!=nullptr
		{
			Node_P *temp = &start;
			start = start->next;
			delete *temp; //删掉的是这个指针的东西
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
	MyQueue(Node_P start_ = nullptr, Node_P *END_ = nullptr, int length_ = 0) : start(start_), END(END_), length(length_) //这次打算怎么重写构造函数?
	{
	}
	~MyQueue()
	{
		if (start != nullptr)
		{
			while (IsEmpty()) //把所有的元素释放掉
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