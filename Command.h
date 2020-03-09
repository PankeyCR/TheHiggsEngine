
#ifndef Command_h
#define Command_h

template<class C>
class Command {
    private:
	
    public:
		virtual void execute(C* c){
			
		}
		virtual void operator=(Command<C> b){
			
		}
		virtual bool operator==(Command<C> b){
			return true;
		}
		virtual bool operator!=(Command<C> b){
			return false;
		}
};
#endif 
