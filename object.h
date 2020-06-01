#ifndef OBJECT_H
#define OBJECT_H
// An object that has interactions with others in the physics engine

template <typename T> struct vect { // 2d vector, temporary
	T x, y;
	vect(T xy) : x(xy), y(xy) {}
	vect(T xi, T yi) : x(xi), y(yi) {}
	vect(const vect<T> &v) : x(v.x), y(v.y) {}
	
	bool operator==(const vect<T> &v) const {
		return (x == v.x && y == v.y);
	}
	
	bool operator!=(const vect<T> &v) const {
		return !(*this == v);
	}
	
	bool operator<(const vect<T> &v) const {
		return x * x + y * y < v.x * v.x + v.y * v.y;
	}
	
	bool operator>(const vect<T> &v) const {
		return x * x + y * y > v.x * v.x + v.y * v.y;
	}
	
	bool operator>=(const vect<T> &v) const {
		return x * x + y * y >= v.x * v.x + v.y * v.y;
	}
	
	bool operator<=(const vect<T> &v) const {
		return x * x + y * y <= v.x * v.x + v.y * v.y;
	}
	
	T operator[](int i) const {
		return i == 0 ? x : y;
	}
	
	T & operator[](int i) {
		return i == 0 ? x : y;
	}
	
	vect<T> operator+(const vect<T> &v) const {
		return vect<T>(x + v.x, y + v.y);
	}
	
	vect<T> operator-(const vect<T> &v) const {
		return vect<T>(x - v.x, y - v.y)
	}
	
	vect<T> operator*(const vect<T> &v) const {
		return vect<T>(x * v.x, y * v.y)
	}
	
	vect<T> operator/(const vect<T> &v) const {
		return vect<T>(x / v.x, y / v.y)
	}
	
	vect<T> operator+(const T c) const {
		return vect<T>(x + c, y + c);
	}
	
	vect<T> operator-(const T c) const {
		return vect<T>(x - c, y - c)
	}
	
	vect<T> operator*(const T c) const {
		return vect<T>(x * c, y * c)
	}
	
	vect<T> operator/(const T c) const {
		return vect<T>(x / c, y / c)
	}
	
	vect<T> operator-() const {
		return vect<T>(-x, -y);
	}
	
	vect<T> operator+() const {
		return *this;
	}
	
	vect<T> operator+=(const vect<T> &v) {
		x += v.x; y += v.y;
		return *this;
	}
	
	vect<T> operator-=(const vect<T> &v) {
		x -= v.x; y -= v.y;
		return *this;
	}
	
	vect<T> operator*=(const vect<T> &v) {
		x *= v.x; y *= v.y;
		return *this;
	}
	
	vect<T> operator/=(const vect<T> &v) {
		x /= v.x; y /= v.y;
		return *this;
	}
	
	vect<T> operator+=(const T c) {
		x += c; y += c;
		return *this;
	}
	
	vect<T> operator-=(const T c) {
		x -= c; y -= c;
		return *this;
	}
	
	vect<T> operator*=(const T c) {
		x *= c; y *= c;
		return *this;
	}
	
	vect<T> operator/=(const T c) {
		x /= c; y /= c;
		return *this;
	}
	
	operator bool() {
		return x || y;
	}
	
	// other conversion operators / generic conversion w/ template
	// ++/-- operators
	
	// need a method to reduce/increase speed.
	// a +/- that takes the current parody into consideration
} vect;

typedef enum e_collisionBehavior {
	ELASTIC,
	INELASTIC,
	P_ELASTIC,
	P_INELASTIC
}; // Idk how we want to define different collision behaviors

class Object
{
  bool mobile;
  double mass;
  e_collisionBehavior hitType = ELASTIC;
  vect<int> position = vect(0,0); // center/corner/whatever
  vect<int> velocity = vect(0,0);
  vect<int> acceleration = vect(0,-9);
  // we need LWH/radius or whatever to declare area
};

#endif
