// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "UPD/Public/GrabData.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGrabData() {}
// Cross Module References
	UPD_API UClass* Z_Construct_UClass_AGrabData_NoRegister();
	UPD_API UClass* Z_Construct_UClass_AGrabData();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_UPD();
	UPD_API UFunction* Z_Construct_UFunction_AGrabData_DataRecv();
	UPD_API UFunction* Z_Construct_UFunction_AGrabData_StartUDPReceiver();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	void AGrabData::StaticRegisterNativesAGrabData()
	{
		UClass* Class = AGrabData::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DataRecv", &AGrabData::execDataRecv },
			{ "StartUDPReceiver", &AGrabData::execStartUDPReceiver },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGrabData_DataRecv_Statics
	{
		struct GrabData_eventDataRecv_Parms
		{
			FString str;
			bool success;
		};
		static void NewProp_success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_success;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_str;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AGrabData_DataRecv_Statics::NewProp_success_SetBit(void* Obj)
	{
		((GrabData_eventDataRecv_Parms*)Obj)->success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGrabData_DataRecv_Statics::NewProp_success = { UE4CodeGen_Private::EPropertyClass::Bool, "success", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrabData_eventDataRecv_Parms), &Z_Construct_UFunction_AGrabData_DataRecv_Statics::NewProp_success_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AGrabData_DataRecv_Statics::NewProp_str = { UE4CodeGen_Private::EPropertyClass::Str, "str", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, STRUCT_OFFSET(GrabData_eventDataRecv_Parms, str), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGrabData_DataRecv_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGrabData_DataRecv_Statics::NewProp_success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGrabData_DataRecv_Statics::NewProp_str,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGrabData_DataRecv_Statics::Function_MetaDataParams[] = {
		{ "Category", "UDP" },
		{ "ModuleRelativePath", "Public/GrabData.h" },
		{ "ToolTip", "DataRecv???\xd8\xba???" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGrabData_DataRecv_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrabData, "DataRecv", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x14420401, sizeof(GrabData_eventDataRecv_Parms), Z_Construct_UFunction_AGrabData_DataRecv_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_DataRecv_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGrabData_DataRecv_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_DataRecv_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGrabData_DataRecv()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGrabData_DataRecv_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics
	{
		struct GrabData_eventStartUDPReceiver_Parms
		{
			FString YourChosenSocketName;
			FString TheIP;
			int32 ThePort;
			bool success;
		};
		static void NewProp_success_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_success;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThePort_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ThePort;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TheIP_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_TheIP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_YourChosenSocketName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_YourChosenSocketName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_success_SetBit(void* Obj)
	{
		((GrabData_eventStartUDPReceiver_Parms*)Obj)->success = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_success = { UE4CodeGen_Private::EPropertyClass::Bool, "success", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000180, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(GrabData_eventStartUDPReceiver_Parms), &Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_success_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_ThePort_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_ThePort = { UE4CodeGen_Private::EPropertyClass::Int, "ThePort", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000082, 1, nullptr, STRUCT_OFFSET(GrabData_eventStartUDPReceiver_Parms, ThePort), METADATA_PARAMS(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_ThePort_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_ThePort_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_TheIP_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_TheIP = { UE4CodeGen_Private::EPropertyClass::Str, "TheIP", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrabData_eventStartUDPReceiver_Parms, TheIP), METADATA_PARAMS(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_TheIP_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_TheIP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_YourChosenSocketName_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_YourChosenSocketName = { UE4CodeGen_Private::EPropertyClass::Str, "YourChosenSocketName", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GrabData_eventStartUDPReceiver_Parms, YourChosenSocketName), METADATA_PARAMS(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_YourChosenSocketName_MetaData, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_YourChosenSocketName_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_success,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_ThePort,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_TheIP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::NewProp_YourChosenSocketName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::Function_MetaDataParams[] = {
		{ "Category", "UDP" },
		{ "ModuleRelativePath", "Public/GrabData.h" },
		{ "ToolTip", "?\xc2\xbd???\xca\xbc??Receiver????" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGrabData, "StartUDPReceiver", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04420401, sizeof(GrabData_eventStartUDPReceiver_Parms), Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGrabData_StartUDPReceiver()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGrabData_StartUDPReceiver_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGrabData_NoRegister()
	{
		return AGrabData::StaticClass();
	}
	struct Z_Construct_UClass_AGrabData_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IMU_Angle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_IMU_Angle;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGrabData_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_UPD,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGrabData_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGrabData_DataRecv, "DataRecv" }, // 1742184339
		{ &Z_Construct_UFunction_AGrabData_StartUDPReceiver, "StartUDPReceiver" }, // 1821629787
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGrabData_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GrabData.h" },
		{ "ModuleRelativePath", "Public/GrabData.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGrabData_Statics::NewProp_IMU_Angle_MetaData[] = {
		{ "Category", "UDP angle" },
		{ "ModuleRelativePath", "Public/GrabData.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGrabData_Statics::NewProp_IMU_Angle = { UE4CodeGen_Private::EPropertyClass::Struct, "IMU_Angle", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000014, 1, nullptr, STRUCT_OFFSET(AGrabData, IMU_Angle), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UClass_AGrabData_Statics::NewProp_IMU_Angle_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGrabData_Statics::NewProp_IMU_Angle_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGrabData_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGrabData_Statics::NewProp_IMU_Angle,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGrabData_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGrabData>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGrabData_Statics::ClassParams = {
		&AGrabData::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AGrabData_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGrabData_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGrabData_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGrabData_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGrabData()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGrabData_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGrabData, 556439896);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGrabData(Z_Construct_UClass_AGrabData, &AGrabData::StaticClass, TEXT("/Script/UPD"), TEXT("AGrabData"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGrabData);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
