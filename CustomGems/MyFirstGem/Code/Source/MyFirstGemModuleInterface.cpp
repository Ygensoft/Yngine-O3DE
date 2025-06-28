
#include "MyFirstGemModuleInterface.h"
#include <AzCore/Memory/Memory.h>

#include <MyFirstGem/MyFirstGemTypeIds.h>

#include <Clients/MyFirstGemSystemComponent.h>

namespace MyFirstGem
{
    AZ_TYPE_INFO_WITH_NAME_IMPL(MyFirstGemModuleInterface,
        "MyFirstGemModuleInterface", MyFirstGemModuleInterfaceTypeId);
    AZ_RTTI_NO_TYPE_INFO_IMPL(MyFirstGemModuleInterface, AZ::Module);
    AZ_CLASS_ALLOCATOR_IMPL(MyFirstGemModuleInterface, AZ::SystemAllocator);

    MyFirstGemModuleInterface::MyFirstGemModuleInterface()
    {
        // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
        // Add ALL components descriptors associated with this gem to m_descriptors.
        // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
        // This happens through the [MyComponent]::Reflect() function.
        m_descriptors.insert(m_descriptors.end(), {
            MyFirstGemSystemComponent::CreateDescriptor(),
            });
    }

    AZ::ComponentTypeList MyFirstGemModuleInterface::GetRequiredSystemComponents() const
    {
        return AZ::ComponentTypeList{
            azrtti_typeid<MyFirstGemSystemComponent>(),
        };
    }
} // namespace MyFirstGem
