
#pragma once

namespace MyFirstGem
{
    // System Component TypeIds
    inline constexpr const char* MyFirstGemSystemComponentTypeId = "{9DB52192-4831-42DD-B1BB-6CD874D61EB6}";
    inline constexpr const char* MyFirstGemEditorSystemComponentTypeId = "{5C06BEF7-C9FD-4D1D-B51B-727F1003456F}";

    // Module derived classes TypeIds
    inline constexpr const char* MyFirstGemModuleInterfaceTypeId = "{C526B241-342E-4E38-BF7E-544BB05E00A6}";
    inline constexpr const char* MyFirstGemModuleTypeId = "{5F75A4D5-5629-498F-8B41-612975C55429}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* MyFirstGemEditorModuleTypeId = MyFirstGemModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* MyFirstGemRequestsTypeId = "{9D69D71C-91BF-4EBF-901F-6BED82773A62}";
} // namespace MyFirstGem
