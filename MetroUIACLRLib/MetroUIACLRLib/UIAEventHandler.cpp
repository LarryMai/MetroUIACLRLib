#include "UIAEventHandler.h"
#include "NativeHandlers.h"

namespace MetroUIACLRLib {
UIAPropertyChangedEventHandler::UIAPropertyChangedEventHandler()
{
	PropertyChangedEventHandler * handler =
		new PropertyChangedEventHandler();
	
	handler->SetCLRObject(this);
	nativieInstance_ = handler;
}

Void UIAPropertyChangedEventHandler::OnHandlePropertyChangedEvent(
	UIAElement ^ element, 
			PROPERTYID propertyID, 
			System::Runtime::InteropServices::VarEnum varType,
			System::Object ^ obj
			) 
{
	if(HandlePropertyChangedEvent != nullptr)
	{
		HandlePropertyChangedEvent(element, propertyID,varType,obj);
	}
}

UIAFocusChangedEventHandler::UIAFocusChangedEventHandler()
{
	FocusChangedEventHandler * handler = 
		new FocusChangedEventHandler();

	handler->SetCLRObject(this);
	nativieInstance_ = handler;
}

Void  UIAFocusChangedEventHandler::OnHandleFocusChangedEvent(UIAElement ^ pSender)
{
	if(HandleFocusChangedEvent != nullptr)
	{
		HandleFocusChangedEvent(pSender);
	}
}

UIAStructureChangedEventHandler::UIAStructureChangedEventHandler()
{
	StructureChangedEventHandler * handler = 
		new StructureChangedEventHandler();

	handler->SetCLRObject(this);
	nativieInstance_ = handler;
}


UIAEventHandler::UIAEventHandler()
{
	AutomationEventHandler * handler = new AutomationEventHandler();

	handler->SetCLRObject(this);
	nativieInstance_ = handler;
}

System::Void UIAEventHandler::OnHandleAutomationEvent(UIAEventHandler ^handler
			,UIAElement ^ element
			,EventID  eventID)
{
	if(HandleAutomationEvent != nullptr)
	{
		HandleAutomationEvent(handler, element , eventID);
	}
}

};