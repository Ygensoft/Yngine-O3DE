/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */
 
#pragma once

#include <AzCore/Component/Component.h>
#include <AzCore/Component/TransformBus.h>
#include <AzCore/Component/NonUniformScaleBus.h>

#include <AzFramework/Components/ComponentAdapter.h>
#include <AzFramework/Asset/AssetCatalogBus.h>

#include <OpenParticleSystem/ParticleComponentConfig.h>
#include <OpenParticleSystem/ParticleFeatureProcessorInterface.h>
#include <OpenParticleSystem/ParticleRequestBus.h>

namespace OpenParticle
{
    constexpr char ParticleComponentTypeId[] = "{250342FE-9592-4194-BBE9-FBF5CF8FD9E8}";

    class ParticleComponentController final
        : private AZ::TransformNotificationBus::Handler
        , private ParticleRequestBus::Handler
        , private AzFramework::AssetCatalogEventBus::Handler
    {
    public:
        friend class EditorParticleComponent;

        AZ_TYPE_INFO(OpenParticle::ParticleComponentController, "{a5b42514-594d-40a8-aca6-7f98f2d913c4}");
        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);

        ParticleComponentController() = default;
        explicit ParticleComponentController(const ParticleComponentConfig& config);

        ~ParticleComponentController() = default;

        void OnTransformChanged(const AZ::Transform& local, const AZ::Transform& world) override;

        void SetVisible(bool visible);

        void Activate(AZ::EntityId entityId);
        void Deactivate();
        void SetConfiguration(const ParticleComponentConfig& config);
        const ParticleComponentConfig& GetConfiguration() const;

    private:
        void Play() override;
        void Pause() override;
        void Stop() override;
        void SetVisibility(bool visible) override;
        bool GetVisibility() const override;

        void SetParticleAsset(AZ::Data::Asset<ParticleAsset> particleAsset, bool inParticleEditor) override;
        void SetParticleAssetByPath(AZStd::string path) override;
        AZStd::string GetParticleAssetPath() const override;

        void SetMaterialDiffuseMap(AZ::u32 emitterIndex, AZStd::string mapPath) override;
        void OnNonUniformScaleChange(const AZ::Vector3& nonUniformScale);

        void Register();

        void Deregister();

        // AzFramework::AssetCatalogEventBus::Handler
        void OnCatalogAssetChanged(const AZ::Data::AssetId&) override;

        ParticleComponentConfig m_configuration;
        AZ::EntityId m_entityId;
        AZ::TransformInterface* m_transformInterface = nullptr;

        AZ::NonUniformScaleChangedEvent::Handler m_nonUniformScaleChangedHandler{
            [&](const AZ::Vector3& nonUniformScale) { OnNonUniformScaleChange(nonUniformScale); }};

        ParticleFeatureProcessorInterface* m_featureProcessor = nullptr;
        ParticleFeatureProcessorInterface::ParticleHandle m_particleHandle;
        bool m_isVisible = true;
    };

    class ParticleComponent final
        : public AzFramework::Components::ComponentAdapter<ParticleComponentController
        , ParticleComponentConfig>
    {
    public:
        using BaseClass = AzFramework::Components::ComponentAdapter<ParticleComponentController, ParticleComponentConfig>;
        AZ_COMPONENT(ParticleComponent, ParticleComponentTypeId, BaseClass);

        static void Reflect(AZ::ReflectContext* context);

        ParticleComponent() = default;
        explicit ParticleComponent(const ParticleComponentConfig& config);
        ~ParticleComponent() = default;
    };
} // namespace OpenParticle
