#pragma once
#include <list>
#include <string>
#include <locale>
#include <d3d9types.h>

#define M_PI       3.14159265358979323846   // pi

namespace Engine {
	const wchar_t* uworld_names[] = {
		L"/Game/Maps/Init/Init.Init",
		L"/Game/Maps/Menu/MainMenuV2.MainMenuV2",
		L"/Game/Maps/PregameV2/CharacterSelectPersistentLevel.CharacterSelectPersistentLevel",
		L"/Game/Maps/Poveglia/Range.Range",
		L"/Game/Maps/Ascent/Ascent.Ascent",
		L"/Game/Maps/Canyon/Canyon.Canyon",
		L"/Game/Maps/Bonsai/Bonsai.Bonsai",
		L"/Game/Maps/Duality/Duality.Duality",
		L"/Game/Maps/Foxtrot/Foxtrot.Foxtrot",
		L"/Game/Maps/Port/Port.Port",
		L"/Game/Maps/Triad/Triad.Triad",
	};

	template<class T>
	struct TArray
	{
		friend struct FString;

	public:
		inline TArray()
		{
			Data = nullptr;
			Count = Max = 0;
		};

		inline int Num() const
		{
			return Count;
		};

		inline T& operator[](int i)
		{
			return Data[i];
		};

		inline const T& operator[](int i) const
		{
			return Data[i];
		};

		inline bool IsValidIndex(int i) const
		{
			return i < Num();
		}

		T* Data;
		int32_t Count;
		int32_t Max;
	};

	struct FString : TArray<wchar_t>
	{
		inline FString()
		{
		};

		FString(const wchar_t* other)
		{
			Max = Count = *other ? wcslen(other) + 1 : 0;

			if (Count)
			{
				Data = const_cast<wchar_t*>(other);
			}
		};

		inline bool IsValid() const
		{
			return Data != nullptr;
		}

		inline const wchar_t* c_str() const
		{
			return Data;
		}
		std::string ToString() const
		{
			auto length = std::wcslen(Data);

			std::string str(length, '\0');

			std::use_facet<std::ctype<wchar_t>>(std::locale()).narrow(Data, Data + length, '?', &str[0]);

			return str;
		}
	};

	class FVector {
	public:
		FVector() : X(0.f), Y(0.f), Z(0.f)
		{

		}

		FVector(float _X, float _Y, float _Z) : X(_X), Y(_Y), Z(_Z)
		{

		}
		~FVector()
		{

		}

		float X;
		float Y;
		float Z;

		float Dot(FVector v) {
			return X * v.X + Y * v.Y + Z * v.Z;
		}
		inline float Dot(const FVector& b) const { return (X * b.X) + (Y * b.Y) + (Z * b.Z); }

		float Distance(FVector v) {
			return float(sqrtf(powf(v.X - X, 2.0) + powf(v.Y - Y, 2.0) + powf(v.Z - Z, 2.0)));
		}

		float Length() {
			return sqrt(X * X + Y * Y + Z * Z);
		}

		float Length2D() {
			return sqrtf((X * X) + (Y * Y));
		}

		void make_absolute() {
			X = std::abs(X);
			Y = std::abs(Y);
			Z = std::abs(Z);
		}

		FVector Clamp()
		{
			FVector clamped = { X, Y, 0 };
			while (clamped.Y < -180.0f)
				clamped.Y += 360.0f;
			while (clamped.Y > 180.0f)
				clamped.Y -= 360.0f;
			while (clamped.X < -180.0f)
				clamped.X += 360.0f;
			while (clamped.X > 180.0f)
				clamped.X -= 360.0f;
			return clamped;
		}
		FVector ToRotator()
		{
			FVector rotator;
			rotator.X = -(float)atan(Z / Length2D()) * (float)(180.0f / 3.14159265358979323846);
			rotator.Y = (float)atan(Y / X) * (float)(180.0f / 3.14159265358979323846);
			rotator.Z = (float)0.f;
			if (X >= 0.f)
				rotator.Y += 180.0f;
			return rotator;
		}

		inline float MagnitudeSqr() const { return Dot(*this); }
		inline float Magnitude() const { return std::sqrtf(MagnitudeSqr()); }

		bool operator==(FVector v) {
			return ((X == v.X) && (Y == v.Y) && (Z == v.Z));
		}

		FVector& operator-=(const FVector& v) {
			X -= v.X; Y -= v.Y; Z -= v.Z; return *this;
		}

		FVector& operator+=(const FVector& v) {
			Y += v.Y; Y += v.Y; Z += v.Z; return *this;
		}

		FVector operator/(float v) const {
			return FVector(X / v, Y / v, Z / v);
		}

		FVector operator+(FVector v) const {
			return FVector(X + v.X, Y + v.Y, Z + v.Z);
		}

		FVector operator+(FVector v) {
			return FVector(X + v.X, Y + v.Y, Z + v.Z);
		}

		FVector operator-(FVector v) {
			return FVector(X - v.X, Y - v.Y, Z - v.Z);
		}

		FVector operator*(float v) {
			return FVector(X * v, Y * v, Z * v);
		}

		FVector operator*(float v) const {
			return FVector(X * v, Y * v, Z * v);
		}

		FVector operator/(float v) {
			return FVector(X / v, Y / v, Z / v);
		}
	};

	struct FQuat
	{
		float x;
		float y;
		float z;
		float w;
	};

	struct FTransform
	{
		FQuat rot;
		FVector translation;
		char pad[4];
		FVector scale;
		char pad1[4];

		D3DMATRIX ToMatrixWithScale()
		{
			D3DMATRIX m;
			m._41 = translation.X;
			m._42 = translation.Y;
			m._43 = translation.Z;

			float x2 = rot.x + rot.x;
			float y2 = rot.y + rot.y;
			float z2 = rot.z + rot.z;

			float xx2 = rot.x * x2;
			float yy2 = rot.y * y2;
			float zz2 = rot.z * z2;
			m._11 = (1.0f - (yy2 + zz2)) * scale.X;
			m._22 = (1.0f - (xx2 + zz2)) * scale.Y;
			m._33 = (1.0f - (xx2 + yy2)) * scale.Z;

			float yz2 = rot.y * z2;
			float wx2 = rot.w * x2;
			m._32 = (yz2 - wx2) * scale.Z;
			m._23 = (yz2 + wx2) * scale.Y;

			float xy2 = rot.x * y2;
			float wz2 = rot.w * z2;
			m._21 = (xy2 - wz2) * scale.Y;
			m._12 = (xy2 + wz2) * scale.X;

			float xz2 = rot.x * z2;
			float wy2 = rot.w * y2;
			m._31 = (xz2 + wy2) * scale.Z;
			m._13 = (xz2 - wy2) * scale.X;

			m._14 = 0.0f;
			m._24 = 0.0f;
			m._34 = 0.0f;
			m._44 = 1.0f;

			return m;
		}
	};

	class FPlane : public FVector {
	public:
		FPlane() : w(0.f) {}

	public:
		float w;
	};

	class FMatrix {
	public:
		FMatrix() : x(FPlane()), y(FPlane()), z(FPlane()), w(FPlane()) {}
	public:
		FPlane x;
		FPlane y;
		FPlane z;
		FPlane w;
	};

	struct FLinearColor {
		float R;
		float G;
		float B;
		float A;
	};

	struct FVector2D {
		float X;
		float Y;
	};

	struct FRotator {
		float Pitch;
		float Yaw;
		float Roll;

		FVector ToVector()
		{
			float angle, sr, sp, sy, cr, cp, cy;

			angle = this->Yaw * (M_PI * 2 / 360);
			sy = sin(angle);
			cy = cos(angle);

			angle = this->Pitch * (M_PI * 2 / 360);
			sp = sin(angle);
			cp = cos(angle);

			angle = this->Roll * (M_PI * 2 / 360);
			sr = sin(angle);
			cr = cos(angle);

			return FVector(cp * cy, cp * sy, -sp);
		}
	};

	struct FMinimalViewInfo {
		FVector Location;
		FRotator Rotation;
		float FOV;
	};

	enum class EAresOutlineMode : uint8_t {
		None = 0,
		Outline = 1,
		Block = 2,
		Enemy = 3,
		AlwaysOutline = 4,
		AlwaysEnemy = 5,
		EAresOutlineMode_MAX = 6
	};
	enum class EAresAlliance : uint8_t {
		Alliance_Ally = 0,
		Alliance_Enemy = 1,
		Alliance_Neutral = 2,
		Alliance_Any = 3,
		Alliance_Count = 4,
		Alliance_MAX = 5
	};
	enum class ESearchCase : uint8 {
		CaseSensitive = 0,
		IgnoreCase = 1,
		ESearchCase_MAX = 2
	};
}