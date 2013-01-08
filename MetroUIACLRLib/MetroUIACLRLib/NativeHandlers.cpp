#include "NativeHandlers.h"
#include "UIAEventHandler.h"

namespace MetroUIACLRLib{
HRESULT PropertyChangedEventHandler::HandlePropertyChangedEvent(
	IUIAutomationElement* pSender, ::PROPERTYID propertyID, VARIANT newValue)
{
	return E_FAIL;
}

HRESULT StructureChangedEventHandler::HandleStructureChangedEvent(
	IUIAutomationElement* pSender
		, StructureChangeType changeType, SAFEARRAY* pRuntimeID)
{
	return E_FAIL;
}

HRESULT AutomationEventHandler::HandleAutomationEvent(IUIAutomationElement * pSender
		, EVENTID eventID)
{
	return E_FAIL;
}

HRESULT FocusChangedEventHandler::HandleFocusChangedEvent(IUIAutomationElement * pSender)
{
	return E_FAIL;
}

};