
/*
*	position = total of chars in the string
*	size = total size of the array
*	length = total of chars before the endValue()
*
*
*	position = length
*
*/
#include "ame_Enviroment.hpp"

#ifndef DISABLE_Note_hpp
#define DISABLE_Note_hpp
	#if defined(DISABLE_Note)
		#define Note_hpp

		#ifdef ame_Windows
			typedef std::string Note;
		#endif

		#ifdef ame_ArduinoIDE
			typedef String Note;
		#endif
	#endif
#endif

#ifndef Note_hpp
#define Note_hpp
#define Note_AVAILABLE

#include "cppObject.hpp"
#include "Array.hpp"

#ifdef ame_Windows
	#include "ame_Printable.hpp"
	#include "ame_Print.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
	#include "IPAddress.h"
#endif

#include "NoteIterator.hpp"

#include "PrimitiveRawList.hpp"
#include "PrimitiveRawMap.hpp"

#include "ame_Byte.hpp"

#define ame_BINARY 0
#define ame_HEXADECIMAL 1
#define ame_DECIMAL 2

#ifdef Note_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define NoteLog(location,method,type,mns) ame_Log((void*)this,location,"Note",method,type,mns)
	#define const_NoteLog(location,method,type,mns) ame_Log((void*)this,location,"Note",method,type,mns)
	#define StaticNoteLog(pointer,location,method,type,mns) ame_Log(pointer,location,"Note",method,type,mns)
#else
	#ifdef Note_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define NoteLog(location,method,type,mns) ame_LogDebug((void*)this,location,"Note",method,type)
		#define const_NoteLog(location,method,type,mns) ame_LogDebug((void*)this,location,"Note",method,type)
		#define StaticNoteLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"Note",method,type)
	#else
		#define NoteLog(location,method,type,mns)
		#define const_NoteLog(location,method,type,mns)
		#define StaticNoteLog(pointer,location,method,type,mns)
	#endif
#endif


namespace ame{

class Note : public Array<char>, public Printable{
    public:
		Note(){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "Default Constructor");
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const char* c_char){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const char* c_char");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "Constructor", "println", c_char);
			int i_array_length = this->arrayLength(c_char);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(c_char, i_array_length);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const Array<char>& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const Array<char>& source");
			int i_array_length = source.length();
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(source.pointer(), i_array_length);
				this->copyEndValue(this->getPosition());
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const Note& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const Note& val");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Note:");
			NoteLog(ame_Log_Statement, "Constructor", "println", source.pointer());
			int i_array_length = source.length();
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			if(i_array_length > 0){
				this->createArray(i_array_length);
				this->copyPointer(source.pointer(), i_array_length);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(Note&& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "Note&& source");
			int i_array_length = source.getPosition();
			if(i_array_length > 0){
				this->m_pos = source.m_pos;
				this->m_size = source.m_size;
				this->m_t_value = source.m_t_value;
				source.m_t_value = nullptr;
				source.m_pos = 0;
				source.m_size = 0;
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const bool& i){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const bool& i");
			NoteLog(ame_Log_Statement, "Constructor", "println", "bool:");
			NoteLog(ame_Log_Statement, "Constructor", "println", i);
			this->createArray(1);
			this->copyValue(i ? '1' : '0');
			this->copyEndValue(this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", 1);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const char& c_char){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const char& c_char");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Char:");
			NoteLog(ame_Log_Statement, "Constructor", "println", c_char);
			this->createArray(1);
			this->copyValue(c_char);
			this->copyEndValue(this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", 1);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const int& c_int){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const int& c_int");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Int:");
			NoteLog(ame_Log_Statement, "Constructor", "println", c_int);
			int i_array_length = intCharSize(c_int);
			this->createArray(i_array_length);
			this->copyInt(c_int, i_array_length, 0, this->m_t_value, true);
			this->copyEndValue();
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const long& c_long){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const long& c_long");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Long:");
			NoteLog(ame_Log_Statement, "Constructor", "println", c_long);
			int i_array_length = longCharSize(c_long);
			this->createArray(i_array_length);
			this->copyLong(c_long, i_array_length, 0, this->m_t_value, true);
			this->copyEndValue(this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const float& c_float){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const float& c_float");
			NoteLog(ame_Log_Statement, "Constructor", "println", "Float:");
			NoteLog(ame_Log_Statement, "Constructor", "println", c_float);
			int i_array_length = floatCharSize(c_float, 4);
			this->createArray(i_array_length);
			this->copyFloat(c_float, i_array_length, 0, 4, this->m_t_value, true);
			this->copyEndValue();
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "Constructor", "println", i_array_length);
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "Constructor", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "Constructor", "println", this->getSize());
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		#ifdef ame_ArduinoIDE
/*
		Note(const ame_Byte& c_byte){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const byte& i");
			this->m_pos = byteCharSize(ame_DECIMAL, c_byte);
			this->m_size = getAvailableSize(this->m_pos);

			this->m_t_value = this->create(this->m_size);
			byteToCharPointer(c_byte, this->m_pos, 0, this->m_t_value, ame_DECIMAL, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", this->m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", this->m_size);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		Note(const ame_Byte& c_byte, int a_type){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			NoteLog(ame_Log_Statement, "Constructor", "println", "const byte& c_byte, int a_type");
			this->m_pos = byteCharSize(a_type, c_byte);
			this->m_size = getAvailableSize(this->m_pos);

			this->m_t_value = this->create(this->m_size);
			byteToCharPointer(c_byte, this->m_pos, 0, this->m_t_value, a_type, true);
			NoteLog(ame_Log_Statement, "Constructor", "println", this->m_pos);
			NoteLog(ame_Log_Statement, "Constructor", "println", this->m_size);
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
*/
		Note(const String& source){
			NoteLog(ame_Log_StartMethod, "Constructor", "println", "const String& source");
			NoteLog(ame_Log_Statement, "Constructor", "println", "String:");
			NoteLog(ame_Log_Statement, "Constructor", "println", source);
			if(source != ""){
				int i_pos = source.length();
				this->createArray(i_pos);
				this->copyPointer(source.c_str(), i_pos);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "Constructor", "println", this->m_pos);
				NoteLog(ame_Log_Statement, "Constructor", "println", this->m_size);
				NoteLog(ame_Log_Statement, "Constructor", "println", this->m_t_value);
			}
			NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		}

		// Note(String&& source){
			// NoteLog(ame_Log_StartMethod, "Constructor", "println", "start");
			// NoteLog(ame_Log_Statement, "Constructor", "println", "String&& source");
			// if(!source.isEmpty()){
				// this->m_t_value = source.c_str();
				// source.c_str() = nullptr;
			// }
			// NoteLog(ame_Log_EndMethod, "Constructor", "println", "");
		// }

		#endif

		virtual ~Note(){
			NoteLog(ame_Log_StartMethod, "Destructor", "println", "");
			NoteLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual char* pointer()const{
			NoteLog(ame_Log_StartMethod, "pointer", "println", "");
			ArrayLog(ame_Log_Statement, "pointer", "println", "Pointer: ");
			ArrayLog(ame_Log_Statement, "pointer", "println", this->m_t_value);
			ArrayLog(ame_Log_EndMethod, "pointer", "println", "");
			return this->m_t_value;
		}

		virtual bool hasEndValue()const{
			const_NoteLog(ame_Log_StartMethod, "hasEndValue", "println", "");
			const_NoteLog(ame_Log_EndMethod, "hasEndValue", "println", "");
			return true;
		}

		virtual char endValue()const{
			const_NoteLog(ame_Log_StartMethod, "endValue", "println", "");
			const_NoteLog(ame_Log_EndMethod, "endValue", "println", "");
            return '\0';
		}

		virtual size_t printTo(Print& p) const{
			const_NoteLog(ame_Log_StartMethod, "printTo", "println", "");
			if(this->isEmpty()){
                const_NoteLog(ame_Log_EndMethod, "printTo", "println", "");
				return 0;
			}
			size_t i_size = 0;
			char i_endValue = this->endValue();
			for(int x = 0; x < this->getPosition(); x++){
				char f_value = this->m_t_value[x];
                if(f_value == i_endValue){
					const_NoteLog(ame_Log_EndMethod, "printTo", "println", "f_value == i_endValue");
                    const_NoteLog(ame_Log_EndMethod, "printTo", "println", "index: ");
                    const_NoteLog(ame_Log_EndMethod, "printTo", "println", x);
                    break;
                }
				p.print(f_value);
				i_size += sizeof(f_value);
			}
			const_NoteLog(ame_Log_EndMethod, "printTo", "println", "");
			return i_size;
		}

		virtual int length(void) const{
			const_NoteLog(ame_Log_StartMethod, "length", "println", "");
			int i_length = this->arrayLength(this->m_t_value);
			if(i_length <= 0){
				const_NoteLog(ame_Log_EndMethod, "length", "println", "");
				return 0;
			}
			const_NoteLog(ame_Log_EndMethod, "length", "println", "");
			return i_length;
		}

		virtual int getAvailableSize(int a_pos){
			NoteLog(ame_Log_StartMethod, "getAvailableSize", "println", "");
			NoteLog(ame_Log_EndMethod, "getAvailableSize", "println", "");
			return a_pos + 1;
		}

		virtual char* create(int a_size){
			NoteLog(ame_Log_StartMethod, "create", "println", "");
			NoteLog(ame_Log_EndMethod, "create", "println", "");
			return new char[a_size];
		}

		virtual int intCharSize(int a_value)const{
			const_NoteLog(ame_Log_StartMethod, "intCharSize", "println", "");
			const_NoteLog(ame_Log_Statement, "intCharSize", "println", "");
			int i_size_val = 0;
			int x = 1;
			int add_x = 0;
			if(a_value < 0){
				a_value *= -1;
				add_x++;
			}
			for( ; x < 100; x++){
				int expn = 1;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}
				if(a_value/expn < 1){
					i_size_val = x;
					break;
				}
			}
			const_NoteLog(ame_Log_EndMethod, "intCharSize", "println", "");
			return i_size_val + add_x;
		}

		virtual void copyInt(int value, int size, int start, char* chr, bool end){
			NoteLog(ame_Log_StartMethod, "intToCharPointer", "println", "");
			NoteLog(ame_Log_Statement, "intToCharPointer", "println", "");
			if(chr == nullptr){
				NoteLog(ame_Log_EndMethod, "intToCharPointer", "println", "");
				return;
			}
			int position = start;
			bool isNegative = false;
			if(value < 0){
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "negative value");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "Position: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", position);
				isNegative = true;
				value *= -1;
				size--;
				chr[position] = 45;
				position++;
			}
			int i_value_reduction = 1;
			int i_reduce_value = 1;
			int i_output_value = 1;
			for(int x = 0; x < size; x++){
				int exponent = 1;
				for(int y = 0; y < size - x - 1; y++){
					exponent *= 10;
				}
				i_value_reduction = value / exponent;
				if(x == 0){
					i_output_value = i_value_reduction;
				}else{
					i_output_value = i_value_reduction - i_reduce_value;
				}
				i_reduce_value = i_value_reduction * 10;
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "exponent: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", exponent);
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "value reduction: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", i_value_reduction);
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "reduce value: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", i_reduce_value);
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "output value: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", i_output_value);
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "Position: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", position);
				chr[position] = i_output_value + 48;
				position++;
			}
			if(end){
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "Adding end value: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", "Position: ");
				NoteLog(ame_Log_Statement, "intToCharPointer", "println", position);
				chr[position] = '\0';
			}
			this->incrementPosition(position);
			NoteLog(ame_Log_EndMethod, "intToCharPointer", "println", "");
		}
		
		virtual char* getInt(int a_value){
			NoteLog(ame_Log_StartMethod, "getInt", "println", "");
			int i_array_length = intCharSize(a_value);
			char* i_pointer = this->createArrayClone(i_array_length);
			this->copyInt(a_value, i_array_length, 0, i_pointer, true);
			this->copyExternEndValue(i_pointer, i_array_length);
			NoteLog(ame_Log_EndMethod, "getInt", "println", "");
			return i_pointer;
		}

		virtual int longCharSize(long value)const{
			const_NoteLog(ame_Log_StartMethod, "longCharSize", "println", "");
			const_NoteLog(ame_Log_Statement, "longCharSize", "println", "");
			int i_size_val = 0;
			int x = 1;
			int add_x = 0;
			if(value < 0){
				value *= -1;
				add_x++;
			}
			for( ; x < 100; x++){
				long expn = 1;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}
				if(value/expn < 1){
					i_size_val = x;
					break;
				}
			}
			const_NoteLog(ame_Log_EndMethod, "longCharSize", "println", "");
			return i_size_val + add_x;
		}

		virtual void copyLong(long value, int size, int start, char* chr, bool end){
			const_NoteLog(ame_Log_StartMethod, "longToCharPointer", "println", "");
			const_NoteLog(ame_Log_Statement, "longToCharPointer", "println", "~Note");
			if(chr == nullptr){
				const_NoteLog(ame_Log_EndMethod, "longToCharPointer", "println", "");
				return;
			}
			int position = start;
			bool isNegative = false;
			if(value < 0){
				isNegative = true;
				value *= -1;
				size--;
				chr[position] = 45;
				position++;
			}
			long n_value = 1;
			long r_value = 1;
			long s_value = 1;
			for(int x = 0; x < size; x++){
				long expn = 1;
				for(int y = 0; y < size - x - 1; y++){
					expn *= 10;
				}
				n_value = value / expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				chr[position] = s_value + 48;
				position++;
			}
			if(end){
				chr[position] = '\0';
			}
			this->incrementPosition(size);
			const_NoteLog(ame_Log_EndMethod, "longToCharPointer", "println", "");
		}
		
		virtual char* getLong(long a_value){
			NoteLog(ame_Log_StartMethod, "getInt", "println", "");
			int i_array_length = intCharSize(a_value);
			char* i_pointer = this->createArrayClone(i_array_length);
			this->copyInt(a_value, i_array_length, 0, i_pointer, true);
			this->copyExternEndValue(i_pointer, i_array_length);
			NoteLog(ame_Log_EndMethod, "getInt", "println", "");
			return i_pointer;
		}

		virtual int floatCharSize(float value,int extra){
			const_NoteLog(ame_Log_StartMethod, "floatCharSize", "println", "");
			const_NoteLog(ame_Log_Statement, "floatCharSize", "println", "");
			int i_size_val = 0;
			int x = 1;
			int add_x = 0;
			if(value < 0){
				value *= -1;
				add_x++;
			}
			for( ; x < 100; x++){
				int expn = 1;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}
				if(value/expn < 1){
					i_size_val = x;
					break;
				}
			}
			const_NoteLog(ame_Log_EndMethod, "floatCharSize", "println", "");
			return i_size_val + add_x + extra + 1;
		}

		virtual void copyFloat(float value, int total_size, int start, int decimal_size, char* chr, bool end){
			const_NoteLog(ame_Log_StartMethod, "floatToCharPointer", "println", "");
			const_NoteLog(ame_Log_Statement, "floatToCharPointer", "println", "");
			if(chr == nullptr){
				const_NoteLog(ame_Log_EndMethod, "floatToCharPointer", "println", "");
				return;
			}
			int position = start;
			bool isNegative = false;
			if(value < 0){
				isNegative = true;
				value *= -1;
				total_size--;
				chr[position] = 45;
				position++;
			}
			int n_value = 1;
			int r_value = 1;
			int s_value = 1;
			int i_size = total_size - decimal_size - 1;
			for(int x = 0; x < i_size; x++){
				int expn = 1;
				for(int y = 0; y < i_size - x - 1; y++){
					expn *= 10;
				}
				n_value = value / expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				chr[position] = s_value + 48;
				position++;
			}

			chr[position] = 46;
			position++;

			n_value = 1;
			r_value = 1;
			s_value = 1;
			float i_value = value - (int)value;
			for(int x = 0; x < decimal_size; x++){
				int expn = 10;
				for(int y = 0; y < x; y++){
					expn *= 10;
				}
				n_value = i_value * expn;
				if(x == 0){
					s_value = n_value;
				}else{
					s_value = n_value - r_value;
				}
				r_value = n_value * 10;
				chr[position] = s_value + 48;
				position++;
			}
			if(end){
				chr[position] = '\0';
			}
			this->incrementPosition(total_size);
			const_NoteLog(ame_Log_EndMethod, "floatToCharPointer", "println", "");
		}
		
		virtual char* getFloat(float a_value){
			NoteLog(ame_Log_StartMethod, "getInt", "println", "");
			int i_array_length = intCharSize(a_value);
			char* i_pointer = this->createArrayClone(i_array_length);
			this->copyInt(a_value, i_array_length, 0, i_pointer, true);
			this->copyExternEndValue(i_pointer, i_array_length);
			NoteLog(ame_Log_EndMethod, "getInt", "println", "");
			return i_pointer;
		}

		virtual void fix(){
			if(this->getPosition() == this->getSize()){
				return;
			}
			for(int x = this->getPosition(); x < this->getSize(); x++){
				if(x == this->getSize() - 1){
					this->set(x, this->endValue());
				}else{
					this->set(x, ' ');
				}
			}
		}

		virtual Note addNote(const Note& a_note){
			NoteLog(ame_Log_StartMethod, "addNote", "println", "const Note& a_note");
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addNote", "println", "");
			return i_note.addLocal(a_note);
		}

		virtual Note addLocalNote(const Note& a_note){
			NoteLog(ame_Log_StartMethod, "addLocalNote", "println", "const Note& a_note");
			NoteLog(ame_Log_EndMethod, "addLocalNote", "println", "");
			return this->insertLocal(this->getPosition(), a_note);
		}

		virtual Note insertLocalNote(int a_position, const Note& a_note){
			NoteLog(ame_Log_StartMethod, "insertLocalNote", "println", "const Note& a_note");
			int i_array_length = a_note.length();
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", i_array_length);
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", this->getSize());
			if(this->isEmpty()){
				this->createArray(i_array_length);
			}
			
			if(a_position < this->getPosition()){
				int totalSize = a_position;
				
				int first_position_1 = a_position;
				int first_position_2 = a_position;
				
				int middle_position_1 = i_array_length;
				int middle_position_2 = i_array_length;
				
				int last_position_1 = a_position;
				int last_position_2 = a_position;
				
				char* i_pointer = this->createArrayClone(totalSize);
				char* t_pointer = this->pointer();
				this->copyExternPointer(i_pointer, this->pointer(), first_position_1, first_position_2);
				this->copyExternPointer(i_pointer, a_note.pointer(), middle_position_1, middle_position_2);
				this->copyExternPointer(i_pointer, this->pointer(), last_position_1, last_position_2);
				
				NoteLog(ame_Log_EndMethod, "insertLocalNote", "println", "");
				return *this;
			}
			
			this->expandIfNeeded(i_array_length);
			
			this->copyPointer(a_note.pointer(), i_array_length);
			this->copyEndValue();
			
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "insertLocalNote", "println", this->getSize());
			NoteLog(ame_Log_EndMethod, "insertLocalNote", "println", "");
			return *this;
		}
/*
		virtual Note addChar(const char& a_char){
			NoteLog(ame_Log_StartMethod, "addChar", "println", "const char* a_char");
			NoteLog(ame_Log_Statement, "addChar", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "addChar", "println", a_char);
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addChar", "println", "");
			return i_note.addLocalChar(a_char);
		}
/*
		virtual Note addLocalChar(const char& a_char){
			NoteLog(ame_Log_StartMethod, "addLocalChar", "println", "const char* a_char");
			NoteLog(ame_Log_Statement, "addLocalChar", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "addLocalChar", "println", a_char);
			NoteLog(ame_Log_EndMethod, "addLocalChar", "println", "");
			return this->insertLocalChar(this->getPosition(), a_char);
		}

		virtual Note insertLocalChar(int a_position, const char& a_char){/*
			NoteLog(ame_Log_StartMethod, "insertLocalChar", "println", "const char* a_char");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", a_char);
			int i_array_length = this->arrayLength(a_char);
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", i_array_length);
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getSize());
			if(this->isEmpty()){
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", "this->isEmpty()");
				this->createArray(i_array_length);
				this->copyPointer(a_char, i_array_length);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "insertLocalChar", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			
			if(a_position >= this->getPosition()){
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", "a_position >= this->getPosition()");
				this->copyPointer(a_char, i_array_length);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "insertLocalChar", "println", "");
				return *this;
			}
			
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "insertLocalChar", "println", this->getSize());
			
			NoteLog(ame_Log_EndMethod, "insertLocalChar", "println", "");
			return *this;
		}
*/
		virtual Note addCharPointer(const char* a_char){
			NoteLog(ame_Log_StartMethod, "addCharPointer", "println", "const char* a_char");
			NoteLog(ame_Log_Statement, "addCharPointer", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "addCharPointer", "println", a_char);
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addCharPointer", "println", "");
			return i_note.addLocal(a_char);
		}

		virtual Note addLocalCharPointer(const char* a_char){
			NoteLog(ame_Log_StartMethod, "addLocalCharPointer", "println", "const char* a_char");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", a_char);
			NoteLog(ame_Log_EndMethod, "addLocalCharPointer", "println", "");
			return this->insertLocalCharPointer(this->getPosition(), a_char);
		}

		virtual Note insertLocalCharPointer(int a_position, const char* a_char){
			NoteLog(ame_Log_StartMethod, "addLocalCharPointer", "println", "const char* a_char");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Char Array:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", a_char);
			int i_array_length = this->arrayLength(a_char);
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Length:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", i_array_length);
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getSize());
			if(this->isEmpty()){
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "this->isEmpty()");
				this->createArray(i_array_length);
				this->copyPointer(a_char, i_array_length);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "addLocalCharPointer", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			
			if(a_position >= this->getPosition()){
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "a_position >= this->getPosition()");
				this->copyPointer(a_char, i_array_length);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "addLocalCharPointer", "println", "");
				return *this;
			}
			
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Position:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getPosition());
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", "Array Size:");
			NoteLog(ame_Log_Statement, "addLocalCharPointer", "println", this->getSize());
			
			NoteLog(ame_Log_EndMethod, "addLocalCharPointer", "println", "");
			return *this;
		}
		
		virtual Note addInt(const int& a_number){
			NoteLog(ame_Log_StartMethod, "addInt", "println", "const int& a_number");
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addInt", "println", "");
			return i_note.addLocalInt(a_number);
		}

		virtual Note addLocalInt(const int& a_number){
			NoteLog(ame_Log_StartMethod, "addLocalInt", "println", "const int& a_number");
			NoteLog(ame_Log_EndMethod, "addLocalInt", "println", "");
			return this->insertLocalInt(this->getPosition(), a_number);
		}

		virtual Note insertLocalInt(int a_position, const int& a_number){
			NoteLog(ame_Log_StartMethod, "insertLocalInt", "println", "const int& a_number");
			int i_array_length = intCharSize(a_number);
			if(this->isEmpty()){
				this->createArray(i_array_length);
				this->copyInt(a_number, i_array_length, 0, this->m_t_value, true);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "insertLocalInt", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "insertLocalInt", "println", i_array_length);
				NoteLog(ame_Log_Statement, "insertLocalInt", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "insertLocalInt", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalInt", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "insertLocalInt", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "insertLocalInt", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			if(a_position >= this->getPosition()){
				this->copyInt(a_number, i_array_length, this->getPosition(), this->m_t_value, true);
				this->copyEndValue();
				NoteLog(ame_Log_EndMethod, "insertLocalInt", "println", "");
				return *this;
			}
			
			NoteLog(ame_Log_EndMethod, "insertLocalInt", "println", "");
			return *this;
		}
		
		virtual Note addFloat(const float& a_number){
			NoteLog(ame_Log_StartMethod, "addFloat", "println", "const float& a_number");
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addFloat", "println", "");
			return i_note.addLocalFloat(a_number);
		}

		virtual Note addLocalFloat(const float& a_number){
			NoteLog(ame_Log_StartMethod, "addLocalFloat", "println", "const float& a_number");
			NoteLog(ame_Log_EndMethod, "addLocalFloat", "println", "");
			return this->insertLocalFloat(this->getPosition(), a_number);
		}

		virtual Note insertLocalFloat(int a_position, const float& a_number){
			NoteLog(ame_Log_StartMethod, "insertLocalFloat", "println", "const float& a_note");
			int i_array_length = floatCharSize(a_number, 4);
			if(this->isEmpty()){
				this->createArray(i_array_length);
				this->copyFloat(a_number, i_array_length, 0, 4, this->m_t_value, true);
				this->copyEndValue();
				NoteLog(ame_Log_Statement, "insertLocalFloat", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "insertLocalFloat", "println", i_array_length);
				NoteLog(ame_Log_Statement, "insertLocalFloat", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "insertLocalFloat", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalFloat", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "insertLocalFloat", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "insertLocalFloat", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			if(a_position >= this->getPosition()){
				this->copyFloat(a_number, i_array_length, 0, 4, this->m_t_value, true);
				this->copyEndValue();
				NoteLog(ame_Log_EndMethod, "insertLocalFloat", "println", "");
				return *this;
			}
			
			this->copyFloat(a_number, i_array_length, 0, 4, this->m_t_value, true);
			this->copyEndValue();
			NoteLog(ame_Log_EndMethod, "insertLocalFloat", "println", "");
			return *this;
		}
		
		virtual Note addLong(const long& a_number){
			NoteLog(ame_Log_StartMethod, "addLong", "println", "const long& a_number");
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addLong", "println", "");
			return i_note.addLocalLong(a_number);
		}

		virtual Note addLocalLong(const long& a_number){
			NoteLog(ame_Log_StartMethod, "addLocalLong", "println", "const long& a_number");
			NoteLog(ame_Log_EndMethod, "addLocalLong", "println", "");
			return this->insertLocalLong(this->getPosition(), a_number);
		}

		virtual Note insertLocalLong(int a_position, const long& a_number){
			NoteLog(ame_Log_StartMethod, "insertLocalLong", "println", "const long& a_note");
			int i_array_length = longCharSize(a_number);
			if(this->isEmpty()){
				this->createArray(i_array_length);
				this->copyLong(a_number, i_array_length, 0, this->m_t_value, true);
				this->copyEndValue(this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalLong", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "insertLocalLong", "println", i_array_length);
				NoteLog(ame_Log_Statement, "insertLocalLong", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "insertLocalLong", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalLong", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "insertLocalLong", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "insertLocalLong", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			if(a_position >= this->getPosition()){
				this->copyLong(a_number, i_array_length, 0, this->m_t_value, true);
				this->copyEndValue(this->getPosition());
				NoteLog(ame_Log_EndMethod, "insertLocalLong", "println", "");
				return *this;
			}
			
			NoteLog(ame_Log_EndMethod, "insertLocalLong", "println", "");
			return *this;
		}
		
		virtual Note addBool(const bool& a_number){
			NoteLog(ame_Log_StartMethod, "addBool", "println", "const bool& a_number");
			Note i_note = *this;
			NoteLog(ame_Log_EndMethod, "addBool", "println", "");
			return i_note.addLocalBool(a_number);
		}

		virtual Note addLocalBool(const bool& a_number){
			NoteLog(ame_Log_StartMethod, "addLocalBool", "println", "const bool& a_number");
			NoteLog(ame_Log_EndMethod, "addLocalBool", "println", "");
			return this->insertLocalBool(this->getPosition(), a_number);
		}

		virtual Note insertLocalBool(int a_position, const bool& a_number){
			NoteLog(ame_Log_StartMethod, "insertLocalBool", "println", "const bool& a_note");
			int i_array_length = 1;
			if(this->isEmpty()){
				this->createArray(i_array_length);
				this->copyValue(a_number ? '1' : '0');
				this->copyEndValue(this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalBool", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "insertLocalBool", "println", i_array_length);
				NoteLog(ame_Log_Statement, "insertLocalBool", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "insertLocalBool", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "insertLocalBool", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "insertLocalBool", "println", this->getSize());
				NoteLog(ame_Log_EndMethod, "insertLocalBool", "println", "");
				return *this;
			}
			this->expandIfNeeded(i_array_length);
			
			if(a_position >= this->getPosition()){
				this->copyValue(a_number ? '1' : '0');
				this->copyEndValue(this->getPosition());
				NoteLog(ame_Log_EndMethod, "insertLocalBool", "println", "");
				return *this;
			}
			
			NoteLog(ame_Log_EndMethod, "insertLocalBool", "println", "");
			return *this;
		}

		Note subNote(int start){
			NoteLog(ame_Log_StartMethod, "subNote", "println", "");
			
			if(this->isEmpty()){
				NoteLog(ame_Log_StartMethod, "subNote", "println", "this->isEmpty()");
				return Note();
			}
			
			int t_size = this->length();
			int s_size = t_size - start;
			NoteLog(ame_Log_StartMethod, "subNote", "println", "subNote size");
			NoteLog(ame_Log_StartMethod, "subNote", "println", s_size);
			char* buff = this->createArrayClone(s_size);
			
			char* i_array = this->pointer();

			for(int x = start; x < t_size; x++){
				buff[x - start] = i_array[x];
			}
			this->copyExternEndValue(buff, s_size);

			Note note = buff;
			delete[] buff;

			NoteLog(ame_Log_EndMethod, "subNote", "println", "");
			return note;
		}

		Note subNote(int start, int end){
			NoteLog(ame_Log_StartMethod, "subNote", "println", "");
			
			if(this->isEmpty()){
				NoteLog(ame_Log_StartMethod, "subNote", "println", "this->isEmpty()");
				return Note();
			}
			
			int t_size = this->length();
			int s_size = t_size - start;
			
			if(end < t_size){
				s_size -= t_size - end;
				t_size = end;
			}
			
			NoteLog(ame_Log_StartMethod, "subNote", "println", "subNote size");
			NoteLog(ame_Log_StartMethod, "subNote", "println", s_size);
			char* buff = this->createArrayClone(s_size);
			
			char* i_array = this->pointer();

			for(int x = start; x < t_size; x++){
				buff[x - start] = i_array[x];
			}
			this->copyExternEndValue(buff, s_size);

			Note note = buff;
			delete[] buff;
			
			NoteLog(ame_Log_EndMethod, "subNote", "println", "");
			return note;
		}

		virtual char charAt(int x) const{
			NoteLog(ame_Log_StartMethod, "charAt", "println", "");
			if(this->isEmpty() || x >= this->getPosition()){
				NoteLog(ame_Log_EndMethod, "operator=", "println", "");
				return -1;
			}
			NoteLog(ame_Log_EndMethod, "charAt", "println", "");
			return this->m_t_value[x];
		}

		virtual bool isNumber(char a_char) const{
			NoteLog(ame_Log_StartMethod, "isNumber", "println", "");
			NoteLog(ame_Log_EndMethod, "isNumber", "println", "");
			return a_char > 47 && a_char < 58;
		}

		virtual int getNumber(char a_char) const{
			NoteLog(ame_Log_StartMethod, "isNumber", "println", "");
			NoteLog(ame_Log_EndMethod, "isNumber", "println", "");
			return a_char - 48;
		}

		virtual bool isDecimalPoint(char a_char) const{
			NoteLog(ame_Log_StartMethod, "isNumber", "println", "");
			NoteLog(ame_Log_EndMethod, "isNumber", "println", "");
			return a_char == 46;
		}

		int toInt(){
			NoteLog(ame_Log_StartMethod, "toInt", "println", "");
			int output = 0;
			int c_size = this->length();
			bool lastDecimals = false;
			for(int x = 0; x < c_size; x++){
				if(this->m_t_value[x] == 46){
					if(lastDecimals){
						// Serial.println("m_string[x] == 46 && lastDecimals");
						// Serial.print("position ");Serial.println(x);
						NoteLog(ame_Log_EndMethod, "toInt", "println", "");
						return 0;
					}
					// Serial.println("m_string[x] == 46");
					// Serial.print("position ");Serial.println(x);
					int expn = 10;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output /= expn;
					lastDecimals = true;
					continue;
				}
				if(this->isNumber(this->m_t_value[x])){
					if(lastDecimals){
						// Serial.println("m_string[x] > 47 && m_string[x] < 58 && lastDecimals");
						// Serial.print("position ");Serial.println(x);
						continue;
					}
					// Serial.println("m_string[x] > 47 && m_string[x] < 58");
					// Serial.print("position ");Serial.println(x);
					int expn = 1;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output += (this->m_t_value[x] - 48) * expn;
				}else{
					// Serial.println("else");
					// Serial.print("position ");Serial.println(x);
					NoteLog(ame_Log_EndMethod, "toInt", "println", "");
					return 0;
				}
			}
			NoteLog(ame_Log_EndMethod, "toInt", "println", "");
			return output;
		}
		
		long toLong(){
			NoteLog(ame_Log_StartMethod, "toLong", "println", "");
			long output = 0;
			int c_size = this->length();
			bool lastDecimals = false;
			for(int x = 0; x < c_size; x++){
				if(this->m_t_value[x] == 46){
					if(lastDecimals){
						NoteLog(ame_Log_EndMethod, "toLong", "println", "");
						return 0;
					}
					long expn = 10;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output /= expn;
					lastDecimals = true;
					continue;
				}
				if(this->isNumber(this->m_t_value[x])){
					if(lastDecimals){
						continue;
					}
					long expn = 1;
					for(int y = 0; y < c_size - x - 1; y++){
						expn *= 10;
					}
					output += (this->m_t_value[x] - 48) * expn;
				}else{
					NoteLog(ame_Log_EndMethod, "toLong", "println", "");
					return 0;
				}
			}
			NoteLog(ame_Log_EndMethod, "toLong", "println", "");
			return output;
		}
		
		float toFloat(){
			NoteLog(ame_Log_StartMethod, "toFloat", "println", "");
			float output = 0;
			int c_size = this->length();
			bool lastDecimals = false;
			int d_pos = 0;
			int decimalCount = 0;
			int endDecimal = 2;
			for(int x = 0; x < c_size; x++){
				char f_char = this->m_t_value[x];
				if(this->isDecimalPoint(f_char)){
					if(lastDecimals){
						NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
						return 0;
					}
					float exponent = 10;
					for(int y = 0; y < c_size - x - 1; y++){
						exponent *= 10;
					}
					output /= exponent;
					lastDecimals = true;
					d_pos = x;
					continue;
				}
				if(this->isNumber(f_char)){
					int expsize = c_size - x - 1;
					if(lastDecimals){
						expsize = x - d_pos;
						decimalCount++;
					}
					// Serial.print("expsize ");Serial.println(expsize);
					float exponent = 1;
					for(int y = 0; y < expsize; y++){
						exponent *= 10;
					}
					if(lastDecimals){
						// Serial.println("divide");
						output += this->getNumber(f_char) / exponent;
					}else{
						// Serial.println("mult");
						output += this->getNumber(f_char) * exponent;
					}
					NoteLog(ame_Log_EndMethod, "toFloat", "println", "exponent: ");
					NoteLog(ame_Log_EndMethod, "toFloat", "println", exponent);
					NoteLog(ame_Log_EndMethod, "toFloat", "println", "output: ");
					NoteLog(ame_Log_EndMethod, "toFloat", "println", output);
					if(decimalCount >= endDecimal){
						NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
						return output;
					}
				}else{
					// Serial.println("else");
					// Serial.print("position ");Serial.println(x);
					NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
					return 0;
				}
			}
			NoteLog(ame_Log_EndMethod, "toFloat", "println", "");
			return output;
		}

		RawList<Note>* split(char a_char, RawList<Note>* a_list) const{
			const_NoteLog(ame_Log_StartMethod, "split", "println", "");
			if(a_list == nullptr){
				return nullptr;
			}
			Note i_note;
			for(int x = 0; x < this->getPosition(); x++){
				const_NoteLog(ame_Log_Statement, "split", "println", "iteration: ");
				const_NoteLog(ame_Log_Statement, "split", "println", x);
				const char f_char = this->m_t_value[x];
				const_NoteLog(ame_Log_Statement, "split", "println", "char: ");
				const_NoteLog(ame_Log_Statement, "split", "println", f_char);
				const_NoteLog(ame_Log_Statement, "split", "println", "i_note: ");
				const_NoteLog(ame_Log_Statement, "split", "println", i_note);
				if(f_char == a_char){
					const_NoteLog(ame_Log_Statement, "split", "println", "f_char == a_char");
					const_NoteLog(ame_Log_Statement, "split", "println", "i_note: ");
					const_NoteLog(ame_Log_Statement, "split", "println", i_note);
					a_list->add(i_note);
					i_note = "";
					const_NoteLog(ame_Log_Statement, "split", "println", "end for loop");
					continue;
				}
				i_note.addLocal(f_char);
				const_NoteLog(ame_Log_Statement, "split", "println", "i_note: ");
				const_NoteLog(ame_Log_Statement, "split", "println", i_note);
				if(x == this->getPosition() - 1){
					const_NoteLog(ame_Log_Statement, "split", "println", "x == this->getPosition() - 1");
					const_NoteLog(ame_Log_Statement, "split", "println", "i_note: ");
					const_NoteLog(ame_Log_Statement, "split", "println", i_note);
					a_list->add(i_note);
				}
				const_NoteLog(ame_Log_Statement, "split", "println", "end for loop");
			}
			const_NoteLog(ame_Log_EndMethod, "split", "println", "");
			return a_list;
		}

		virtual char getLastChar(){
			NoteLog(ame_Log_StartMethod, "getLastChar", "println", "");
			NoteLog(ame_Log_Statement, "getLastChar", "println", "");
			if(this->isEmpty()){
				return this->endValue();
			}
			NoteLog(ame_Log_EndMethod, "getLastChar", "println", "");
			return this->charAt(this->getPosition() - 1);
		}

		virtual void addLine(Note a_line){
			NoteLog(ame_Log_StartMethod, "addLine", "println", "");
			NoteLog(ame_Log_Statement, "addLine", "println", "");
			if(this->isEmpty()){
				this->addLocal(a_line);
				this->addLocal('\n');
				return;
			}
			if(this->getLastChar() != '\n'){
				this->addLocal('\n');
			}
			this->addLocal(a_line);
			NoteLog(ame_Log_EndMethod, "addLine", "println", "");
		}

		virtual int getOrder(Note a_note, char a_split, char a_end){
			NoteLog(ame_Log_StartMethod, "getOrder", "println", "");
			NoteLog(ame_Log_Statement, "getOrder", "println", "");
			Note i_note = "";
			int split_position = 0;
			bool addToNote = true;
			for(int x = 0; x < this->getPosition(); x++){
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", "iteration: ");
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", x);
				const char f_char = this->charAt(x);
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", "char: ");
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", f_char);
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", "i_note: ");
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", i_note);
				if(f_char == a_end){
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "f_char == a_end");
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "i_note: ");
					const_NoteLog(ame_Log_Statement, "getOrder", "println", i_note);
					i_note = "";
					addToNote = true;
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "end for loop");
					continue;
				}
				if(f_char == a_split){
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "f_char == a_split");
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "i_note: ");
					const_NoteLog(ame_Log_Statement, "getOrder", "println", i_note);
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "split_position: ");
					const_NoteLog(ame_Log_Statement, "getOrder", "println", split_position);
					if(a_note == i_note){
						const_NoteLog(ame_Log_Statement, "getOrder", "println", "a_note == i_note");
						return split_position;
					}
					split_position++;
					i_note = "";
					addToNote = false;
					const_NoteLog(ame_Log_Statement, "getOrder", "println", "end for loop");
					continue;
				}
				if(addToNote){
					i_note.addLocal(f_char);
				}
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", "i_note: ");
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", i_note);
				// const_NoteLog(ame_Log_Statement, "getOrder", "println", "end for loop");
			}
			NoteLog(ame_Log_EndMethod, "getOrder", "println", "");
			return -1;
		}
		
		virtual int getIndex(Note a_search){
			NoteLog(ame_Log_StartMethod, "replace", "println", "");
			Note i_note;
			int i_index = 0;
			int i_note_count = 0;
			for(int x = 0; x < a_search.getPosition(); x++){
				char f_char = this->charAt(x);
				i_note.addLocal(f_char);
				char f_char_search = a_search.charAt(i_note_count);
				char f_char_record = i_note.charAt(i_note_count);
				if(f_char_search == f_char_record){
					if(i_note_count == 0){
						i_index = x;
					}
					i_note_count++;
				}else{
					i_note.clear();
					continue;
				}
				if(a_search == i_note){
					return i_index;
				}
			}
			NoteLog(ame_Log_EndMethod, "replace", "println", "");
			return -1;
		}
		
		virtual bool removeNote(Note a_note){
			NoteLog(ame_Log_StartMethod, "replace", "println", "");
			int i_index = this->getIndex(a_note);
			if(i_index == -1){
				return false;
			}
			this->remove(i_index, a_note.getPosition());
			NoteLog(ame_Log_EndMethod, "replace", "println", "");
			return false;
		}

		virtual bool replace(Note a_search, Note a_change){
			NoteLog(ame_Log_StartMethod, "replace", "println", "");
			NoteLog(ame_Log_Statement, "replace", "println", "");
			Note i_note;
			Note i_search;
			int i_search_index = 0;

			if(this->isEmpty()){
				return false;
			}
			int i_index = this->getIndex(a_search);
			if(i_index == -1){
				return false;
			}
			this->remove(i_index, a_change.getPosition());
			this->insertLocal(i_index, a_change);
			NoteLog(ame_Log_EndMethod, "replace", "println", "");
			return true;
		}

		virtual Note& operator=(const Note& source){
			NoteLog(ame_Log_StartMethod, "operator=", "println", "");
			this->clear();
			NoteLog(ame_Log_Statement, "operator=", "println", "const Note& val");
			int i_array_length = source.length();
			if(i_array_length > 0){
				this->m_size = this->getAvailableSize(i_array_length);
				this->m_t_value = this->create(this->m_size);
				this->copyPointer(source.m_t_value, i_array_length);
				this->copyEndValue(this->getPosition());
				NoteLog(ame_Log_Statement, "operator=", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "operator=", "println", i_array_length);
				NoteLog(ame_Log_Statement, "operator=", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "operator=", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "operator=", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "operator=", "println", this->getSize());
			}
			NoteLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual Note& operator=(Note&& source){
			this->clear();
			NoteLog(ame_Log_StartMethod, "operator=", "println", "");
			NoteLog(ame_Log_Statement, "operator=", "println", "const Note& val");
			int i_array_length = source.length();
			if(i_array_length > 0){
				this->m_pos = source.m_pos;
				this->m_size = source.m_size;
				this->m_t_value = source.m_t_value;
				source.m_t_value = nullptr;
				source.m_pos = 0;
				source.m_size = 0;
				NoteLog(ame_Log_Statement, "operator=", "println", "Array Length:");
				NoteLog(ame_Log_Statement, "operator=", "println", i_array_length);
				NoteLog(ame_Log_Statement, "operator=", "println", "Array Position:");
				NoteLog(ame_Log_Statement, "operator=", "println", this->getPosition());
				NoteLog(ame_Log_Statement, "operator=", "println", "Array Size:");
				NoteLog(ame_Log_Statement, "operator=", "println", this->getSize());
			}
			NoteLog(ame_Log_EndMethod, "operator=", "println", "");
			return *this;
		}

		virtual Note operator+=(const Note& a_note){
			NoteLog(ame_Log_StartMethod, "operator+=", "println", "");
			NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
			return this->addLocal(a_note);
		}

		virtual Note operator+=(const char* a_char){
			NoteLog(ame_Log_StartMethod, "operator+=", "println", "");
			NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
			return this->addLocal(a_char);
		}

		virtual Note operator+=(const char& a_char){
			NoteLog(ame_Log_StartMethod, "operator+=", "println", "");
			NoteLog(ame_Log_EndMethod, "operator+=", "println", "");
			return this->addLocal(a_char);
		}

		virtual Note operator+(const Note& a_note){
			NoteLog(ame_Log_StartMethod, "operator+", "println", "");
			NoteLog(ame_Log_EndMethod, "operator+", "println", "");
			return this->add(a_note);
		}

		virtual Note operator+(char* a_note){
			NoteLog(ame_Log_StartMethod, "operator+", "println", "");
			NoteLog(ame_Log_EndMethod, "operator+", "println", "");
			return this->add(a_note);
		}

		virtual Note operator+(const char& a_note){
			NoteLog(ame_Log_StartMethod, "operator+", "println", "");
			NoteLog(ame_Log_EndMethod, "operator+", "println", "");
			return this->add(a_note);
		}

		virtual Note operator-=(const int& a_remove){
			if(this->isEmpty()){
				return *this;
			}

			return *this;
		}

		virtual Note operator-(const int& a_remove){
			Note i_value = *this;
			i_value-=(a_remove);
			return i_value;
		}

		virtual Note operator--(){

			return *this;
		}

		virtual bool operator==(const Note& a_note){
			if(a_note.getPosition() != this->getPosition()){
				return false;
			}
			for(int x = 0; x < this->getPosition(); x++){
				char f_char_1 = this->charAt(x);
				char f_char_2 = a_note.charAt(x);
				if(f_char_1 != f_char_2){
					return false;
				}
			}
			return true;
		}

		virtual bool operator!=(const Note& a_note){
			if(a_note.getPosition() != this->getPosition()){
				return true;
			}
			for(int x = 0; x < this->getPosition(); x++){
				char f_char_1 = this->charAt(x);
				char f_char_2 = a_note.charAt(x);
				if(f_char_1 == f_char_2){
					return false;
				}
			}
			return true;
		}
};

}

#endif






