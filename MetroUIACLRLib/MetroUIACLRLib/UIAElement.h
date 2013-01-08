#ifndef _UIA_ELEMENT_H_
#define _UIA_ELEMENT_H_

#include "UIACommon.h"
#include "UIACacheResult.h"
#include "UIACondition.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections;
using namespace System::Collections::Generic;
namespace MetroUIACLRLib{
	public ref class UIAElement  sealed
	{
	public:
		System::Int64 SetFocus();
		bool GetRuntimeId(
			[System::Runtime::InteropServices::OutAttribute()]
			array<System::Int32>^ % retVal);
		
        //virtual HRESULT STDMETHODCALLTYPE FindFirst( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **found) = 0;

			bool FindFirst(TreeScope scope,
				UIACondition ^ condition,
				[OutAttribute()] UIAElement^% found);
				

        //virtual HRESULT STDMETHODCALLTYPE FindAll( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **found) = 0;
        
			bool FindAll(TreeScope scope, 
				UIACondition ^ condition,
				[OutAttribute()] array<UIAElement ^>^ found);
        //virtual HRESULT STDMETHODCALLTYPE FindFirstBuildCache( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **found) = 0;


			bool FindFirstBuildCache(TreeScope scope,
				UIACondition ^ condition,
				UIACacheRequest ^ cacheResult,
				[OutAttribute()] UIAElement ^& found);
        //virtual HRESULT STDMETHODCALLTYPE FindAllBuildCache( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **found) = 0;

			bool FindAllBuildCache(TreeScope scope,
				UIACondition ^ condition,
				UIACacheRequest ^ cacheResult,
				[OutAttribute()] array<UIAElement ^> ^& found);
        //virtual HRESULT STDMETHODCALLTYPE BuildUpdatedCache( 
        //    /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **updatedElement) = 0;

			
           bool BuildUpdatedCache(
			   UIACacheRequest ^ cacheRequest
			   ,[OutAttribute()] UIAElement ^& updatedElement
			   );
        //virtual HRESULT STDMETHODCALLTYPE GetCurrentPropertyValue( 
        //    /* [in] */ PROPERTYID propertyId,
        //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
           
           bool GetCurrentPropertyValue(
			   PROPERTYID propertyId,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   );
    //    //virtual HRESULT STDMETHODCALLTYPE GetCurrentPropertyValueEx( 
    //    //    /* [in] */ PROPERTYID propertyId,
    //    //    /* [in] */ BOOL ignoreDefaultValue,
    //    //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
		   bool GetCurrentPropertyValueEx(
			   PROPERTYID propertyId,
			   System::Boolean ignoreDefaultValue,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   );
    //    //virtual HRESULT STDMETHODCALLTYPE GetCachedPropertyValue( 
    //    //    /* [in] */ PROPERTYID propertyId,
    //    //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
             bool GetCachedPropertyValue(
			   PROPERTYID propertyId,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   );
    //    //virtual HRESULT STDMETHODCALLTYPE GetCachedPropertyValueEx( 
    //    //    /* [in] */ PROPERTYID propertyId,
    //    //    /* [in] */ BOOL ignoreDefaultValue,
    //    //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
			  bool GetCachedPropertyValueEx(
			   PROPERTYID propertyId,
			   System::Boolean ignoreDefaultValue,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   );
    //    //virtual HRESULT STDMETHODCALLTYPE GetCurrentPatternAs( 
    //    //    /* [in] */ PATTERNID patternId,
    //    //    /* [in] */ __RPC__in REFIID riid,
    //    //    /* [retval][iid_is][out] */ __RPC__deref_out_opt void **patternObject) = 0;

			/*  Object GetCurrentPatternAs(
				PATTERNID patternId,
				Guid riid);*/
    //    //virtual HRESULT STDMETHODCALLTYPE GetCachedPatternAs( 
    //    //    /* [in] */ PATTERNID patternId,
    //    //    /* [in] */ __RPC__in REFIID riid,
    //    //    /* [retval][iid_is][out] */ __RPC__deref_out_opt void **patternObject) = 0;

          /*  Object GetCachedPatternAs(
				PATTERNID patternId,
				Guid riid);*/

        //virtual HRESULT STDMETHODCALLTYPE GetCachedParent( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **parent) = 0;

			bool CachedParent([OutAttribute()] UIAElement ^& parent);
        //virtual HRESULT STDMETHODCALLTYPE GetCachedChildren( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **children) = 0;

          bool CachedChildren([OutAttribute()] array<UIAElement^> ^& parent);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentProcessId( 
        //    /* [retval][out] */ __RPC__out int *retVal) = 0;

		bool CurrentProcessId([System::Runtime::InteropServices::OutAttribute()]
		System::Int32 %  retVal);

        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentControlType( 
        //    /* [retval][out] */ __RPC__out CONTROLTYPEID *retVal) = 0;

		bool CurrentControlType([OutAttribute()] CONTROLTYPEID % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentLocalizedControlType( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

         bool CurrentLocalizedControlType([OutAttribute()] String ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentName( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool CurrentName( [System::Runtime::InteropServices::OutAttribute()]
			String ^% retVal);
		
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAcceleratorKey( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

           bool CurrentAcceleratorKey( [System::Runtime::InteropServices::OutAttribute()]
			String ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAccessKey( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

            bool CurrentAccessKey( [System::Runtime::InteropServices::OutAttribute()]
			String ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentHasKeyboardFocus( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

            bool CurrentHasKeyboardFocus( [System::Runtime::InteropServices::OutAttribute()]
			System::Boolean % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsKeyboardFocusable( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

            bool CurrentIsKeyboardFocusable( [System::Runtime::InteropServices::OutAttribute()]
			System::Boolean % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsEnabled( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

            bool CurrentIsEnabled( [System::Runtime::InteropServices::OutAttribute()]
			System::Boolean % retVal);

        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAutomationId( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		
		bool CurrentAutomationId( [OutAttribute()]String ^% retVal);        
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentClassName( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool CurrentClassName( [OutAttribute()]String ^% retVal);       
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentHelpText( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool CurrentHelpText( [OutAttribute()]String ^% retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentCulture( 
        //    /* [retval][out] */ __RPC__out int *retVal) = 0;

		bool CurrentCulture( [OutAttribute()] System::Int32 % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsControlElement( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

		bool CurrentIsControlElement([OutAttribute()] System::Boolean % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsContentElement( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

		bool CurrentIsContentElement([OutAttribute()] System::Boolean % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsPassword( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

        bool CurrentIsPassword([OutAttribute()] System::Boolean % retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentNativeWindowHandle( 
        //    /* [retval][out] */ __RPC__deref_out_opt UIA_HWND *retVal) = 0;

		bool CurrentNativeWindowHandle(System::IntPtr  retVal);  
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentItemType( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
        
         bool CurrentItemType( [OutAttribute()]String ^% retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsOffscreen( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

		 bool CurrentIsOffscreen( [OutAttribute()]System::Boolean % retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentOrientation( 
        //    /* [retval][out] */ __RPC__out enum OrientationType *retVal) = 0;

		 bool CurrentOrientation( [OutAttribute()]OrientationType % retVal); 
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFrameworkId( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool CurrentFrameworkId( [OutAttribute()]String ^% retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsRequiredForForm( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

		bool CurrentIsRequiredForForm( [OutAttribute()]System::Boolean % retVal);  
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentItemStatus( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool CurrentItemStatus( [OutAttribute()]String ^% retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentBoundingRectangle( 
        //    /* [retval][out] */ __RPC__out RECT *retVal) = 0;
		bool CurrentBoundingRectangle([OutAttribute()] System::Windows::Rect % rect);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentLabeledBy( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **retVal) = 0;
		bool CurrentLabeledBy([OutAttribute()] UIAElement ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAriaRole( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
        
		bool CurrentAriaRole( [OutAttribute()]String ^% retVal);   
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAriaProperties( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
        
		bool CurrentAriaProperties( [OutAttribute()]String ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsDataValidForForm( 
        //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

		bool CurrentIsDataValidForForm( [OutAttribute()]System::Boolean % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentControllerFor( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;

		bool CurrentControllerFor( [OutAttribute()] array<UIAElement^> ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDescribedBy( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;

		bool CurrentDescribedBy( [OutAttribute()]array<UIAElement ^> ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFlowsTo( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;
		bool CurrentFlowsTo( [OutAttribute()] array<UIAElement^> ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentProviderDescription( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool CurrentProviderDescription( [OutAttribute()]System::String ^% retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedProcessId( 
        //    /* [retval][out] */ __RPC__out int *retVal) = 0;

		bool CachedProcessId( [OutAttribute()]System::Int32 % retVal);
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedControlType( 
        //    /* [retval][out] */ __RPC__out CONTROLTYPEID *retVal) = 0;

		//bool get_CachedControlType( [OutAttribute()]CONTROLTYPEID % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedLocalizedControlType( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool get_CachedLocalizedControlType( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedName( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool get_CachedName( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAcceleratorKey( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool get_CachedAcceleratorKey( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAccessKey( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool get_CachedAccessKey( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedHasKeyboardFocus( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
		//bool get_CachedHasKeyboardFocus( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsKeyboardFocusable( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
		//bool get_CachedIsKeyboardFocusable( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsEnabled( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
  //      bool get_CachedIsEnabled( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAutomationId( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		//bool get_CachedAutomationId( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedClassName( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

  //      bool get_CachedClassName( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedHelpText( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //     
		// bool get_CachedHelpText( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedCulture( 
  //      //    /* [retval][out] */ __RPC__out int *retVal) = 0;
  //      
		// bool get_CachedCulture( [OutAttribute()]System::Int32 % retVal);
  //      //virtual /* [proplget] */ HRESULT STDMETHODCALLTYPE get_CachedIsControlElement( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
  //      
		// bool get_CachedIsControlElement( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsContentElement( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
  //       bool get_CachedIsContentElement( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsPassword( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
  //      
		// bool get_CachedIsPassword( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedNativeWindowHandle( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt UIA_HWND *retVal) = 0;
  //      
		// bool get_CachedNativeWindowHandle( [OutAttribute()]System::IntPtr % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedItemType( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //      
		// bool get_CachedItemType( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsOffscreen( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
  //      
		// bool get_CachedIsOffscreen( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedOrientation( 
  //      //    /* [retval][out] */ __RPC__out enum OrientationType *retVal) = 0;
  //      
		//bool get_CachedOrientation( [OutAttribute()]OrientationType % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedFrameworkId( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		//bool get_CachedFrameworkId( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsRequiredForForm( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;

		//bool get_CachedIsRequiredForForm( [OutAttribute()]System::Boolean % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedItemStatus( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //     
		//bool get_CachedItemStatus( [OutAttribute()]System::String^ % retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedBoundingRectangle( 
  //      //    /* [retval][out] */ __RPC__out RECT *retVal) = 0;

		//bool get_CachedBoundingRectangle( [OutAttribute()]System::Windows::Rect & retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedLabeledBy( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **retVal) = 0;

		//bool get_CachedLabeledBy( [OutAttribute()]UIAElement ^& retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAriaRole( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //      
		//bool get_CachedAriaRole( [OutAttribute()] System::String ^& retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAriaProperties( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //      bool get_CachedAriaProperties( [OutAttribute()] System::String ^& retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsDataValidForForm( 
  //      //    /* [retval][out] */ __RPC__out BOOL *retVal) = 0;
  //      
		//bool get_CachedIsDataValidForForm( [OutAttribute()] System::Boolean & retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedControllerFor( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;
  //      
		//bool get_CachedControllerFor([OutAttribute()] array<UIAElement ^>^ retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedDescribedBy( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;

  //      bool get_CachedDescribedBy([OutAttribute()] array<UIAElement ^>^ retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedFlowsTo( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;
  //      
		//bool get_CachedFlowsTo([OutAttribute()] array<UIAElement ^>^ retVal);
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedProviderDescription( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) 
		//bool get_CachedProviderDescription([OutAttribute()] System::String ^& retVal);
  //      //virtual HRESULT STDMETHODCALLTYPE GetClickablePoint( 
  //      //    /* [out] */ __RPC__out POINT *clickable,
  //      //    /* [retval][out] */ __RPC__out BOOL *gotClickable) = 0;
  //      
		//bool GetClickablePoint([OutAttribute()] System::Windows::Point & clickable
		//	,[OutAttribute()]  System::Boolean & retVal);
	public:

		~UIAElement()
		{
			GC::SuppressFinalize(this);
			this->!UIAElement();
		}

		!UIAElement()
		{
			if(nativieInstance_ != nullptr && autoRelease_)
			{
				nativieInstance_->Release();
				nativieInstance_ = nullptr;
			}
		}
	internal:
		UIAElement (IUIAutomationElement * data ,bool autoRelease  ) 
			: nativieInstance_(data)
			, autoRelease_(autoRelease)
		{
	    }

		UIAElement (IUIAutomationElement * data ) 
		: nativieInstance_(data)
			, autoRelease_(true)
		{
	    }
	     
         
		IUIAutomationElement* GetNativeContent ()
		{
			return nativieInstance_;
 		}
	private:
	
		IUIAutomationElement * nativieInstance_;
		bool autoRelease_;
	};

}

#endif