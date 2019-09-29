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
	//TSharedRef是不可空的非侵入性引用计数的权威对象引用。
	//TSharedPtr(OtherType * InObject)  构造一个拥有指定对象的共享指针。
	//新建RemoteAddr变量
	//ISocketSubsystem::Get 获取给定的命名子系统的单例套接字子系统
	// ISocketSubsystem::CreateInternetAddr         TSharedRef < FInternetAddr > CreateInternetAddr ( uint32 Address, uint32 Port )
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	//FIPv4Address Implements an IPv4 address.,实现了ipv4地址
	FIPv4Address Addr;
	//Parse（） 将字符串转换为IPv4地址。
	FIPv4Address::Parse(TheIP, Addr);

	//Create Socket
	// FIPv4Endpoint::FIPv4Endpoint          FIPv4Endpoint ( const FIPv4Address & InAddress, uint16 InPort )  InAddress:The endpoint's IP address.   InPort:The endpoint's port number.
	//使用指定的NetID和端口创建并初始化新的IPv4端点。
	// Any: Defines the wild card endpoint, which is 0.0.0.0:0
	FIPv4Endpoint Endpoint(FIPv4Address::Any, ThePort);  //所有ip地址本地
														 //FIPv4Endpoint Endpoint(Addr, ThePort);                 //指定ip地址
														 //FUdpSocketBuilder: Implements a fluent builder for UDP sockets.
	ListenSocket = FUdpSocketBuilder(*YourChosenSocketName)
		.AsNonBlocking()//将套接字操作设置为非阻塞。 这个实例（用于方法链）。
		.AsReusable()//使绑定的地址可以被其他套接字重用。 这个实例（用于方法链）。
		.BoundToEndpoint(Endpoint)//设置将端口绑定到本地端点。 这个实例（用于方法链）。
		.WithReceiveBufferSize(2 * 1024 * 1024)//设置接收数据大小
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
	//TSharedRef是不可空的非侵入性引用计数的权威对象引用。
	//TSharedPtr(OtherType * InObject)  构造一个拥有指定对象的共享指针。
	//新建RemoteAddr变量
	//ISocketSubsystem::Get 获取给定的命名子系统的单例套接字子系统
	// ISocketSubsystem::CreateInternetAddr         TSharedRef < FInternetAddr > CreateInternetAddr ( uint32 Address, uint32 Port )
	TSharedRef<FInternetAddr> targetAddr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->CreateInternetAddr();
	TArray<uint8> ReceivedData;//定义一个接收器
	uint32 Size;
	//ListenSocket->HasPendingData(Size) 查询套接字以确定队列中是否有挂起的数据，如果套接字有数据，则为true，否则为false           Size参数指示单个recv调用的管道上有多少数据
	if (ListenSocket->HasPendingData(Size))
	{
		success = true;
		str = "";
		uint8 *Recv = new uint8[Size];
		int32 BytesRead = 0;

		//将数组调整到给定数量的元素。 新元素将被初始化。
		ReceivedData.SetNumUninitialized(FMath::Min(Size, 65507u));
		ListenSocket->RecvFrom(ReceivedData.GetData(), ReceivedData.Num(), BytesRead, *targetAddr);//创建远程接收地址
		char ansiiData[1024];
		memcpy(ansiiData, ReceivedData.GetData(), BytesRead);//拷贝数据到接收器
		ansiiData[BytesRead] = 0;                            //判断数据结束
		FString debugData = ANSI_TO_TCHAR(ansiiData);         //字符串转换
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
	//UDPReceiver置空
	delete UDPReceiver;
	UDPReceiver = nullptr;

	//Clear all sockets!
	//makes sure repeat plays in Editor dont hold on to old sockets!
	
	if (ListenSocket)//若ListenSocket不为空
	{
		//关闭，销毁
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

