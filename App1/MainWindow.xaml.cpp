#include "pch.h"
#include "MainWindow.xaml.h"
#if __has_include("MainWindow.g.cpp")
#include "MainWindow.g.cpp"
#endif
#include "winrt/Windows.UI.Xaml.Interop.h"
#include "Dynamic.h"
using namespace winrt;
using namespace Microsoft::UI::Xaml;
// To learn more about WinUI, the WinUI project structure,
// and more about our project templates, see: http://aka.ms/winui-project-info.

namespace winrt::App1::implementation
{
#if 1
	static Microsoft::UI::Xaml::DependencyProperty G_value_property =
		Microsoft::UI::Xaml::DependencyProperty::Register(
			L"Value1",
			winrt::xaml_typename<hstring>(),
			winrt::xaml_typename<App1::MainWindow>(), nullptr 
	);
#endif

    MainWindow::MainWindow()
    {
        InitializeComponent();
#if 0
        {
			Binding biding;
        dynamic = winrt::make<implementation::Dynamic>(L"100");
		biding.Converter(dynamic);
        biding.Mode(Data::BindingMode::TwoWay);


        biding.UpdateSourceTrigger(Data::UpdateSourceTrigger::PropertyChanged);

        biding.Source(dynamic);
        biding.Path(PropertyPath(L"Value"));
        Num().SetBinding(Num().ValueProperty(), biding);
       
        }
#endif // 0

#if 1
        {
			Binding biding2;

			dynamic2 = winrt::make<implementation::Dynamic>(L"100");
			biding2.Converter(dynamic2);
			biding2.Mode(Data::BindingMode::TwoWay);


			biding2.UpdateSourceTrigger(Data::UpdateSourceTrigger::PropertyChanged);

			biding2.Source(dynamic2);
			biding2.Path(PropertyPath(L"Value"));
            Hd().SetBinding(Hd().TextProperty(), biding2);
        }
#endif // 0
    }

    App1::Dynamic MainWindow::MyProperty()
    {
        return dynamic2;
    }

    void MainWindow::MyProperty(App1::Dynamic const & /* value */)
    {
        throw hresult_not_implemented();
    }

    void MainWindow::myButton_Click(IInspectable const&, RoutedEventArgs const&)
    {
        OutputDebugStringA("1:\t");

        OutputDebugStringA(winrt::to_string(dynamic2.ValueText()).c_str());
        OutputDebugStringA("\r\n");
        OutputDebugStringA("2:\t");
        OutputDebugStringA(winrt::to_string(dynamic.ValueText()).c_str());
        OutputDebugStringA("\r\n");
    }
}
