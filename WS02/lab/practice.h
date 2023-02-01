#pragma once

#include "practice.g.h"

namespace winrt::lab::implementation
{
    struct practice : practiceT<practice>
    {
        practice() 
        {
            // Xaml objects should not call InitializeComponent during construction.
            // See https://github.com/microsoft/cppwinrt/tree/master/nuget#initializecomponent
        }

        int32_t MyProperty();
        void MyProperty(int32_t value);

        void ClickHandler(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);
    };
}

namespace winrt::lab::factory_implementation
{
    struct practice : practiceT<practice, implementation::practice>
    {
    };
}
