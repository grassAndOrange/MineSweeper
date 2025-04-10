// Fill out your copyright notice in the Description page of Project Settings.

#include "MineGenerator.h"
#include "Components/ActorComponent.h"
#include "Engine/Engine.h"
#include "Engine/World.h"
#include "Math/RandomStream.h"
#include "MineBasic.h"
#include <Components/TextRenderComponent.h>


// Sets default values
AMineGenerator::AMineGenerator()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMineGenerator::BeginPlay()
{
	Super::BeginPlay();
	GenerateMine();
	//FirstClick(GridLenNum / 2, GridWidNum / 2);
}

// Called every frame
void AMineGenerator::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMineGenerator::GenerateMine()
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("GenerateMine"));
	UClass* MineClass = LoadClass<AMineBasic>(NULL, TEXT("'/Game/BluePrints/BP_MinePrefabs.BP_MinePrefabs_C'"));

	if (MineClass)
	{
		for (int i = 0; i < GridLenNum; i++)
		{
			for (int j = 0; j < GridWidNum; j++)
			{
				AMineBasic* mineCube = GetWorld()->SpawnActor<AMineBasic>(MineClass, GetActorLocation() + FVector((i - (GridLenNum / 2)) * MineGap, (j - (GridWidNum / 2)) * MineGap, 0), GetActorRotation());
				mineCube->PosX = i;
				mineCube->PosY = j;
				mineCube->Grid = this;
				MineArray.Add(mineCube);
				
			}
		}
	}
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("nullptr"));

	for (auto mine : MineArray)
	{
		//mine->mineGenerator = this;
	}

}

void AMineGenerator::GenerateUniqueRandomNumbers(int32 Min, int32 Max, int32 PosX, int32 PosY, int32 Count, TArray<int32>& OutUniqueRandomNumbers)
{
	//返回包含不重复随机数的数组，且不包含受点击网格周围至多八个王哥编号
	FRandomStream RandomStream(FPlatformTime::Seconds());
	TSet<int32> UniqueRandomNumbers;
	while (UniqueRandomNumbers.Num() < Count)
	{
		int32 RandomNumber = RandomStream.RandRange(Min, Max);
		if(RandomNumber!=PosX*GridWidNum+PosY && RandomNumber!=PosX*GridWidNum+PosY+1 && RandomNumber!=PosX*GridWidNum+PosY-1 && RandomNumber!=PosX*GridWidNum+PosY+GridWidNum && RandomNumber!=PosX*GridWidNum+PosY-GridWidNum && RandomNumber!=PosX*GridWidNum+PosY+GridWidNum+1 && RandomNumber!=PosX*GridWidNum+PosY+GridWidNum-1 && RandomNumber!=PosX*GridWidNum+PosY-GridWidNum+1 && RandomNumber!=PosX*GridWidNum+PosY-GridWidNum-1)
			UniqueRandomNumbers.Add(RandomNumber);
		//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, (FString::FromInt(RandomNumber)));
	}
	for (auto num : UniqueRandomNumbers)
	{
        OutUniqueRandomNumbers.Add(num);
	}
}
//
void AMineGenerator::GenerateBomb(const TArray<int32>&  Index)
{
	//生成Bomb显示为*
	for (int i = 0;i < MineArray.Num();i++)
	{
		TArray<UTextRenderComponent*> TextRenderComponents;
		if (Index.Find(i)!= INDEX_NONE)
		{
			MineArray[i]->isBomb = true;
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(i));
			MineArray[i]->GetComponents(TextRenderComponents);
			if (TextRenderComponents.Num() > 0)
			{
				UTextRenderComponent* TextRenderComponent = TextRenderComponents[0];
				//TextRenderComponent->SetText(FText::FromString("*"));
			}
		}
	}

}

void AMineGenerator::GameFail()
{
	for (auto cube : MineArray)
	{
		if(cube->isBomb)
		{
			cube->bombMesh->SetVisibility(true);
			cube->cubeMesh->SetVisibility(false);
			cube->numText->SetVisibility(false);
		}
	}
}

void AMineGenerator::GameWin()
{
}

void AMineGenerator::GetAroundMine(const int32& x, const int32& y, int32& num, TArray<AMineBasic*>& aroundMine)
{
	num = 0;
	aroundMine.Empty();
	int32 count = 0;
	for (int i = x - 1; i <= x + 1; i++)
    {
        for (int j = y - 1; j <= y + 1; j++)
        {

            if (i >= 0 && i < GridLenNum && j >= 0 && j < GridWidNum && count != 4)
            {
				aroundMine.Add(MineArray[i * GridWidNum + j]);
                if (MineArray[i * GridWidNum + j]->isBomb)
                {
                   num++;
                }
            }
			count++;
        }
    }
}

void AMineGenerator::RevealAround()
{
	//int32 num;
	
}

void AMineGenerator::FirstClick(int32 PosX, int32 PosY) //首次点击时生成地雷，确保第一次点击不会生成地雷
{
	GenerateUniqueRandomNumbers(0, GridWidNum * GridLenNum - 1, PosX, PosY, BombNum, bombIndex);
	GenerateBomb(bombIndex);

	isFirstClick = false;
}

