/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_VCL_INC_HAIKU_SALBMP_HXX
#define INCLUDED_VCL_INC_HAIKU_SALBMP_HXX

#include <tools/gen.hxx>
#include <salbmp.hxx>

struct BitmapBuffer;
class BitmapColor;
class BitmapPalette;
class SalGraphics;
struct BitmapSystemData;
class BBitmap;

class HaikuSalBitmap : public SalBitmap
{
private:
    BitmapBuffer*   mpDIB;
    BBitmap*        mpBitmap;
public:
    HaikuSalBitmap();
    virtual ~HaikuSalBitmap();

    virtual bool            Create( const Size& rSize,
                                    sal_uInt16 nBitCount,
                                    const BitmapPalette& rPal ) override;
    virtual bool            Create( const SalBitmap& rSalBmp ) override;
    virtual bool            Create( const SalBitmap& rSalBmp,
                                    SalGraphics* pGraphics ) override;
    virtual bool            Create( const SalBitmap& rSalBmp,
                                    sal_uInt16 nNewBitCount ) override;
    virtual bool            Create( const css::uno::Reference< css::rendering::XBitmapCanvas >& rBitmapCanvas,
                                    Size& rSize,
                                    bool bMask = false ) override;
    virtual void            Destroy() override;
    virtual Size            GetSize() const override;
    virtual sal_uInt16      GetBitCount() const override;

    virtual BitmapBuffer*   AcquireBuffer( BitmapAccessMode nMode ) override;
    virtual void            ReleaseBuffer( BitmapBuffer* pBuffer, BitmapAccessMode nMode ) override;
    virtual bool            GetSystemData( BitmapSystemData& rData ) override;

    virtual bool            Scale( const double& rScaleX, const double& rScaleY, BmpScaleFlag nScaleFlag ) override;
    virtual bool            Replace( const Color& rSearchColor, const Color& rReplaceColor, sal_uLong nTol ) override;

    BBitmap*                GetBitmap() const;
    BBitmap*                GetBitmap(const HaikuSalBitmap& rAlphaSource) const;
};

#endif

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
