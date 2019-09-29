// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/Networking/Public/Networking.h"
#include "GameFramework/Actor.h"
#include "GrabData.generated.h"

UCLASS()
class UPD_API AGrabData : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGrabData();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	//新建ListenSocket指针
	//FSocket特定套接字实现的抽象基类
	FSocket* ListenSocket;
	//新建空的UDPReceiver指针
	//FUdpSocketReceiver 从UDP套接字异步接收数据。
	FUdpSocketReceiver* UDPReceiver = nullptr;

	UFUNCTION(BlueprintCallable, Category = "UDP")
		//新建初始化Receiver函数
		void StartUDPReceiver(const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort, bool& success);
	UFUNCTION(BlueprintPure, Category = "UDP")
		//DataRecv返回函数
		void DataRecv(FString& str, bool& success);

	//ScreenMsg
	//FORCEINLINE 它是非标准关键字，它覆盖编译器的启发式和强制内联当前函数。
	FORCEINLINE void ScreenMsg(const FString& Msg)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, *Msg);
	}
	
	FORCEINLINE void ScreenMsg(const FString& Msg, const float Value)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %f"), *Msg, Value));
	}
	
	FORCEINLINE void ScreenMsg(const FString& Msg, const FString& Msg2)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::Printf(TEXT("%s %s"), *Msg, *Msg2));
	}
	
	UPROPERTY(BlueprintReadOnly, Category = "UDP angle")
		FVector IMU_Angle;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void parserIMU(FString AngleData);
};
