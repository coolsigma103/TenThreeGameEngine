#pragma once

struct vector1
{
    float x;

    vector1() : x(0.0f) {}
    vector1(float x) : x(x) {}

    vector1 operator+(const vector1& other) const {
        return vector1(x + other.x);
    }

    vector1 operator-(const vector1& other) const {
        return vector1(x - other.x);
    }

    vector1 operator*(float scalar) const {
        return vector1(x * scalar);
    }

    vector1 operator/(float scalar) const {
        return vector1(x / scalar);
    }
};

struct vector2
{
    float x, y;

    vector2() : x(0.0f), y(0.0f) {}
    vector2(float x, float y) : x(x), y(y) {}

    vector2 operator+(const vector2& other) const {
        return vector2(x + other.x, y + other.y);
    }

    vector2 operator-(const vector2& other) const {
        return vector2(x - other.x, y - other.y);
    }

    vector2 operator*(float scalar) const {
        return vector2(x * scalar, y * scalar);
    }

    vector2 operator/(float scalar) const {
        return vector2(x / scalar, y / scalar);
    }
};

struct vector3
{
    float x, y, z;

    vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    vector3 operator+(const vector3& other) const {
        return vector3(x + other.x, y + other.y, z + other.z);
    }

    vector3 operator-(const vector3& other) const {
        return vector3(x - other.x, y - other.y, z - other.z);
    }

    vector3 operator*(float scalar) const {
        return vector3(x * scalar, y * scalar, z * scalar);
    }

    vector3 operator/(float scalar) const {
        return vector3(x / scalar, y / scalar, z / scalar);
    }
};

struct vector4
{
    float x, y, z, w;

    vector4() : x(0.0f), y(0.0f), z(0.0f), w(1.0f) {}
    vector4(float x, float y, float z, float w = 1.0f) : x(x), y(y), z(z), w(w) {}

    vector4 operator+(const vector4& other) const {
        return vector4(x + other.x, y + other.y, z + other.z, w + other.w);
    }

    vector4 operator-(const vector4& other) const {
        return vector4(x - other.x, y - other.y, z - other.z, w - other.w);
    }

    vector4 operator*(float scalar) const {
        return vector4(x * scalar, y * scalar, z * scalar, w * scalar);
    }

    vector4 operator/(float scalar) const {
        return vector4(x / scalar, y / scalar, z / scalar, w / scalar);
    }
};