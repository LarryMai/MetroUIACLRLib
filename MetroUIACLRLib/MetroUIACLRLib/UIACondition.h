#ifndef _UIA_CONDITION_H_
#define _UIA_CONDITION_H_

#include "UIACommon.h"

namespace MetroUIACLRLib{

	public ref class UIACondition  sealed
	{
	public:

		~UIACondition()
		{
			GC::SuppressFinalize(this);
			this->!UIACondition();
		}

		!UIACondition()
		{
			if(nativieInstance_ != nullptr)
			{
				nativieInstance_->Release();
				nativieInstance_ = nullptr;
			}
		}
	internal:
		UIACondition (IUIAutomationCondition * data ) 
		{
			nativieInstance_ = data;
	    }
         
		IUIAutomationCondition* GetNativeContent ()
		{
			return nativieInstance_;
 		}
	private:
		IUIAutomationCondition * nativieInstance_;
	};

}

#endif