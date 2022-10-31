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
		FRotator GetCameraRotation() { // Function Engine.PlayerCameraManager.GetCameraRotation // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x54c5510
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.PlayerCameraManager.GetCameraRotation", false);
			if (!Function) {
				return {};
			}
			struct {
				FRotator Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;

		}
		FVector GetCameraLocation() { // Function Engine.PlayerCameraManager.GetCameraLocation // (Native|Public|HasDefaults|BlueprintCallable|BlueprintPure|Const) // @ game+0x54c54c0
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.PlayerCameraManager.GetCameraLocation", false);
			if (!Function) {
				return {};
			}
			struct {
				FVector Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	class UMeshComponent
	{
	public:
		void SetAresOutlineMode(EAresOutlineMode Mode, bool bPropagateToChildren)
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.MeshComponent.SetAresOutlineMode", false);
			if (!Function) {
				return;
			}
			struct {
				EAresOutlineMode Mode;
				bool bPropagateToChildren;
			} Parameters;
			Parameters.Mode = Mode;
			Parameters.bPropagateToChildren = bPropagateToChildren;

			Function->ProcessEvent(this, Function, &Parameters);
		}

		void SetIsFirstPerson(bool Value)
		{
			static UObject* Function = UObject::StaticFindObject(0, 0, L"PrimitiveComponent.SetIsFirstPerson", false);
			if (!Function) {
				return;
			}
			struct {
				bool Value;
			} Parameters;
			Parameters.Value = Value;

			Function->ProcessEvent(this, Function, &Parameters);
		}

		FTransform K2_GetComponentToWorld() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"Engine.SceneComponent.K2_GetComponentToWorld", false);
			if (!Function) {
				return {};
			}
			struct {
				FTransform Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FVector GetBone(std::int32_t index) {
			FMatrix matrix = {};
			reinterpret_cast<FMatrix* (*)(UMeshComponent*, FMatrix*, std::int32_t)>(module_base + offsets::bone_matrix)(this, &matrix, index);
			return { matrix.w.X, matrix.w.Y, matrix.w.Z };
		}
	};

	class AActor;

	class APlayerController : public UObject {
	public:
		ACameraManager* GetPlayerCameraManager() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresPlayerController.GetPlayerCameraManager", false);
			if (!Function) {
				return nullptr;
			}
			struct
			{
				ACameraManager* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		AActor* GetShooterCharacter() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresPlayerController.GetShooterCharacter", false);
			if (!Function) {
				return nullptr;
			}
			struct {
				AActor* Out;
			}Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		void AddPitchInput(float value) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.PlayerController.AddPitchInput", false);
			if (!Function) {
				return;
			}

			Function->ProcessEvent(this, Function, &value);
		}

		void AddYawInput(float value) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.PlayerController.AddYawInput", false);
			if (!Function) {
				return;
			}

			Function->ProcessEvent(this, Function, &value);
		}

		float GetMouseSensitivity() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterPlayerController.GetMouseSensitivity", false);
			if (!Function) {
				return 0.0f;
			}
			struct {
				float Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool ProjectWorldLocationToScreen(FVector WorldLocation, FVector* ScreenLocation)
		{
			static UObject* Function = UObject::StaticFindObject(0, 0, L"PlayerController.ProjectWorldLocationToScreen", false);
			if (!Function) {
				return false;
			}
			struct {
				FVector WorldLocation;
				FVector2D ScreenLocation;
				bool bPlayerViewportRelative;
				bool Out;
			} Parameters;

			Parameters.WorldLocation = WorldLocation;
			Parameters.bPlayerViewportRelative = false;

			Function->ProcessEvent(this, Function, &Parameters);

			ScreenLocation->X = Parameters.ScreenLocation.X;
			ScreenLocation->Y = Parameters.ScreenLocation.Y;
			ScreenLocation->Z = 0.f;

			return Parameters.Out;
		}

		FRotator GetControlRotation()
		{
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.Controller.GetControlRotation", false);
			if (!Function) {
				return { 0,0,0 };
			}
			struct {
				FRotator Out;
			} Parameters;
			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool line_of_sight_to(const AActor* Target, FVector ViewPoint = {}, bool AlternateChecks = false) {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.Controller.LineOfSightTo", false);

			if (!Function) {
				return false;
			}
			struct {
				const AActor* Target;
				FVector ViewPoint;
				bool AlternateChecks;
				bool Out;
			} Parameters;

			Parameters.Target = Target;
			Parameters.ViewPoint = ViewPoint;
			Parameters.AlternateChecks = AlternateChecks;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		void FOV(float NewFov)
		{
			static UObject* Function = UObject::StaticFindObject(0, 0, L"PlayerController.FOV", false);
			if (!Function) {
				return;
			}
			struct {
				float NewFov;
			} Parameters;
			Parameters.NewFov = NewFov;

			Function->ProcessEvent(this, Function, &Parameters);
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

	struct UEquippableSkinDataAsset
	{

	};
	struct UEquippableSkinChromaDataAsset
	{

	};
	struct UEquippableCharmDataAsset
	{

	};

	namespace KismetMathLibrary {
		UObject* Static_Class() {
			return UObject::StaticFindObject(nullptr, nullptr, L"Engine.Default__KismetMathLibrary", false);
		}

		FRotator FindLookAtRotation(FVector Start, FVector Target) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetMathLibrary.FindLookAtRotation", false);
			if (!Function) {
				return {};
			}
			struct {
				FVector Start;
				FVector Target;
				FRotator Out;
			} Parameters;
			Parameters.Start = Start;
			Parameters.Target = Target;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}

		FRotator RInterpTo_Constant(const FRotator& current, const FRotator& target, float delta_time, float speed) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetMathLibrary.RInterpTo_Constant", false);
			if (!Function) {
				return {};
			}
			struct {
				FRotator current;
				FRotator target;
				float delta_time;
				float speed;
				FRotator Out;
			} Parameters;
			Parameters.current = current;
			Parameters.target = target;
			Parameters.delta_time = delta_time;
			Parameters.speed = speed;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}

		FRotator RInterpTo(const FRotator& current, const FRotator& target, float delta_time, float speed) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetMathLibrary.RInterpTo", false);
			if (!Function) {
				return {};
			}
			struct {
				FRotator current;
				FRotator target;
				float delta_time;
				float speed;

				FRotator Out;
			} Parameters;
			Parameters.current = current;
			Parameters.target = target;
			Parameters.delta_time = delta_time;
			Parameters.speed = speed;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}

		FRotator NormalizedDeltaRotator(const FRotator& a, const FRotator& b) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetMathLibrary.NormalizedDeltaRotator", false);
			if (!Function) {
				return {};
			}
			struct {
				FRotator a;
				FRotator b;
				
				FRotator Out;
			} Parameters;
			Parameters.a = a;
			Parameters.b = b;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}
	}

	namespace GameplayStatics {
		UObject* Static_Class() {
			return UObject::StaticFindObject(0, 0, L"Engine.Default__GameplayStatics", false);
		}

		float get_world_delta_seconds(UObject* WorldContext) {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.GameplayStatics.GetWorldDeltaSeconds", false);
			if (!Function) {
				return 0.0f;
			}
			struct {
				UObject* WorldContext;
				float Out;
			} Parameters;

			Parameters.WorldContext = WorldContext;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}
	}

	namespace KismetSystemLibrary {
		UObject* Static_Class() {
			return UObject::StaticFindObject(nullptr, nullptr, L"Engine.Default__KismetSystemLibrary", false);
		}
		void call_remote_function(UObject* function, void* args, void* out_args = nullptr, void* stack = nullptr) {
			return reinterpret_cast<void (*)(UObject*, UObject*, void*, void*, void*)>(module_base + 0x3520430)(Static_Class(), function, args, out_args, stack);
		}

		FString GetObjectName(UObject* Object) {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetSystemLibrary.GetObjectName", false);
			if (!Function) {
				return L"";
			}
			struct {
				UObject* Object;
				FString Out;
			} Parameters;
			Parameters.Object = Object;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}

		bool contains(FString SearchIn, FString SubString, bool UseCase = false, bool SearchFromEnd = false) {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetStringLibrary.Contains", false);
			if (!Function) {

			}
			struct {
				FString SearchIn;
				FString SubString;
				bool UseCase;
				bool SearchFromEnd;
				bool Out;
			} Parameters;

			Parameters.SearchIn = SearchIn;
			Parameters.SubString = SubString;
			Parameters.UseCase = UseCase;
			Parameters.SearchFromEnd = SearchFromEnd;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);

			return Parameters.Out;
		}

		bool StartsWith(FString SourceString, FString InPrefix) {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.KismetStringLibrary.StartsWith", false);
			if (!Function) {
				return false;
			}
			struct {
				FString SourceString;
				FString InPrefix;
				ESearchCase SearchCase;
				bool Out;
			} Parameters;
			Parameters.SourceString = SourceString;
			Parameters.InPrefix = InPrefix;
			Parameters.SearchCase = ESearchCase::IgnoreCase;

			Function->ProcessEvent(Static_Class(), Function, &Parameters);
			return Parameters.Out;
		}
	}

	struct AAresEquippable
	{
		struct type {
			const wchar_t* search = nullptr;
			const char* config = nullptr;

			std::int32_t index = 0;

			const bool IsValid() const noexcept {
				return this->search != nullptr || this->config != nullptr;
			}
		};

		static inline type types[] = {
					{ L"basepistol", "classic" },
					{ L"sawedoffshotgun", "shorty" },
					{ L"automaticpistol", "frenzy" },
					{ L"lugerpistol", "ghost" },
					{ L"revolverpistol", "sheriff" },

					{ L"vector", "stinger" },
					{ L"submachinegun_mp5", "spectre" },

					{ L"pumpshotgun", "bucky" },
					{ L"automaticshotgun", "judge" },

					{ L"assaultrifle_burst", "bulldog" },
					{ L"dmr", "guardian" },
					{ L"assaultrifle_acr", "phantom" },
					{ L"assaultrifle_ak", "vandal" },

					{ L"leversniperrifle", "marshal" },
					{ L"boltsniper", "operator" },

					{ L"lightmachinegun", "ares" },
					{ L"heavymachinegun", "odin" },

					{ L"ability_melee_base", "knife" },

					{ L"gun_sprinter_x_heavylightninggun_production", "neon_x" },
					{ L"ability_wushu_x_dagger_production", "jett_dagger" }
		};

		UEquippableSkinDataAsset* GetEquippableSkinDataAsset() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresEquippable.GetEquippableSkinDataAsset", false);
			if (!Function) {
				return nullptr;
			}
			struct {
				UEquippableSkinDataAsset* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		type GetType() {
			const FString& name = KismetSystemLibrary::GetObjectName((UObject*)this);

			for (std::int32_t index = 0; index < sizeof(types) / sizeof(type); index++) {
				AAresEquippable::type type = types[index];
				if (KismetSystemLibrary::StartsWith(name.c_str(), type.search))
					return { type.search, type.config, index };
			}

			return {};
		}
	};

	struct UAresInventory
	{
		AAresEquippable* GetCurrentEquippable() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.AresInventory.GetCurrentEquippable", false);
			if (!Function) {
				return 0;
			}
			struct {
				AAresEquippable* Out;
			}Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	class AActor {
	public:

		UMeshComponent* GetPawnMesh() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetPawnMesh", false);
			if (!Function) {
				return nullptr;
			}
			struct {
				UMeshComponent* Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool IsAlive() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.IsAlive", false);
			if (!Function) {
				return false;
			}
			struct {
				bool Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float GetHealth() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"ShooterCharacter.GetHealth", false);
			if (!Function) {
				return 0.0f;
			}
			struct {
				float Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		float GetShield() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"ShooterCharacter.GetShield", false);
			if (!Function) {
				return 0.0f;
			}
			struct {
				float Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FVector K2_GetActorLocation() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.Actor.K2_GetActorLocation", false);
			if (!Function) {
				return {};
			}
			struct {
				FVector Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FVector GetPawnViewLocation() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetPawnViewLocation", false);
			if (!Function) {
				return {};
			}
			struct {
				FVector Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FRotator K2_GetActorRotation() {
			UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"Engine.Actor.K2_GetActorRotation", false);
			FRotator Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters;
		}

		bool CanJump() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"Character.CanJump", false);
			if (!Function) {
				return false;
			}
			struct {
				bool Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		bool CanJumpInternal() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"Character.CanJumpInternal", false);
			if (!Function) {
				return false;
			}
			struct {
				bool Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		void Jump() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"Character.Jump", false);
			if (!Function) {
				return;
			}
			struct {

			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
		}

		void StopJumping() {
			static UObject* Function = UObject::StaticFindObject(0, 0, L"Character.StopJumping", false);
			if (!Function) {
				return;
			}
			struct {

			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
		}

		UAresInventory* GetInventory() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetInventory", false);
			if (!Function) {
				return nullptr;
			}
			struct {
				UAresInventory* Out;
			}Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FRotator GetViewRotationFullRecoil() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetViewRotationFullRecoil", false);
			if (!Function) {
				return {};
			}
			struct {
				FRotator Out;
			} Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}

		FRotator GetViewRotationNoRecoil() {
			static UObject* Function = UObject::StaticFindObject(nullptr, nullptr, L"ShooterGame.ShooterCharacter.GetViewRotationNoRecoil", false);
			if (!Function) {
				return {};
			}
			struct {
				FRotator Out;
			}Parameters;

			Function->ProcessEvent(this, Function, &Parameters);
			return Parameters.Out;
		}
	};

	class ULevel {
	public:

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
			Params._bCentreY = true;

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

		FVector project(const FVector& world_location) {
			UObject* function = UObject::StaticFindObject(0, 0, L"Engine.Canvas.K2_Project", false);

			if (function == nullptr)
				return {};

			struct
			{
				FVector world_location;
				FVector return_value;
			} params;

			params.world_location = world_location;

			function->ProcessEvent(this, function, &params);

			return params.return_value;
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

	namespace NoSpread {
		inline FVector get_error_angle(uint64_t actor, uint64_t firing_state_component) {
			static auto get_spread_values_fn =
				(float* (__fastcall*)(uint64_t, float*))(module_base + 0x25DD3C0);
			static auto get_spread_angles_fn =
				(void(__fastcall*)(uint64_t, FVector*, float, float, int, int, uint64_t))(module_base + 0x2C73E40);
			static auto get_firing_location_and_direction_fn =
				(void(__fastcall*)(uint64_t, FVector*, FVector*))(module_base + 0x2AB4B90);
			static auto to_vector_and_normalize_fn =
				(FVector* (__fastcall*)(FVector*, FVector*))(module_base + 0x3268090);
			static auto to_angle_and_normalize_fn =
				(FVector* (__fastcall*)(FVector*, FVector*))(module_base + 0x3261F90);

			static uint8_t error_values[4096] = { 0 };
			static uint8_t seed_data_snapshot[4096] = { 0 };
			static uint8_t spread_angles[4096] = { 0 };
			static uint8_t out_spread_angles[4096] = { 0 };

			if (!actor || !firing_state_component)
				return FVector(0, 0, 0);

			memset(error_values, 0, sizeof(error_values));
			memset(seed_data_snapshot, 0, sizeof(seed_data_snapshot));
			memset(spread_angles, 0, sizeof(spread_angles));
			memset(out_spread_angles, 0, sizeof(out_spread_angles));

			*(uint64_t*)(&out_spread_angles[0]) = (uint64_t)&spread_angles[0];
			*(int*)(&out_spread_angles[0] + 8) = 1;
			*(int*)(&out_spread_angles[0] + 12) = 1; //It's a TArray but I'm lazy

			uint64_t seed_data = ReadStub<uint64_t>(firing_state_component + 0x420);
			memcpy((void*)seed_data_snapshot, (void*)seed_data, sizeof(seed_data_snapshot)); //Make our own copy since we don't want to desync our own seed component

			uint64_t stability_component = ReadStub<uint64_t>(firing_state_component + 0x410);
			if (stability_component)
				get_spread_values_fn(stability_component, (float*)&error_values[0]);

			FVector temp1, temp2 = FVector(0, 0, 0);
			FVector previous_firing_direction, firing_direction = FVector(0, 0, 0);
			get_firing_location_and_direction_fn(actor, &temp1, &previous_firing_direction);
			to_vector_and_normalize_fn(&previous_firing_direction, &temp2);
			to_angle_and_normalize_fn(&temp2, &temp1);
			previous_firing_direction = temp1;
			temp1.X += *(float*)(&error_values[0] + 12); //Your recoil angle
			temp1.Y += *(float*)(&error_values[0] + 16);
			to_vector_and_normalize_fn(&temp1, &firing_direction);

			float error_degrees = *(float*)(&error_values[0] + 8) + *(float*)(&error_values[0] + 4);
			float error_power = *(float*)(firing_state_component + 0x3f0);
			int error_retries = *(int*)(firing_state_component + 0x3f4);
			get_spread_angles_fn(((uint64_t)&seed_data_snapshot[0]) + 0xE8, &firing_direction, error_degrees, error_power, error_retries, 1, (uint64_t)&out_spread_angles[0]);

			FVector spread_vector = *(FVector*)(&spread_angles[0]);
			to_angle_and_normalize_fn(&spread_vector, &firing_direction);

			return firing_direction - previous_firing_direction; //Get the difference. Now subtract it against your aimbot!
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

namespace World
{
	Valorant::UWorld* ReadWorld()
	{
		for (int i = 0; i < sizeof(uworld_names) / sizeof(wchar_t*); i++)
		{
			Valorant::UWorld* cache_uworld = (Valorant::UWorld*)::Valorant::UObject::StaticFindObject(nullptr, nullptr, uworld_names[i], false);
			if (cache_uworld)
				return cache_uworld;
		}
		return nullptr;
	}
}