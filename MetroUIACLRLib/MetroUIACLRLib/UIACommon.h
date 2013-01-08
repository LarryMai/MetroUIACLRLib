#ifndef _UIA_COMMON_H_
#define _UIA_COMMON_H_

#include <Windows.h>

#include <objbase.h>
#include <shobjidl.h>
#include <uiautomation.h>
#include <appmodel.h>
#include <string>
#include "UIAEnum.h"
#include <vcclr.h>

using namespace std;
using namespace System;
using namespace System::Runtime::InteropServices;
#define CLR_MARSHAL_STRING(x) \
	(char*) System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(x).ToPointer()

#define CLR_MARSHAL_WSTRING(x) \
	(wchar_t*) System::Runtime::InteropServices::Marshal::StringToHGlobalUni(x).ToPointer()

#define CLR_MARSHAL_CSTRING(x) \
	(char*) System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(x).ToPointer()

#define CLR_MARSHAL_WCSTRING(x) \
	(wchar_t*) System::Runtime::InteropServices::Marshal::StringToHGlobalUni(x).ToPointer()

#define CLR_MARSHAL_FREE(x) \
	System::Runtime::InteropServices::Marshal::FreeHGlobal(IntPtr(x))


#define STDSTR2CLRSTR(varname, val) \
	varname = gcnew String(val.c_str());

#define CLRSTR2STDSTR(varname, val) \
	char* a_##varname = CLR_MARSHAL_CSTRING(val); \
	std::string varname(a_##varname); \
	CLR_MARSHAL_FREE(a_##varname);

#define WSTDSTR2CLRSTR(varname, val) \
	varname = gcnew String(val.c_str());

#define CLRSTR2WSTDSTR(varname, val) \
	wchar_t * a_##varname = CLR_MARSHAL_WCSTRING(val); \
	std::wstring varname(a_##varname); \
	CLR_MARSHAL_FREE(a_##varname);

//// Properties definition

template <unsigned int  size>
inline int get_string_literal_length(char (&strDestination)[size])
{
   return size;
}


#define PROPERTY_VALUETYPE_BOTH(dtype, propertyName)\
	public: \
	virtual property dtype propertyName\
{\
	dtype get() {return propertyName##_;}\
	void set(dtype value) {propertyName##_ = value;}\
}\
	private:\
	dtype propertyName##_;\



#define PROPERTY_STRING_BOTH(name) \
    property String ^ name \
	{ \
		String ^ get() \
		{ \
			String ^ value; \
			 int len = strlen(GetNativeContent(); \
			if( len==0 ) \
			   value = System::String::Empty ; \
			else \
			{  \
			   char * temp = GetInnerObject()->name; \
			   value =literal2SystemString(temp ,get_string_literal_length( GetNativeContent()->name), len); \
			} \
			return value; \
		} \
		void set(String^ value) \
		{ \
		    int strLiteralLength = get_string_literal_length(GetNativeContent()->name); \
		    if(value->Length <= strLiteralLength) \
			{\
			   CLRSTR2STDSTR(str, value); \
			   doCopy(GetInnerObject()->name,strLiteralLength,str); \
			}\
		}\
	}

#endif