#include "ClearScene.h"
#include "Engine//Image.h"
#include "Engine//SceneManager.h"


ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hClearPic_(-1),timer_(0.0f)
{
}

ClearScene::~ClearScene()
{
}

void ClearScene::Initialize()
{
	hClearPic_ = Image::Load("Clear3.jpg");
	assert(hClearPic_ >= 0);
}

void ClearScene::Update()
{
	timer_ += 0.025f;

	if (timer_ >= 3.0f)
	{
		SceneManager* pSceneManager =
			(SceneManager*)(this->GetParent());

		pSceneManager->ChangeScene(SCENE_ID_TEST);
	}
}

void ClearScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void ClearScene::Release()
{
}
