#include "PlayScene.h"
#include "Engine//Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Engine//SceneManager.h"
#include "Engine//Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)//メンバーの設定はこっちで
{
}

void PlayScene::Initialize()//その他はここで
{
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	//Instantiate<Bullet>(this);//弾のインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
	//Camera::SetPosition(XMFLOAT3(0.0f, 30.0f, 0.0f));
	//Camera::SetTarget(XMFLOAT3(0.0f, 0.0f, 0.0f));
}

void PlayScene::Update()
{
	if (FindObject("Enemy") == nullptr)
	{
		SceneManager* pSceneManager = (SceneManager*)(this->GetParent());
		pSceneManager->ChangeScene(SCENE_ID_CLEAR);
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
