#ifndef _NATIVE_HANDLER_H_
#define _NATIVE_HANDLER_H_


#include "UIACommon.h"

namespace MetroUIACLRLib{
#pragma region native handler

ref class UIAPropertyChangedEventHandler;
ref class UIAStructureChangedEventHandler;
ref class UIAFocusChangedEventHandler;
ref class UIAEventHandler;

class StructureChangedEventHandler:
    public IUIAutomationStructureChangedEventHandler
{
private:
    LONG _refCount;
	gcroot<UIAStructureChangedEventHandler ^> _CLRHandler;
public:
    int _eventCount;

    // Constructor.
    StructureChangedEventHandler(): _refCount(1), _eventCount(0) 
    {
    }

    // IUnknown methods.
    ULONG STDMETHODCALLTYPE AddRef() 
    {
        ULONG ret = InterlockedIncrement(&_refCount);
        return ret;
    }

    ULONG STDMETHODCALLTYPE Release() 
    {
        ULONG ret = InterlockedDecrement(&_refCount);
        if (ret == 0) 
        {
            delete this;
            return 0;
        }
        return ret;
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppInterface) 
    {
        if (riid == __uuidof(IUnknown))
            *ppInterface=static_cast<IUIAutomationStructureChangedEventHandler*>(this);
        else if (riid == __uuidof(IUIAutomationStructureChangedEventHandler)) 
            *ppInterface=static_cast<IUIAutomationStructureChangedEventHandler*>(this);
        else 
        {
            *ppInterface = NULL;
            return E_NOINTERFACE;
        }
        this->AddRef();
        return S_OK;
    }

    // IUIAutomationStructureChangedEventHandler methods
    HRESULT STDMETHODCALLTYPE HandleStructureChangedEvent(IUIAutomationElement* pSender
		, StructureChangeType changeType, SAFEARRAY* pRuntimeID)
	//{
	//
	//	BSTR bstAutomationID = nullptr;
	//	HRESULT	 hr = S_OK;
 //       switch (changeType) 
 //       {
 //           case StructureChangeType_ChildAdded:
 //               wprintf(L">> Structure Changed: ChildAdded! (count: %d)\n", _eventCount);
	//			break;
 //           case StructureChangeType_ChildRemoved:
 //               wprintf(L">> Structure Changed: ChildRemoved! (count: %d)\n", _eventCount);
	//			break;
 //          case StructureChangeType_ChildrenInvalidated:
 //               wprintf(L">> Structure Changed: ChildrenInvalidated! (count: %d)\n", _eventCount);
	//			break;
 //           case StructureChangeType_ChildrenBulkAdded:
 //               wprintf(L">> Structure Changed: ChildrenBulkAdded! (count: %d)\n", _eventCount);
	//		
 //               break;
 //           case StructureChangeType_ChildrenBulkRemoved:
 //               wprintf(L">> Structure Changed: ChildrenBulkRemoved! (count: %d)\n", _eventCount);
	//			break;
 //           case StructureChangeType_ChildrenReordered:
 //               wprintf(L">> Structure Changed: ChildrenReordered! (count: %d)\n", _eventCount);
 //               break;
	//		default:break;
 //       }

 //       return S_OK;
 //   }
	;

	void SetCLRObject(UIAStructureChangedEventHandler ^  clrHandler)
	{
		_CLRHandler = clrHandler;
	}
};


class PropertyChangedEventHandler:
    public IUIAutomationPropertyChangedEventHandler
{
private:
    LONG _refCount;

	gcroot<UIAPropertyChangedEventHandler ^> _CLRHandler;
public:
    int _eventCount;

    //Constructor.
    PropertyChangedEventHandler(): _refCount(1), _eventCount(0) 
    {
    }

    //IUnknown methods.
    ULONG STDMETHODCALLTYPE AddRef() 
    {
        ULONG ret = InterlockedIncrement(&_refCount);
        return ret;
    }

    ULONG STDMETHODCALLTYPE Release() 
    {
        ULONG ret = InterlockedDecrement(&_refCount);
        if (ret == 0) 
        {
            delete this;
            return 0;
        }
        return ret;
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppInterface) 
    {
        if (riid == __uuidof(IUnknown))
            *ppInterface=static_cast<IUIAutomationPropertyChangedEventHandler*>(this);
        else if (riid == __uuidof(IUIAutomationPropertyChangedEventHandler)) 
            *ppInterface=static_cast<IUIAutomationPropertyChangedEventHandler*>(this);
        else 
        {
            *ppInterface = NULL;
            return E_NOINTERFACE;
        }
        this->AddRef();
        return S_OK;
    }

    // IUIAutomationPropertyChangedEventHandler methods.
    HRESULT STDMETHODCALLTYPE HandlePropertyChangedEvent(IUIAutomationElement* pSender, ::PROPERTYID propertyID, VARIANT newValue) 
  //  {
  //     // _eventCount++;
  //      if (propertyID == 
		//	UIA_IsOffscreenPropertyId
		//	//UIA_ToggleToggleStatePropertyId
		//	) 
		//{

		//}
  //      else 
  //          wprintf(L">> Property (%d) changed!\n", propertyID);

  //      return S_OK;
  //  }
  ;

	void SetCLRObject(UIAPropertyChangedEventHandler ^  clrHandler)
	{
		_CLRHandler =clrHandler;
	}
};

class AutomationEventHandler:
    public IUIAutomationEventHandler
{
private:
    LONG _refCount;
	gcroot<UIAEventHandler^> _CLRHandler;
public:
    int _eventCount;

    // Constructor.
    AutomationEventHandler(): _refCount(1), _eventCount(0) 
    {
    }

    // IUnknown methods.
    ULONG STDMETHODCALLTYPE AddRef() 
    {
        ULONG ret = InterlockedIncrement(&_refCount);
        return ret;
    }

    ULONG STDMETHODCALLTYPE Release() 
    {
        ULONG ret = InterlockedDecrement(&_refCount);
        if (ret == 0) 
        {
            delete this;
            return 0;
        }
        return ret;
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppInterface) 
    {
        if (riid == __uuidof(IUnknown)) 
            *ppInterface=static_cast<IUIAutomationEventHandler*>(this);
        else if (riid == __uuidof(IUIAutomationEventHandler)) 
            *ppInterface=static_cast<IUIAutomationEventHandler*>(this);
        else 
        {
            *ppInterface = NULL;
            return E_NOINTERFACE;
        }
        this->AddRef();
        return S_OK;
    }

    // IUIAutomationEventHandler methods
    HRESULT STDMETHODCALLTYPE HandleAutomationEvent(IUIAutomationElement * pSender
		, EVENTID eventID)
    //{
    //   /* switch (eventID) 
    //    {
    //        case UIA_ToolTipOpenedEventId:
    //            wprintf(L">> Event ToolTipOpened Received! (count: %d)\n", _eventCount);
    //            break;
    //        case UIA_ToolTipClosedEventId:
    //            wprintf(L">> Event ToolTipClosed Received! (count: %d)\n", _eventCount);
    //            break;
    //        case UIA_Window_WindowOpenedEventId:
				//{
				//
				//	
				//}
				//break;
    //        case UIA_Window_WindowClosedEventId:
				//{
				//
				//}
    //            break;
    //        default:
    //            wprintf(L">> Event (%d) Received! (count: %d)\n", eventID, _eventCount);
    //            break;
    //    }*/

		
    //    return S_OK;
    //}
	;
	void SetCLRObject(UIAEventHandler ^ handler)
	{
		_CLRHandler = handler;
	}
private:

};


class FocusChangedEventHandler:
    public IUIAutomationFocusChangedEventHandler
{
private:
    LONG _refCount;

	gcroot<UIAFocusChangedEventHandler^> _CLRHandler;
public:
    int _eventCount;

    //Constructor.
    FocusChangedEventHandler(): _refCount(1), _eventCount(0) 
    {
    }

    //IUnknown methods.
    ULONG STDMETHODCALLTYPE AddRef() 
    {
        ULONG ret = InterlockedIncrement(&_refCount);
        return ret;
    }

    ULONG STDMETHODCALLTYPE Release() 
    {
        ULONG ret = InterlockedDecrement(&_refCount);
        if (ret == 0) 
        {
            delete this;
            return 0;
        }
        return ret;
    }

    HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppInterface) 
    {
        if (riid == __uuidof(IUnknown))
            *ppInterface = static_cast<IUIAutomationFocusChangedEventHandler*>(this);
        else if(riid == __uuidof(IUIAutomationFocusChangedEventHandler)) 
            *ppInterface=static_cast<IUIAutomationFocusChangedEventHandler*>(this);
        else 
        {
            *ppInterface = NULL;
            return E_NOINTERFACE;
        }
        this->AddRef();
        return S_OK;
    }

    // IUIAutomationFocusChangedEventHandler methods.
    HRESULT STDMETHODCALLTYPE HandleFocusChangedEvent(IUIAutomationElement * pSender) 
   /* {
        _eventCount++;
		BSTR bstr;
		BSTR bAutomationID;
		BSTR bClassname;
	    pSender->get_CurrentName(&bstr);

		pSender->get_CurrentAutomationId(&bAutomationID);
		pSender->get_CurrentClassName(&bClassname);
		wprintf_s(
			L"[%d]FocusedElement with name : %s, automationID : %s, Classname : %s\n"
			, _eventCount, bstr , bAutomationID , bClassname
			);
		 
        return S_OK;
    }*/
	;

	void SetCLRObject(UIAFocusChangedEventHandler ^ handler)
	{
		_CLRHandler = handler;
	}
};

#pragma endregion

};

#endif