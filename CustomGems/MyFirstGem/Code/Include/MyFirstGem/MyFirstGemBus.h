
#pragma once

#include <MyFirstGem/MyFirstGemTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace MyFirstGem
{
    class MyFirstGemRequests
    {
    public:
        AZ_RTTI(MyFirstGemRequests, MyFirstGemRequestsTypeId);
        virtual ~MyFirstGemRequests() = default;
        // Put your public methods here
    };

    class MyFirstGemBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using MyFirstGemRequestBus = AZ::EBus<MyFirstGemRequests, MyFirstGemBusTraits>;
    using MyFirstGemInterface = AZ::Interface<MyFirstGemRequests>;

} // namespace MyFirstGem
