#ifndef _UIA_EVENTHANDLER_H_
#define _UIA_EVENTHANDLER_H_

#include "UIACommon.h"
#include "UIAElement.h"
using namespace System;



namespace MetroUIACLRLib {

class PropertyChangedEventHandler;
class StructureChangedEventHandler;

class AutomationEventHandler;
class FocusChangedEventHandler;
#pragma region managed handler
public ref class UIAPropertyChangedEventHandler sealed
{
	public:
		UIAPropertyChangedEventHandler();
	
		~UIAPropertyChangedEventHandler()
		{
			GC::SuppressFinalize(this);
			this->!UIAPropertyChangedEventHandler();
		}

		!UIAPropertyChangedEventHandler()
		{
			if(this->GetNativeContent() != nullptr)
			{
				this->GetNativeContent()->Release();
				nativieInstance_ = nullptr;
			}
		}
		Void OnHandlePropertyChangedEvent(UIAElement ^ element, 
			PROPERTYID propertyID, 
			System::Runtime::InteropServices::VarEnum varType,
			System::Object ^ obj
			) ;

		property System::Action<UIAElement ^ , PROPERTYID, 
			System::Runtime::InteropServices::VarEnum ,
			System::Object ^ >^ HandlePropertyChangedEvent
		{
			System::Action<UIAElement ^ , 
			PROPERTYID, 
			System::Runtime::InteropServices::VarEnum ,
			System::Object ^ >^ get() { return _handlePropertyChangedEvent;}

			void set(System::Action<UIAElement ^ , 
			PROPERTYID, 
			System::Runtime::InteropServices::VarEnum ,
			System::Object ^ >^ value)
			{
				_handlePropertyChangedEvent =value;
			}
		}
	internal:
         
		IUIAutomationPropertyChangedEventHandler* GetNativeContent ()
		{
			return nativieInstance_;
 		}
private:
	IUIAutomationPropertyChangedEventHandler *nativieInstance_;

	System::Action<UIAElement ^ , 
			PROPERTYID, 
			System::Runtime::InteropServices::VarEnum ,
			System::Object ^ >^ _handlePropertyChangedEvent ;
};

public ref class UIAFocusChangedEventHandler sealed
{
	public:
		UIAFocusChangedEventHandler();
		~UIAFocusChangedEventHandler()
		{
			GC::SuppressFinalize(this);
			this->!UIAFocusChangedEventHandler();
		}

		!UIAFocusChangedEventHandler()
		{
			if(this->GetNativeContent() != nullptr)
			{
				this->GetNativeContent()->Release();
				nativieInstance_ = nullptr;
			}
		}

		Void  OnHandleFocusChangedEvent(UIAElement ^ pSender) ;
		

	    property System::Action<UIAElement^> ^ HandleFocusChangedEvent
		{
			System::Action<UIAElement^>^ get()
			{
				return _handleFocusChangedEvent;
			}

			void set(System::Action<UIAElement^>^ value)
			{
				_handleFocusChangedEvent =value;
			}
		}
		internal:
		IUIAutomationFocusChangedEventHandler* GetNativeContent ()
		{
			return nativieInstance_;
 		}
private:
	  IUIAutomationFocusChangedEventHandler *nativieInstance_;
	  System::Action<UIAElement^> ^ _handleFocusChangedEvent;
};

public ref class UIAStructureChangedEventHandler sealed
{
	public:
		UIAStructureChangedEventHandler();
		~UIAStructureChangedEventHandler()
		{
			GC::SuppressFinalize(this);
			this->!UIAStructureChangedEventHandler();
		}

		!UIAStructureChangedEventHandler()
		{
			if(this->GetNativeContent() != nullptr)
			{
				this->GetNativeContent()->Release();
				nativieInstance_ = nullptr;
			}
		}
	internal:
		IUIAutomationStructureChangedEventHandler* GetNativeContent ()
		{
			return nativieInstance_;
 		}
private:
	  IUIAutomationStructureChangedEventHandler *nativieInstance_;
};

public ref class UIAEventHandler sealed
{
	public:
		UIAEventHandler();
		~UIAEventHandler()
		{
			GC::SuppressFinalize(this);
			this->!UIAEventHandler();
		}

		!UIAEventHandler()	
		{
			if(this->GetNativeContent() != nullptr)
			{
				this->GetNativeContent()->Release();
				nativieInstance_ = nullptr;
			}
		}

		System::Void OnHandleAutomationEvent(UIAEventHandler ^handler
			,UIAElement ^ element
			,EventID  eventID);
	internal:
		IUIAutomationEventHandler* GetNativeContent ()
		{
			return nativieInstance_;
 		}

	   property  System::Action<UIAEventHandler ^,UIAElement ^ ,EventID  > ^
		   HandleAutomationEvent
		{
			System::Action<UIAEventHandler ^,UIAElement ^ ,EventID  > ^ get(){
				return _handleAutomationEvent;
			}		

			void set(System::Action<UIAEventHandler ^,UIAElement ^ ,EventID  > ^  value)
			{
				_handleAutomationEvent =value;
			}
		}
private:
	  IUIAutomationEventHandler *nativieInstance_;

	  System::Action<UIAEventHandler ^
			,UIAElement ^ 
			,EventID  > ^  _handleAutomationEvent;
};
#pragma endregion




};
#endif