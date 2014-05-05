//
// Copyright (c) 2008-2014 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "Component.h"

namespace Tmx
{
    class Map;
}

namespace Urho3D
{

class File;
class Sprite2D;

/// Tile map.
class URHO3D_API TileMap2D : public Component
{
    OBJECT(TileMap2D);

public:
    /// Construct.
    TileMap2D(Context* scontext);
    /// Destruct.
    virtual ~TileMap2D();
    /// Register object factory.
    static void RegisterObject(Context* context);

    /// Set tmx file.
    bool SetTMXFile(File* tmxFile);

    /// Return tile width.
    float GetTileWidth() const;
    /// Return tile height.
    float GetTileHeight() const;
    /// Return sprite by id.
    Sprite2D* GetTileSprite(int id) const;
    /// Return tmx map.
    Tmx::Map* GetTMXMap() const;

private:
    /// Tmx map.
    Tmx::Map* tmxMap_;
    /// Id to sprite mapping.
    HashMap<int, SharedPtr<Sprite2D> > tileSpriteMapping_;
};

}
