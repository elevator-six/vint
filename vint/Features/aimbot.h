#pragma once

//if (IFH(GetAsyncKeyState)(VK_XBUTTON2) < 0) {
//	controller->AddPitchInput(Smoothed.X);
//	controller->AddYawInput(Smoothed.Y);
//}

namespace Aimbot {
	int Width = GetSystemMetrics(SM_CXSCREEN);
	int Height = GetSystemMetrics(SM_CYSCREEN);
	float ScreenCenterX;
	float ScreenCenterY;

	namespace defines
	{
		AActor* closest_actor = nullptr;
		float closest_distance = FLT_MAX;
		float distance;
	}

	namespace math
	{
		FRotator interpolate(const float speed, const FRotator& current, const FRotator& target, float delta_time)
		{
			return KismetMathLibrary::RInterpTo(current, target, delta_time, speed);
		}
	}

	void Tick(APlayerController* controller, AActor* current_actor) {

		if (current_actor->GetPawnMesh() == nullptr) return;

		ACameraManager* camera = controller->GetPlayerCameraManager();
		if (camera == nullptr) return;

		UMeshComponent* mesh = current_actor->GetPawnMesh();
		if (mesh == nullptr) return;

		if (!canvas->project(mesh->GetBone(0)).Z)
			return;

		/* Still broken. This should work but isn't. */
		FVector head_bone_out;
		FVector head_bone = mesh->GetBone(8);
		controller->ProjectWorldLocationToScreen(head_bone, &head_bone_out);

		auto dx = head_bone_out.X - ((int)1920 / 2);
		auto dy = head_bone_out.Y - ((int)1080 / 2);
		auto dist = sqrtf(dx * dx + dy * dy);

		defines::distance = camera->GetCameraLocation().Distance(head_bone_out);

		if (dist < 45.0 * 8 && defines::distance < defines::closest_distance) {
			defines::closest_distance = defines::distance;
			defines::closest_actor = current_actor;
		}

		if (defines::closest_actor != nullptr) {
			const FRotator& view_rotation_with_full_recoil = defines::closest_actor->GetViewRotationFullRecoil();
			const FRotator& view_rotation_with_no_recoil = defines::closest_actor->GetViewRotationNoRecoil();

			const auto aim_rotation = KismetMathLibrary::FindLookAtRotation(camera->GetCameraLocation(), defines::closest_actor->GetPawnMesh()->GetBone(8));

			if (IFH(GetAsyncKeyState)(VK_XBUTTON2) && controller->line_of_sight_to(current_actor))
			{
				FRotator rotator = math::interpolate(15.0f, controller->GetControlRotation(), aim_rotation, GameplayStatics::get_world_delta_seconds(controller));

				const FRotator& delta = KismetMathLibrary::NormalizedDeltaRotator(rotator, controller->GetControlRotation());
				auto sensitivity = controller->GetMouseSensitivity();

				controller->AddPitchInput(delta.Pitch / -sensitivity);
				controller->AddYawInput(delta.Yaw / sensitivity);
			}
		}
	}
}