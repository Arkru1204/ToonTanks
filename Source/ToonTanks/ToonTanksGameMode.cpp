// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"

void AToonTanksGameMode::BeginPlay()
{
	Super::BeginPlay();

	Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AToonTanksGameMode::ActorDied(AActor* DeadActor)
{
	if (DeadActor == Tank) // 파괴된 액터가 플레이어라면
	{
		Tank->HandleDestruction();
		if (Tank->GetTankPlayerController())
		{
			Tank->DisableInput(Tank->GetTankPlayerController()); // 플레이어 인풋 비활성화
			Tank->GetTankPlayerController()->bShowMouseCursor = false; // 마우스 커서 숨기기
		}
	}
	else if (ATower* DestroyedTower = Cast<ATower>(DeadActor)) // 파괴된 액터가 타워라면
	{
		DestroyedTower->HandleDestruction();
	}
}