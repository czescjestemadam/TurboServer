#pragma once
#include <cmath>

template<class T>
struct Vec3
{
	T x, y, z;

	Vec3() = default;
	explicit Vec3(T v);
	Vec3(T x, T y, T z);

	Vec3<T> operator+(Vec3<T> v);
	Vec3<T> operator-(Vec3<T> v);
	Vec3<T> operator*(Vec3<T> v);
	Vec3<T> operator/(Vec3<T> v);

	Vec3<T> operator*(T v);

	float distance(Vec3<T> v);
	float distanceSquared(Vec3<T> v);

	template<class R>
	Vec3<R> cast();
};

typedef Vec3<int> Vec3i;
typedef Vec3<float> Vec3f;
typedef Vec3<double> Vec3d;

template<class T>
Vec3<T>::Vec3(T v) : x(v), y(v), z(v)
{
}

template<class T>
Vec3<T>::Vec3(T x, T y, T z) : x(x), y(y), z(z)
{
}


template<class T>
Vec3<T> Vec3<T>::operator+(Vec3<T> v)
{
	return Vec3<T>(x + v.x, y + v.y, z + v.z);
}

template<class T>
Vec3<T> Vec3<T>::operator-(Vec3<T> v)
{
	return Vec3<T>(x - v.x, y - v.y, z - v.z);
}

template<class T>
Vec3<T> Vec3<T>::operator*(Vec3<T> v)
{
	return Vec3<T>(x * v.x, y * v.y, z * v.z);
}

template<class T>
Vec3<T> Vec3<T>::operator/(Vec3<T> v)
{
	return Vec3<T>(x / v.x, y / v.y, z / v.z);
}


template<class T>
Vec3<T> Vec3<T>::operator*(T v)
{
	return Vec3<T>(x * v, y * v, z * v);
}

template<class T>
float Vec3<T>::distance(Vec3<T> v)
{
	return std::sqrt(distanceSquared(v));
}

template<class T>
float Vec3<T>::distanceSquared(Vec3<T> v)
{
	const T dx = x - v.x;
	const T dy = y - v.y;
	const T dz = z - v.z;
	return (dx * dx) + (dy * dy) + (dz * dz);
}

template<class T>
template<class R>
Vec3<R> Vec3<T>::cast()
{
	return Vec3<R>(x, y, z);
}
