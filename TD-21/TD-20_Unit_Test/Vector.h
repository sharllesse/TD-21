#pragma once
#include <iostream>
#include <math.h>

template<class V>
class Vector2
{
public:
	Vector2() : x(static_cast<V>(0.)), y(static_cast<V>(0.)) {}
	Vector2(V _x, V _y) : x(_x), y(_y) {}
	~Vector2() {}

	V x;
	V y;

	template<typename T>
	Vector2<V> operator+(const Vector2<T> v)
	{
		return Vector2<V>(x + static_cast<V>(v.x), y + static_cast<V>(v.y));
	}

	template<typename T>
	Vector2<V> operator-(const Vector2<T> v)
	{
		return Vector2<V>(x - static_cast<V>(v.x), y - static_cast<V>(v.y));
	}

	Vector2<V> operator*(const float f)
	{
		return Vector2<V>(x * f, y * f);
	}

	Vector2<V> operator/(const float f)
	{
		if (f == 0)
			throw std::logic_error("The vector can't be divided by 0");

		return Vector2<V>(x / f, y / f);
	}

	template<typename T>
	bool operator==(const Vector2<T> v)
	{
		if (v.x == x && v.y == y)
			return true;

		return false;
	}

	template<typename T>
	bool operator!=(const Vector2<T> v)
	{
		if (v.x == x && v.y == y)
			return false;

		return true;
	}

	template<typename T>
	void lerp(Vector2<T> g, float t)
	{
		x = (1 - t) * x + t * g.x;
		y = (1 - t) * y + t * g.y;
	}

	template<typename T>
	inline float dotProduct(Vector2<T> v)
	{
		return x * v.x + y * v.y;
	}

	inline float getNorme()
	{
		return std::sqrt((this->x * this->x) + (this->y * this->y));
	}

	template<typename T>
	inline float getDistance(Vector2<T> v)
	{
		return std::sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y));
	}

	template<typename T>
	inline float getAngle(Vector2<T> v)
	{
		return acos(dotProduct(v) / (getNorme() * v.getNorme())) * (180.f / 3.14159265359f);
	}

	inline void normalize()
	{
		*this = *this / getNorme();
	}
};

template<class V>
class Vector3
{
public:
	Vector3() : x(static_cast<V>(0.)), y(static_cast<V>(0.)), z(static_cast<V>(0.)) {}
	Vector3(V _x, V _y, V _z) : x(_x), y(_y), z(_z) {}
	~Vector3() {}

	V x;
	V y;
	V z;

	template<typename T>
	Vector3<V> operator+(const Vector3<T> v)
	{
		return Vector3<V>(this->x + static_cast<V>(v.x), this->y + static_cast<V>(v.y), z + static_cast<V>(v.z));
	}

	template<typename T>
	Vector3<V> operator-(const Vector3<T> v)
	{
		return Vector3<V>(this->x - static_cast<V>(v.x), this->y - static_cast<V>(v.y), z - static_cast<V>(v.z));
	}

	Vector3<V> operator*(const float f)
	{
		return Vector3<V>(this->x * f, this->y * f, z * f);
	}

	Vector3<V> operator/(const float f)
	{
		if (f == 0)
			throw std::logic_error("The vector can't be divided by 0");

		return Vector3<V>(this->x / f, this->y / f, z / f);
	}

	template<typename T>
	bool operator==(const Vector3<T> v)
	{
		if (v.x == x && v.y == y && v.z == z)
			return true;

		return false;
	}

	template<typename T>
	bool operator!=(const Vector3<T> v)
	{
		if (v.x == x && v.y == y && v.z == z)
			return false;

		return true;
	}

	template<typename T>
	void lerp(Vector3<T> g, float t)
	{
		x = (1 - t) * x + t * g.x;
		y = (1 - t) * y + t * g.y;
		z = (1 - t) * z + t * g.z;
	}

	template<typename T>
	inline float dotProduct(Vector3<T> v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	inline float getNorme()
	{
		return std::sqrt((x * x) + (y * y) + (z * z));
	}

	template<typename T>
	inline float getDistance(Vector3<T> v)
	{
		return std::sqrt((v.x - x) * (v.x - x) + (v.y - y) * (v.y - y) + (v.z - z) * (v.z - z));
	}

	template<typename T>
	inline float getSignedAngleBetween(Vector3<T> v)
	{
		return acos(dotProduct(v) / std::sqrt((v.x * v.x + v.y * v.y + v.z * v.z) * (x * x + y * y + z * z)));
	}

	template<typename T>
	inline float getAngle(Vector3<T> v)
	{
		return acos(dotProduct(v) / (getNorme() * v.getNorme())) * (180.f / 3.14159265359f);
	}

	void normalize()
	{
		*this = *this / getNorme();
	}
};