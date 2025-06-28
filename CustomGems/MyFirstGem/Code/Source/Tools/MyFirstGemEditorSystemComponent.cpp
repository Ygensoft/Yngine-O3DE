
#include <AzCore/Serialization/SerializeContext.h>
#include "MyFirstGemEditorSystemComponent.h"

#include <MyFirstGem/MyFirstGemTypeIds.h>

namespace MyFirstGem
{
    AZ_COMPONENT_IMPL(MyFirstGemEditorSystemComponent, "MyFirstGemEditorSystemComponent",
        MyFirstGemEditorSystemComponentTypeId, BaseSystemComponent);

    void MyFirstGemEditorSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<MyFirstGemEditorSystemComponent, MyFirstGemSystemComponent>()
                ->Version(0);
        }
    }

    MyFirstGemEditorSystemComponent::MyFirstGemEditorSystemComponent() = default;

    MyFirstGemEditorSystemComponent::~MyFirstGemEditorSystemComponent() = default;

    void MyFirstGemEditorSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        BaseSystemComponent::GetProvidedServices(provided);
        provided.push_back(AZ_CRC_CE("MyFirstGemEditorService"));
    }

    void MyFirstGemEditorSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        BaseSystemComponent::GetIncompatibleServices(incompatible);
        incompatible.push_back(AZ_CRC_CE("MyFirstGemEditorService"));
    }

    void MyFirstGemEditorSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
        BaseSystemComponent::GetRequiredServices(required);
    }

    void MyFirstGemEditorSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
        BaseSystemComponent::GetDependentServices(dependent);
    }

    void MyFirstGemEditorSystemComponent::Activate()
    {
        MyFirstGemSystemComponent::Activate();
        AzToolsFramework::EditorEvents::Bus::Handler::BusConnect();
    }

    void MyFirstGemEditorSystemComponent::Deactivate()
    {
        AzToolsFramework::EditorEvents::Bus::Handler::BusDisconnect();
        MyFirstGemSystemComponent::Deactivate();
    }

} // namespace MyFirstGem
