
#ifndef ThreadControl_hpp
#define ThreadControl_hpp
#define ThreadControl_AVAILABLE

namespace ame{

class ThreadControl{
    public:
		ThreadControl(){}
		virtual ~ThreadControl(){}
		
		virtual void initialize(){}
		
		virtual void update(){}
};

}

#endif