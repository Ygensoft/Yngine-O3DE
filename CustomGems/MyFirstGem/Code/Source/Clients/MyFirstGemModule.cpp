
#include <MyFirstGem/MyFirstGemTypeIds.h>
#include <MyFirstGemModuleInterface.h>
#include "MyFirstGemSystemComponent.h"

namespace MyFirstGem
{
    class MyFirstGemModule
        : public MyFirstGemModuleInterface
    {
    public:
        AZ_RTTI(MyFirstGemModule, MyFirstGemModuleTypeId, MyFirstGemModuleInterface);
        AZ_CLASS_ALLOCATOR(MyFirstGemModule, AZ::SystemAllocator);
    };
}// namespace MyFirstGem

#if defined(O3DE_GEM_NAME)
AZ_DECLARE_MODULE_CLASS(AZ_JOIN(Gem_, O3DE_GEM_NAME), MyFirstGem::MyFirstGemModule)
#else
AZ_DECLARE_MODULE_CLASS(Gem_MyFirstGem, MyFirstGem::MyFirstGemModule)
#endif
