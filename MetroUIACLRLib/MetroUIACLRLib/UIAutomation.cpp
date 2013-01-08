#include "UIAutomation.h"
namespace MetroUIACLRLib{
		 //virtual HRESULT STDMETHODCALLTYPE CompareElements( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *el1,
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *el2,
   //         /* [retval][out] */ __RPC__out BOOL *areSame) = 0;
    
	bool UIAutomation::CompareElements(UIAElement ^ el1, UIAElement ^el2 , 
			[OutAttribute()] System::Boolean % areSame)
	{
		throw gcnew NotImplementedException();
	}
   //     virtual HRESULT STDMETHODCALLTYPE CompareRuntimeIds( 
   //         /* [in] */ __RPC__in SAFEARRAY * runtimeId1,
   //         /* [in] */ __RPC__in SAFEARRAY * runtimeId2,
   //         /* [retval][out] */ __RPC__out BOOL *areSame) = 0;
		bool UIAutomation::CompareRuntimeIds(
			array<System::Int32> ^ el1
			, array<System::Int32> ^el2 , 
			[OutAttribute()] System::Boolean % areSame)
	{
		throw gcnew NotImplementedException();
	}
   //     virtual HRESULT STDMETHODCALLTYPE GetRootElement( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **root) = 0;
    
		System::Boolean UIAutomation::
			GetRootElement( [OutAttribute]  UIAElement ^% root)
		{
			HRESULT hr = E_FAIL;
			IUIAutomationElement * element = nullptr;
			if(nativieInstance_ == nullptr)
			{
				goto END;
			}
			
		    hr = nativieInstance_->GetRootElement(&element);

			if(FAILED(hr))
			{
				goto END;
			}

			root = gcnew UIAElement(element);
END:
			return SUCCEEDED(hr);
		}
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromHandle( 
   //         /* [in] */ __RPC__in UIA_HWND hwnd,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
   
		bool UIAutomation::ElementFromHandle(System::IntPtr hwnd,
			[OutAttribute()]UIAElement ^% root)
		{
			
			if(this->GetNativeContent() == nullptr
				|| hwnd == IntPtr::Zero)
				return false;
			IUIAutomationElement * element = nullptr;
			HRESULT hr = this->GetNativeContent()->ElementFromHandle(
				(UIA_HWND)	hwnd.ToInt32() , &element);

			if(SUCCEEDED(hr))
			{
				root = gcnew UIAElement(element);
			}

			return SUCCEEDED(hr);
		}
		UIAElement ^ UIAutomation::ElementFromHandle(System::IntPtr hwnd)
		{
			UIAElement ^ element = nullptr;
			if(!ElementFromHandle(hwnd,  element))
				return nullptr;
			else
				return element;
		}
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromPoint( 
   //         /* [in] */ POINT pt,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
		bool UIAutomation::ElementFromPoint(System::Windows::Point point,
			[OutAttribute()]UIAElement ^% root)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			POINT nPoint;
			nPoint.x = point.X;
			nPoint.y = point.Y;
			IUIAutomationElement * element = nullptr;
			HRESULT hr =this->GetNativeContent()->ElementFromPoint(nPoint,
				&element);
			if(SUCCEEDED(hr))
			{
				root = gcnew UIAElement(element);
			}
			return SUCCEEDED(hr);
		}
		UIAElement ^ UIAutomation::ElementFromPoint(System::Windows::Point point)
		{
			UIAElement ^ element = nullptr;
			if(!this->ElementFromPoint(point ,  element))
			{
				return element;
			}
			else
				return nullptr;
		}
   //     virtual HRESULT STDMETHODCALLTYPE GetFocusedElement( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
		bool UIAutomation::GetFocusedElement([OutAttribute()]UIAElement ^% root)
		{
			throw gcnew NotImplementedException();
		}
		
		UIAElement ^ UIAutomation::GetFocusedElement()
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE GetRootElementBuildCache( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **root) = 0;
		bool UIAutomation::GetRootElementBuildCache(UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root)
		{
			throw gcnew NotImplementedException();
		}
		bool UIAutomation::GetRootElementBuildCache(UIACacheRequest ^ cacheRequest)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromHandleBuildCache( 
   //         /* [in] */ __RPC__in UIA_HWND hwnd,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
		bool UIAutomation::ElementFromHandleBuildCache(
			IntPtr hwnd,
			UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root)
		{
			throw gcnew NotImplementedException();
		}

		UIAElement ^ UIAutomation::ElementFromHandleBuildCache(IntPtr hwnd,  UIACacheRequest ^ cacheRequest)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromPointBuildCache( 
   //         /* [in] */ POINT pt,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
   
		bool UIAutomation::ElementFromPointBuildCache(
			System::Windows::Point pt,
			UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root)
		{
			throw gcnew NotImplementedException();
		}

		UIAElement ^ UIAutomation::
			ElementFromPointBuildCache(System::Windows::Point pt, 
			UIACacheRequest ^ cacheRequest)
		{
			throw gcnew NotImplementedException();
		
		}
   //     virtual HRESULT STDMETHODCALLTYPE GetFocusedElementBuildCache( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
   
		bool UIAutomation::GetFocusedElementBuildCache(
			UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root)
		{
			throw gcnew NotImplementedException();
		}

		UIAElement ^ UIAutomation::GetFocusedElementBuildCache(
			UIACacheRequest ^ cacheRequest)
		{
			throw gcnew NotImplementedException();
		}
        //virtual HRESULT STDMETHODCALLTYPE CreateTreeWalker( 
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *pCondition,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
   
		System::Boolean UIAutomation::CreateTreeWalker( UIACondition ^ condition 
			, [OutAttribute()] UIATreeWalker ^% walker)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ControlViewWalker( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
		System::Boolean UIAutomation::getControlViewWalker(
			[OutAttribute()] UIATreeWalker ^% walker)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ContentViewWalker( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
		System::Boolean UIAutomation::getContentViewWalker(
			[OutAttribute()] UIATreeWalker ^% walker)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RawViewWalker( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
		System::Boolean  UIAutomation::getRawViewWalker(
			[OutAttribute()] UIATreeWalker ^% walker)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RawViewCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **condition) = 0;
		System::Boolean  UIAutomation::getRawViewCondition(
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ControlViewCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **condition) = 0;
   
		System::Boolean  UIAutomation::getControlViewCondition(
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ContentViewCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **condition) = 0;
		System::Boolean  UIAutomation::getContentViewCondition(
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateCacheRequest( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCacheRequest **cacheRequest) = 0;
		System::Boolean  UIAutomation::CreateCacheRequest(
			[OutAttribute()] UIACacheRequest ^% cacheRequest)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateTrueCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean UIAutomation::CreateTrueCondition(
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}

   //     virtual HRESULT STDMETHODCALLTYPE CreateFalseCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean UIAutomation::CreateFalseCondition(
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreatePropertyCondition( 
   //         /* [in] */ PROPERTYID propertyId,
   //         /* [in] */ VARIANT value,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean UIAutomation::CreatePropertyCondition(
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreatePropertyConditionEx( 
   //         /* [in] */ PROPERTYID propertyId,
   //         /* [in] */ VARIANT value,
   //         /* [in] */ enum PropertyConditionFlags flags,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean UIAutomation::CreatePropertyConditionEx(
			PROPERTYID propertyId,
			System::Runtime::InteropServices::VarEnum varEnum,
			Object EnumData,
			PropertyConditionFlags flags,
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateAndCondition( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition1,
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition2,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		System::Boolean UIAutomation::CreateAndCondition(
			UIACondition ^ condition1,
			UIACondition ^ condition2,
			[OutAttribute()] UIACondition ^% newCondition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateAndConditionFromArray( 
   //         /* [in] */ __RPC__in_opt SAFEARRAY * conditions,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
   //     virtual HRESULT STDMETHODCALLTYPE CreateAndConditionFromNativeArray( 
   //         /* [size_is][in] */ __RPC__in_ecount_full(conditionCount) IUIAutomationCondition **conditions,
   //         /* [in] */ int conditionCount,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
			System::Boolean UIAutomation::CreateAndConditionFromArray(
			array<UIACondition^>^ conditions,
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateOrCondition( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition1,
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition2,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		  System::Boolean UIAutomation::CreateOrCondition(
			UIACondition ^ condition1,
			UIACondition ^ condition2,
			[OutAttribute()] UIACondition ^% newCondition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateOrConditionFromArray( 
   //         /* [in] */ __RPC__in_opt SAFEARRAY * conditions,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE CreateOrConditionFromNativeArray( 
   //         /* [size_is][in] */ __RPC__in_ecount_full(conditionCount) IUIAutomationCondition **conditions,
   //         /* [in] */ int conditionCount,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		  System::Boolean UIAutomation::CreateOrConditionFromArray(
			array<UIACondition^>^ conditions,
			[OutAttribute()] UIACondition ^% condition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE CreateNotCondition( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		  System::Boolean UIAutomation::CreateNotCondition(UIACondition ^ condition,
			  [OutAttribute()] UIACondition ^% newCondition)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE AddAutomationEventHandler( 
   //         /* [in] */ EVENTID eventId,
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ enum TreeScope scope,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationEventHandler *handler) = 0;
   
		  bool   UIAutomation::AddAutomationEventHandler( EventID eventId,
			  UIAElement ^ element,
			  UIACacheRequest ^ cacheRequest,
			  UIAEventHandler ^ handler)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE RemoveAutomationEventHandler( 
   //         /* [in] */ EVENTID eventId,
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ __RPC__in_opt IUIAutomationEventHandler *handler) = 0;
   
		 bool UIAutomation::RemoveAutomationEventHandler( EventID eventId,
			  UIAElement ^ element,
			  UIAEventHandler ^ handler)
		{
			throw gcnew NotImplementedException();
		}
   //     virtual HRESULT STDMETHODCALLTYPE AddPropertyChangedEventHandlerNativeArray( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ enum TreeScope scope,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationPropertyChangedEventHandler *handler,
   //         /* [size_is][in] */ __RPC__in_ecount_full(propertyCount) PROPERTYID *propertyArray,
   //         /* [in] */ int propertyCount) = 0;
   
		
   //     virtual HRESULT STDMETHODCALLTYPE AddPropertyChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ enum TreeScope scope,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationPropertyChangedEventHandler *handler,
   //         /* [in] */ __RPC__in SAFEARRAY * propertyArray) = 0;
   
				bool UIAutomation::AddPropertyChangedEventHandlerArray(
				UIAElement ^ element,
				TreeScope  scope,
				UIACacheRequest ^ cacheResult,
				UIAPropertyChangedEventHandler ^ handler,
				array<PROPERTYID>^ propertyArray)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE RemovePropertyChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ __RPC__in_opt IUIAutomationPropertyChangedEventHandler *handler) = 0;
   //     
			bool UIAutomation::RemovePropertyChangedEventHandler(
					UIAElement ^ element,
					UIAPropertyChangedEventHandler ^ handler)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE AddStructureChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ enum TreeScope scope,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationStructureChangedEventHandler *handler) = 0;
   
			bool UIAutomation::AddStructureChangedEventHandler(
				UIAElement ^ element,
				TreeScope scope,
				UIACacheRequest ^ cacheResult,
				UIAStructureChangedEventHandler ^ handler)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE RemoveStructureChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ __RPC__in_opt IUIAutomationStructureChangedEventHandler *handler) = 0;
   
			bool UIAutomation::RemoveStructureChangedEventHandler(
				UIAElement ^ element,
				UIAStructureChangedEventHandler ^ handler)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE AddFocusChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationFocusChangedEventHandler *handler) = 0;
   
			bool UIAutomation::AddFocusChangedEventHandler(
				UIAElement ^ element,
				UIAFocusChangedEventHandler ^ handler)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE RemoveFocusChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationFocusChangedEventHandler *handler) = 0;
   
			bool UIAutomation::RemoveFocusChangedEventHandler(
				UIAFocusChangedEventHandler ^handler)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE RemoveAllEventHandlers( void) = 0;
   
			bool UIAutomation::RemoveAllEventHandlers()
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE IntNativeArrayToSafeArray( 
   //         /* [size_is][in] */ __RPC__in_ecount_full(arrayCount) int *array,
   //         /* [in] */ int arrayCount,
   //         /* [retval][out] */ __RPC__deref_out_opt SAFEARRAY * *safeArray) = 0;
   
   //     virtual HRESULT STDMETHODCALLTYPE IntSafeArrayToNativeArray( 
   //         /* [in] */ __RPC__in SAFEARRAY * intArray,
   //         /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*arrayCount) int **array,
   //         /* [retval][out] */ __RPC__out int *arrayCount) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE RectToVariant( 
   //         /* [in] */ RECT rc,
   //         /* [retval][out] */ __RPC__out VARIANT *var) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE VariantToRect( 
   //         /* [in] */ VARIANT var,
   //         /* [retval][out] */ __RPC__out RECT *rc) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE SafeArrayToRectNativeArray( 
   //         /* [in] */ __RPC__in SAFEARRAY * rects,
   //         /* [size_is][size_is][out] */ __RPC__deref_out_ecount_full_opt(*rectArrayCount) RECT **rectArray,
   //         /* [retval][out] */ __RPC__out int *rectArrayCount) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE CreateProxyFactoryEntry( 
   //         /* [in] */ __RPC__in_opt IUIAutomationProxyFactory *factory,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationProxyFactoryEntry **factoryEntry) = 0;
   //     
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ProxyFactoryMapping( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationProxyFactoryMapping **factoryMapping) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE GetPropertyProgrammaticName( 
   //         /* [in] */ PROPERTYID property,
   //         /* [retval][out] */ __RPC__deref_out_opt BSTR *name) = 0;
   
			bool UIAutomation::GetPropertyProgrammaticName(PROPERTYID property,
				[OutAttribute()]System::String ^% name)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE GetPatternProgrammaticName( 
   //         /* [in] */ PATTERNID pattern,
   //         /* [retval][out] */ __RPC__deref_out_opt BSTR *name) = 0;
   
			bool UIAutomation::GetPropertyProgrammaticName(PATTERNID property,
				[OutAttribute()]System::String ^% name)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE PollForPotentialSupportedPatterns( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *pElement,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *patternIds,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *patternNames) = 0;
   //     
			bool UIAutomation::PollForPotentialSupportedPatterns(
				UIAElement ^ element,
				[OutAttribute()] array<PATTERNID>^% patternIds,
				[OutAttribute()] array<System::String^> ^% patternNames)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE PollForPotentialSupportedProperties( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *pElement,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *propertyIds,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *propertyNames) = 0;
   
			bool UIAutomation::PollForPotentialSupportedProperties(
				UIAElement ^ element,
				[OutAttribute()] array<PROPERTYID>^% patternIds,
				[OutAttribute()] array<System::String^> ^% propertyNames
				)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual HRESULT STDMETHODCALLTYPE CheckNotSupported( 
   //         /* [in] */ VARIANT value,
   //         /* [retval][out] */ __RPC__out BOOL *isNotSupported) = 0;
   
			bool UIAutomation::CheckNotSupported(System::Runtime::InteropServices::VarEnum varEnum,
				Object ^ value,
				[OutAttribute()] System::Boolean % isNotSupported)
			{
				throw gcnew NotImplementedException();
			}
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ReservedNotSupportedValue( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUnknown **notSupportedValue) = 0;
   
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ReservedMixedAttributeValue( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUnknown **mixedAttributeValue) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromIAccessible( 
   //         /* [in] */ __RPC__in_opt IAccessible *accessible,
   //         /* [in] */ int childId,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
  
	
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromIAccessibleBuildCache( 
   //         /* [in] */ __RPC__in_opt IAccessible *accessible,
   //         /* [in] */ int childId,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
	
	System::Boolean UIAutomation::CreateUIAutomation([System::Runtime::InteropServices::OutAttribute] UIAutomation ^% uiaAutomation)
	{
		IUIAutomation * uiAutomation = nullptr;
		HRESULT hr = CoCreateInstance(
			//__uuidof(CUIAutomation8)
			CLSID_CUIAutomation8
			, NULL,
                CLSCTX_INPROC_SERVER
				, IID_PPV_ARGS(&uiAutomation)
				);
		if (FAILED(hr))
		{
			//wprintf(L"Failed to create a CUIAutomation8, HR: 0x%08x\n", hr);
			goto END;
		}

	    uiaAutomation = gcnew UIAutomation(uiAutomation);
		
END:
		return SUCCEEDED( hr);
	}

    void UIAutomation::CloseUIAutomation(UIAutomation ^ automation)
	{
		if(automation != nullptr)
		{
			automation->!UIAutomation();
			automation =nullptr;
		}

		try{
			CoUninitialize();
		}
		catch(...)
		{
		
		}
	}

   }