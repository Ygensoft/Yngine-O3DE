/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include "particle/core/ParticlePool.h"

namespace SimuCore::ParticleCore {
    void ParticlePool::Resize(AZ::u32 size)
    {
        alive = 0;
        maxSize = size;
        particles.resize(maxSize);
    }

    void ParticlePool::Recycle(AZ::u32 beginPos)
    {
        for (AZ::u32 i = beginPos; i < alive; ++i) {
            Particle& particle = particles[i];
            if (particle.lifeTime < AZ::Constants::FloatEpsilon || particle.currentLife > particle.lifeTime) {
                Particle& endP = particles[alive - 1];
                particle = endP;
                --i;
                --alive;
            }
        }
    }

    void ParticlePool::Reset()
    {
        alive = 0;
    }

    AZ::u32 ParticlePool::Size() const
    {
        return maxSize;
    }

    AZ::u32 ParticlePool::Alive() const
    {
        return alive;
    }

    const AZStd::vector<Particle>& ParticlePool::ParticleData() const
    {
        return particles;
    }
}
