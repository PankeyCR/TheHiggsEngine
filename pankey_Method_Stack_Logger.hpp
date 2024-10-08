
#ifndef pankey_Method_Stack_Logger_hpp
#define pankey_Method_Stack_Logger_hpp

#include "pankey_Logger_position.hpp"
#include "pankey_String.hpp"
#include "PrimitiveRawList.hpp"
#include "System.hpp"
#include "PrintableList.hpp"

namespace pankey{

PrimitiveRawList<pankey_String> g_log_method_stack_catcher;
PrimitiveRawList<PrimitiveRawList<pankey_String>> g_log_method_stack_checker;

template<class... T>
void addStackChecker(T... a_stack){
	PrimitiveRawList<pankey_String> i_stack;
	i_stack.addPack(a_stack...);
	g_log_method_stack_checker.add(i_stack);
}
pankey_String stackName(pankey_String a_class, pankey_String a_method){
	return "[" + a_class + " , " + a_method + "]";
}
	
template<class T>
void Stack_LogPrint_(void* a_log_pointer, int a_location, const pankey_String& a_name, const pankey_String& a_method, const pankey_String& a_type, T a_mns){

	if(a_location == pankey_Log_StartMethod){
		pankey_String i_stack = stackName(a_name,a_method);
		g_log_method_stack_catcher.add(i_stack);
		return;
	}
	if(a_location == pankey_Log_EndMethod && !g_log_method_stack_catcher.isEmpty()){
		pankey_String i_stack = stackName(a_name,a_method);
		g_log_method_stack_catcher.remove(i_stack);
		return;
	}
	if(a_location == pankey_Log_EndMethod && g_log_method_stack_catcher.isEmpty()){
		System::console.println("error on logger");
	}

	if(g_log_method_stack_catcher.isEmpty()){
		//System::console.println("g_log_method_stack_catcher.isEmpty()");
		return;
	}

	bool i_print_log = false;

	for(int x = 0; x < g_log_method_stack_checker.getPosition(); x++){
		//System::console.println("start");
		PrimitiveRawList<pankey_String>* f_list = g_log_method_stack_checker.getByPosition(x);
		if(f_list == nullptr){
			continue;
		}
		int f_catcher_x = g_log_method_stack_catcher.getPosition() - 1;
		bool f_print_log = true;

		for(int x = f_list->getPosition() - 1; x >= 0; x--){
			pankey_String* f_catcher_string = g_log_method_stack_catcher.getByPosition(f_catcher_x);
			f_catcher_x--;
			pankey_String* f_checker_string = f_list->getByPosition(x);
			if(f_catcher_string == nullptr || f_checker_string == nullptr){
				continue;;
			}
			//System::console.print(*f_catcher_string);
			//System::console.println(*f_checker_string);
			if(*f_catcher_string != *f_checker_string){
				//System::console.println("*f_catcher_string != *f_checker_string");
				f_print_log = false;
				break;
			}
		}
		if(f_print_log){
			//System::console.println("f_print_log");
			i_print_log = true;
			break;
		}
	}
	if(!i_print_log){
		//System::console.println("!i_print_log");
		return;
	}

	#ifdef pankey_SystemFullLog
		System::console.print("Method Stack: ");
		System::console.println(PrintableList<PrimitiveRawList<pankey_String>,pankey_String>(g_log_method_stack_catcher,false));
		System::console.print("Loggin class: ");
		System::console.print(a_name);
		System::console.print(" - Method: ");
		System::console.print(a_method);
		System::console.print(" - Location: ");
		System::console.print(a_location);
		System::console.print(" - Log: ");
		System::console.println(a_mns);
	#elif defined(pankey_Arduino_Log)
		Serial.print("Method Stack: ");
		Serial.println(PrintableList<PrimitiveRawList<pankey_String>,pankey_String>(g_log_method_stack_catcher,false));
		Serial.console.print("Loggin class: ");
		Serial.console.print(a_name);
		Serial.console.print(" - Method: ");
		Serial.console.print(a_method);
		Serial.console.print(" - Location: ");
		Serial.console.print(a_location);
		Serial.console.print(" - Log: ");
		Serial.console.println(a_mns);
	#endif
}
	
}

#endif 

