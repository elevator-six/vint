#include <windows.h>
#include <iostream>
#include <string>
#include <cstdint>
#include <winnt.h>
#include <vector>
#include <Psapi.h>

uint64_t module_base = NULL;

#include "Utils/defs.h"
#include "Utils/lazy.h"
#include "Utils/memory.h"
#include "Utils/xor.h"
#include "Utils/offsets.h"

#include "SDK/engine.h"
using namespace Engine;
#include "SDK/functions.h"
using namespace Valorant;

UWorld* world = nullptr;

#include "Utils/universal.h"

#include "Framework/ZeroInput.h"
#include "Framework/ZeroGUI.h"
#include "Framework/menu.h"

#include "Features/esp.h"
#include "Features/chams.h"
#include "Features/skin_changer.h"

using DrawTransitionOrg = void(*)(uintptr_t this_, UCanvas* Canvas);
DrawTransitionOrg DrawTransitionOriginal = 0;

void DrawTransition(uintptr_t this_, UCanvas* Canvas)
{
	if (!Canvas) {
		return DrawTransition(this_, Canvas);
	}

	SetupCanvas(Canvas);
	Menu::menu_tick();

	APlayerController* controller = ShooterGameBlueprints::GetFirstLocalPlayerController(world);
	AActor* local_acator = controller->GetShooterCharacter();
	TArray<AActor*> actors = ShooterGameBlueprints::FindAllShooterCharactersWithAlliance(world, local_acator, EAresAlliance::Alliance_Any, false, true);

	for (int i = 0; i < actors.Num(); i++) {
		if (!actors.IsValidIndex(i))
			continue;

		AActor* actor = actors[i];

		FVector my_camera_location;
		if (actor == local_acator) {
			my_camera_location = actor->K2_GetActorLocation();
			SkinChanger::Commit(actor);
			continue;
		}

		if (BaseTeamComponent::IsAlly(actor, local_acator))
			continue;

		UMeshComponent* mesh = actor->GetPawnMesh();
		bool IsAlive = actor->IsAlive();

		FVector actor_location = actor->K2_GetActorLocation();
		float health = actor->GetHealth();
		float shield = actor->GetShield();

		if (mesh && IsAlive) {
			Chams::Activate(mesh);
			Walls::Render(controller, mesh, actor_location, my_camera_location, health, shield);
		}
	}

	return DrawTransitionOriginal(this_, Canvas);
}

void Initialize()
{
	module_base = (uintptr_t)IFH(GetModuleHandleA)(0);

	AllocConsole();
	FILE* fDummy;
	freopen_s(&fDummy, "CONIN$", "r", stdin);
	freopen_s(&fDummy, "CONOUT$", "w", stderr);
	freopen_s(&fDummy, "CONOUT$", "w", stdout);

	world = Decrypt::UWorld();
	UViewportClient* ViewportClient = world->OwningGameInstance()->LocalPlayers()->LocalPlayer()->ViewportClient();
	APlayerController* PlayerController = world->OwningGameInstance()->LocalPlayers()->LocalPlayer()->PlayerController();

	Hook::hook((PVOID)ViewportClient, DrawTransition, 0x68, (PVOID*)&DrawTransitionOriginal);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		Initialize();
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}
