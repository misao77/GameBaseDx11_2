#include "ClearScene.h"
#include "Engine//Image.h"


ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent, "ClearScene"), hClearPic_(-1)
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
}

void ClearScene::Draw()
{
	Image::SetTransform(hClearPic_, transform_);
	Image::Draw(hClearPic_);
}

void ClearScene::Release()
{
}
