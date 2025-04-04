// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameState1.h"
AMyGameState1::AMyGameState1()
{
	CurrentScore = 0;
}
int32 AMyGameState1::GetScore()
{
	return CurrentScore;
}
void AMyGameState1::SetScore(int32 NewScore)
{
	CurrentScore = NewScore;
}
