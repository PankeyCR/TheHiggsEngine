
#ifndef StartState_hpp
#define StartState_hpp

#include "AppState.hpp"
#include "Application.hpp"
#include "MetricScale.hpp"
#include "MetricPrefix.hpp"

using namespace ame;

class StartState : public AppState{
	public:
 
		StartState(){}
		StartState(Stream *port){
			serial = port;
		}
   
		void initialize(Application *app){
			MetricScale scale;
			scale.setScaleTransform(MetricPrefix::micro , MetricPrefix::none);
			app->getTimeControl()->initialize(scale.getValue(2));// 2 seconds
			app->getTimeControl()->startInterrupt();
			app->getTimeControl()->attachInterrupt();
			serial->println("init start");
			App = app;
		}
   
    bool instanceof(cppObjectClass* cls){
      return cls == Class<StartState>::classType || AppState::instanceof(cls);
    }
   
    cppObjectClass* getClass(){
      return Class<StartState>::classType;
    }
   		
	private:
    Application *App;
    Stream *serial = nullptr;
  
};

#endif 