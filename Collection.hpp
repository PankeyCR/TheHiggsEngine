
#ifndef Collection_hpp
	#define Collection_hpp

	#include "Member.hpp"

	#ifdef Collection_LogApp
		#include "pankey_Logger.hpp"
		#define CollectionLog(location,method,type,mns) pankey_Log((void*)this,location,"Collection",method,type,mns)
	#else
		#define CollectionLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H, class M>
		class Collection{
			public:

				virtual ~Collection(){
					CollectionLog(pankey_Log_StartMethod, "Destructor", "println", "");
					CollectionLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual bool isEmpty()const=0;

				virtual int length()const{
					CollectionLog(pankey_Log_StartMethod, "length", "println", "");
					CollectionLog(pankey_Log_EndMethod, "length", "println", "");
					return this->m_length;
				}
				
				virtual int getSize()const=0;

				virtual bool replace(int a_index_1, int a_index_2)=0;

				virtual Member<H,M> getByPointer(const Member<H,M>& a_value)const=0;

				virtual Member<H,M> get(int x)const=0;

				virtual bool containByPointer(const Member<H,M>& a_value)const=0;
				
				virtual int getIndexByPointer(const Member<H,M>& a_value)const=0;
				
				virtual bool removeByPointer(const Member<H,M>& a_value)=0;
				
				virtual Member<H,M> remove(int a_index)=0;
				
				virtual bool removeFirstIndex(int a_amount)=0;

				virtual bool removeLastIndex(int a_amount)=0;

				virtual bool removePart(int a_index, int a_amount)=0;
				
				virtual bool removeFirst()=0;

				virtual bool removeLast()=0;
				
				virtual bool clear()=0;

				virtual bool isInOrder()const=0;

				virtual void setReorder(bool a_reorder)=0;
				
				virtual void reorder()=0;
				
			protected:
				
				virtual void incrementPosition(){
					CollectionLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
					this->m_length++;
					CollectionLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
				}
				virtual void decrementPosition(){
					CollectionLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
					this->m_length--;
					if(this->m_length < 0){
						this->m_length = 0;
					}
					CollectionLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
				}
				
				virtual void incrementPosition(int a_size){
					CollectionLog(pankey_Log_StartMethod, "incrementPosition", "println", "");
					this->m_length += a_size;
					CollectionLog(pankey_Log_EndMethod, "incrementPosition", "println", "");
				}
				virtual void decrementPosition(int a_size){
					CollectionLog(pankey_Log_StartMethod, "decrementPosition", "println", "");
					this->m_length -= a_size;
					if(this->m_length < 0){
						this->m_length = 0;
					}
					CollectionLog(pankey_Log_EndMethod, "decrementPosition", "println", "");
				}

			public:
			
				virtual bool operator<(int x) const{
					CollectionLog(pankey_Log_StartMethod, "operator<", "println", "");
					CollectionLog(pankey_Log_EndMethod, "operator<", "println", "");
					return this->length() < x;
				}
				
				virtual bool operator>(int x) const{
					CollectionLog(pankey_Log_StartMethod, "operator>", "println", "");
					CollectionLog(pankey_Log_EndMethod, "operator>", "println", "");
					return this->length() > x;
				}
				
				virtual bool operator<=(int x) const{
					CollectionLog(pankey_Log_StartMethod, "operator<=", "println", "");
					CollectionLog(pankey_Log_EndMethod, "operator<=", "println", "");
					return this->length() <= x;
				}
				
				virtual bool operator>=(int x) const{
					CollectionLog(pankey_Log_StartMethod, "operator>=", "println", "");
					CollectionLog(pankey_Log_EndMethod, "operator>=", "println", "");
					return this->length() >= x;
				}
				
				virtual bool operator==(int x) const{
					CollectionLog(pankey_Log_StartMethod, "operator==", "println", "");
					CollectionLog(pankey_Log_EndMethod, "operator==", "println", "");
					return this->length() == x;
				}
				
				virtual bool operator!=(int x) const{
					CollectionLog(pankey_Log_StartMethod, "operator!=", "println", "");
					CollectionLog(pankey_Log_EndMethod, "operator!=", "println", "");
					return this->length() != x;
				}
			
			protected:
				int m_length = 0;
		};

	}

#endif