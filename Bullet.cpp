#include "Bullet.h"
#include "Engine//Model.h"
#include "Engine//Input.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Bullet::Initialize()
{
	hModel_ = Model::Load("Bulletziki.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { 0.0f, -4.0f, 0.0f };
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
