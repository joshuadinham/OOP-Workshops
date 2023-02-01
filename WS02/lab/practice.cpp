#include "pch.h"
#include "practice.h"
#if __has_include("practice.g.cpp")
#include "practice.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::lab::implementation
{
    int32_t practice::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void practice::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void practice::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
