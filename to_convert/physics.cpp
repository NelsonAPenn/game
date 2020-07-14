#include "physics.h"

void Physics::resolveCollision(Object A, Object B) {
	if (!A.mobile && !B.mobile) return; // idk
	else if (!A.mobile && B.mobile) {
		return resolveCollision(B,A);
	} else if (!B.mobile && A.mobile) {
		switch (A.hitType) {
			case ELASTIC:
				A.velocity *= -1;
				break;
			default: break;
		}
	} else {
		(this->*colliderMap[A.hitType][B.hitType])(A,B);
	}
	// consider elastic (common) vs inelestic (rare)
	// remember to consider the mass of an object
	// light attack stops enemy momentum, heavy reverses&reduces?
}
