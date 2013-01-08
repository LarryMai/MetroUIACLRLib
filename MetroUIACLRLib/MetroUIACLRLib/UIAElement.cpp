#include "UIAElement.h"

using namespace System;

namespace MetroUIACLRLib {
	System::Int64 UIAElement::SetFocus()
	{
		if(this->GetNativeContent() ==nullptr)
			return 0;
		else
			return this->GetNativeContent()->SetFocus();
	}
	
	bool UIAElement::GetRuntimeId(
			[System::Runtime::InteropServices::OutAttribute()]
			array<System::Int32>^ % retVal)
	{
		 if(this->GetNativeContent() ==nullptr)
			return false;

			SAFEARRAY * safeArray = nullptr;
			HRESULT hr=
				this->GetNativeContent()->GetRuntimeId(&safeArray);
			if(SUCCEEDED(hr))
			{
				ULONG elements = safeArray->rgsabound->cElements;
				retVal = gcnew array<System::Int32>(elements);

				for(LONG i=0;i<elements;++i)
				{
					int value = 0;
					SafeArrayGetElement(safeArray,&i,&value);
					retVal->SetValue(value , i);
				}
				SafeArrayDestroy(safeArray);
			}
			return SUCCEEDED(hr);
	}
		
        //virtual HRESULT STDMETHODCALLTYPE FindFirst( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **found) = 0;

			bool UIAElement::FindFirst(TreeScope scope,
				UIACondition ^ condition,
				[OutAttribute()] UIAElement ^% found)
			{
				if(this->GetNativeContent() ==nullptr
			        )
					return false;
				else
				{
					IUIAutomationElement * element;
					HRESULT hr = this->GetNativeContent()->FindFirst(
						(::TreeScope)scope,
						condition->GetNativeContent(),
						&element);

					if(SUCCEEDED(hr))
					{
						found = gcnew UIAElement(element);
					}

					return SUCCEEDED(hr);
				}
			}
				

        //virtual HRESULT STDMETHODCALLTYPE FindAll( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **found) = 0;
        
			bool UIAElement::FindAll(TreeScope scope, 
				UIACondition ^ condition,
				[OutAttribute()] array<UIAElement ^>^ found)
		{
			if(this->GetNativeContent() ==nullptr)
				return false;

			IUIAutomationElementArray * elementArray = nullptr;
			HRESULT hr =this->GetNativeContent()->FindAll(
				(::TreeScope)scope,
				condition->GetNativeContent(),
				&elementArray);

			if(SUCCEEDED(hr))
			{
				int count =0;
				hr = elementArray->get_Length(&count);
	
				if(SUCCEEDED(hr))
				{
					found = gcnew array<UIAElement ^ >(count);
					IUIAutomationElement * element =nullptr;
					for(int index =0;index<count;++index)
					{
						hr = elementArray->GetElement(index,&element);
						if(SUCCEEDED(hr))
						{
							found[index] = gcnew UIAElement(element);
						}
						else
						{
							
							for(int deleteIndex =0 ;deleteIndex <=index
								;++deleteIndex)
							{
								try{
								found[deleteIndex]->GetNativeContent()->Release();
								}catch(...){}
							}
							break;
						}
					}
				}

				elementArray->Release();
			}

			return SUCCEEDED(hr);
		}
        //virtual HRESULT STDMETHODCALLTYPE FindFirstBuildCache( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **found) = 0;


			bool UIAElement::FindFirstBuildCache(TreeScope scope,
				UIACondition ^ condition,
				UIACacheRequest ^ cacheResult,
				[OutAttribute()] UIAElement ^& found)
		{
			throw gcnew NotImplementedException();
		}
        //virtual HRESULT STDMETHODCALLTYPE FindAllBuildCache( 
        //    /* [in] */ enum TreeScope scope,
        //    /* [in] */ __RPC__in_opt IUIAutomationCondition *condition,
        //    /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **found) = 0;

			bool UIAElement::FindAllBuildCache(TreeScope scope,
				UIACondition ^ condition,
				UIACacheRequest ^ cacheResult,
				[OutAttribute()] array<UIAElement ^> ^& found)
		{
			throw gcnew NotImplementedException();
		}
        //virtual HRESULT STDMETHODCALLTYPE BuildUpdatedCache( 
        //    /* [in] */ __RPC__in_opt IUIAutomationCacheRequest *cacheRequest,
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **updatedElement) = 0;

			
           bool UIAElement::BuildUpdatedCache(
			   UIACacheRequest ^ cacheRequest
			   ,[OutAttribute()] UIAElement ^& updatedElement
			   )
		{
			throw gcnew NotImplementedException();
		}
        //virtual HRESULT STDMETHODCALLTYPE GetCurrentPropertyValue( 
            ///* [in] */ PROPERTYID propertyId,
            ///* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
           
           bool UIAElement::GetCurrentPropertyValue(
			   PROPERTYID propertyId,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   )
		{
			throw gcnew NotImplementedException();
		}
  //      //virtual HRESULT STDMETHODCALLTYPE GetCurrentPropertyValueEx( 
  //      //    /* [in] */ PROPERTYID propertyId,
  //      //    /* [in] */ bool UIAElement::ignoreDefaultValue,
  //      //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
		   bool UIAElement::GetCurrentPropertyValueEx(
			   PROPERTYID propertyId,
			   System::Boolean ignoreDefaultValue,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   )
		{
			throw gcnew NotImplementedException();
		}
  //      //virtual HRESULT STDMETHODCALLTYPE GetCachedPropertyValue( 
  //      //    /* [in] */ PROPERTYID propertyId,
  //      //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
        bool UIAElement::GetCachedPropertyValue(
			   PROPERTYID propertyId,
			   [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
			   [OutAttribute()]  System::Object ^% retVal
			   )
		{
			throw gcnew NotImplementedException();
		}
  //      //virtual HRESULT STDMETHODCALLTYPE GetCachedPropertyValueEx( 
  //      //    /* [in] */ PROPERTYID propertyId,
  //      //    /* [in] */ bool UIAElement::ignoreDefaultValue,
  //      //    /* [retval][out] */ __RPC__out VARIANT *retVal) = 0;
		bool UIAElement::GetCachedPropertyValueEx(
		PROPERTYID propertyId,
		System::Boolean ignoreDefaultValue,
	    [OutAttribute()]  System::Runtime::InteropServices::VarEnum % varEnum,
	    [OutAttribute()]  System::Object ^% retVal
	    )
		{
			throw gcnew NotImplementedException();
		}
        //virtual HRESULT STDMETHODCALLTYPE GetCurrentPatternAs( 
        //    /* [in] */ PATTERNID patternId,
        //    /* [in] */ __RPC__in REFIID riid,
        //    /* [retval][iid_is][out] */ __RPC__deref_out_opt void **patternObject) = 0;

		/*Object GetCurrentPatternAs(
		PATTERNID patternId,
		Guid riid)
		{
			throw gcnew NotImplementedException();
		}*/
        //virtual HRESULT STDMETHODCALLTYPE GetCachedPatternAs( 
        //    /* [in] */ PATTERNID patternId,
        //    /* [in] */ __RPC__in REFIID riid,
        //    /* [retval][iid_is][out] */ __RPC__deref_out_opt void **patternObject) = 0;

       /* Object GetCachedPatternAs(PATTERNID patternId,Guid riid)
		{
			throw gcnew NotImplementedException();
		}*/

        //virtual HRESULT STDMETHODCALLTYPE GetCachedParent( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **parent) = 0;

		bool UIAElement::CachedParent([OutAttribute()] UIAElement ^& parent)
		{
			throw gcnew NotImplementedException();
		}
        //virtual HRESULT STDMETHODCALLTYPE GetCachedChildren( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **children) = 0;

        bool UIAElement::CachedChildren([OutAttribute()] array<UIAElement^> ^& parent)
		{
			throw gcnew NotImplementedException();
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentProcessId( 
        //    /* [retval][out] */ __RPC__out int *retVal) = 0;

		bool UIAElement::CurrentProcessId([System::Runtime::InteropServices::OutAttribute()]
		System::Int32 %  retVal)
		{
			if(GetNativeContent() ==nullptr)
				return false;
			int processId =0;
			HRESULT hr = GetNativeContent()->get_CurrentProcessId(&processId);

			if(SUCCEEDED(hr))
			{
				retVal =processId;		
			}
			return SUCCEEDED(hr);
		}

        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentControlType( 
        //    /* [retval][out] */ __RPC__out CONTROLTYPEID *retVal) = 0;

		bool UIAElement::CurrentControlType([OutAttribute()] CONTROLTYPEID % retVal)
		{
			throw gcnew NotImplementedException();
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentLocalizedControlType( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool UIAElement::CurrentLocalizedControlType([OutAttribute()] String ^% retVal)
		{
			throw gcnew NotImplementedException();
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentName( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool UIAElement::CurrentName( [System::Runtime::InteropServices::OutAttribute()]
			String ^% retVal)
		{		
			if(GetNativeContent() == nullptr)
				return false;

			BSTR temp = nullptr;
			HRESULT hr =GetNativeContent()->
				get_CurrentName(&temp);

			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(temp);
				SysFreeString(temp);
			}
			return SUCCEEDED(hr); 
		}
           
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAcceleratorKey( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool UIAElement::CurrentAcceleratorKey( 
			[OutAttribute()] String ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			BSTR temp = nullptr;
			HRESULT hr =GetNativeContent()->get_CurrentAcceleratorKey
				(&temp);

			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(temp);
				SysFreeString(temp);
			}
			return SUCCEEDED(hr); 
		}
						
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAccessKey( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool UIAElement::CurrentAccessKey( [OutAttribute()]
		String ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			BSTR temp = nullptr;
			HRESULT hr =GetNativeContent()->get_CurrentAccessKey
				(&temp);

			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(temp);
				SysFreeString(temp);
			}
			return SUCCEEDED(hr); 
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentHasKeyboardFocus( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

            bool UIAElement::CurrentHasKeyboardFocus( [OutAttribute()]
			System::Boolean % retVal)
			{
				throw gcnew NotImplementedException();
			}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsKeyboardFocusable( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

            bool UIAElement::CurrentIsKeyboardFocusable(
				[OutAttribute()]System::Boolean % retVal)
			{
				throw gcnew NotImplementedException();
			}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsEnabled( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

        bool UIAElement::CurrentIsEnabled( [System::Runtime::InteropServices::OutAttribute()]
			System::Boolean % retVal)
		{
			throw gcnew NotImplementedException();
		}

        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAutomationId( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		
		bool UIAElement::CurrentAutomationId( [OutAttribute()]String ^% retVal)
		{
			if(GetNativeContent() == nullptr)
				return false;

			BSTR temp = nullptr;
			HRESULT hr =GetNativeContent()->
				get_CurrentAutomationId(&temp);

			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(temp);
				SysFreeString(temp);
			}
			return SUCCEEDED(hr); 
		}
            
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentClassName( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool UIAElement::CurrentClassName( [OutAttribute()]String ^% retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BSTR value =nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentName(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(retVal);
			    SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentHelpText( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool UIAElement::CurrentHelpText( [OutAttribute()]String ^% retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BSTR value =nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentHelpText(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(retVal);
			    SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentCulture( 
        //    /* [retval][out] */ __RPC__out int *retVal) = 0;

		bool UIAElement::CurrentCulture( [OutAttribute()] System::Int32 % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			int value =0;
			HRESULT hr = this->GetNativeContent()->get_CurrentCulture(&value);
			if(SUCCEEDED(hr))
			{
				retVal =value;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsControlElement( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

		bool UIAElement::CurrentIsControlElement([OutAttribute()] System::Boolean % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BOOL value =FALSE;
			HRESULT hr = this->GetNativeContent()->get_CurrentIsControlElement(&value);
			if(SUCCEEDED(hr))
			{
				retVal = value==TRUE?true:false;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsContentElement( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

		bool UIAElement::CurrentIsContentElement([OutAttribute()] System::Boolean % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BOOL value =FALSE;
			HRESULT hr = this->GetNativeContent()->get_CurrentIsControlElement(&value);
			if(SUCCEEDED(hr))
			{
				retVal = value==TRUE?true:false;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsPassword( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

        bool UIAElement::CurrentIsPassword([OutAttribute()] System::Boolean % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BOOL value =FALSE;
			HRESULT hr = this->GetNativeContent()->get_CurrentIsPassword(&value);
			if(SUCCEEDED(hr))
			{
				retVal = value==TRUE?true:false;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentNativeWindowHandle( 
        //    /* [retval][out] */ __RPC__deref_out_opt UIA_HWND *retVal) = 0;

		bool UIAElement::CurrentNativeWindowHandle(System::IntPtr  retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			UIA_HWND value =nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentNativeWindowHandle(&value);
			if(SUCCEEDED(hr))
			{
				retVal =  IntPtr(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentItemType( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
        
        bool UIAElement::CurrentItemType( [OutAttribute()]String ^% retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BSTR value =nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentItemType(&value);
			if(SUCCEEDED(hr))
			{
				retVal =  gcnew String(value);
				SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsOffscreen( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

		bool UIAElement::CurrentIsOffscreen( [OutAttribute()]System::Boolean % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BOOL value =FALSE;
			HRESULT hr = this->GetNativeContent()->get_CurrentIsPassword(&value);
			if(SUCCEEDED(hr))
			{
				retVal = value==TRUE?true:false;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentOrientation( 
        //    /* [retval][out] */ __RPC__out enum OrientationType *retVal) = 0;

		bool UIAElement::CurrentOrientation( [OutAttribute()]OrientationType % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			::OrientationType value = ::OrientationType::OrientationType_None;
			HRESULT hr = this->GetNativeContent()->get_CurrentOrientation(&value);
			if(SUCCEEDED(hr))
			{
				retVal = static_cast<OrientationType>(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFrameworkId( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

        bool UIAElement::CurrentFrameworkId( [OutAttribute()]String ^% retVal)
		{
			//throw gcnew NotImplementedException();

			if(this->GetNativeContent() == nullptr)
				return false;

			BSTR value = nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentFrameworkId(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(value);
				SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsRequiredForForm( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

		bool UIAElement::CurrentIsRequiredForForm( 
			[OutAttribute()]System::Boolean % retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BOOL value =FALSE;
			HRESULT hr = this->GetNativeContent()->get_CurrentIsRequiredForForm(&value);
			if(SUCCEEDED(hr))
			{
				retVal = value==TRUE?true:false;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentItemStatus( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool UIAElement::CurrentItemStatus( [OutAttribute()]String ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			BSTR value = nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentItemStatus(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(value);
				SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentBoundingRectangle( 
        //    /* [retval][out] */ __RPC__out RECT *retVal) = 0;
		bool UIAElement::CurrentBoundingRectangle(
			[OutAttribute()] System::Windows::Rect % rect)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			RECT value ;
			HRESULT hr = this->GetNativeContent()->get_CurrentBoundingRectangle(&value);
			if(SUCCEEDED(hr))
			{
				rect =  System::Windows::Rect(value.left,value.top
					, (value.right-value.bottom), (value.bottom-value.top));
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentLabeledBy( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **retVal) = 0;
		bool UIAElement::CurrentLabeledBy([OutAttribute()] UIAElement ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			IUIAutomationElement * value ;
			HRESULT hr = this->GetNativeContent()->get_CurrentLabeledBy(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew UIAElement(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAriaRole( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
        
		bool UIAElement::CurrentAriaRole( [OutAttribute()]String ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			BSTR value = nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentAriaRole(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(value);
				SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentAriaProperties( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
        
		bool UIAElement::CurrentAriaProperties( [OutAttribute()]String ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			BSTR value = nullptr;
			HRESULT hr = this->GetNativeContent()->get_CurrentAriaProperties(&value);
			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(value);
				SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentIsDataValidForForm( 
        //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

		bool UIAElement::CurrentIsDataValidForForm(
			[OutAttribute()]System::Boolean % retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			BOOL value = FALSE;
			HRESULT hr = this->GetNativeContent()->get_CurrentIsDataValidForForm(&value);
			if(SUCCEEDED(hr))
			{
				retVal = value==TRUE?true:false;
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentControllerFor( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;

		bool UIAElement::CurrentControllerFor(
			[OutAttribute()]array<UIAElement^> ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			IUIAutomationElementArray * elementArray ;
			HRESULT hr = this->GetNativeContent()->get_CurrentControllerFor(&elementArray);

			if(FAILED(hr))
			   return false;

			int count =0;
			hr = elementArray->get_Length(&count);
	
			if(FAILED(hr))
			goto END;

			retVal = gcnew array<UIAElement ^ >(count);
			IUIAutomationElement * element =nullptr;
			for(int index =0;index<count;++index)
			{
				hr = elementArray->GetElement(index,&element);
				if(SUCCEEDED(hr))
				{
					retVal[index] = gcnew UIAElement(element);
				}
				else
				{		
					for(int deleteIndex =0 ;deleteIndex <index
						;++deleteIndex)
					{
						try{
							retVal[deleteIndex]->GetNativeContent()->Release();
						}catch(...){}
					}
					goto END;
				}
			}
	END:
			elementArray->Release();
			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentDescribedBy( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;

		bool UIAElement::CurrentDescribedBy( [OutAttribute()]array<UIAElement^> ^% retVal)
		{
			if(this->GetNativeContent() == nullptr)
				return false;

			IUIAutomationElementArray * elementArray ;
			HRESULT hr = this->GetNativeContent()->get_CurrentDescribedBy(&elementArray);

			if(FAILED(hr))
			   return false;

			int count =0;
			hr = elementArray->get_Length(&count);
	
			if(FAILED(hr))
			goto END;

			retVal = gcnew array<UIAElement ^ >(count);
			IUIAutomationElement * element =nullptr;
			for(int index =0;index<count;++index)
			{
				hr = elementArray->GetElement(index,&element);
				if(SUCCEEDED(hr))
				{
					retVal[index] = gcnew UIAElement(element);
				}
				else
				{		
					for(int deleteIndex =0 ;deleteIndex <index
						;++deleteIndex)
					{
						try{
							retVal[deleteIndex]->GetNativeContent()->Release();
						}catch(...){}
					}
					goto END;
				}
			}
	END:
			elementArray->Release();
			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentFlowsTo( 
        //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;
		bool UIAElement::CurrentFlowsTo( [OutAttribute()]array<UIAElement^> ^% retVal)
		{
						if(this->GetNativeContent() == nullptr)
				return false;

			IUIAutomationElementArray * elementArray ;
			HRESULT hr = this->GetNativeContent()->get_CurrentFlowsTo(&elementArray);

			if(FAILED(hr))
			   return false;

			int count =0;
			hr = elementArray->get_Length(&count);
	
			if(FAILED(hr))
			goto END;

			retVal = gcnew array<UIAElement ^ >(count);
			IUIAutomationElement * element =nullptr;
			for(int index =0;index<count;++index)
			{
				hr = elementArray->GetElement(index,&element);
				if(SUCCEEDED(hr))
				{
					retVal[index] = gcnew UIAElement(element);
				}
				else
				{		
					for(int deleteIndex =0 ;deleteIndex <index
						;++deleteIndex)
					{
						try{
							retVal[deleteIndex]->GetNativeContent()->Release();
						}catch(...){}
					}
					goto END;
				}
			}
	END:
			elementArray->Release();
			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CurrentProviderDescription( 
        //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		bool UIAElement::CurrentProviderDescription( 
			[OutAttribute()]System::String ^% retVal)
		{
			if(this->GetNativeContent()==nullptr)
				return false;

			BSTR value=nullptr;
			HRESULT hr= this->GetNativeContent()->
				get_CurrentProviderDescription(&value);

			if(SUCCEEDED(hr))
			{
				retVal = gcnew String(value);
				SysFreeString(value);
			}

			return SUCCEEDED(hr);
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedProcessId( 
        //    /* [retval][out] */ __RPC__out int *retVal) = 0;

		bool UIAElement::CachedProcessId( [OutAttribute()]System::Int32 % retVal)
		{
			throw gcnew NotImplementedException();
		}
        //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedControlType( 
        //    /* [retval][out] */ __RPC__out CONTROLTYPEID *retVal) = 0;

		//bool UIAElement::get_CachedControlType( [OutAttribute()]CONTROLTYPEID % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedLocalizedControlType( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool UIAElement::get_CachedLocalizedControlType(
		//	[OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedName( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool UIAElement::get_CachedName( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAcceleratorKey( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool UIAElement::get_CachedAcceleratorKey( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAccessKey( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
		//bool UIAElement::get_CachedAccessKey( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedHasKeyboardFocus( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
		//bool UIAElement::get_CachedHasKeyboardFocus( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsKeyboardFocusable( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
		//bool UIAElement::get_CachedIsKeyboardFocusable( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsEnabled( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
  //      bool UIAElement::get_CachedIsEnabled( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAutomationId( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		//bool UIAElement::get_CachedAutomationId( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedClassName( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

  //      bool UIAElement::get_CachedClassName( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedHelpText( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //     
		// bool UIAElement::get_CachedHelpText( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedCulture( 
  //      //    /* [retval][out] */ __RPC__out int *retVal) = 0;
  //      
		// bool UIAElement::get_CachedCulture( [OutAttribute()]System::Int32 % retVal)
		// {
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [proplget] */ HRESULT STDMETHODCALLTYPE get_CachedIsControlElement( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
  //      
		//bool UIAElement::get_CachedIsControlElement( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsContentElement( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
  //      bool UIAElement::get_CachedIsContentElement( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsPassword( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
  //      
		//bool UIAElement::get_CachedIsPassword( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedNativeWindowHandle( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt UIA_HWND *retVal) = 0;
  //      
		//bool UIAElement::get_CachedNativeWindowHandle( [OutAttribute()]System::IntPtr % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedItemType( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //      
		//bool UIAElement::get_CachedItemType( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsOffscreen( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
  //      
		// bool UIAElement::get_CachedIsOffscreen( [OutAttribute()]System::Boolean % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedOrientation( 
  //      //    /* [retval][out] */ __RPC__out enum OrientationType *retVal) = 0;
  //      
		//bool UIAElement::get_CachedOrientation( [OutAttribute()]OrientationType % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedFrameworkId( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;

		//bool UIAElement::get_CachedFrameworkId( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsRequiredForForm( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;

		//bool UIAElement::get_CachedIsRequiredForForm( [OutAttribute()]System::Boolean % retVal){
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedItemStatus( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //     
		//bool UIAElement::get_CachedItemStatus( [OutAttribute()]System::String^ % retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedBoundingRectangle( 
  //      //    /* [retval][out] */ __RPC__out RECT *retVal) = 0;

		//bool UIAElement::get_CachedBoundingRectangle( [OutAttribute()]System::Windows::Rect & retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedLabeledBy( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElement **retVal) = 0;

		//bool UIAElement::get_CachedLabeledBy( [OutAttribute()]UIAElement ^& retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}

  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAriaRole( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //      
		//bool UIAElement::get_CachedAriaRole( [OutAttribute()] System::String ^& retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedAriaProperties( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) = 0;
  //      bool UIAElement::get_CachedAriaProperties( [OutAttribute()] System::String ^& retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedIsDataValidForForm( 
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*retVal) = 0;
  //      
		//bool UIAElement::get_CachedIsDataValidForForm( [OutAttribute()] System::Boolean & retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedControllerFor( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;
  //      
		//bool UIAElement::get_CachedControllerFor([OutAttribute()] array<UIAElement ^>^ retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedDescribedBy( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;

  //      bool UIAElement::get_CachedDescribedBy([OutAttribute()] array<UIAElement ^>^ retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedFlowsTo( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt IUIAutomationElementArray **retVal) = 0;
  //      
		//bool UIAElement::get_CachedFlowsTo([OutAttribute()] array<UIAElement ^>^ retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CachedProviderDescription( 
  //      //    /* [retval][out] */ __RPC__deref_out_opt BSTR *retVal) 
		//bool UIAElement::get_CachedProviderDescription([OutAttribute()] System::String ^& retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}
  //      //virtual HRESULT STDMETHODCALLTYPE GetClickablePoint( 
  //      //    /* [out] */ __RPC__out POINT *clickable,
  //      //    /* [retval][out] */ __RPC__out bool UIAElement::*gotClickable) = 0;
  //      
		//bool UIAElement::GetClickablePoint([OutAttribute()] System::Windows::Point & clickable
		//	,[OutAttribute()]  System::Boolean & retVal)
		//{
		//	throw gcnew NotImplementedException();
		//}

};