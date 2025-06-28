
#include <MyFirstGem/MyFirstGemTypeIds.h>
#include <MyFirstGemModuleInterface.h>
#include "MyFirstGemEditorSystemComponent.h"

namespace MyFirstGem
{
    class MyFirstGemEditorModule
        : public MyFirstGemModuleInterface
    {
    public:
        AZ_RTTI(MyFirstGemEditorModule, MyFirstGemEditorModuleTypeId, MyFirstGemModuleInterface);
        AZ_CLASS_ALLOCATOR(MyFirstGemEditorModule, AZ::SystemAllocator);

        MyFirstGemEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                MyFirstGemEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<MyFirstGemEditorSystemComponent>(),
            };
        }
    };
}// namespace MyFirstGem

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), MyFirstGem::MyFirstGemEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_MyFirstGem_Editor, MyFirstGem::MyFirstGemEditorModule)
#endif
