
#ifndef SerialNetworkProtocol_h
#define SerialNetworkProtocol_h

#include "SerialPort.h"
#include "ByteArray.h"

namespace ame{
	
class SerialMessageState;

class SerialNetworkProtocol{	
    public:
		SerialNetworkProtocol(){}
		virtual ~SerialNetworkProtocol(){}
		
		virtual void attach(SerialMessageState* state){
			this->serialState = state;
		}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantBroadcastMessage(SerialPort* port, String mns){}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantPrivateMessage(SerialPort* port, String mns){}
		
		virtual void InstantPrivateByteArrayMessage(SerialPort* port, ByteArray array){}
		
		virtual void GlobalDisconect(SerialPort* port){}
		virtual void Disconect(SerialPort* port){}
		virtual void UpdateDisconect(SerialPort* port){}
		
		virtual void Read(int index, SerialPort* port){}
		
		//you need to send to message manually
		virtual void BroadcastMessage(SerialPort* port, String mns){}
		//you need to send to message manually
		virtual void PrivateMessage(SerialPort* port, String mns){}
		
		virtual void setSafeDelete(bool s){safeDelete = s;}
		virtual bool SafeDelete(){return safeDelete;}
		
		virtual void update(SerialPort* port, float tpc){}
		
		virtual void operator=(SerialNetworkProtocol b){}
		virtual bool operator==(SerialNetworkProtocol b){return true;}
		virtual bool operator!=(SerialNetworkProtocol b){return true;}
		
	protected:
		bool safeDelete = true;
		SerialMessageState* serialState = nullptr;
};

}

#endif 
