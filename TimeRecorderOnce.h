

#ifndef TimeRecorderOnce_h
#define TimeRecorderOnce_h

#include "Arduino.h"
#include "Now.h"
#include "List.h"
#include "PrimitiveList.h"
#include "TimeCheck.h"
#include "TimeRecorder.h"

namespace ame{
	
#define isRecorder() 
class TimeRecorderOnce : public TimeRecorder{
    public:		
		TimeRecorderOnce(){
			once =  new PrimitiveList<float>();
		}	
		TimeRecorderOnce(List<float>* o){
			if(o == nullptr){
				once =  new PrimitiveList<float>();
			}else{
				once =  o;
			}
		}
		virtual ~TimeRecorderOnce(){
			delete once;
		}
		
		virtual bool isNow(float time,float offset){
			if(TimeRecorder::isNow(time, offset) && ! once->contain(time)){
				once->add(time);
				return true;
			}
			return false;
		}
		
		virtual bool isNow(TimeCheck check,float time,float offset){
			if(TimeRecorder::isNow(check, time, offset) && ! once->contain(time)){
				once->add(new float(time));
				return true;
			}
			return false;
		}
		
		virtual void reset(float t){
			once->removeDelete(t);
		}
		
		virtual void reset(void){
			once->resetDelete();
			this->recordtimeh = 0.0f;
		}
    
	protected:	
		List<float>* once = nullptr;
};

}

#endif 
