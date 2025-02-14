// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "LMADefaultCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
class ULMAHealthComponent;
class UAnimMontage;

UCLASS()
class LEAVEMEALONE_API ALMADefaultCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ALMADefaultCharacter();

	UFUNCTION()
	ULMAHealthComponent* GetHealthComponent() const { return HealthComponent; }

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;//������

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;//������

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Health")
	ULMAHealthComponent* HealthComponent;//��������

	UPROPERTY()
	UDecalComponent* CurrentCursor = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	UMaterialInterface* CursorMaterial = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cursor")
	FVector CursorSize = FVector(20.0f, 40.0f, 40.0f);

	UPROPERTY(EditDefaultsOnly, Category = "Animation")
	UAnimMontage* DeathMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Components|Stamina")
	float SprintSpeedMultiplier = 2.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Components|Stamina")
	float MaxStamina = 100.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Components|Stamina")
	float StaminaDrainRate = 50.0f;
	UPROPERTY(EditDefaultsOnly, Category = "Components|Stamina")
	float StaminaRecoveryRate = 10.0f;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components|Stamina")
	bool IsSprinting = false;

	virtual void BeginPlay() override;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:

	float YRotation = -75.0f;//� �������� �� ������� ������ �� ��� Y.
	float ArmLength = 1400.0f; // � �������� �� ����� �������.
	float FOV = 55.0f;		   // � �������� �� ���� ������ ������.
	float MinArmLength = 300.0f;
	float MaxArmLength = 2500.0f;
	float ZoomSpeed = 100.0f;

	void MoveForward(float Value);//�������� ��������� �� ��� X.
	void MoveRight(float Value);// �������� ��������� �� ��� Y.
	void Zoom(float Value);//����������� ������

	void OnDeath();
	void OnHealthChanged(float NewHealth);

	void RotationPlayerOnCursor();

	/*float SprintSpeed=1000.0f;
	float NormalSpeed;
	void StartSprint();
	void StopSprint();*/

	float DefaultWalkSpeed;
	float Stamina = 0.0f;
	bool CanSprint = true;

	void StaminaManager();
	void StartSprinting();
	void StopSprinting();




};
