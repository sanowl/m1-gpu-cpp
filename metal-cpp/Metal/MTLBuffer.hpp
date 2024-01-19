//-------------------------------------------------------------------------------------------------------------------------------------------------------------
//
// Metal/MTLBuffer.hpp
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

#include "MTLResource.hpp"

namespace MTL
{
    class Buffer : public NS::Referencing<Buffer, Resource>
    {
    public:
        // Get the length of the buffer
        NS::UInteger length() const;

        // Get the contents of the buffer
        void *contents();

        // Notify that a range of the buffer has been modified
        void didModifyRange(NS::Range range);

        // Create a new texture using a descriptor, offset, and bytes per row
        class Texture *newTexture(const class TextureDescriptor *descriptor, NS::UInteger offset, NS::UInteger bytesPerRow);

        // Add a debug marker with a specified range
        void addDebugMarker(const NS::String *marker, NS::Range range);

        // Remove all debug markers from the buffer
        void removeAllDebugMarkers();

        // Get the remote storage buffer
        class Buffer *remoteStorageBuffer() const;

        // Create a new remote buffer view for a specified device
        class Buffer *newRemoteBufferViewForDevice(const class Device *device);
    };

}

// Get the length of the buffer
_MTL_INLINE NS::UInteger MTL::Buffer::length() const
{
    return Object::sendMessage<NS::UInteger>(this, _MTL_PRIVATE_SEL(length));
}

// Get the contents of the buffer
_MTL_INLINE void *MTL::Buffer::contents()
{
    return Object::sendMessage<void *>(this, _MTL_PRIVATE_SEL(contents));
}

// Notify that a range of the buffer has been modified
_MTL_INLINE void MTL::Buffer::didModifyRange(NS::Range range)
{
    Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(didModifyRange_), range);
}

// Create a new texture with a descriptor, offset, and bytes per row
_MTL_INLINE MTL::Texture *MTL::Buffer::newTexture(const MTL::TextureDescriptor *descriptor, NS::UInteger offset, NS::UInteger bytesPerRow)
{
    return Object::sendMessage<MTL::Texture *>(this, _MTL_PRIVATE_SEL(newTextureWithDescriptor_offset_bytesPerRow_), descriptor, offset, bytesPerRow);
}

// Add a debug marker with a specified range
_MTL_INLINE void MTL::Buffer::addDebugMarker(const NS::String *marker, NS::Range range)
{
    Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(addDebugMarker_range_), marker, range);
}

// Remove all debug markers from the buffer
_MTL_INLINE void MTL::Buffer::removeAllDebugMarkers()
{
    Object::sendMessage<void>(this, _MTL_PRIVATE_SEL(removeAllDebugMarkers));
}

// Get the remote storage buffer
_MTL_INLINE MTL::Buffer *MTL::Buffer::remoteStorageBuffer() const
{
    return Object::sendMessage<MTL::Buffer *>(this, _MTL_PRIVATE_SEL(remoteStorageBuffer));
}

// Create a new remote buffer view for a specified device
_MTL_INLINE MTL::Buffer *MTL::Buffer::newRemoteBufferViewForDevice(const MTL::Device *device)
{
    return Object::sendMessage<MTL::Buffer *>(this, _MTL_PRIVATE_SEL(newRemoteBufferViewForDevice_), device);
}
