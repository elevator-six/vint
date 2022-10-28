#pragma once

namespace Walls {
	void Render(APlayerController* controller, UMeshComponent* mesh, FVector relative_location, FVector camera_location, float health, float shield) {
		FVector head_bone_out;
		FVector head_bone = mesh->GetEntityBone(8);
		controller->ProjectWorldLocationToScreen(head_bone, &head_bone_out);

		FVector root_bone_out;
		FVector root_bone = mesh->GetEntityBone(0);
		controller->ProjectWorldLocationToScreen(root_bone, &root_bone_out);

		FVector relative_location_out;
		controller->ProjectWorldLocationToScreen(relative_location, &relative_location_out);

		float box_height = abs(head_bone_out.Y - root_bone_out.Y);
		float box_width = box_height * 0.40;

		float distance = camera_location.Distance(relative_location) / 100.f;
		float distanceModifier = camera_location.Distance(head_bone) * 0.001F;

		FVector relative_position = relative_location - camera_location;
		float relative_distance = relative_position.Length() / 10000 * 2;

		if (Vint::Global::EspSettings::box_esp)
			CornerBox(relative_location_out, box_width, box_height, { 0.988f, 0.988f, 0, 1 });

		if (Vint::Global::EspSettings::health_esp) {
			DrawHealthBar(relative_location_out, box_width, box_height, health, relative_distance);
			DrawShieldBar(relative_location_out, box_width, box_height, shield, relative_distance);
		}

		if (Vint::Global::EspSettings::dist_esp) {
			wchar_t buffer[64];
			swprintf(buffer, 64, L"[%.2f M]", distance);
			canvas->K2_DrawText(FVector2D{root_bone_out.X, root_bone_out.Y - 20.0f}, {1, 1, 1, 1}, FString(buffer), true, true);
		}
	}
}