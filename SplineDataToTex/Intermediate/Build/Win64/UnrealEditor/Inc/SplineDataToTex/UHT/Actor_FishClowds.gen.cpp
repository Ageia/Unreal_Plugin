// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Actor_FishClowds.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS

void EmptyLinkFunctionForGeneratedCodeActor_FishClowds() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_AActor();
ENGINE_API UClass* Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_USplineComponent_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UTexture2D_NoRegister();
SPLINEDATATOTEX_API UClass* Z_Construct_UClass_AActor_FishClowds();
SPLINEDATATOTEX_API UClass* Z_Construct_UClass_AActor_FishClowds_NoRegister();
UPackage* Z_Construct_UPackage__Script_SplineDataToTex();
// ********** End Cross Module References **********************************************************

// ********** Begin Class AActor_FishClowds ********************************************************
void AActor_FishClowds::StaticRegisterNativesAActor_FishClowds()
{
}
FClassRegistrationInfo Z_Registration_Info_UClass_AActor_FishClowds;
UClass* AActor_FishClowds::GetPrivateStaticClass()
{
	using TClass = AActor_FishClowds;
	if (!Z_Registration_Info_UClass_AActor_FishClowds.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			StaticPackage(),
			TEXT("Actor_FishClowds"),
			Z_Registration_Info_UClass_AActor_FishClowds.InnerSingleton,
			StaticRegisterNativesAActor_FishClowds,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_AActor_FishClowds.InnerSingleton;
}
UClass* Z_Construct_UClass_AActor_FishClowds_NoRegister()
{
	return AActor_FishClowds::GetPrivateStaticClass();
}
struct Z_Construct_UClass_AActor_FishClowds_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "Actor_FishClowds.h" },
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SplineComp_MetaData[] = {
		{ "Category", "Actor_FishClowds" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ISM_MetaData[] = {
		{ "Category", "Actor_FishClowds" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_HISM_MetaData[] = {
		{ "Category", "Actor_FishClowds" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ISMCount_MetaData[] = {
		{ "Category", "Actor_FishClowds" },
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RuntimeTexture_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DynamicMID_MetaData[] = {
		{ "ModuleRelativePath", "Public/Actor_FishClowds.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FObjectPropertyParams NewProp_SplineComp;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ISM;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_HISM;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ISMCount;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_RuntimeTexture;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DynamicMID;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AActor_FishClowds>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_SplineComp = { "SplineComp", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActor_FishClowds, SplineComp), Z_Construct_UClass_USplineComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SplineComp_MetaData), NewProp_SplineComp_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_ISM = { "ISM", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActor_FishClowds, ISM), Z_Construct_UClass_UInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ISM_MetaData), NewProp_ISM_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_HISM = { "HISM", nullptr, (EPropertyFlags)0x00100000000a001d, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActor_FishClowds, HISM), Z_Construct_UClass_UHierarchicalInstancedStaticMeshComponent_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_HISM_MetaData), NewProp_HISM_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_ISMCount = { "ISMCount", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActor_FishClowds, ISMCount), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ISMCount_MetaData), NewProp_ISMCount_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_RuntimeTexture = { "RuntimeTexture", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActor_FishClowds, RuntimeTexture), Z_Construct_UClass_UTexture2D_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RuntimeTexture_MetaData), NewProp_RuntimeTexture_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_DynamicMID = { "DynamicMID", nullptr, (EPropertyFlags)0x0010000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(AActor_FishClowds, DynamicMID), Z_Construct_UClass_UMaterialInstanceDynamic_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DynamicMID_MetaData), NewProp_DynamicMID_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AActor_FishClowds_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_SplineComp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_ISM,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_HISM,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_ISMCount,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_RuntimeTexture,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AActor_FishClowds_Statics::NewProp_DynamicMID,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActor_FishClowds_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_AActor_FishClowds_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_AActor,
	(UObject* (*)())Z_Construct_UPackage__Script_SplineDataToTex,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AActor_FishClowds_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_AActor_FishClowds_Statics::ClassParams = {
	&AActor_FishClowds::StaticClass,
	"Engine",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_AActor_FishClowds_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_AActor_FishClowds_Statics::PropPointers),
	0,
	0x008001A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AActor_FishClowds_Statics::Class_MetaDataParams), Z_Construct_UClass_AActor_FishClowds_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_AActor_FishClowds()
{
	if (!Z_Registration_Info_UClass_AActor_FishClowds.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AActor_FishClowds.OuterSingleton, Z_Construct_UClass_AActor_FishClowds_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_AActor_FishClowds.OuterSingleton;
}
DEFINE_VTABLE_PTR_HELPER_CTOR(AActor_FishClowds);
AActor_FishClowds::~AActor_FishClowds() {}
// ********** End Class AActor_FishClowds **********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_User_Desktop_New_Odo_Plugins_SplineDataToTex_Source_SplineDataToTex_Public_Actor_FishClowds_h__Script_SplineDataToTex_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_AActor_FishClowds, AActor_FishClowds::StaticClass, TEXT("AActor_FishClowds"), &Z_Registration_Info_UClass_AActor_FishClowds, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AActor_FishClowds), 3301529106U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_User_Desktop_New_Odo_Plugins_SplineDataToTex_Source_SplineDataToTex_Public_Actor_FishClowds_h__Script_SplineDataToTex_877346140(TEXT("/Script/SplineDataToTex"),
	Z_CompiledInDeferFile_FID_Users_User_Desktop_New_Odo_Plugins_SplineDataToTex_Source_SplineDataToTex_Public_Actor_FishClowds_h__Script_SplineDataToTex_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_User_Desktop_New_Odo_Plugins_SplineDataToTex_Source_SplineDataToTex_Public_Actor_FishClowds_h__Script_SplineDataToTex_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
