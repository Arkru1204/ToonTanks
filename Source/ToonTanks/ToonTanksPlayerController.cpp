// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksPlayerController.h"
#include "GameFramework/Pawn.h"

void AToonTanksPlayerController::SetPlayerEnabledState(bool BPlayerEnabled)
{
	if (BPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this); // 플레이어 인풋 비활성화
	}
	bShowMouseCursor = BPlayerEnabled; // 마우스 커서 활성화/비활성화
}