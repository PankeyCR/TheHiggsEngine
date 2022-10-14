
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialListenerState)
	#define SerialListenerState_hpp
#endif

#ifndef SerialListenerState_hpp
#define SerialListenerState_hpp
#define SerialListenerState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "BaseAppState.hpp"
#include "Application.hpp"
#include "PrimitiveMap.hpp"
#include "PrimitiveList.hpp"
#include "SerialListener.hpp"

#ifdef SerialListenerState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	#include "MemoryRam.hpp"
	
	#define SerialListenerStateLog(location,method,type,mns) ame_Log(this,location,"SerialListenerState",method,type,mns)
	#define const_SerialListenerStateLog(location,method,type,mns) 
	#define StaticSerialListenerStateLog(pointer,location,method,type,mns) ame_Log(pointer,location,"SerialListenerState",method,type,mns)
#else
	#ifdef SerialListenerState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		#include "MemoryRam.hpp"
		
		#define SerialListenerStateLog(location,method,type,mns) ame_LogDebug(this,location,"SerialListenerState",method,type)
		#define const_SerialListenerStateLog(location,method,type,mns) 
		#define StaticSerialListenerStateLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"SerialListenerState",method,type)
	#else
		#define SerialListenerStateLog(location,method,type,mns) 
		#define const_SerialListenerStateLog(location,method,type,mns) 
		#define StaticSerialListenerStateLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

template<class T>
class SerialListenerState : public BaseAppState{	
    public:
		using ListenerMethod = void (*)(T*);
		
		SerialListenerState(){
			SerialListenerStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			SerialListenerStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		SerialListenerState(Note c_name){
			SerialListenerStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->setId(c_name);
			SerialListenerStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		SerialListenerState(Note c_name, ListenerMethod c_method){
			SerialListenerStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			m_methodListener.add(c_method);
			this->setId(c_name);
			SerialListenerStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~SerialListenerState(){
			SerialListenerStateLog(ame_Log_StartMethod, "Destructor", "println", "");
			SerialListenerStateLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void addListener(Command<T>* mnsCmd){
			SerialListenerStateLog(ame_Log_StartMethod, "addListener",  "println", "Command<T>* mnsCmd");
			m_listener.addPointer(mnsCmd);
			SerialListenerStateLog(ame_Log_EndMethod, "addListener", "println", "");
		}
		
		virtual void addListener(ListenerMethod method){
			SerialListenerStateLog(ame_Log_StartMethod, "addListener",  "println", "ListenerMethod method");
			m_methodListener.add(method);
			SerialListenerStateLog(ame_Log_EndMethod, "addListener", "println", "");
		}
		
		virtual Command<T>* getListener(cppObjectClass* cls){
			SerialListenerStateLog(ame_Log_StartMethod, "getListener",  "println", "");
			for(int x = 0; x < m_listener.getPosition(); x++){
				Command<T>* serialListener = m_listener.getByPosition(x);
				if(serialListener->getClass() == cls){
					SerialListenerStateLog(ame_Log_EndMethod, "getListener", "println", "");
					return serialListener;
				}
			}
			SerialListenerStateLog(ame_Log_EndMethod, "getListener", "println", "");
			return nullptr;
		}

		virtual void removeListener(int index) {
			SerialListenerStateLog(ame_Log_StartMethod, "removeListener",  "println", "int index");
			SerialListenerStateLog(ame_Log_Statement, "removeListener",  "println", ame_String("index: ") + ame_String(index));
			m_listener.removeDeleteByPosition(index);
			SerialListenerStateLog(ame_Log_EndMethod, "removeListener", "println", "");
		}

		virtual void removeAllListener() {
			SerialListenerStateLog(ame_Log_StartMethod, "removeAllListener",  "println", "");
			m_listener.resetDelete();
			m_methodListener.resetDelete();
			SerialListenerStateLog(ame_Log_EndMethod, "removeAllListener", "println", "");
		}

		virtual void removeAllCommandListener() {
			SerialListenerStateLog(ame_Log_StartMethod, "removeAllCommandListener",  "println", "");
			m_listener.resetDelete();
			SerialListenerStateLog(ame_Log_EndMethod, "removeAllCommandListener", "println", "");
		}

		virtual void removeAllMethodListener() {
			SerialListenerStateLog(ame_Log_StartMethod, "removeAllMethodListener",  "println", "");
			m_methodListener.resetDelete();
			SerialListenerStateLog(ame_Log_EndMethod, "removeAllMethodListener", "println", "");
		}
		
		virtual void addMail(T* m){
			m_receivedMessage.addPointer(m);
		}
		
		virtual PrimitiveList<T> getMail(){
			return m_receivedMessage;
		}
		
		virtual List<T>* getMailLocker(){
			return &m_receivedMessage;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<SerialListenerState<T>>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialListenerState<T>>::getClass() || AppState::instanceof(cls);
		}
		
		virtual void update(float tpc){
			if(m_receivedMessage.isEmpty()){
				return;
			}
			SerialListenerStateLog(ame_Log_StartMethod, "update",  "println", "");
			for(int x = 0; x < m_receivedMessage.getPosition(); x++){
				SerialListenerStateLog(ame_Log_Statement, "update",  "println", ame_String("receivedMessage index: ") + ame_String(x));
				T* f_message = m_receivedMessage.getByPosition(x);
				for(int y = 0; y < m_methodListener.getPosition(); y++){
					ListenerMethod  event = *m_methodListener.getByPosition(y);
					event(f_message);
				}
				for(int y = 0; y < m_listener.getPosition(); y++){
					Command<T>*  event = m_listener.getByPosition(y);
					event->execute(f_message);
				}
			}
			m_receivedMessage.resetDelete();
			SerialListenerStateLog(ame_Log_EndMethod, "update",  "println", "");
		}
		
	protected:
		PrimitiveList<T> m_receivedMessage;
		
		PrimitiveList<Command<T>> m_listener;
		PrimitiveList<ListenerMethod> m_methodListener;
};

}

#endif