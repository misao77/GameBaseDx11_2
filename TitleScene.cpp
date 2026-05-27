#include "TitleScene.h"
#include "Engine//Input.h"
#include "Engine//SceneManager.h"
#include "Engine//Image.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent, "TitleScene"), hClearPic_(-1)
{
}

void TitleScene::Initialize()
{
	hClearPic_ = Image::Load("Title.png");
	assert(hClearPic_ >= 0);
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_RETURN))
	{
		SceneManager::ChangeScene("GameScene");
	}
}

void TitleScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void TitleScene::Release()
{
}
