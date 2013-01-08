#ifndef _UI_AUTOMATION_H_
#define _UI_AUTOMATION_H_


#include "UIAElement.h"
#include "UIATreeWalker.h"
#include "UIACacheResult.h"
#include "UIAEventHandler.h"

namespace MetroUIACLRLib {

	public ref class UIAutomation  : IDisposable
	{
	public:
		 //virtual HRESULT STDMETHODCALLTYPE CompareElements( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *el1,
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *el2,
   //         /* [retval][out] */ __RPC__out BOOL *areSame) = 0;
    
		bool CompareElements(UIAElement ^ el1, UIAElement ^el2 , 
			[OutAttribute()] System::Boolean % areSame);
   //     virtual HRESULT STDMETHODCALLTYPE CompareRuntimeIds( 
   //         /* [in] */ __RPC__in SAFEARRAY * runtimeId1,
   //         /* [in] */ __RPC__in SAFEARRAY * runtimeId2,
   //         /* [retval][out] */ __RPC__out BOOL *areSame) = 0;
		bool CompareRuntimeIds(array<System::Int32> ^ el1, array<System::Int32> ^el2 , 
			[OutAttribute()] System::Boolean % areSame);
   //     virtual HRESULT STDMETHODCALLTYPE GetRootElement( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **root) = 0;
    
		System::Boolean GetRootElement( [OutAttribute()]  UIAElement ^% root);
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromHandle( 
   //         /* [in] */ __RPC__in UIA_HWND hwnd,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
   
		bool ElementFromHandle(System::IntPtr hwnd,
			[OutAttribute()]UIAElement ^% root);
		UIAElement ^ ElementFromHandle(System::IntPtr hwnd);
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromPoint( 
   //         /* [in] */ POINT pt,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
		bool ElementFromPoint(System::Windows::Point point,
			[OutAttribute()]UIAElement ^% root);
		UIAElement ^ ElementFromPoint(System::Windows::Point point);
   //     virtual HRESULT STDMETHODCALLTYPE GetFocusedElement( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
		bool GetFocusedElement([OutAttribute()]UIAElement ^% root);
		
		UIAElement ^ GetFocusedElement();
   //     virtual HRESULT STDMETHODCALLTYPE GetRootElementBuildCache( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **root) = 0;
		bool GetRootElementBuildCache(UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root);
		bool GetRootElementBuildCache(UIACacheRequest ^ cacheRequest);
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromHandleBuildCache( 
   //         /* [in] */ __RPC__in UIA_HWND hwnd,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
		bool ElementFromHandleBuildCache(
			IntPtr hwnd,
			UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root);
		UIAElement ^ ElementFromHandleBuildCache(IntPtr hwnd,  UIACacheRequest ^ cacheRequest);
		  
   //     virtual HRESULT STDMETHODCALLTYPE ElementFromPointBuildCache( 
   //         /* [in] */ POINT pt,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
   
		bool ElementFromPointBuildCache(
			System::Windows::Point pt,
			UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root);
		UIAElement ^ ElementFromPointBuildCache(System::Windows::Point pt,  UIACacheRequest ^ cacheRequest);
   //     virtual HRESULT STDMETHODCALLTYPE GetFocusedElementBuildCache( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **element) = 0;
   
		bool GetFocusedElementBuildCache(
			UIACacheRequest ^ cacheRequest,
			[OutAttribute()]UIAElement ^% root);
		UIAElement ^ GetFocusedElementBuildCache(  UIACacheRequest ^ cacheRequest);
        //virtual HRESULT STDMETHODCALLTYPE CreateTreeWalker( 
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *pCondition,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
   
		System::Boolean CreateTreeWalker( UIACondition ^ condition , [OutAttribute()] UIATreeWalker ^% walker);
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ControlViewWalker( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
		System::Boolean getControlViewWalker([OutAttribute()] UIATreeWalker ^% walker);
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ContentViewWalker( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
		System::Boolean getContentViewWalker([OutAttribute()] UIATreeWalker ^% walker);
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RawViewWalker( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationTreeWalker **walker) = 0;
		System::Boolean getRawViewWalker([OutAttribute()] UIATreeWalker ^% walker);
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_RawViewCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **condition) = 0;
		System::Boolean getRawViewCondition([OutAttribute()] UIACondition ^% condition);
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ControlViewCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **condition) = 0;
   
		System::Boolean getControlViewCondition([OutAttribute()] UIACondition ^% condition);
   //     virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_ContentViewCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **condition) = 0;
		System::Boolean getContentViewCondition([OutAttribute()] UIACondition ^% condition);
   //     virtual HRESULT STDMETHODCALLTYPE CreateCacheRequest( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCacheRequest **cacheRequest) = 0;
		System::Boolean CreateCacheRequest([OutAttribute()] UIACacheRequest ^% cacheRequest);
   //     virtual HRESULT STDMETHODCALLTYPE CreateTrueCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean CreateTrueCondition([OutAttribute()] UIACondition ^% condition);
   //     virtual HRESULT STDMETHODCALLTYPE CreateFalseCondition( 
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean CreateFalseCondition([OutAttribute()] UIACondition ^% condition); 
   //     virtual HRESULT STDMETHODCALLTYPE CreatePropertyCondition( 
   //         /* [in] */ PROPERTYID propertyId,
   //         /* [in] */ VARIANT value,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean CreatePropertyCondition([OutAttribute()] UIACondition ^% condition);
   //     virtual HRESULT STDMETHODCALLTYPE CreatePropertyConditionEx( 
   //         /* [in] */ PROPERTYID propertyId,
   //         /* [in] */ VARIANT value,
   //         /* [in] */ enum PropertyConditionFlags flags,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
		System::Boolean CreatePropertyConditionEx(
			PROPERTYID propertyId,
			System::Runtime::InteropServices::VarEnum varEnum,
			Object EnumData,
			PropertyConditionFlags flags,
			[OutAttribute()] UIACondition ^% condition);
   //     virtual HRESULT STDMETHODCALLTYPE CreateAndCondition( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition1,
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition2,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		System::Boolean CreateAndCondition(
			UIACondition ^ condition1,
			UIACondition ^ condition2,
			[OutAttribute()] UIACondition ^% newCondition);
   //     virtual HRESULT STDMETHODCALLTYPE CreateAndConditionFromArray( 
   //         /* [in] */ __RPC__in_opt SAFEARRAY * conditions,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
   //     virtual HRESULT STDMETHODCALLTYPE CreateAndConditionFromNativeArray( 
   //         /* [size_is][in] */ __RPC__in_ecount_full(conditionCount) IUIAutomationCondition **conditions,
   //         /* [in] */ int conditionCount,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
			System::Boolean CreateAndConditionFromArray(
			array<UIACondition^>^ conditions,
			[OutAttribute()] UIACondition ^% condition); 
   //     virtual HRESULT STDMETHODCALLTYPE CreateOrCondition( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition1,
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition2,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		  System::Boolean CreateOrCondition(
			UIACondition ^ condition1,
			UIACondition ^ condition2,
			[OutAttribute()] UIACondition ^% newCondition);
   //     virtual HRESULT STDMETHODCALLTYPE CreateOrConditionFromArray( 
   //         /* [in] */ __RPC__in_opt SAFEARRAY * conditions,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   //     
   //     virtual HRESULT STDMETHODCALLTYPE CreateOrConditionFromNativeArray( 
   //         /* [size_is][in] */ __RPC__in_ecount_full(conditionCount) IUIAutomationCondition **conditions,
   //         /* [in] */ int conditionCount,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		  System::Boolean CreateOrConditionFromArray(
			array<UIACondition^>^ conditions,
			[OutAttribute()] UIACondition ^% condition); 
   //     virtual HRESULT STDMETHODCALLTYPE CreateNotCondition( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
   //         /* [retval][out] */ __RPC__deref_out_opt IUIAutomationCondition **newCondition) = 0;
   
		  System::Boolean CreateNotCondition(UIACondition ^ condition,
			  [OutAttribute()] UIACondition ^% newCondition); 
   //     virtual HRESULT STDMETHODCALLTYPE AddAutomationEventHandler( 
   //         /* [in] */ EVENTID eventId,
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ enum TreeScope scope,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationEventHandler *handler) = 0;
   
		  bool   AddAutomationEventHandler( EventID eventId,
			  UIAElement ^ element,
			  UIACacheRequest ^ cacheRequest,
			  UIAEventHandler ^ handler);
   //     virtual HRESULT STDMETHODCALLTYPE RemoveAutomationEventHandler( 
   //         /* [in] */ EVENTID eventId,
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ __RPC__in_opt IUIAutomationEventHandler *handler) = 0;
   
		    bool   RemoveAutomationEventHandler( EventID eventId,
			  UIAElement ^ element,
			  UIAEventHandler ^ handler);
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
   
				bool AddPropertyChangedEventHandlerArray(
				UIAElement ^ element,
				TreeScope  scope,
				UIACacheRequest ^ cacheResult,
				UIAPropertyChangedEventHandler ^ handler,
				array<PROPERTYID>^ propertyArray);
   //     virtual HRESULT STDMETHODCALLTYPE RemovePropertyChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ __RPC__in_opt IUIAutomationPropertyChangedEventHandler *handler) = 0;
   //     
				bool RemovePropertyChangedEventHandler(
					UIAElement ^ element,
					UIAPropertyChangedEventHandler ^ handler);
   //     virtual HRESULT STDMETHODCALLTYPE AddStructureChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ enum TreeScope scope,
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationStructureChangedEventHandler *handler) = 0;
   
			bool AddStructureChangedEventHandler(
				UIAElement ^ element,
				TreeScope scope,
				UIACacheRequest ^ cacheResult,
				UIAStructureChangedEventHandler ^ handler);
   //     virtual HRESULT STDMETHODCALLTYPE RemoveStructureChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *element,
   //         /* [in] */ __RPC__in_opt IUIAutomationStructureChangedEventHandler *handler) = 0;
   
			bool RemoveStructureChangedEventHandler(
				UIAElement ^ element,
				UIAStructureChangedEventHandler ^ handler);
   //     virtual HRESULT STDMETHODCALLTYPE AddFocusChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
   //         /* [in] */ __RPC__in_opt IUIAutomationFocusChangedEventHandler *handler) = 0;
   
			bool AddFocusChangedEventHandler(
				UIAElement ^ element,
				UIAFocusChangedEventHandler ^ handler);
   //     virtual HRESULT STDMETHODCALLTYPE RemoveFocusChangedEventHandler( 
   //         /* [in] */ __RPC__in_opt IUIAutomationFocusChangedEventHandler *handler) = 0;
   
			bool RemoveFocusChangedEventHandler(UIAFocusChangedEventHandler ^handler);
   //     virtual HRESULT STDMETHODCALLTYPE RemoveAllEventHandlers( void) = 0;
   
			bool RemoveAllEventHandlers();
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
   
			bool GetPropertyProgrammaticName(PROPERTYID property,
				[OutAttribute()]System::String ^% name);
   //     virtual HRESULT STDMETHODCALLTYPE GetPatternProgrammaticName( 
   //         /* [in] */ PATTERNID pattern,
   //         /* [retval][out] */ __RPC__deref_out_opt BSTR *name) = 0;
   
			bool GetPropertyProgrammaticName(PATTERNID property,
				[OutAttribute()]System::String ^% name);
   //     virtual HRESULT STDMETHODCALLTYPE PollForPotentialSupportedPatterns( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *pElement,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *patternIds,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *patternNames) = 0;
   //     
			bool PollForPotentialSupportedPatterns(
				UIAElement ^ element,
				[OutAttribute()] array<PATTERNID>^% patternIds,
				[OutAttribute()] array<System::String^> ^% patternNames);
   //     virtual HRESULT STDMETHODCALLTYPE PollForPotentialSupportedProperties( 
   //         /* [in] */ __RPC__in_opt IUIAutomationElement *pElement,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *propertyIds,
   //         /* [out] */ __RPC__deref_out_opt SAFEARRAY * *propertyNames) = 0;
   
			bool PollForPotentialSupportedProperties(
				UIAElement ^ element,
				[OutAttribute()] array<PROPERTYID>^% patternIds,
				[OutAttribute()] array<System::String^> ^% propertyNames
				);
   //     virtual HRESULT STDMETHODCALLTYPE CheckNotSupported( 
   //         /* [in] */ VARIANT value,
   //         /* [retval][out] */ __RPC__out BOOL *isNotSupported) = 0;
   
			bool CheckNotSupported(System::Runtime::InteropServices::VarEnum varEnum,
				Object ^ value,
				[OutAttribute()] System::Boolean % isNotSupported);
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

	static System::Boolean CreateUIAutomation([OutAttribute()] UIAutomation ^% uiaAutomation);
	static void CloseUIAutomation(UIAutomation ^ automation);


	public:
		~UIAutomation()
		{
			GC::SuppressFinalize(this);
			this->!UIAutomation();
		}

		!UIAutomation()
		{
			if(nativieInstance_ != nullptr)
			{
				nativieInstance_->Release();
				nativieInstance_ = nullptr;
			}
		}
	internal:
		UIAutomation (IUIAutomation * data ) 
		{
			nativieInstance_ = data;
	    }
         
		IUIAutomation* GetNativeContent ()
		{
			return nativieInstance_;
 		}
	private:
		IUIAutomation * nativieInstance_;
	};

};

#endif