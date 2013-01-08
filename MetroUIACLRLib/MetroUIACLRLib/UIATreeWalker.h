#ifndef _UIA_TREEWALKER_H_
#define _UIA_TREEWALKER_H_
#include "UIACommon.h"

namespace MetroUIACLRLib{
	public ref class UIATreeWalker sealed
	{
	public:
		~UIATreeWalker()
		{
			GC::SuppressFinalize(this);
			this->!UIATreeWalker();
		}

		!UIATreeWalker()
		{
			if(nativieInstance_ != nullptr)
			{
				nativieInstance_->Release();
				nativieInstance_ = nullptr;
			}
		}
	internal:
		UIATreeWalker (IUIAutomationTreeWalker * data ) 
		{
			nativieInstance_ = data;
	    }
         
		IUIAutomationTreeWalker* GetNativeContent ()
		{
			return nativieInstance_;
 		}
	private:
		IUIAutomationTreeWalker * nativieInstance_;	
};


};

#endif