#include "Player.h"
#include "Engine//Model.h"
#include "Engine//Input.h"

Player::Player(GameObject* parent)//親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("spaceShip.fbx");
	assert(hModel_ >= 0);
	tr_.position_ = { 0.0f, -4.0f, 0.0f };
}

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT) || Input::IsKey(DIK_A))
	{
		tr_.position_.x = 1.0f;
	}
	if (Input::IsKey(DIK_RIGHT) || Input::IsKey(DIK_D))
	{
		tr_.position_.x = -1.0f;
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, tr_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
