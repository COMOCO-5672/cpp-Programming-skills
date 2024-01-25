#include <iostream>
#include <vector>

template<typename T, std::size_t BlockSize = 10>
class ObjectPool
{
public:
    ObjectPool()
    {
        allocateBlock();
    }

    ~ObjectPool()
    {
        for (auto block: blocks) {
            delete[] block;
        }
    }

    T *allocate()
    {
        if (freeList == nullptr) {
            allocateBlock();
        }

        T *object = freeList;
        freeList = freeList->next;
        return object;
    }

    void deallocate(T *object)
    {
        object->next = freeList;
        freeList = object;
    }

private:
    struct Block
    {
        T *data;
        Block *next;
    };

    void allocateBlock()
    {
        T *new_block = new T[BlockSize];
        Block *block_header = new Block { new_block, nullptr };
        blocks.push_back(block_header);

        for (std::size_t i = 1; i < BlockSize; ++i) {
            new_block[i - 1].next = &new_block[i];
        }

        new_block[BlockSize - 1].next = nullptr;
        freeList = new_block;
    }

    std::vector<Block *> blocks;
    T *freeList;
};

class MyClass
{
public:
    MyClass() : data(0), next(nullptr)
    { }

public:
    int data;
    int data2;
    int data3;
    int data4;
    int data5;
    int data6;
    int data7;
    int data8;
    MyClass *next;
};

int main()
{
    ObjectPool<MyClass> objectPool;

    MyClass *obj1 = objectPool.allocate();
    MyClass *obj2 = objectPool.allocate();

    obj1->data = 42;
    obj2->data = 99;

    std::cout << obj1->data << std::endl;
    std::cout << obj2->data << std::endl;

    objectPool.deallocate(obj1);
    objectPool.deallocate(obj2);
    return 0;
}



