// Fill out your copyright notice in the Description page of Project Settings.

#include "GrabData.h"
#include <sstream>

// Sets default values
AGrabData::AGrabData()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//init listen socket
	ListenSocket = NULL;
}

// Called when the game starts or when spawned
void AGrabData::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGrabData::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGrabData::StartUDPReceiver(const FString & YourChosenSocketName, const FString & TheIP, const int32 ThePort, bool & success)
{
	//TSharedRef�ǲ��ɿյķ����������ü�����Ȩ���������á�
	//TSharedPtr(OtherType * InObject)  ����һ��ӵ��ָ������Ĺ���ָ�롣
	//�½�RemoteAddr����
	//ISocketSubsystem::Get ��ȡ������������ϵͳ�ĵ����׽�����ϵͳ
	// ISocketSubsystem::CreateInternetAddr         TSharedRef < FInternetAddr > CreateInternetAddr ( uint32 Address, uint32 Port )
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//FIPv4Address Implements an IPv4 address.,ʵ����ipv4��ַ
	FIPv4Address Addr;
	//Parse���� ���ַ���ת��ΪIPv4��ַ��
	FIPv4Address::Parse(TheIP, Addr);

	//Create Socket
	// FIPv4Endpoint::FIPv4Endpoint          FIPv4Endpoint ( const FIPv4Address & InAddress, uint16 InPort )  InAddress:The endpoint's IP address.   InPort:The endpoint's port number.
	//ʹ��ָ����NetID�Ͷ˿ڴ�������ʼ���µ�IPv4�˵㡣
	// Any: Defines the wild card endpoint, which is 0.0.0.0:0
	FIPv4Endpoint Endpoint(FIPv4Address::Any, ThePort);  //����ip��ַ����
														 //FIPv4Endpoint Endpoint(Addr, ThePort);                 //ָ��ip��ַ
														 //FUdpSocketBuilder: Implements a fluent builder for UDP sockets.
	ListenSocket = FUdpSocketBuilder(*YourChosenSocketName)
		.AsNonBlocking()//���׽��ֲ�������Ϊ�������� ���ʵ�������ڷ���������
		.AsReusable()//ʹ�󶨵ĵ�ַ���Ա������׽������á� ���ʵ�������ڷ���������
		.BoundToEndpoint(Endpoint)//���ý��˿ڰ󶨵����ض˵㡣 ���ʵ�������ڷ���������
		.WithReceiveBufferSize(2 * 1024 * 1024)//���ý������ݴ�С
		;
	//BUFFER SIZE
	int32 BufferSize = 2 * 1024 * 1024;
	ListenSocket->SetSendBufferSize(BufferSize, BufferSize);
	ListenSocket->SetReceiveBufferSize(BufferSize, BufferSize);

	if (!ListenSocket)
	{
		ScreenMsg("No socket");
		success = false;

	}
	if (ListenSocket)
	{
		ScreenMsg("The receiver is initialized");
		success = true;
	}
}

void AGrabData::DataRecv(FString & str, bool & success)
{
	if (!ListenSocket)
	{
		ScreenMsg("No sender socket");
		success = false;
		//return success;
	}
	//TSharedRef�ǲ��ɿյķ����������ü�����Ȩ���������á�
	//TSharedPtr(OtherType * InObject)  ����һ��ӵ��ָ������Ĺ���ָ�롣
	//�½�RemoteAddr����
	//ISocketSubsystem::Get ��ȡ������������ϵͳ�ĵ����׽�����ϵͳ
	// ISocketSubsystem::CreateInternetAddr         TSharedRef < FInternetAddr > CreateInternetAddr ( uint32 Address, uint32 Port )
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	TArray<uint8> ReceivedData;//����һ��������
	uint32 Size;
	//ListenSocket->HasPendingData(Size) ��ѯ�׽�����ȷ���������Ƿ��й�������ݣ�����׽��������ݣ���Ϊtrue������Ϊfalse           Size����ָʾ����recv���õĹܵ����ж�������
	if (ListenSocket->HasPendingData(Size))
	{
		success = true;
		str = "";
		uint8 *Recv = new uint8[Size];
		int32 BytesRead = 0;

		//���������������������Ԫ�ء� ��Ԫ�ؽ�����ʼ����
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
		ListenSocket->RecvFrom(ReceivedData.GetData(), ReceivedData.Num(), BytesRead, *targetAddr);//����Զ�̽��յ�ַ
		char ansiiData[1024];
		memcpy(ansiiData, ReceivedData.GetData(), BytesRead);//�������ݵ�������
		ansiiData[BytesRead] = 0;                            //�ж����ݽ���
		FString debugData = ANSI_TO_TCHAR(ansiiData);         //�ַ���ת��
		str = debugData;
		
		parserIMU(str);
	}
	else
	{
		success = false;
	}
}

void AGrabData::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	//UDPReceiver�ÿ�
	delete UDPReceiver;
	UDPReceiver = nullptr;

	//Clear all sockets!
	//makes sure repeat plays in Editor dont hold on to old sockets!
	
	if (ListenSocket)//��ListenSocket��Ϊ��
	{
		//�رգ�����
		ListenSocket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(ListenSocket);
	}
}

void AGrabData::parserIMU(FString AngleData)
{
	if (!AngleData.IsEmpty())
	{
		std::string sData(TCHAR_TO_UTF8(*AngleData));
		std::stringstream ssData(sData);
		ssData >> IMU_Angle.X >> IMU_Angle.Y >> IMU_Angle.Z;
	}
	else
	{
		IMU_Angle.X = 0.0;
		IMU_Angle.Y = 0.0;
		IMU_Angle.Z = 0.0;
	}
}

