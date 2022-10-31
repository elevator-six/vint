#pragma once

namespace SkinChanger {
    int FilterWeaponName(FString in)
    {
		if (in.ToString().find("Ability_Melee_Base_C") != std::string::npos)
			return 1;
		if (in.ToString().find("BasePistol_C") != std::string::npos)
			return 2;
		if (in.ToString().find("TrainingBotBasePistol_C") != std::string::npos)
			return 3;
		if (in.ToString().find("SawedOffShotgun_C") != std::string::npos)
			return 4;
		if (in.ToString().find("AutomaticPistol_C") != std::string::npos)
			return 5;
		if (in.ToString().find("LugerPistol_C") != std::string::npos)
			return 6;
		if (in.ToString().find("RevolverPistol_C") != std::string::npos)
			return 7;
		if (in.ToString().find("Vector_C") != std::string::npos)
			return 8;
		if (in.ToString().find("SubMachineGun_MP5_C") != std::string::npos)
			return 9;
		if (in.ToString().find("PumpShotgun_C") != std::string::npos)
			return 10;
		if (in.ToString().find("AssaultRifle_Burst_C") != std::string::npos)
			return 11;
		if (in.ToString().find("DMR_C") != std::string::npos)
			return 12;
		if (in.ToString().find("AssaultRifle_ACR_C") != std::string::npos)
			return 13;
		if (in.ToString().find("AssaultRifle_AK_C") != std::string::npos)
			return 14;
		if (in.ToString().find("LeverSniperRifle_C") != std::string::npos)
			return 15;
		if (in.ToString().find("BoltSniper_C") != std::string::npos)
			return 16;
		if (in.ToString().find("LightMachineGun_C") != std::string::npos)
			return 17;
		if (in.ToString().find("HeavyMachineGun_C") != std::string::npos)
			return 18;
		else
			return 0;
    }

	void Commit(AActor* actor) {
		UAresInventory* Inventory = actor->GetInventory();
		AAresEquippable* current_equippable = Inventory->GetCurrentEquippable();

		int equippable_type = FilterWeaponName(KismetSystemLibrary::GetObjectName((UObject*)current_equippable));

		int random = rand() % (2 - 0 + 1) + 0;

		UEquippableSkinDataAsset* current_skin = current_equippable->GetEquippableSkinDataAsset();

		UObject* skin_data_asset = nullptr;
		UObject* chroma_data_asset = nullptr;

		if (random == 0) {
			skin_data_asset = UObject::StaticFindObject(nullptr, reinterpret_cast<UObject*>(-1), L"Default__Melee_Soulstealer2_PrimaryAsset_C", false);
			chroma_data_asset = UObject::StaticFindObject(nullptr, reinterpret_cast<UObject*>(-1), L"Default__Melee_Soulstealer2_v3_PrimaryAsset_C", false);
		}
		else if (random == 1) {
			skin_data_asset = UObject::StaticFindObject(nullptr, reinterpret_cast<UObject*>(-1), L"Default__Melee_Alien_PrimaryAsset_C", false);
			chroma_data_asset = UObject::StaticFindObject(nullptr, reinterpret_cast<UObject*>(-1), L"Default__Melee_Alien_Standard_PrimaryAsset_C", false);
		}
		else if (random == 2) {
			skin_data_asset = UObject::StaticFindObject(nullptr, reinterpret_cast<UObject*>(-1), L"Default__Melee_Base_Sovereign_PrimaryAsset_C", false);
			chroma_data_asset = UObject::StaticFindObject(nullptr, reinterpret_cast<UObject*>(-1), L"Default__Melee_Base_Sovereign_Standard_PrimaryAsset_C", false);
		}

		auto decrypt = ((__int64(__fastcall*)(__int64 a1))(module_base + 0x26132e0));
		auto check = decrypt((__int64)current_equippable);
		auto a1 = *reinterpret_cast<uintptr_t*>(check + 0x298);
		a1 = *reinterpret_cast<uintptr_t*>(a1 + 0xA0);

		auto old = *reinterpret_cast<int*>(a1 + 0x80);
		write(a1 + 0x80, 2);

		ContentLibrary::ClearWeaponComponents((AActor*)current_equippable);
		ContentLibrary::ApplySkin((AActor*)current_equippable, (UEquippableSkinDataAsset*)skin_data_asset, (UEquippableSkinChromaDataAsset*)chroma_data_asset, 2, nullptr, -1);
		write<int>(a1 + 0x80, old);
		Vint::Global::MiscSettings::skinchanger = false;

		// Not fully implemented, was just testing
	}
}