
#pragma once

#include <AzToolsFramework/API/ToolsApplicationAPI.h>

#include <Clients/MyFirstGemSystemComponent.h>

namespace MyFirstGem
{
    /// System component for MyFirstGem editor
    class MyFirstGemEditorSystemComponent
        : public MyFirstGemSystemComponent
        , protected AzToolsFramework::EditorEvents::Bus::Handler
    {
        using BaseSystemComponent = MyFirstGemSystemComponent;
    public:
        AZ_COMPONENT_DECL(MyFirstGemEditorSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        MyFirstGemEditorSystemComponent();
        ~MyFirstGemEditorSystemComponent();

    private:
        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        // AZ::Component
        void Activate() override;
        void Deactivate() override;
    };
} // namespace MyFirstGem
