// Map.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <map>
#include <GameEngineDebug.h>

typedef int KeyType;
typedef int ValueType;

class GameEnginePair
{
public:
    KeyType first;
    ValueType second;
};

class GameEngineMap
{
private:
    class BinaryNode
    {
    public:
        BinaryNode* Parent = nullptr;
        BinaryNode* LeftChild = nullptr;
        BinaryNode* RightChild = nullptr;
        GameEnginePair Pair;

        BinaryNode* find(const KeyType& _Key)
        {
            if (Pair.first == _Key)
            {
                return this;
            }
            else if (Pair.first > _Key)
            {
                if (nullptr == LeftChild)
                {
                    return nullptr;
                }

                return LeftChild->find(_Key);
            }
            else if (Pair.first < _Key)
            {
                if (nullptr == RightChild)
                {
                    return nullptr;
                }

                return RightChild->find(_Key);
            }

            return nullptr;

        }

        void Insert(const GameEnginePair& _Pair)
        {
            if (Pair.first > _Pair.first)
            {
                if (nullptr == LeftChild)
                {
                    LeftChild = new BinaryNode();
                    LeftChild->Pair = _Pair;
                    LeftChild->Parent = this;
                    return;
                }

                return LeftChild->Insert(_Pair);
            }
            else if (Pair.first < _Pair.first)
            {
                if (nullptr == RightChild)
                {
                    RightChild = new BinaryNode();
                    RightChild->Pair = _Pair;
                    RightChild->Parent = this;
                    return;
                }

                RightChild->Insert(_Pair);
            }
            else
            {
                MessageBoxAssert("키가 겹치는 pair를 insert했습니다");
            }
        }

        void FirstOrder()
        {
            std::cout << Pair.first << std::endl;
            if (nullptr != LeftChild)
            {
                LeftChild->FirstOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->FirstOrder();
            }
        }

        // 후위 순회
        void LastOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->LastOrder();
            }
            if (nullptr != RightChild)
            {
                RightChild->LastOrder();
            }
            std::cout << Pair.first << std::endl;
        }

        // 중위 순회
        void MidOrder()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->MidOrder();
            }
            std::cout << Pair.first << std::endl;
            if (nullptr != RightChild)
            {
                RightChild->MidOrder();
            }
        }

        void clear()
        {
            if (nullptr != LeftChild)
            {
                LeftChild->clear();
            }
            if (nullptr != RightChild)
            {
                RightChild->clear();
            }
            delete this;
        }

    public:
        BinaryNode()
        {

        }
        ~BinaryNode()
        {
        }
    };

public:
    class iterator
    {
        friend GameEngineMap;

    private:
        BinaryNode* CurNode;

    public:
        bool operator==(const iterator& _Other)
        {
            return _Other.CurNode == CurNode;
        }

        bool operator!=(const iterator& _Other)
        {
            return _Other.CurNode != CurNode;
        }


        GameEnginePair* operator->()
        {
            if (nullptr == CurNode)
            {
                return nullptr;
            }

            return &CurNode->Pair;
        }


        iterator& operator++()
        {
            return *this;
        }
    };

public:
    GameEngineMap() {}
    ~GameEngineMap()
    {
        clear();
    }

    void insert(const GameEnginePair& _Pair)
    {
        if (nullptr == RootNode)
        {
            RootNode = new BinaryNode();
            RootNode->Pair = _Pair;
            return;
        }

        RootNode->Insert(_Pair);
    }

    iterator find(const KeyType& _Key)
    {
        if (nullptr == RootNode)
        {
            return end();
        }

        iterator NewIter;
        NewIter.CurNode = RootNode->find(_Key);
        return NewIter;
    }

    iterator end()
    {
        iterator NewIter;
        NewIter.CurNode = nullptr;
        return NewIter;
    }

    // 전위 순회
    void FirstOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->FirstOrder();
    }

    // 후위 순회
    void LastOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->LastOrder();
    }

    // 중위 순회
    void MidOrder()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->MidOrder();
    }

    void clear()
    {
        if (nullptr == RootNode)
        {
            return;
        }
        RootNode->clear();
    }


public:
    BinaryNode* RootNode = nullptr;
};

GameEnginePair make_pair(KeyType _Key, KeyType _Value)
{
    return { _Key , _Value };
}

int main()
{
    LeckCheck(); 

    {
        GameEngineMap DataMap;

        DataMap.insert(make_pair(10, 1));
        DataMap.insert(make_pair(2, 1));
        DataMap.insert(make_pair(5, 1));
        DataMap.insert(make_pair(7, 1));
        DataMap.insert(make_pair(8, 1));
        DataMap.insert(make_pair(3, 1));
        DataMap.insert(make_pair(20, 1));

        GameEngineMap::iterator FindIter = DataMap.find(99);

        if (FindIter != DataMap.end())
        {
            FindIter->first;
            FindIter->second;
        }

        /*std::cout << "전위 순회" << std::endl;
        DataMap.FirstOrder();
        std::cout << "후위 순회" << std::endl;
        DataMap.LastOrder();
        std::cout << "중위 순회" << std::endl;
        DataMap.MidOrder();*/
    }
}
