#include "Player.h"
#include "Engine//Model.h"
#include "Engine//Input.h"
#include "Bullet.h"

Player::Player(GameObject* parent)//親のポインタ、オブジェクトの名前
	:GameObject(parent, "Player"), hModel_(-1)
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("spaceShip.fbx");
	assert(hModel_ >= 0);
	transform_.position_ = { 0.0f, -1.0f, 0.0f };
	transform_.rotate_.y = 180.0f;
}

void Player::Update()
{
	if (Input::IsKey(DIK_A))
	{
		transform_.position_.x -= 0.1f;
	}
	if (Input::IsKey(DIK_D))
	{
		transform_.position_.x += 0.1f;
	}
	if (Input::IsKey(DIK_W))
	{
		transform_.position_.y += 0.1f;
	}
	if (Input::IsKey(DIK_S))
	{
		transform_.position_.y -= 0.1f;
	}
	if (Input::IsKeyDown(DIK_SPACE))
	{
		Bullet *pBullet = Instantiate<Bullet>(this->GetParent());
		pBullet->SetPosition(transform_.position_);
	}

	if (Input::IsKeyDown(DIK_R))
	{
		// 左
		Bullet* bullet1 = Instantiate<Bullet>(this->GetParent());
		bullet1->SetPosition(transform_.position_);
		bullet1->SetDirection(XMFLOAT3(-0.3f, 0.0f, 1.0f));

		// 真ん中
		Bullet* bullet2 = Instantiate<Bullet>(this->GetParent());
		bullet2->SetPosition(transform_.position_);
		bullet2->SetDirection(XMFLOAT3(0.0f, 0.0f, 1.0f));

		// 右
		Bullet* bullet3 = Instantiate<Bullet>(this->GetParent());
		bullet3->SetPosition(transform_.position_);
		bullet3->SetDirection(XMFLOAT3(0.3f, 0.0f, 1.0f));
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
