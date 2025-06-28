
#pragma once

namespace WindowPosition
{
    // System Component TypeIds
    inline constexpr const char* WindowPositionSystemComponentTypeId = "{7FB5B2E8-0148-4FA1-BCB5-5CAD0B2F6B64}";
    inline constexpr const char* WindowPositionEditorSystemComponentTypeId = "{B560CA3B-2B41-49E3-8AFD-05007D626F14}";

    // Module derived classes TypeIds
    inline constexpr const char* WindowPositionModuleInterfaceTypeId = "{E91ECE0B-D1F7-448C-A669-D88BA445BA8F}";
    inline constexpr const char* WindowPositionModuleTypeId = "{E5E9014A-8965-4778-9AB7-D598642932A9}";
    // The Editor Module by default is mutually exclusive with the Client Module
    // so they use the Same TypeId
    inline constexpr const char* WindowPositionEditorModuleTypeId = WindowPositionModuleTypeId;

    // Interface TypeIds
    inline constexpr const char* WindowPositionRequestsTypeId = "{1E4EBCEF-C820-4D76-9A7E-F30E29D439CB}";
} // namespace WindowPosition
