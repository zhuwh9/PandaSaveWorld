#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

using namespace std;

#define min(x,y) ((x) < (y) ? (x) : (y))
#define max(x,y) ((x) < (y) ? (y) : (x))

#define PandaHeight 7.5f           // ����ӵ㵽�ŵĸ߶�
#define GravityAcceleration -9.8f
#define MoveSpeed 0.15f            // ����ƶ��ٶ�
#define BoundaryGap 1.0f           // ��ײ���
#define JumpInitialSpeed 12.0f     // �������ٶ�
#define JumpFactor 0.04f           // �����ٶ�ϵ��
#define GravityFactor 0.04f        // �����ٶ�ϵ��

class PhysicsEngine {

public:
	PhysicsEngine();
	~PhysicsEngine();

	// ���ÿռ��ⲿ��Ե
	void setSceneOuterBoundary(glm::vec2 leftBackPoint, glm::vec2 rightFrontPoint);


	// ���ÿռ��ڲ���Ե
	void setSceneInnerBoundary(glm::vec3 leftBackDownPoint, glm::vec3 rightFrontUpPoint);


	// �ⲿ��ײ���
	void checkOutsideCollision(glm::vec3 & cameraPos, glm::vec3 & targetPos);


	// �ڲ���ײ���
	void checkInsideCollision(glm::vec3 & cameraPos, glm::vec3 & targetPos);


	// �Ƿ�����Ծ
	bool isJumping;


	void jumpAndUpdateVelocity();    //����space��Ծʱ����
									 //ÿ֡���Ƶ�ʱ������������ֱ�����ƶ�


	void updateItemMovement(glm::vec3 & cameraPos, glm::vec3 & targetPos);

	// Ӧ������
	void applyGravity(bool flag);

private:
	// �ռ��ⲿ��Ե��ײ���
	void checkOutsideCollisionXZ(glm::vec3 & cameraPos, glm::vec3 & targetPos);


	// �ռ��ڲ���Ե��ײ��⣨����XYZ��
	void checkInsideCollisionXYZ(glm::vec3 innerBoundaryMin, glm::vec3 innerBoundaryMax, glm::vec3 & cameraPos, glm::vec3 & targetPos);


	// �ռ��ڲ���Ե��ײ��⣨����XZ��
	void checkInsideCollisionXZ(glm::vec3 innerBoundaryMin, glm::vec3 innerBoundaryMax, glm::vec3 & cameraPos, glm::vec3 & targetPos);


	glm::vec3 velocity;        // ��ֱ�����ٶ�
	glm::vec3 gravity;         // �������ٶ�
	glm::vec3 accelerationUp;  // �������ϵļ��ٶ�

	glm::vec2 outerBoundaryMin;          // ����С��xz����
	glm::vec2 outerBoundaryMax;		     // �������xz����
	vector<glm::vec3> innerBoundaryMin;  // ��ײ��С��x/y/z����
	vector<glm::vec3> innerBoundaryMax;  // ��ײ�����x/y/z����
};

#endif // !PHYSICSENGINE_H