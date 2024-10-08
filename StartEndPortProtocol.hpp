
#ifndef StartEndPortProtocol_hpp
#define StartEndPortProtocol_hpp
#define StartEndPortProtocol_AVAILABLE

#include "PortProtocol.hpp"
#include "SerialPort.hpp"
#include "Note.hpp"
#include "NoteHelper.hpp"

#ifdef StartEndPortProtocol_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"
	
	#define StartEndPortProtocolLog(location,method,type,mns) higgs_Log(this,location,"StartEndPortProtocol",method,type,mns)
	#define const_StartEndPortProtocolLog(location,method,type,mns) 
	#define StaticStartEndPortProtocolLog(pointer,location,method,type,mns) higgs_Log(pointer,location,"StartEndPortProtocol",method,type,mns)
#else
	#ifdef StartEndPortProtocol_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"
		
		#define StartEndPortProtocolLog(location,method,type,mns) higgs_LogDebug(this,location,"StartEndPortProtocol",method,type)
		#define const_StartEndPortProtocolLog(location,method,type,mns) 
		#define StaticStartEndPortProtocolLog(pointer,location,method,type,mns) higgs_LogDebug(pointer,location,"StartEndPortProtocol",method,type)
	#else
		#define StartEndPortProtocolLog(location,method,type,mns) 
		#define const_StartEndPortProtocolLog(location,method,type,mns) 
		#define StaticStartEndPortProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace higgs{

class StartEndPortProtocol : public PortProtocol{	
    public:
		StartEndPortProtocol(){}
		StartEndPortProtocol(char s, char e){
			m_start = s;
			m_end = e;
		}
		virtual ~StartEndPortProtocol(){}
		
		virtual void InstantBroadcastMessage(SerialPort* port, Note a_mns){
			StartEndPortProtocolLog(higgs_Log_Statement, "InstantBroadcastMessage",  "println", port->getName());
			StartEndPortProtocolLog(higgs_Log_Statement, "InstantBroadcastMessage",  "println", a_mns);
			Note i_send;
			addLocalValue(i_send, m_start);
			addLocalNote(i_send, a_mns);
			addLocalValue(i_send, m_end);
			port->print(i_send);
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, Note a_mns){
			StartEndPortProtocolLog(higgs_Log_Statement, "InstantPrivateMessage",  "println", port->getName());
			StartEndPortProtocolLog(higgs_Log_Statement, "InstantPrivateMessage",  "println", a_mns);
			Note i_send;
			addLocalValue(i_send, m_start);
			addLocalNote(i_send, a_mns);
			addLocalValue(i_send, m_end);
			port->print(i_send);
		}
		
		virtual void BroadcastMessage(SerialPort* port, Note a_mns){
			StartEndPortProtocolLog(higgs_Log_Statement, "BroadcastMessage",  "println", port->getName());
			StartEndPortProtocolLog(higgs_Log_Statement, "BroadcastMessage",  "println", a_mns);
			Note i_send;
			addLocalValue(i_send, m_start);
			addLocalNote(i_send, a_mns);
			addLocalValue(i_send, m_end);
			port->print(i_send);
		}
		
		virtual void PrivateMessage(SerialPort* port, Note a_mns){
			StartEndPortProtocolLog(higgs_Log_Statement, "PrivateMessage",  "println", port->getName());
			StartEndPortProtocolLog(higgs_Log_Statement, "PrivateMessage",  "println", a_mns);
			Note i_send;
			addLocalValue(i_send, m_start);
			addLocalNote(i_send, a_mns);
			addLocalValue(i_send, m_end);
			port->print(i_send);
		}
		
		virtual void GlobalDisconect(SerialPort* port){
			StartEndPortProtocolLog(higgs_Log_Statement, "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void Disconect(SerialPort* port){
			StartEndPortProtocolLog(higgs_Log_Statement, "Disconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void UpdateDisconect(SerialPort* port){
			StartEndPortProtocolLog(higgs_Log_Statement, "UpdateDisconect",  "println", "");
			StartEndPortProtocolLog(higgs_Log_Statement, "UpdateDisconect",  "println", Note("port name: ") + Note(port->getName()));
			port->flush();
			port->stop();
		}
		
		Note StartEndRead(int index, SerialPort* port){
			StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", "");
			char m = port->read();
			StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", Note(m));
			if((m == m_end) && messageText.length() > 0){
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", Note("messageText.length(): ") + Note(messageText.length()));
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", "adding Message to serialState");
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", Note("messageText: ") + messageText);
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", Note("index: ") + Note(index));
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", "raw");
				Note r_message = messageText;
				messageText = "";
				m_read = false;
				return r_message;
			}
			if(m == m_start){
				m_read = true;
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", Note("start adding char to messageText: ") + Note(m));
				return "";
			}
			if(m_read){
				StartEndPortProtocolLog(higgs_Log_Statement, "StartEndRead",  "println", Note("adding char to messageText: ") + Note(m));
				addLocalValue(messageText, m);
			}
			return "";
		}
		
	protected:
		Note messageText = "";
		char m_start = '!';
		char m_end = '!';
		bool m_read = false;
};

}

#endif