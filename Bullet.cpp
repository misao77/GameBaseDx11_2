#include "Bullet.h"
#include "Engine//Model.h"
#include "Engine//Input.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), hModel_(-1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bulletziki.fbx");
	assert(hModel_ >= 0);
	tr_.scale_ = { 0.3f, 0.3f, 0.3f };
}

void Bullet::Update()
{
}

void Bullet::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Bullet::Release()
{
}
