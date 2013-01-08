#ifndef _UIA_CACHE_RESULT_H_
#define _UIA_CACHE_RESULT_H_

#include "UIACommon.h"

namespace MetroUIACLRLib{

	public ref class UIACacheRequest  sealed
	{
	public:

		~UIACacheRequest()
		{
			GC::SuppressFinalize(this);
			this->!UIACacheRequest();
		}

		!UIACacheRequest()
		{
			if(cacheResult_ != nullptr)
			{
				cacheResult_->Release();
				cacheResult_ = nullptr;
			}
		}
	internal:
		UIACacheRequest (IUIAutomationCacheRequest * data ) 
		{
			cacheResult_ = data;
	    }
         
		IUIAutomationCacheRequest* GetNativeContent ()
		{
			return cacheResult_;
 		}
	private:
		IUIAutomationCacheRequest * cacheResult_;
	};

}

#endif