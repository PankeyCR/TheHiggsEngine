
#ifndef AppState_hpp
#define AppState_hpp
#define AppState_AVAILABLE

#include "Class.hpp"

namespace ame{

class AppState : public cppObject{
    public:
		virtual ~AppState(){}
		virtual void initialize(Application *app){}
		virtual void onEnable(){}
		virtual void onDisable(){}
		virtual void setId(Note i){
			id = i;
		}
		virtual Note getId(){
			return id;
		}
		virtual void update(float tpc){}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<AppState>::classType || cppObject::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<AppState>::classType;}
		
		virtual void operator=(AppState b){}
		virtual bool operator==(AppState b){
				return this->getClass() == b.getClass();
		}
		virtual bool operator!=(AppState b){
				return this->getClass() != b.getClass();
		}
	protected:
		Note id = "";
};

}

#endif
