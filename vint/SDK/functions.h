#pragma once
#include <list>

#include "matrix.h"

namespace Valorant {
	class UObject {
	public:
		static UObject* StaticFindObject(UObject* Class, UObject* InOuter, const wchar_t* Name, bool ExactClass)
		{
			static uintptr_t StaticFindObjectAddress = module_base + 0x35610e0;

			auto StaticFindObjectFN = reinterpret_cast<UObject * (__fastcall*)(UObject*, UObject*, const wchar_t*, bool)>(StaticFindObjectAddress);

			return StaticFindObjectFN(Class, InOuter, Name, ExactClass);
		}
		static void ProcessEvent(void* class_, UObject* function, void* params)
		{
			reinterpret_cast<void (*)(void*, UObject*, void*)>(module_base + 0x3520430)(class_, function, params);
		}
		TArray<struct AGameObject*> FindAllGameObjects(UObject* WorldContextObject)
		{

		}

		static uintptr_t StaticLoadObject(uintptr_t Class, uintptr_t InOuter, const TCHAR* Name, const TCHAR* Filename, uint32 LoadFlags, uintptr_t Sandbox, bool bAllowObjectReconciliation, uintptr_t InSerializeContext)
		{
			uintptr_t ADDRESS = module_base + 0x3562ee0;

			uintptr_t(*StaticLoadbject_)(uintptr_t, uintptr_t, const TCHAR*, const TCHAR*, uint32, uintptr_t, bool, uintptr_t) = reinterpret_cast<decltype(StaticLoadbject_)>(ADDRESS);
			uintptr_t Return = StaticLoadbject_(Class, InOuter, Name, Filename, LoadFlags, Sandbox, bAllowObjectReconciliation, InSerializeContext);

			return Return;
		}
	};

	class ACameraManager {
	public:
		FMinimalViewInfo GetCamera()
		{
			return read<FMinimalViewInfo>((uintptr_t)this + 0x1260);
		}
	};

	class UMeshComponent
	{
	public:
		void SetAresOutlineMode(EAresOutlineMode Mode, bool bPropagateToChildren)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.MeshComponent.SetAresOutlineMode", false);
			if (!Function)
			{
				return;
			}
			struct
			{
				EAresOutlineMode Mode;
				bool bPropagateToChildren;
			}Parameters;
			Parameters.Mode = Mode;
			Parameters.bPropagateToChildren = bPropagateToChildren;
			Function->ProcessEvent(this, Function, &Parameters);
		}

		void SetIsFirstPerson(bool Value)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"PrimitiveComponent.SetIsFirstPerson", false);
			}

			struct {
				bool val;
			} Params;

			Params.val = Value;

			Function->ProcessEvent(this, Function, &Params);
		}

		FTransform K2_GetComponentToWorld() {
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Engine.SceneComponent.K2_GetComponentToWorld", false);
			}

			struct {
				FTransform out;
			} Params;
			Function->ProcessEvent(this, Function, &Params);
			return Params.out;
		}

		FVector GetEntityBone(int id) {
			DWORD_PTR array = read<uintptr_t>((uintptr_t)this + offsets::bone_array);

			FTransform bone = read<FTransform>(array + (id * 0x30));

			FTransform ComponentToWorld = this->K2_GetComponentToWorld();
			D3DMATRIX Matrix;

			Matrix = MatrixMultiplication(bone.ToMatrixWithScale(), ComponentToWorld.ToMatrixWithScale());

			return FVector(Matrix._41, Matrix._42, Matrix._43);
		}
	};

	class AActor;

	class APlayerController {
	public:
		AActor* GetShooterCharacter() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresPlayerController.GetShooterCharacter", false);
			if (!Function)
			{
				return nullptr;
			}
			struct
			{
				AActor* Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float InputYawScale()
		{
			return read<float>((uintptr_t)this + 0x5e4);
		}

		float InputPitchScale()
		{
			return read<float>((uintptr_t)this + 0x5e8);
		}

		ACameraManager* CameraManager()
		{
			return read<ACameraManager*>((uintptr_t)this + 0x478);
		}

		void AddYawInput(float Val)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"PlayerController.AddYawInput", false);
			}

			struct {
				float _Val;
			} Params;

			Params._Val = Val;

			Function->ProcessEvent(this, Function, &Params);
		}

		void AddPitchInput(float Val)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"PlayerController.AddPitchInput", false);
			}

			struct {
				float _Val;
			} Params;

			Params._Val = Val;

			Function->ProcessEvent(this, Function, &Params);
		}

		bool ProjectWorldLocationToScreen(FVector WorldLocation, FVector* ScreenLocation)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"PlayerController.ProjectWorldLocationToScreen", false);
			}

			struct {
				FVector _WorldLocation;
				FVector2D _ScreenLocation;
				bool _bPlayerViewportRelative;
				bool _ReturnValue;
			} Params;

			Params._WorldLocation = WorldLocation;
			Params._bPlayerViewportRelative = false;

			Function->ProcessEvent(this, Function, &Params);

			ScreenLocation->X = Params._ScreenLocation.X;
			ScreenLocation->Y = Params._ScreenLocation.Y;
			ScreenLocation->Z = 0.f;

			return Params._ReturnValue;
		}

		bool LineOfSightTo(uintptr_t Other, FVector ViewPoint, bool bAlternateChecks)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Controller.LineOfSightTo", false);
			}

			struct {
				uintptr_t _Other;
				FVector _ViewPoint;
				bool _bAlternateChecks;
				bool _ReturnValue;
			} Params;

			Params._Other = Other;
			Params._ViewPoint = ViewPoint;
			Params._bAlternateChecks = bAlternateChecks;

			Function->ProcessEvent(this, Function, &Params);

			return Params._ReturnValue;
		}

		void FOV(float NewFov)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"PlayerController.FOV", false);
			}

			struct {
				float _NewFov;
			} Params;
			Params._NewFov = NewFov;

			Function->ProcessEvent(this, Function, &Params);
		}
	};

	class UViewportClient {
	public:
		void** VTable;
	};

	class ULocalPlayer {
	public:
		APlayerController* PlayerController()
		{
			return read<APlayerController*>((uintptr_t)this + 0x38);
		}

		UViewportClient* ViewportClient()
		{
			return read<UViewportClient*>((uintptr_t)this + 0x78);
		}
	};

	class ULocalPlayers {
	public:
		ULocalPlayer* LocalPlayer()
		{
			return read<ULocalPlayer*>((uintptr_t)this);
		}
	};

	class UGameInstance {
	public:
		ULocalPlayers* LocalPlayers()
		{
			return read<ULocalPlayers*>((uintptr_t)this + 0x40);
		}
	};

	class USceneComponent {
	public:
		FVector RelativeLocation()
		{
			return read<FVector>((uintptr_t)this + 0x164);
		}
	};

	class APlayerState {
	public:

	};

	struct AAresEquippable
	{

	};

	struct UEquippableSkinDataAsset
	{

	};
	struct UEquippableSkinChromaDataAsset
	{

	};
	struct UEquippableCharmDataAsset
	{

	};

	struct UAresInventory
	{
		AAresEquippable* GetCurrentEquippable()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresInventory.GetCurrentEquippable", false);
			if (!Function)
			{
				return 0;
			}
			struct
			{
				AAresEquippable* Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	class AActor {
	public:
		int32_t ObjectID()
		{
			return read<int32_t>((uintptr_t)this + 0x18);
		}

		int32_t UniqueID()
		{
			return read<int32_t>((uintptr_t)this + 0x38);
		}

		USceneComponent* RootComponent()
		{
			return read<USceneComponent*>((uintptr_t)this + 0x230);
		}

		APlayerState* PlayerState()
		{
			return read<APlayerState*>((uintptr_t)this + 0x3F0);
		}

		UMeshComponent* GetPawnMesh()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetPawnMesh", false);
			if (!Function)
			{
				return 0;
			}
			struct
			{
				UMeshComponent* Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool IsAlive()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.IsAlive", false);
			if (!Function)
			{
				return 0;
			}
			struct
			{
				bool Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float GetHealth()
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"ShooterCharacter.GetHealth", false);
			}

			struct {
				float _ReturnValue;
			} Params;

			Function->ProcessEvent(this, Function, &Params);

			return Params._ReturnValue;
		}

		float GetShield()
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"ShooterCharacter.GetShield", false);
			}

			struct {
				float _ReturnValue;
			} Params;

			Function->ProcessEvent(this, Function, &Params);

			return Params._ReturnValue;
		}

		FVector K2_GetActorLocation()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.Actor.K2_GetActorLocation", false);
			if (!Function)
			{
				return {};
			}
			struct
			{
				FVector Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FVector GetPawnViewLocation()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetPawnViewLocation", false);
			if (!Function)
			{
				return {};
			}
			struct
			{
				FVector Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool CanJump()
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Character.CanJump", false);
			}

			struct {
				bool _ReturnValue;
			} Params;

			Function->ProcessEvent(this, Function, &Params);

			return Params._ReturnValue;
		}

		bool CanJumpInternal()
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Character.CanJumpInternal", false);
			}

			struct {
				bool _ReturnValue;
			} Params;

			Function->ProcessEvent(this, Function, &Params);

			return Params._ReturnValue;
		}

		void Jump()
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Character.Jump", false);
			}

			struct {

			} Params;

			Function->ProcessEvent(this, Function, &Params);
		}

		void StopJumping()
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Character.StopJumping", false);
			}

			struct {

			} Params;

			Function->ProcessEvent(this, Function, &Params);
		}

		UAresInventory* GetInventory()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetInventory", false);
			struct
			{
				UAresInventory* out;
			}Parameters;
			AAresEquippable* out;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.out;
		}
	};

	class ULevel {
	public:
		uintptr_t ActorArray()
		{
			return read<uintptr_t>((uintptr_t)this + 0xA0);
		}

		int32_t ActorCount()
		{
			return read<int32_t>((uintptr_t)this + 0xB8);
		}
	};

	class UCanvas {
	public:
		bool pad_1[0x30];
		float OrgX; // 0x30(0x04)
		float OrgY; // 0x34(0x04)
		float ClipX; // 0x38(0x04)
		float ClipY; // 0x3c(0x04)

		void K2_DrawText(FVector2D ScreenPosition, FLinearColor RenderColor, FString RenderText, bool bCentered, bool bOutlined)
		{
			static UObject* Address;
			if (!Address)
			{
				Address = UObject::StaticFindObject(0, 0, L"Canvas.K2_DrawText", false);
			}

			uintptr_t Font = UObject::StaticLoadObject(0, 0, L"/Engine/EngineFonts/Roboto.Roboto", 0, 0, 0, true, 0);

			struct {
				uintptr_t _RenderFont;
				FString _RenderText;
				FVector2D _ScreenPosition;
				FVector2D _Scale;
				FLinearColor _RenderColor;
				float _Kerning;
				FLinearColor _ShadowColor;
				FVector2D _ShadowOffset;
				bool _bCentreX;
				bool _bCentreY;
				bool _bOutlined;
				FLinearColor _OutlineColor;
			} Params;

			Params._RenderFont = Font;
			Params._RenderText = RenderText;
			Params._ScreenPosition = { ScreenPosition.X, ScreenPosition.Y };
			Params._Scale = { 0.97f, 0.97f };
			Params._RenderColor = RenderColor;
			Params._Kerning = 0;
			Params._ShadowColor = { 0.f, 0.f, 0.f, 0.f };
			Params._ShadowOffset = { ScreenPosition.X, ScreenPosition.Y };
			Params._bOutlined = bOutlined;
			Params._OutlineColor = { 0.0f, 0.0f, 0.0f, 255.f };
			Params._bCentreX = bCentered;
			Params._bCentreY = false;

			Address->ProcessEvent(this, Address, &Params);
		}

		void K2_DrawLine(FVector2D _ScreenPositionA, FVector2D _ScreenPositionB, float _Thickness, FLinearColor _RenderColor)
		{
			static UObject* Function;
			if (!Function)
			{
				Function = UObject::StaticFindObject(0, 0, L"Canvas.K2_DrawLine", false);
			}

			struct {
				FVector2D ScreenPositionA;
				FVector2D ScreenPositionB;
				float Thickness;
				FLinearColor RenderColor;
			} params;

			params.ScreenPositionA = { _ScreenPositionA.X, _ScreenPositionA.Y };
			params.ScreenPositionB = { _ScreenPositionB.X, _ScreenPositionB.Y };
			params.Thickness = _Thickness;
			params.RenderColor = _RenderColor;

			Function->ProcessEvent(this, Function, &params);
		}
	};

	class UWorld : public UObject {
	public:
		UGameInstance* OwningGameInstance()
		{
			return read<UGameInstance*>((uintptr_t)this + 0x1A0);
		}

		ULevel* PersistentLevel()
		{
			return read<ULevel*>((uintptr_t)this + 0x38);
		}
	};

	class UWorldState {
	public:
		uintptr_t Key[7];
	};

	namespace ShooterGameBlueprints
	{
		UObject* Static_Class()
		{
			return UObject::StaticFindObject(0, 0, L"ShooterGame.Default__ShooterBlueprintLibrary", false);
		}

		APlayerController* GetFirstLocalPlayerController(UWorld* WorldContextObject)
		{
			UObject* Function = UObject::StaticFindObject(0, 0, L"ShooterGame.ShooterBlueprintLibrary.GetFirstLocalPlayerController", false);
			if (!Function)
			{
				return 0;
			}
			struct
			{
				UWorld* WorldContextObject;
				APlayerController* Out;
			}Parameters;
			Parameters.WorldContextObject = WorldContextObject;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}
		TArray<AActor*> FindAllShooterCharactersWithAlliance(UWorld* WorldContextObject, AActor* LocalViewer, EAresAlliance Alliance, bool OnlyPlayerControlled, bool OnlyAlivePlayers)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterBlueprintLibrary.FindAllShooterCharactersWithAlliance", false);
			struct
			{
				UWorld* WorldContextObject;
				AActor* LocalViewer;
				EAresAlliance Alliance;
				bool OnlyPlayerControlled;
				bool OnlyAlivePlayers;
				TArray<AActor*> Out;
			}Parameters;
			Parameters.WorldContextObject = WorldContextObject;
			Parameters.LocalViewer = LocalViewer;
			Parameters.Alliance = Alliance;
			Parameters.OnlyPlayerControlled = OnlyPlayerControlled;
			Parameters.OnlyAlivePlayers = OnlyAlivePlayers;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}
	}

	namespace AresOutlineRendering
	{
		UObject* Static_Class()
		{
			return UObject::StaticFindObject(nullptr, nullptr, L"Renderer.Default__AresOutlineRendering", false);
		}

		void SetOutlineColorsForRender(UWorld* WorldContextObject, FLinearColor AllyColor, FLinearColor EnemyColor)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Renderer.AresOutlineRendering.SetOutlineColorsForRender", false);
			if (!Function)
			{
				return;
			}
			struct {
				UWorld* WorldContextObject;
				FLinearColor AllyColor;
				FLinearColor EnemyColor;
			}Parameters;
			Parameters.WorldContextObject = WorldContextObject;
			Parameters.AllyColor = AllyColor;
			Parameters.EnemyColor = EnemyColor;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
		}
	}

	namespace BaseTeamComponent {
		UObject* Static_Class()
		{
			return UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.Default__BaseTeamComponent", false);
		}

		bool IsAlly(AActor* Enemy, AActor* Self)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.BaseTeamComponent.IsAlly", false);
			struct {
				AActor* Enemy;
				AActor* Self;
				bool ReturnValue;
			}Parameters;
			Parameters.Enemy = Enemy;
			Parameters.Self = Self;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.ReturnValue;
		}
	}

	namespace KismetSystemLibrary {
		UObject* Static_Class() {
			return UObject::StaticFindObject(nullptr, nullptr, L"Engine.Default__KismetSystemLibrary", false);
		}
		FString GetObjectName(UObject* Object) {
			static UObject* Function;
			if (!Function) {
				Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetSystemLibrary.GetObjectName", false);
			}
			struct {
				UObject* Object;
				FString out;
			}Params;
			Params.Object = Object;
			Function->ProcessEvent(Static_Class(), Function, &Params);
			return Params.out;
		}
	}

	namespace ContentLibrary {
		UObject* Static_Class()
		{
			return UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.Default__ContentLibrary", false);
		}

		void ApplySkin(AActor* Parent, UEquippableSkinDataAsset* EquippableSkinAsset, UEquippableSkinChromaDataAsset* EquippableChromaAsset, int32_t SkinLevel, UEquippableCharmDataAsset* EquippableCharmAsset, int32_t CharmLevel)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ContentLibrary.ApplySkin", false);
			if (!Function)
			{
				return;
			}
			struct
			{
				AActor* Parent;
				UEquippableSkinDataAsset* EquippableSkinAsset;
				UEquippableSkinChromaDataAsset* EquippableChromaAsset;
				int32_t SkinLevel;
				UEquippableCharmDataAsset* EquippableCharmAsset;
				int32_t CharmLevel;
			}Parameters;
			Parameters.Parent = Parent;
			Parameters.EquippableSkinAsset = EquippableSkinAsset;
			Parameters.EquippableChromaAsset = EquippableChromaAsset;
			Parameters.SkinLevel = SkinLevel;
			Parameters.EquippableCharmAsset = EquippableCharmAsset;
			Parameters.CharmLevel = CharmLevel;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
		}

		void ClearWeaponComponents(AActor* Parent)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ContentLibrary.ClearWeaponComponents", false);
			if (!Function)
			{
				return;
			}
			struct
			{
				AActor* Parent;
			}Parameters;
			Parameters.Parent = Parent;
			Function->ProcessEvent(Static_Class(), Function, &Parameters);
		}
	}
}

namespace Hook
{
	bool hook(PVOID vTabelPtr, PVOID dest, int index, PVOID* orig) {
		auto vtable = *(uintptr_t**)vTabelPtr;
		int methods = 0;

		do {
			methods++;
		} while (*(uintptr_t*)((uintptr_t)vtable + (methods * 0x8)));

		auto vtable_buf = new uint64_t[methods * 0x8];
		for (auto count = 0; count < methods; count++) {
			vtable_buf[count] = *(uintptr_t*)((uintptr_t)vtable + (count * 0x8));

			*orig = (PVOID*)vtable[index];

			vtable_buf[index] = (uintptr_t)(dest);
			*(uint64_t**)vTabelPtr = vtable_buf;
		}
		return true;
	}
}

namespace Decrypt
{
	Valorant::UWorld* UWorld()
	{
		uintptr_t uworld_key = read<uintptr_t>(module_base + 0x9282978);
		Valorant::UWorldState uworld_state = read<Valorant::UWorldState>(module_base + 0x9282940);
		uintptr_t uworld = decrypt_uworld(uworld_key, (uintptr_t*)&uworld_state);
		uworld = ReadStub<uintptr_t>(uworld);

		return (Valorant::UWorld*)uworld;
	}
}