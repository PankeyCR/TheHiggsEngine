
#ifndef TimeControl_hpp
#define TimeControl_hpp
#define TimeControl_AVAILABLE

namespace ame{
	class TimeControl;
}

#include "cppObject.hpp"
#include "PrimitiveList.hpp"
#include "Note.hpp"
#include "TimeElapsed.hpp"

namespace ame{

class TimeControl : public cppObject{
    public:
		List<TimeElapsed> *timeList;
		long time=0;
		long period=0;
		
		TimeControl(){
			this->timeList = new PrimitiveList<TimeElapsed>();
		}
		
		virtual ~TimeControl(){
			delete this->timeList;
		}
		
		virtual long getTime(){
			return this->time;
		}
		
		
		virtual TimeControl* initialize(long timeperiod){
			return this;
		}
		virtual TimeControl* setPeriod(long timeperiod){
			return this;
		}
		virtual long getPeriod(){
			return this->period;
		}
		
		virtual TimeControl* attachInterrupt(){
			return this;										
		}
		virtual TimeControl* detachInterrupt(){
			return this;										
		}
		virtual TimeControl* startInterrupt(){
			return this;										
		}
		virtual TimeControl* stopInterrupt(){
			return this;										
		}
		virtual TimeControl* resumeInterrupt(){
			return this;										
		}
		
		virtual TimeElapsed *add(TimeElapsed *t){
			this->timeList->addPointer(t);
			return t;
		}
		virtual TimeElapsed *remove(TimeElapsed *t){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->removeByPointer(t);
		}
		virtual TimeElapsed *removeByPos(int pos){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->removeByPosition(pos);
		}
		 
		virtual List<TimeElapsed> *getTimeElapsedList(){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList;
		}
		virtual TimeElapsed *getTimeElapsed(int pos){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->getByPosition(pos);
		}
		virtual TimeElapsed *getTimeElapsed(TimeElapsed *t){
			if(this->timeList == nullptr){
				return nullptr;
			}
			return this->timeList->getByPointer(t);
		}
		
		virtual cppObjectClass* getClass(){
			return Class<TimeControl>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<TimeControl>::classType;
		}
		
	protected:
	
};

}

#endif