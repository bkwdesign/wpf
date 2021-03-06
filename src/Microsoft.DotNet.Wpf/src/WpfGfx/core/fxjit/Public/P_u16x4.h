// Licensed to the .NET Foundation under one or more agreements.
// The .NET Foundation licenses this file to you under the MIT license.
// See the LICENSE file in the project root for more information.


//+----------------------------------------------------------------------------
//

//
//  Abstract:
//      Prototype class to represent pointer to u16x4 variable.
//
//-----------------------------------------------------------------------------

#pragma once

//+-----------------------------------------------------------------------------
//
//  Class:
//      R_u16x4
//
//  Synopsis:
//      Represents a reference to variable of type "C_u16x4" in prototype
//      program. Serves as intermediate calculation type for P_u16x4::operator[].
//
//------------------------------------------------------------------------------

class R_u16x4
{
public:
    static const UINT32 IndexShift = 3;
    static const RefType IndexScale = RefType_Index_8;

    R_u16x4(
        RefType refType,
        UINT32 uBaseVarID,
        UINT32 uIndexVarID,
        UINT_PTR uDisplacement
        );

    operator C_u16x4() const;
    C_u16x4 const& operator=(C_u16x4 const& origin);

    C_u16x4 operator+(C_u16x4 const& src) const {return ((C_u16x4)(*this)) + src;}
    C_u16x4 operator-(C_u16x4 const& src) const {return ((C_u16x4)(*this)) - src;}
    C_u16x4 operator&(C_u16x4 const& src) const {return ((C_u16x4)(*this)) & src;}
    C_u16x4 operator|(C_u16x4 const& src) const {return ((C_u16x4)(*this)) | src;}
    C_u16x4 operator^(C_u16x4 const& src) const {return ((C_u16x4)(*this)) ^ src;}

    C_u16x4 AddSaturate(C_u16x4 const& src) const {return ((C_u16x4)(*this)).AddSaturate(src);}
    C_u16x4 SubSaturate(C_u16x4 const& src) const {return ((C_u16x4)(*this)).SubSaturate(src);}

    C_u16x4 operator+(R_u16x4 const& ref) const {return ((C_u16x4)(*this)) + ref;}
    C_u16x4 operator-(R_u16x4 const& ref) const {return ((C_u16x4)(*this)) - ref;}
    C_u16x4 operator&(R_u16x4 const& ref) const {return ((C_u16x4)(*this)) & ref;}
    C_u16x4 operator|(R_u16x4 const& ref) const {return ((C_u16x4)(*this)) | ref;}
    C_u16x4 operator^(R_u16x4 const& ref) const {return ((C_u16x4)(*this)) ^ ref;}

    C_u16x4 AddSaturate(R_u16x4 const& ref) const {return ((C_u16x4)(*this)).AddSaturate(ref);}
    C_u16x4 SubSaturate(R_u16x4 const& ref) const {return ((C_u16x4)(*this)).SubSaturate(ref);}

private:
    friend class C_u16x4;
    friend class P_u16x4;

private:
    RefType const m_refType;
    UINT32 const m_uBaseVarID;
    UINT32 const m_uIndexVarID;
    UINT_PTR const m_uDisplacement;
};

//+-----------------------------------------------------------------------------
//
//  Class:
//      P_u16x4
//
//  Synopsis:
//      Represents variable of type "u16x4*" in prototype program.
//
//------------------------------------------------------------------------------
class P_u16x4 : public TIndexer<P_u16x4, R_u16x4>
{
public:
    P_u16x4() {}
    P_u16x4(void * pOrigin) : TIndexer<P_u16x4, R_u16x4>(pOrigin) {}
};

