// Copyright (c) 2014-2017, THUNDERBEAST GAMES LLC All rights reserved
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

#include <ToolCore/Import/ModelPacker.h>

using namespace ToolCore;

namespace AtomicGlow
{

struct LMVertex
{
    Vector3 position_;
    Vector3 normal_;
    Vector2 uv0_;
    Vector2 uv1_;
};

struct LMLexel
{
    Vector3 position_;
    Vector3 normal_;
    Vector2 pixelCoord_;
    Color color_;
    Color diffuseColor_;
};

class BakeModel : public Object
{
    ATOMIC_OBJECT(BakeModel, Object)

    public:

    BakeModel(Context* context);
    virtual ~BakeModel();

    bool LoadModel(Model* model);

    ModelPacker* GetModelPacker() { return modelPacker_; }

private:

    SharedPtr<ModelPacker> modelPacker_;

};

class BakeModelCache : public Object
{
    ATOMIC_OBJECT(BakeModelCache, Object)

    public:

    BakeModelCache(Context* context);
    virtual ~BakeModelCache();

    BakeModel* GetBakeModel(Model* model);

private:

    /// Model->GetName -> BakeModel
    HashMap<StringHash, SharedPtr<BakeModel>> bakeCache_;

};



}