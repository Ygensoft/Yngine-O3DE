
#include "MyFirstGemSystemComponent.h"

#include <MyFirstGem/MyFirstGemTypeIds.h>

#include <AzCore/Serialization/SerializeContext.h>

namespace MyFirstGem
{
    AZ_COMPONENT_IMPL(MyFirstGemSystemComponent, "MyFirstGemSystemComponent",
        MyFirstGemSystemComponentTypeId);

    void MyFirstGemSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<MyFirstGemSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void MyFirstGemSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("MyFirstGemService"));
    }

    void MyFirstGemSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("MyFirstGemService"));
    }

    void MyFirstGemSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void MyFirstGemSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    MyFirstGemSystemComponent::MyFirstGemSystemComponent()
    {
        if (MyFirstGemInterface::Get() == nullptr)
        {
            MyFirstGemInterface::Register(this);
        }
    }

    MyFirstGemSystemComponent::~MyFirstGemSystemComponent()
    {
        if (MyFirstGemInterface::Get() == this)
        {
            MyFirstGemInterface::Unregister(this);
        }
    }

    void MyFirstGemSystemComponent::Init()
    {
    }

    void MyFirstGemSystemComponent::Activate()
    {
        MyFirstGemRequestBus::Handler::BusConnect();
        AZ::TickBus::Handler::BusConnect();
    }

    void MyFirstGemSystemComponent::Deactivate()
    {
        AZ::TickBus::Handler::BusDisconnect();
        MyFirstGemRequestBus::Handler::BusDisconnect();
    }

    void MyFirstGemSystemComponent::OnTick([[maybe_unused]] float deltaTime, [[maybe_unused]] AZ::ScriptTimePoint time)
    {
    }

} // namespace MyFirstGem
