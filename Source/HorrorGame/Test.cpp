// Fill out your copyright notice in the Description page of Project Settings.

#include "Test.h"

// Sets default values
ATest::ATest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TimesBeen = 0;
	PLintensity = 3000;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->AttachToComponent(Root, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	TriggerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TriggerBox"));
	TriggerBox->AttachToComponent(StaticMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	TriggerBox->OnComponentBeginOverlap.AddDynamic(this, &ATest::OnOverlapBegin);
	TriggerBox->OnComponentEndOverlap.AddDynamic(this, &ATest::OnOverlapEnd);

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->AttachToComponent(StaticMesh, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	PointLight->SetIntensity(PLintensity);
	PointLight->SetLightColor(FLinearColor(1, 0, 0), true);
	
}

// Called when the game starts or when spawned
void ATest::BeginPlay()
{
	Super::BeginPlay();
	
}
// Called every frame
void ATest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
// OverlapBegin 
void ATest::OnOverlapBegin(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	
}
// OverlapEnd
void ATest::OnOverlapEnd(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
}
// Light function
void ATest::PlayWithLight()
{
	PLintensity = PLintensity + 200;
	PointLight->SetIntensity(PLintensity);
}

void ATest::MoveCube()
{

}



