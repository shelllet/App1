#include "pch.h"
#include "Dynamic.h"
#include "Dynamic.g.cpp"

#include <regex>
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "winrt/Windows.UI.Xaml.h"
using namespace winrt::Microsoft::UI::Xaml;
namespace winrt::App1::implementation
{
	using namespace Windows::Foundation;

	
	static Microsoft::UI::Xaml::DependencyProperty G_switch_property =
		Microsoft::UI::Xaml::DependencyProperty::Register(
			L"Switch",
			winrt::xaml_typename<bool>(),
			winrt::xaml_typename<App1::Dynamic>(), nullptr
	);

#if 1
	static Microsoft::UI::Xaml::DependencyProperty G_value_property =
		Microsoft::UI::Xaml::DependencyProperty::Register(
			L"Value",
			winrt::xaml_typename<hstring>(),
			winrt::xaml_typename<App1::Dynamic>() ,nullptr
	);
#endif
#if 0
	static Microsoft::UI::Xaml::DependencyProperty G_value_property =
		Microsoft::UI::Xaml::DependencyProperty::Register(
			L"Value",
			winrt::xaml_typename<double>(),
			winrt::xaml_typename<App1::Dynamic>(),
			Microsoft::UI::Xaml::PropertyMetadata{ winrt::box_value(11.0),PropertyChangedCallback{ &OnNameChanged2 } }
	);
#endif



	static hstring m1(hstring const& text) {
		const std::regex base_reg(R"(\{?(.+)\}?)");
		std::smatch base_match;
		std::string s = winrt::to_string(text);
		if (std::regex_match(s, base_match, base_reg)) {
			return winrt::to_hstring(base_match[1].str());
		}
		return text;
	}

	static bool m2(hstring const& text) {
		const std::regex reg(R"(\{.+\})");
		std::smatch base_match;
		std::string s = winrt::to_string(text);
		if (std::regex_match(s, base_match, reg)) {
			return true;
		}

		return false;
	}
	Dynamic::Dynamic(hstring const& text)
	{
		SetValue(G_switch_property, winrt::box_value(m2(text)));
		SetValue(G_value_property, winrt::box_value(m1(text)));
	}



	hstring Dynamic::Text()
	{
		
		return winrt::unbox_value<hstring>(GetValue(G_value_property));
	}
	void Dynamic::Text(hstring const& value)
	{
		SetValue(G_value_property, winrt::box_value(value));


	}
	hstring Dynamic::ValueText()
	{
		if (!IsDynamic())
			return Text();

		return L"{" + Text() + L"}";
	}
	void Dynamic::ValueText(hstring const& value)
	{


		SetValue(G_switch_property, winrt::box_value(m2(value)));
		SetValue(G_value_property, winrt::box_value(m1(value)));
	}
	bool Dynamic::IsDynamic()
	{
		return winrt::unbox_value<bool>(GetValue(G_switch_property));
	}
	void Dynamic::IsDynamic(bool value)
	{



		SetValue(G_switch_property, winrt::box_value(value));


	}

	Windows::Foundation::IInspectable Dynamic::Convert(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language)
	{
		auto s = winrt::get_class_name(value);
		Log(L"1 type:" + s);
		Log(L"1 target: " + targetType.Name);
		return value;
		//double d = winrt::unbox_value<double>(value);
		return winrt::box_value(1.0);

	}

	Windows::Foundation::IInspectable Dynamic::ConvertBack(Windows::Foundation::IInspectable const& value, Windows::UI::Xaml::Interop::TypeName const& targetType, Windows::Foundation::IInspectable const& parameter, hstring const& language)
	{
		auto s = winrt::get_class_name(value);
		Log(L"2 type:" + s);
		Log(L"2 target: " + targetType.Name);
		return value;
	}

}
