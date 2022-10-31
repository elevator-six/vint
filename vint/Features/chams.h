#pragma once

namespace Chams {
	void Activate(UMeshComponent* mesh) {
		mesh->SetAresOutlineMode(EAresOutlineMode::AlwaysOutline, true);
		AresOutlineRendering::SetOutlineColorsForRender(world, Vint::Global::ChamsSettings::chams_color, {1, 1, 1, 1});
	}
}