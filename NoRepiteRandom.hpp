
#ifndef NoRepiteRandom_hpp
#define NoRepiteRandom_hpp
#define NoRepiteRandom_AVAILABLE

#include "Function.hpp"
#include "RealRandom.hpp"

#ifdef NoRepiteRandom_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"

	#define NoRepiteRandomLog(location,method,type,mns) higgs_Log(this,location,"NoRepiteRandom",method,type,mns)
#else
	#ifdef NoRepiteRandom_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"

		#define NoRepiteRandomLog(location,method,type,mns) higgs_LogDebug(this,location,"NoRepiteRandom",method,type)
	#else
		#define NoRepiteRandomLog(location,method,type,mns)
	#endif
#endif

namespace higgs{

class NoRepiteRandom : public Function<float,float,float,float>{
	protected:
		RealRandom *m_realRandom = nullptr;
		
    public:
		NoRepiteRandom(){
			this->m_realRandom = new RealRandom();
			float limitMax = ((float)2147483646/1000000.0f);
			this->initializeConstantes(4,0);
			this->setConstante(0,limitMax);
			this->setConstante(1,100000.0f);
			this->setConstante(2,0.0f);
			this->setConstante(3,1.0f);
		}
		NoRepiteRandom(const NoRepiteRandom& a__random){
			this->m_realRandom = new RealRandom();
			float limitMax = ((float)2147483646/1000000.0f);
			this->initializeConstantes(4,0);
			this->setConstante(0,limitMax);
			this->setConstante(1,100000.0f);
			this->setConstante(2,0.0f);
			this->setConstante(3,1.0f);
		}
		virtual ~NoRepiteRandom(){
			delete this->m_realRandom;
		}
		virtual float function(const PrimitiveList<float>& a_variables){
			if(a_variables.getPosition() < 3){
				return 0;
			}
			float i_max = a_variables[0];
			float i_min = a_variables[1];
			float i_seed_1 = a_variables[2];
			float i_seed = this->m_realRandom->f(this->getConstante(1), this->getConstante(2), i_seed_1);
			float time = ((float)micros()/1000000.0f);
			float d = i_max - i_min;
			float dx = (this->getConstante(0) / (i_seed * this->getConstante(3)));
			float tdx = ((float)(time/dx));
			float tx = (((float)(tdx))-((long)(tdx)));
			float x = d*tx;
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println","");
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println","NoRepiteRandom");
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "print","time ");NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println",Note(time));
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "print","d ");NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println",Note(d));
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "print","dx ");NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println",Note(dx));
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "print","tdx ");NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println",Note(tdx));
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "print","tx ");NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println",Note(tx));
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "print","x ");NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println",Note(x));
			NoRepiteRandomLog(higgs_Log_Statement, "getRandom", "println","");
			this->setConstante(3, 1.0f / (x + i_min + 0.1f));
			return x + i_min;
		}
		
};

}

#endif