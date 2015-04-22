#include <cmath>
#include "Object.h"

namespace SPTracer
{

	const double Object::Eps = 1e-10;

	Object::Object(std::string name, std::shared_ptr<Material> material)
		: name_(std::move(name)), material_(std::move(material))
	{
	}

	Object::~Object()
	{
	}

	Vec3 Object::ComputeNormal(const Vec3& v1, const Vec3& v2, const Vec3& v3)
	{
		// get two vectors
		Vec3 a = v2 - v1;
		Vec3 b = v3 - v1;

		// compute normal vector (using cross product)
		Vec3 normal = Vec3::CrossProduct(a, b);

		// normalize normal vector
		normal.Normalize();

		return normal;
	}

	bool Object::IntersectWithTriangle(const Ray& ray, const Vec3& v1, const Vec3& v2, const Vec3& v3, const Vec3& n, double d, Intersection& intersection)
	{
		double b = (n.x * ray.direction.x) + (n.y * ray.direction.y) + (n.y * ray.direction.y);
		if (std::abs(b) < Eps)
		{
			// line is parallel to plane
			return false;
		}

		double a = d - (n.x * ray.origin.x) - (n.y * ray.origin.y) - (n.z * ray.origin.z);
		double& t = intersection.distance;
		t = a / b;

		if (t < 0)
		{
			// ray points in direction oposite from plane
			return false;
		}

		// intersection point
		Vec3& p = intersection.point;
		p = ray.origin + ray.direction * t;

		// compute areas
		double area = Vec3::CrossProduct(v2 - v1, v3- v1).EuclideanNorm() / 2.0;
		double a1 = Vec3::CrossProduct(v1 - p, v2 - p).EuclideanNorm() / 2.0;
		double a2 = Vec3::CrossProduct(v2 - p, v3 - p).EuclideanNorm() / 2.0;
		double a3 = Vec3::CrossProduct(v3 - p, v1 - p).EuclideanNorm() / 2.0;

		if ((a1 + a2 + a3) > area)
		{
			// point is outside of triangle
			return false;
		}

		return true;
	}

}
