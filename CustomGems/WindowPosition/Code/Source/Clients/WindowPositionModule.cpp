
#include <WindowPosition/WindowPositionTypeIds.h>
#include <WindowPositionModuleInterface.h>
#include "WindowPositionSystemComponent.h"

namespace WindowPosition
{
    class WindowPositionModule
        : public WindowPositionModuleInterface
    {
    public:
        AZ_RTTI(WindowPositionModule, WindowPositionModuleTypeId, WindowPositionModuleInterface);
        AZ_CLASS_ALLOCATOR(WindowPositionModule, AZ::SystemAllocator);
    };
}// namespace WindowPosition

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), WindowPosition::WindowPositionModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_WindowPosition, WindowPosition::WindowPositionModule)
#endif
