#include "PlayScene.h"
#include "Engine//Model.h"
#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Engine//SceneManager.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene"),hModel_(-1)//メンバーの設定はこっちで
{
}

void PlayScene::Initialize()//その他はここで
{
	/*hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);*/
	Instantiate<Player>(this);//Playerのインスタンス＝プレイヤーオブジェクトを作る
	//Instantiate<Bullet>(this);//弾のインスタンス＝プレイヤーオブジェクトを作る
	Instantiate<Enemy>(this);
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
