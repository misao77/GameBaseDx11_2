#include "PlayScene.h"
#include "Engine/\\Model.h"
#include "Player.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)//メンバーの設定はこっちで
{
}

void PlayScene::Initialize()//その他はここで
{
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
}

void PlayScene::Update()
{
	static float time = 0.0f
		;
	ot_.position_ = { 0.0f, 0.0f, 10.0f };//位置
	ot_.scale_ = { 0.5f, 0.5f, 0.5f };
	ot_.rotate_.y += 0.1f;//回転
	time += 0.025f;
	ot_.position_.x = 6.0f * sin(time);
	ot_.position_.y = 6.0f * sin(time);
	//float posx = 6.0 * sin(time) * 0.5;
	//ot_.position_.x = posx;
}

void PlayScene::Draw()
{
	Model::SetTransform(hModel_, ot_);
	Model::Draw(hModel_);
}

void PlayScene::Release()
{
}
