#ifndef SPT_CIE1931_H
#define SPT_CIE1931_H

#include "../stdafx.h"
#include "XYZConverter.h"

namespace SPTracer
{

	class Vec3;

	class CIE1931 : public XYZConverter
	{
	public:
		Vec3 GetXYZ(float waveLength) const override;
		float GetWaveLengthMin() const override;
		float GetWaveLengthMax() const override;
		float GetWaveLengthStep() const override;

	private:
		static const float waveLengthMin_;
		static const float waveLengthMax_;
		static const float waveLengthStep_;
		static const std::vector<Vec3> colorMap_;
	};

}

#endif