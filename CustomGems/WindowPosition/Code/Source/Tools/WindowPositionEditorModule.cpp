
#include <WindowPosition/WindowPositionTypeIds.h>
#include <WindowPositionModuleInterface.h>
#include "WindowPositionEditorSystemComponent.h"

namespace WindowPosition
{
    class WindowPositionEditorModule
        : public WindowPositionModuleInterface
    {
    public:
        AZ_RTTI(WindowPositionEditorModule, WindowPositionEditorModuleTypeId, WindowPositionModuleInterface);
        AZ_CLASS_ALLOCATOR(WindowPositionEditorModule, AZ::SystemAllocator);

        WindowPositionEditorModule()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            // Add ALL components descriptors associated with this gem to m_descriptors.
            // This will associate the AzTypeInfo information for the components with the the SerializeContext, BehaviorContext and EditContext.
            // This happens through the [MyComponent]::Reflect() function.
            m_descriptors.insert(m_descriptors.end(), {
                WindowPositionEditorSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         * Non-SystemComponents should not be added here
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList {
                azrtti_typeid<WindowPositionEditorSystemComponent>(),
            };
        }
    };
}// namespace WindowPosition

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME, _Editor), WindowPosition::WindowPositionEditorModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_WindowPosition_Editor, WindowPosition::WindowPositionEditorModule)
#endif
