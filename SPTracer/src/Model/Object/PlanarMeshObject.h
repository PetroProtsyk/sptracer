#ifndef SPT_PLANAR_MESH_OBJECT_H
#define SPT_PLANAR_MESH_OBJECT_H

#include <memory>
#include <vector>
#include "../../Vec3.h"
#include "../Vertex.h"
#include "Object.h"

namespace SPTracer
{
	class Material;

	class PlanarMeshObject : public Object
	{
	public:
		PlanarMeshObject(
			std::string name,
			std::shared_ptr<Material> material, 
			std::vector<std::shared_ptr<Vertex>> outline,
			std::vector<std::vector<std::shared_ptr<Vertex>>> holes);

		bool Intersect(const Ray& ray, Intersection& intersection) const override;

	private:
		std::vector<std::shared_ptr<Vertex>> outline_;
		std::vector<std::vector<std::shared_ptr<Vertex>>> holes_;
		
		std::vector<Vec3> outlineNormals_;
		std::vector<std::vector<Vec3>> holesNormals_;
	};

}

#endif
