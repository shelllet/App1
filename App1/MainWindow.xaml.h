#pragma once

//#include "Dynamic.h"
#pragma push_macro("GetCurrentTime")
#undef GetCurrentTime

#include "MainWindow.g.h"
#include <winrt/Microsoft.UI.Xaml.Data.h>
#pragma pop_macro("GetCurrentTime")
using namespace winrt::Microsoft::UI::Xaml::Data;
namespace winrt::App1::implementation
{
    struct MainWindow : MainWindowT<MainWindow>
    {
        MainWindow();

        App1::Dynamic MyProperty();
        void MyProperty(App1::Dynamic const& value);
   
        void myButton_Click(Windows::Foundation::IInspectable const& sender, Microsoft::UI::Xaml::RoutedEventArgs const& args);
       App1:: Dynamic dynamic = { nullptr };
       App1:: Dynamic dynamic2 = { nullptr };
    };
}

namespace winrt::App1::factory_implementation
{
    struct MainWindow : MainWindowT<MainWindow, implementation::MainWindow>
    {
    };
}
