
#ifndef LinkedListNode_h
#define LinkedListNode_h

namespace ame{

template <class T>
class LinkedListNode{
	private:
	
    public:
		LinkedListNode* last = nullptr;
		T* actual = nullptr;
		LinkedListNode* next = nullptr;
		
		LinkedListNode<T>(){
		}
		
		~LinkedListNode<T>(){
		}
};

}

#endif 
