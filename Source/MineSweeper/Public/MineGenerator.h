// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MineBasic.h"
#include "MineGenerator.generated.h"

UCLASS()
class MINESWEEPER_API AMineGenerator : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMineGenerator();

	UPROPERTY(EditAnywhere)
	int32 GridLenNum = 9;

	UPROPERTY(EditAnywhere)
	int32 GridWidNum = 9;

	UPROPERTY(EditAnywhere)
	int32 BombNum = 9;

	UPROPERTY(EditAnywhere)
	int32 MineGap = 50;

	UPROPERTY(VisibleDefaultsOnly)
	TArray<AMineBasic*> MineArray;

	TArray<int32> bombIndex;//地雷序号
	bool isFirstClick = true;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void GenerateMine();
	void GenerateUniqueRandomNumbers(int32 Min, int32 Max, int32 PosX, int32 PosY, int32 Count, TArray<int32>& OutUniqueRandomNumbers);
	void GenerateBomb(const TArray<int32>& BombIndex);
	void GameFail();
	void GameWin();
	void GetAroundMine(const int32& x, const int32& y, int32& num, TArray<AMineBasic*>& aroundMine);//获取指定位置 (x, y) 周围的雷的数量。根据 Minesweeper 的规则，这个函数检查 (x, y) 周围的八个格子，并统计其中包含的雷的数量。
	void RevealAround();
	void FirstClick(int32 PosX,int32 PosY);
};