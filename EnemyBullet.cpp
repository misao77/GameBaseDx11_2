#include "EnemyBullet.h"
#include "Engine//Model.h"
#include "Engine//SphereCollider.h"

EnemyBullet::EnemyBullet(GameObject* parent)
	: GameObject(parent, "EnemyBullet"), hModel_(-1), speed_(0.5f)
{
}

EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Initialize()
{
    hModel_ = Model::Load("Bulletteki.fbx");

    transform_.scale_ = { 0.5f, 0.5f, 0.5f };

    // 衝突判定（コライダー）を登録
    SphereCollider* collider = new SphereCollider(XMFLOAT3(0.0f, 0.0f, 0.0f), 0.5f);
    AddCollider(collider);
}

void EnemyBullet::Update()
{
    transform_.position_.z = transform_.position_.z - speed_;

    // 【改造点2】手前に消えていくので、一定の座標（例：-50.0f）より手前に来たら消す
    if (transform_.position_.z < -50.0f)
    {
        KillMe(); // 自分を削除する
    }
}

void EnemyBullet::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);
}

void EnemyBullet::Release()
{
}
