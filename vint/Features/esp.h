#pragma once

namespace Walls {
	void Render(APlayerController* controller, UMeshComponent* mesh, FVector relative_location, ACameraManager* camera_manager, float health, float shield) {
		FVector head_bone_out;
		FVector head_bone = mesh->GetBone(8);
		controller->ProjectWorldLocationToScreen(head_bone, &head_bone_out);

		FVector root_bone_out;
		FVector root_bone = mesh->GetBone(0);
		controller->ProjectWorldLocationToScreen(root_bone, &root_bone_out);

		FVector relative_location_out;
		controller->ProjectWorldLocationToScreen(relative_location, &relative_location_out);

		FVector camera_location = camera_manager->GetCameraLocation();

		float box_height = abs(head_bone_out.Y - root_bone_out.Y);
		float box_width = box_height * 0.50;

		float distance = camera_location.Distance(relative_location) / 100.f;
		float distance_modifier = camera_location.Distance(head_bone) * 0.001F;

		FVector relative_position = relative_location - camera_location;
		float relative_distance = relative_position.Length() / 10000 * 2;

		if (Vint::Global::EspSettings::box_esp)
			CornerBox(relative_location_out, box_width, box_height, { 0.988f, 0.988f, 0, 1 });

		if (Vint::Global::EspSettings::head_esp)
			DrawCircle(FVector2D{ head_bone_out.X, head_bone_out.Y }, 9 / distance_modifier, 30, { 1,1,1,1 }, 2.0f);

		if (Vint::Global::EspSettings::health_esp) {
			if (health <= 100) {
				DrawHealthBar(relative_location_out, box_width, box_height, health, relative_distance);
				DrawShieldBar(relative_location_out, box_width, box_height, shield, relative_distance);
			}
		}

		if (Vint::Global::EspSettings::dist_esp) {
			wchar_t buffer[64];
			swprintf(buffer, 64, L"[%.1f M]", distance);
			canvas->K2_DrawText(FVector2D{root_bone_out.X, root_bone_out.Y + 10.0f / distance_modifier}, {1, 1, 1, 1}, FString(buffer), true, false);
		}
	}
}