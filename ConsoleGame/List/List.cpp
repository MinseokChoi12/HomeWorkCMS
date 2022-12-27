#include <iostream>
#include <list>
#include <vector>
#include <GameEngineDebug.h>

// 1. 릭없애오세요 
// 2. push_front 만들어 오세요.

typedef int DataType;

class GameEngineList
{

private:
	class ListNode
	{
	public:
		ListNode* Front = nullptr;
		ListNode* Back = nullptr;
		DataType Value;



	public:
		ListNode() {}
		~ListNode() {}
	};

public:
	class iterator
	{
		friend GameEngineList;

	private:
		ListNode* CurNode;

	public:
		iterator& operator++()
		{
			CurNode = CurNode->Back;
			return *this;
		}

		DataType& operator*() const noexcept
		{
			return CurNode->Value;
		}

		bool operator!=(const iterator _Iter) const noexcept
		{
			return _Iter.CurNode != CurNode;
		}

	};


public:
	GameEngineList()
	{
		FrontNode = new ListNode();
		BackNode = new ListNode();

		FrontNode->Back = BackNode;
		BackNode->Front = FrontNode;
	}

	// constrcuter destructer
	GameEngineList(size_t _Count)
	{
	}

	~GameEngineList()
	{
		clear(this);

		delete BackNode;
		BackNode = nullptr;

		delete FrontNode;
		FrontNode = nullptr;
	}


	// delete Function
	GameEngineList(const GameEngineList& _Other) = delete;
	GameEngineList(GameEngineList&& _Other) noexcept
	{

	}
	GameEngineList& operator=(GameEngineList&& _Other) noexcept = delete;

	size_t size()
	{
		return DataSize;
	}

	iterator begin()
	{
		iterator Return = iterator();
		Return.CurNode = FrontNode->Back;
		return Return;
	}

	iterator end()
	{
		iterator Return = iterator();
		Return.CurNode = BackNode;
		return Return;
	}

	void erase(const iterator& Iter)
	{
		ListNode* Node = Iter.CurNode;

		if (BackNode == Node || FrontNode == Node)
		{
			return;
		}

		if (nullptr == Node)
		{
			return;
		}

		ListNode* DeleteFrontNode = Node->Front;
		ListNode* DeleteBackNode = Node->Back;

		delete Node;
		Node = nullptr;

		DeleteFrontNode->Back = DeleteBackNode;
		DeleteBackNode->Front = DeleteFrontNode;


		return;
	}

	void clear(GameEngineList* _list)
	{
		ListNode* NextNode = _list->FrontNode->Back;
		if (_list->DataSize ==0)
			return;

		NextNode = NextNode->Back;
		delete NextNode->Front;
		NextNode->Front = _list->FrontNode;
		_list->FrontNode->Back = NextNode;

		--_list->DataSize;

		clear(_list);
	}

	void push_back(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* FrontNode = BackNode->Front;
		FrontNode->Back = NewNode;
		BackNode->Front = NewNode;

		NewNode->Front = FrontNode;
		NewNode->Back = BackNode;

		++DataSize;

	}

	void push_front(const DataType& _Data)
	{
		ListNode* NewNode = new ListNode();
		NewNode->Value = _Data;

		ListNode* BackNode = FrontNode->Back;
		BackNode->Front = NewNode;
		FrontNode->Back = NewNode;

		NewNode->Front = FrontNode;
		NewNode->Back = BackNode;

		++DataSize;
	}

	void resize(size_t _Count)
	{
	}


private:
	size_t DataSize = 0;
	ListNode* FrontNode = nullptr;
	ListNode* BackNode = nullptr;
};


int main()
{
	LeckCheck();

	/*std::cout << "stdList" << std::endl;
	{
		std::list<size_t> IntList = std::list<size_t>();


		for (size_t i = 0; i < 10; i++)
		{
			IntList.push_front(i);
			std::cout << "Size" << IntList.size() << std::endl;
		}

		{
			std::list<size_t>::iterator StartIter = IntList.begin();
			std::list<size_t>::iterator EndIter = IntList.end();
			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}

			int a = 0;
		}
	}
	
	std::cout << std::endl;
	std::cout << std::endl;

	*/

	
	std::cout << "myList" << std::endl;

	{
		GameEngineList IntList = GameEngineList();


		for (size_t i = 0; i < 5; i++)
		{
			IntList.push_back(i);
			std::cout << "Size" << IntList.size() << std::endl;
		}

		for (size_t i = 0; i < 5; i++)
		{
			IntList.push_front(i);
			std::cout << "Size" << IntList.size() << std::endl;
		}


		/*{
			GameEngineList::iterator StartIter = IntList.begin();

			++StartIter;

			IntList.erase(StartIter);
		}*/

		{
			GameEngineList::iterator StartIter = IntList.begin();
			GameEngineList::iterator EndIter = IntList.end();

			for (; StartIter != EndIter; ++StartIter)
			{
				std::cout << *StartIter << std::endl;
			}
		}
	}
}
