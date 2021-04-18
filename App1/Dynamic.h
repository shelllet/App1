#pragma once
#include "Dynamic.g.h"



namespace winrt::App1::implementation
{

	static inline void Log(hstring const& s) {
		OutputDebugStringW(s.c_str());
		OutputDebugStringW(L"\r\n");
	}

	struct DynamicPrivate;
	struct Dynamic : DynamicT<Dynamic>
	{
		Dynamic(hstring const& text);

		hstring Text();
		void Text(hstring const& value);

		hstring ValueText();
		void ValueText(hstring const& value);
		bool IsDynamic();
		void IsDynamic(bool value);

		Windows::Foundation::IInspectable Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);

		Windows::Foundation::IInspectable ConvertBack(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language);
		
		template<typename T>
		T dynamic_Value() {
			try
			{
				return py::globals()[winrt::to_string(ValueText()).c_str()].cast<T>();

			}
			catch (const py::error_already_set&)
			{

			}

			return {};
		}

		template<typename T>
		T static_Value() {
			try
			{
				return boost::lexical_cast<T>(winrt::to_string(ValueText()).c_str());

			}
			catch (const boost::bad_lexical_cast&)
			{

			}

			return {};
		}
	};
}
namespace winrt::App1::factory_implementation
{
	struct Dynamic : DynamicT<Dynamic, implementation::Dynamic>
	{
	};
}
