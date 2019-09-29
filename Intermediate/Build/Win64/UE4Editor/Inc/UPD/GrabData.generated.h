// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef UPD_GrabData_generated_h
#error "GrabData.generated.h already included, missing '#pragma once' in GrabData.h"
#endif
#define UPD_GrabData_generated_h

#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execDataRecv) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_str); \
		P_GET_UBOOL_REF(Z_Param_Out_success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DataRecv(Z_Param_Out_str,Z_Param_Out_success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartUDPReceiver) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_YourChosenSocketName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_TheIP); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ThePort); \
		P_GET_UBOOL_REF(Z_Param_Out_success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartUDPReceiver(Z_Param_YourChosenSocketName,Z_Param_TheIP,Z_Param_ThePort,Z_Param_Out_success); \
		P_NATIVE_END; \
	}


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execDataRecv) \
	{ \
		P_GET_PROPERTY_REF(UStrProperty,Z_Param_Out_str); \
		P_GET_UBOOL_REF(Z_Param_Out_success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->DataRecv(Z_Param_Out_str,Z_Param_Out_success); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execStartUDPReceiver) \
	{ \
		P_GET_PROPERTY(UStrProperty,Z_Param_YourChosenSocketName); \
		P_GET_PROPERTY(UStrProperty,Z_Param_TheIP); \
		P_GET_PROPERTY(UIntProperty,Z_Param_ThePort); \
		P_GET_UBOOL_REF(Z_Param_Out_success); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->StartUDPReceiver(Z_Param_YourChosenSocketName,Z_Param_TheIP,Z_Param_ThePort,Z_Param_Out_success); \
		P_NATIVE_END; \
	}


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGrabData(); \
	friend struct Z_Construct_UClass_AGrabData_Statics; \
public: \
	DECLARE_CLASS(AGrabData, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UPD"), NO_API) \
	DECLARE_SERIALIZER(AGrabData)


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_INCLASS \
private: \
	static void StaticRegisterNativesAGrabData(); \
	friend struct Z_Construct_UClass_AGrabData_Statics; \
public: \
	DECLARE_CLASS(AGrabData, AActor, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/UPD"), NO_API) \
	DECLARE_SERIALIZER(AGrabData)


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGrabData(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGrabData) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrabData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrabData); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGrabData(AGrabData&&); \
	NO_API AGrabData(const AGrabData&); \
public:


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGrabData(AGrabData&&); \
	NO_API AGrabData(const AGrabData&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGrabData); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGrabData); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGrabData)


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_PRIVATE_PROPERTY_OFFSET
#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_10_PROLOG
#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_PRIVATE_PROPERTY_OFFSET \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_RPC_WRAPPERS \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_INCLASS \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_PRIVATE_PROPERTY_OFFSET \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_RPC_WRAPPERS_NO_PURE_DECLS \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_INCLASS_NO_PURE_DECLS \
	CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h_13_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID CPPdemo_Plugins_UPD_Source_UPD_Public_GrabData_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
