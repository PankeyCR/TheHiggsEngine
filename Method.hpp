
/*
*
*	Method Functionality:
*	1. utility = method that helps the class do something but doesnt contain any variable of the class
*	2. polimorfic = is intended to be inheret to another class
*	3. unit = method that has a single and basic function, cant be reduce to smaller functions
*	4. contruct = method that helps create the basic functionality of the class
*	5. reduce = method that is compose of methods of the same class that reduces the complexity of the code
*	6. reductive = method that encapsulates a part of the logic of the class to reduce complexity and size of the code
*
*/

#ifndef Method_hpp
#define Method_hpp

#include "RawPointerList.hpp"

#include "Parameter.hpp"
#include "MethodType.hpp"
#include "MethodReturn.hpp"

namespace pankey{

class Method{
	public:
		Method(){}
		Method(const Method& a_method){
			methodClass = a_method.methodClass;
			m_type = a_method.m_type;
		}
		Method(cppObjectClass* cls, MethodType i_type){
			methodClass = cls;
			m_type = i_type;
		}
		virtual ~Method(){}
		
		virtual void setName(char* a_name){
			m_name = a_name;
		}
		
		virtual char* getName(){
			return m_name;
		}
		
		template<class T, class R, class... Args>
		R invoke(T* a_instance, Args... args){
			R i_return = MethodReturn<R>::getReturn();
			// if(m_type == MethodType::Method){
			// 	return MethodMap<Args...>::invoke(methodClass, args...);
			// }
			// if(m_type == MethodType::MethodReturn){
			// 	return MethodReturnMap<R,Args...>::invoke(methodClass, i_return, args...);
			// }
			// if(m_type == MethodType::ClassMethod){
			// 	return ClassMethodMap<T,Args...>::invoke(a_instance, methodClass, args...);
			// }
			// if(m_type == MethodType::ClassMethodReturn){
			// 	return ClassMethodReturnMap<T,R,Args...>::invoke(a_instance, methodClass, i_return, args...);
			// }
			// if(m_type == MethodType::ObjectMethod){
			// 	return ObjectMethodMap<T,Args...>::invoke(a_instance, methodClass, args...);
			// }
			// if(m_type == MethodType::ObjectMethodReturn){
			// 	return ObjectMethodReturnMap<T,R,Args...>::invoke(a_instance, methodClass, i_return, args...);
			// }
			return i_return;
		}
		
		virtual MethodType getMethodType(){
			return m_type;
		}
		
		virtual Method operator=(const Method& a_method){
			methodClass = a_method.methodClass;
			m_type = a_method.m_type;
			return *this;
		}
		virtual bool operator==(const Method& a_method){
			return 	methodClass == a_method.methodClass &&
					m_type == a_method.m_type;
		}
		virtual bool operator!=(const Method& a_method){
			return 	methodClass != a_method.methodClass &&
					m_type != a_method.m_type;
		}

		virtual RawPointerList<Parameter>* getParameters(){return nullptr;}

		virtual cppObjectClass* getClass(){return methodClass;}
		virtual bool instanceof(cppObjectClass* cls){return false;}
			
	protected:
		cppObjectClass* methodClass = nullptr;
		MethodType m_type = MethodType::Method;
		char* m_name = nullptr;
};

}

#endif