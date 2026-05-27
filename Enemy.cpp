#include "Enemy.h"
#include "Engine//Model.h"
#include "Engine//Input.h"
#include "Engine//SphereCollider.h"
#include "Bullet.h"
#include "EnemyBullet.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent, "Enemy"), hModel_(-1)
{
}

Enemy::~Enemy()
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("syati.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, 0.0f, 20.0f };
	transform_.scale_ = { 1.0f, 1.0f, 1.0f };
	transform_.rotate_ = { 0.0f, 0.0f, 0.0f };

	SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 1.0f);
	AddCollider(collider);
	new EnemyBullet(this);
}

void Enemy::Update()
{
	static float time = 0.0f;
	transform_.scale_ = { 1.0f, 1.0f, 1.0f };
	//transform_.rotate_.y += 0.1f;//回転
	time += 0.025f;
	transform_.position_.x = 6.0f * sin(time);
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{

}

void Enemy::OnCollision(GameObject* pTarget)
{
	if (pTarget->GetObjectName() == "Bullet")
	{
		pTarget->KillMe();//バレットを消して
		KillMe();//自分も消す
	}
}

void Enemy::SetPosition(XMFLOAT3 pos)
{
	transform_.position_ = pos;
}
