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

	//�½�ListenSocketָ��
	//FSocket�ض��׽���ʵ�ֵĳ������
	FSocket* ListenSocket;
	//�½��յ�UDPReceiverָ��
	//FUdpSocketReceiver ��UDP�׽����첽�������ݡ�
	FUdpSocketReceiver* UDPReceiver = nullptr;

	UFUNCTION(BlueprintCallable, Category = "UDP")
		//�½���ʼ��Receiver����
		void StartUDPReceiver(const FString& YourChosenSocketName, const FString& TheIP, const int32 ThePort, bool& success);
	UFUNCTION(BlueprintPure, Category = "UDP")
		//DataRecv���غ���
		void DataRecv(FString& str, bool& success);

	//ScreenMsg
	//FORCEINLINE ���ǷǱ�׼�ؼ��֣������Ǳ�����������ʽ��ǿ��������ǰ������
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
