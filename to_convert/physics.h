#ifndef PHYSICS_H
#define PHYSICS_H
// Physics handles physics and collisions between objects, works with the frame manager and timing system
// I'm assuming detecting collisions is done by another system
#include "object.h"
#include <map>

typedef struct s_hitFcns {
	// Collision Behavior Functions
	void elasticHitInelastic(Object, Object);
	void inelasticHitElastic(Object, Object);
	void elasticHitElastic(Object, Object);
	void inelasticHitInelastic(Object, Object);
} s_hitFcns;

typedef void (s_hitFcns::*pHitFcn)(Object, Object);
typedef std::map<e_collisionBehavior, pHitFcn> m_behaviorToFcn;
typedef std::map<e_collisionBehavior, m_behaviorToFcn> m_behaviorToMap;

class Physics : public s_hitFcns {
public:
	Physics();
	~Physics();
	void resolveCollision(Object, Object);
	
private:
	// colliderMap usage: (this->*colliderMap[ELASTIC][ELASTIC])(A,B);
	struct colliderMap : public m_behaviorToMap {
		colliderMap() {
			this->operator[](ELASTIC) = elasticMap;
			this->operator[](INELASTIC) = inelasticMap;
			this->operator[](P_ELASTIC) = elasticMap;
			this->operator[](P_INELASTIC) = inelasticMap;
		}
		
		struct elasticMap : public m_behaviorToFcn {
			elasticMap() {
				this->operator[](ELASTIC) = &s_hitFcns::elasticHitElastic;
				this->operator[](INELASTIC) = &s_hitFcns::elasticHitInelastic;
				this->operator[](P_ELASTIC) = &s_hitFcns::elasticHitElastic;
				this->operator[](P_INELASTIC) = &s_hitFcns::elasticHitInelastic;
			}
		} elasticMap;
		
		struct inelasticMap : public m_behaviorToFcn {
			inelasticMap() {
				this->operator[](ELASTIC) = &s_hitFcns::inelasticHitElastic;
				this->operator[](INELASTIC) = &s_hitFcns::inelasticHitInelastic;
				this->operator[](P_ELASTIC) = &s_hitFcns::inelasticHitElastic;
				this->operator[](P_INELASTIC) = &s_hitFcns::inelasticHitInelastic;
			}
		} inelasticMap;
	} colliderMap;

};

#endif
