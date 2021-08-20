
#ifndef Entity_h
#define Entity_h

#include "Arduino.h"
#include "cppObject.h"
#include "GameObject.h"
#include "Map.h"
#include "PrimitiveList.h"
#include "PrimitiveMap.h"

namespace ame{

class Entity : public GameObject{
    protected:
		Map<String,cppObject>* data = nullptr;
	
    public:
		
		Entity();
		Entity(int idEntity);
		virtual ~Entity();
		
		virtual void setData(String name, cppObject* obj);
		virtual cppObject* getData(String name);
		
		virtual cppObjectClass* getClass();
		virtual String toString();
};

}

#endif 
