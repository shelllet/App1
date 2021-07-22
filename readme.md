# Binding does not work in winrt c++ desktop

binding code in cpp.

```
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
```


idl defined in used component.

```
import "Dynamic.idl";

namespace App1
{
    [default_interface]
    runtimeclass MainWindow : Microsoft.UI.Xaml.Window
    {
        MainWindow();
        //Dynamic MyProperty;
    }
}

```

if I add `Dynamic` property in `MainWindow` idl file , this works fine.  otherwise if I comment `Dynamic` property, the binding will don't work. maybe `biding2.Path(PropertyPath(L"Value"));` has inernal bug. and if i remove binding path set, it's also works fine. 

https://github.com/microsoft/microsoft-ui-xaml/issues/4848
