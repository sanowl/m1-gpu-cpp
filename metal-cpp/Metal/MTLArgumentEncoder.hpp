//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLArgumentEncoder.hpp
//
// Copyright 2020-2021 Apple Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
//-------------------------------------------------------------------------------------------------------------------------------------------------------------

#pragma once

#include "MTLDefines.hpp"
#include "MTLHeaderBridge.hpp"
#include "MTLPrivate.hpp"

#include <Foundation/Foundation.hpp>

#include "MTLBuffer.hpp"
#include "MTLComputePipeline.hpp"
#include "MTLIndirectCommandBuffer.hpp"
#include "MTLIntersectionFunctionTable.hpp"
#include "MTLRenderPipeline.hpp"
#include "MTLSampler.hpp"
#include "MTLTexture.hpp"
#include "MTLVisibleFunctionTable.hpp"

namespace MTL
{
    class ArgumentEncoder : public NS::Referencing<ArgumentEncoder>
    {
    public:
        // Properties
        class Device *device() const;
        NS::String *label() const;
        void setLabel(const NS::String *label);
        NS::UInteger encodedLength() const;
        NS::UInteger alignment() const;

        // Methods for setting different types of arguments
        void setArgumentBuffer(const class Buffer *argumentBuffer, NS::UInteger offset);
        void setArgumentBuffer(const class Buffer *argumentBuffer, NS::UInteger startOffset, NS::UInteger arrayElement);
        void setBuffer(const class Buffer *buffer, NS::UInteger offset, NS::UInteger index);
        void setBuffers(MTL::Buffer *buffers[], const NS::UInteger offsets[], NS::Range range);
        void setTexture(const class Texture *texture, NS::UInteger index);
        void setTextures(MTL::Texture *textures[], NS::Range range);
        void setSamplerState(const class SamplerState *sampler, NS::UInteger index);
        void setSamplerStates(MTL::SamplerState *samplers[], NS::Range range);
        void *constantData(NS::UInteger index);
        void setRenderPipelineState(const class RenderPipelineState *pipeline, NS::UInteger index);
        void setRenderPipelineStates(MTL::RenderPipelineState *pipelines, NS::Range range);
        void setComputePipelineState(const class ComputePipelineState *pipeline, NS::UInteger index);
        void setComputePipelineStates(MTL::ComputePipelineState *pipelines, NS::Range range);
        void setIndirectCommandBuffer(const class IndirectCommandBuffer *indirectCommandBuffer, NS::UInteger index);
        void setIndirectCommandBuffers(MTL::IndirectCommandBuffer *buffers, NS::Range range);
        void setAccelerationStructure(const class AccelerationStructure *accelerationStructure, NS::UInteger index);
        class ArgumentEncoder *newArgumentEncoder(NS::UInteger index);
        void setVisibleFunctionTable(const class VisibleFunctionTable *visibleFunctionTable, NS::UInteger index);
        void setVisibleFunctionTables(const VisibleFunctionTable *visibleFunctionTables[], NS::Range range);
        void setIntersectionFunctionTable(const class IntersectionFunctionTable *intersectionFunctionTable, NS::UInteger index);
        void setIntersectionFunctionTables(const IntersectionFunctionTable *intersectionFunctionTables[], NS::Range range);
    };
}

// Inline implementations of properties and methods
#include "MTLArgumentEncoder_inline.hpp"
