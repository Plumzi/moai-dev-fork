// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAIANIMCURVEVEC3D_H
#define	MOAIANIMCURVEVEC3D_H

#include <moaicore/MOAIAnimCurveBase.h>
#include <moaicore/MOAILua.h>
#include <moaicore/MOAINode.h>
#include <moaicore/MOAIWeakPtr.h>

//================================================================//
// MOAIAnimCurveVec3D
//================================================================//
// TODO: doxygen
class MOAIAnimCurveVec3D :
	public virtual MOAIAnimCurveBase {
private:

	USLeanArray < USVec3D > mSamples;
	USVec3D mValue;

	//----------------------------------------------------------------//
	static int		_getValueAtTime		( lua_State* L );
	static int		_setKey				( lua_State* L );

	//----------------------------------------------------------------//
	USVec3D			GetCurveDelta		() const;
	USVec3D			GetValue			( const MOAIAnimKeySpan& span ) const;

public:
	
	DECL_LUA_FACTORY ( MOAIAnimCurveVec3D )
	
	//----------------------------------------------------------------//
	void			ApplyValueAttrOp		( MOAIAttrOp& attrOp, u32 op );
	void			GetDelta				( MOAIAttrOp& attrOp, const MOAIAnimKeySpan& span0, const MOAIAnimKeySpan& span1 ) const;
	USVec3D			GetValue				( float time ) const;
	void			GetValue				( MOAIAttrOp& attrOp, const MOAIAnimKeySpan& span ) const;
	void			GetZero					( MOAIAttrOp& attrOp ) const;
					MOAIAnimCurveVec3D		();
					~MOAIAnimCurveVec3D		();
	void			OnDepNodeUpdate			();
	void			RegisterLuaClass		( MOAILuaState& state );
	void			RegisterLuaFuncs		( MOAILuaState& state );
	void			ReserveSamples			( u32 total );
	void			SetSample				( u32 id, const USVec3D& value );
};

#endif
